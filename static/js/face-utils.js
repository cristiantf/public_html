/**
 * Utilidades compartidas de reconocimiento facial (face-api.js).
 * Usadas por el registro de rostro (perfil.html) y la verificación al marcar (docente.html).
 *
 * Diseño pensado para celulares:
 *  - La detección corre en un bucle secuencial (nunca se solapan dos análisis).
 *  - Los modelos se cargan una sola vez y los errores se muestran al usuario.
 *  - El video y el canvas comparten el tamaño real de la cámara (sin desalineación).
 */
(function (window) {
    'use strict';

    const MODEL_URL = '/static/models';
    const SCRIPT_URL = '/static/js/face-api.min.js';
    let modelsPromise = null;

    function loadScript(src) {
        return new Promise((resolve, reject) => {
            if (window.faceapi) return resolve();
            const s = document.createElement('script');
            s.src = src;
            s.onload = resolve;
            s.onerror = () => reject(new Error('No se pudo descargar la librería de reconocimiento facial.'));
            document.head.appendChild(s);
        });
    }

    /** Carga face-api.js y los tres modelos (solo la primera vez). */
    function loadModels() {
        if (!modelsPromise) {
            modelsPromise = loadScript(SCRIPT_URL)
                .then(() => Promise.all([
                    faceapi.nets.tinyFaceDetector.loadFromUri(MODEL_URL),
                    faceapi.nets.faceLandmark68Net.loadFromUri(MODEL_URL),
                    faceapi.nets.faceRecognitionNet.loadFromUri(MODEL_URL)
                ]))
                .catch(err => {
                    modelsPromise = null; // permitir reintentar
                    throw new Error('No se pudieron cargar los modelos de IA. Revise su conexión e intente de nuevo.');
                });
        }
        return modelsPromise;
    }

    /** Traduce los errores de getUserMedia a mensajes comprensibles. */
    function cameraErrorMessage(err) {
        switch (err && err.name) {
            case 'NotAllowedError':
            case 'SecurityError':
                return 'Permiso de cámara denegado. Habilítelo en la configuración del navegador (ícono de candado junto a la dirección) y vuelva a intentar.';
            case 'NotFoundError':
            case 'OverconstrainedError':
                return 'No se encontró una cámara en este dispositivo.';
            case 'NotReadableError':
                return 'La cámara está siendo usada por otra aplicación. Ciérrela e intente de nuevo.';
            default:
                return 'No se pudo iniciar la cámara: ' + (err && err.message ? err.message : 'error desconocido');
        }
    }

    /**
     * Enciende una cámara en el <video> y ajusta el contenedor a su proporción real.
     * facing: 'user' (frontal, por defecto) o 'environment' (trasera).
     * La vista se muestra en espejo solo con la cámara frontal.
     */
    async function startCamera(video, canvas, container, facing) {
        facing = facing || 'user';
        if (!navigator.mediaDevices || !navigator.mediaDevices.getUserMedia) {
            throw new Error('Este navegador no permite usar la cámara. Use Chrome o Safari actualizados y acceda por https.');
        }
        const pedir = (modo) => navigator.mediaDevices.getUserMedia({
            audio: false,
            video: { facingMode: modo, width: { ideal: 1280 }, height: { ideal: 720 } }
        });
        let stream;
        try {
            stream = await pedir({ ideal: facing });
        } catch (err) {
            throw new Error(cameraErrorMessage(err));
        }
        // Algunos teléfonos ignoran la preferencia: si entregaron la otra cámara, pedirla de forma estricta
        const obtenida = (stream.getVideoTracks()[0].getSettings ? stream.getVideoTracks()[0].getSettings() : {}).facingMode;
        if (obtenida && obtenida !== facing) {
            stopStream(stream);
            try {
                stream = await pedir({ exact: facing });
            } catch (err) {
                stream = await pedir({ ideal: facing }).catch(e => { throw new Error(cameraErrorMessage(e)); });
            }
        }
        video.srcObject = stream;
        video.setAttribute('playsinline', '');
        video.muted = true;
        await new Promise(resolve => {
            if (video.readyState >= 1) return resolve();
            video.onloadedmetadata = () => resolve();
        });
        try { await video.play(); } catch (e) { /* iOS puede requerir gesto; autoplay+muted suele bastar */ }

        const w = video.videoWidth || 640;
        const h = video.videoHeight || 480;
        if (canvas) { canvas.width = w; canvas.height = h; }
        // Cámara realmente obtenida (en computadoras suele no informarse: se asume frontal)
        const settings = stream.getVideoTracks()[0].getSettings ? stream.getVideoTracks()[0].getSettings() : {};
        const actual = settings.facingMode || facing;
        if (container) {
            container.style.aspectRatio = w + ' / ' + h;
            container.classList.toggle('mirror', actual !== 'environment');
        }
        stream.facing = actual;
        return stream;
    }

    /** true si el dispositivo tiene más de una cámara (llamar después de obtener permiso). */
    async function hasMultipleCameras() {
        try {
            const devices = await navigator.mediaDevices.enumerateDevices();
            return devices.filter(d => d.kind === 'videoinput').length > 1;
        } catch (e) {
            return false;
        }
    }

    /** Toma una foto del video (sin espejo) y la devuelve como File JPEG. */
    function captureFile(video, nombre) {
        const c = document.createElement('canvas');
        c.width = video.videoWidth;
        c.height = video.videoHeight;
        c.getContext('2d').drawImage(video, 0, 0, c.width, c.height);
        return new Promise((resolve, reject) => c.toBlob(blob => {
            if (!blob) return reject(new Error('No se pudo capturar la foto.'));
            resolve(new File([blob], nombre || ('evidencia_' + Date.now() + '.jpg'), { type: 'image/jpeg', lastModified: Date.now() }));
        }, 'image/jpeg', 0.85));
    }

    function stopStream(stream) {
        if (stream) stream.getTracks().forEach(t => t.stop());
    }

    /**
     * Bucle de detección secuencial. Llama a onResult({faces, video}) tras cada análisis.
     * Devuelve una función para detenerlo.
     */
    function detectLoop(video, onResult, intervalMs) {
        let active = true;
        const options = new faceapi.TinyFaceDetectorOptions({ inputSize: 224, scoreThreshold: 0.45 });
        async function step() {
            if (!active) return;
            if (video.readyState >= 2 && !video.paused) {
                try {
                    const faces = await faceapi.detectAllFaces(video, options)
                        .withFaceLandmarks()
                        .withFaceDescriptors();
                    if (!active) return;
                    await onResult(faces);
                } catch (e) {
                    console.error('Error en detección facial', e);
                }
            }
            if (active) setTimeout(step, intervalMs || 120);
        }
        step();
        return () => { active = false; };
    }

    /**
     * Evalúa la calidad de una detección: exactamente un rostro, confianza suficiente
     * y tamaño adecuado. Devuelve {ok, message, level}.
     */
    function evaluate(faces, video, minScore) {
        if (!faces.length) return { ok: false, level: 'danger', message: 'No se detecta un rostro. Mire de frente a la cámara.' };
        if (faces.length > 1) return { ok: false, level: 'danger', message: 'Se detecta más de un rostro. Solo usted debe aparecer.' };
        const det = faces[0].detection;
        const ratio = det.box.width / (video.videoWidth || 640);
        if (ratio < 0.22) return { ok: false, level: 'warning', message: 'Acérquese un poco más a la cámara.' };
        if (ratio > 0.75) return { ok: false, level: 'warning', message: 'Aléjese un poco de la cámara.' };
        if (det.score < (minScore || 0.6)) return { ok: false, level: 'warning', message: 'Imagen poco clara. Busque mejor iluminación y mire de frente.' };
        return { ok: true, level: 'success', message: '' };
    }

    /** Dibuja el recuadro del rostro (en coordenadas reales del video). */
    function draw(canvas, faces, color) {
        const ctx = canvas.getContext('2d');
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        ctx.lineWidth = Math.max(3, canvas.width / 160);
        ctx.strokeStyle = color || '#198754';
        faces.forEach(f => {
            const b = f.detection.box;
            ctx.strokeRect(b.x, b.y, b.width, b.height);
        });
    }

    /** Promedio de varios descriptores (Float32Array de 128). */
    function average(descriptors) {
        const out = new Array(128).fill(0);
        descriptors.forEach(d => { for (let i = 0; i < 128; i++) out[i] += d[i]; });
        return out.map(v => v / descriptors.length);
    }

    function csrfToken() {
        const m = document.querySelector('meta[name="csrf-token"]');
        return m ? m.content : '';
    }

    window.FaceUtils = { loadModels, startCamera, stopStream, detectLoop, evaluate, draw, average, csrfToken, hasMultipleCameras, captureFile };
})(window);
