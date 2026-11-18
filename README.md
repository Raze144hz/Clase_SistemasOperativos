# 🖥️ Sistemas Operativos — Pontificia Universidad Javeriana

![C](https://img.shields.io/badge/Lenguaje-C_(ISO_C99/C11)-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Kernel-GNU/Linux_(POSIX)-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Ubuntu](https://img.shields.io/badge/Entorno-Ubuntu_Linux-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Build](https://img.shields.io/badge/Automatización-GNU_Make-427819?style=for-the-badge&logo=gnu&logoColor=white)
![Javeriana](https://img.shields.io/badge/PUJ-Ingeniería_de_Sistemas-003366?style=for-the-badge)

> **Pontificia Universidad Javeriana — Bogotá**  
> **Facultad de Ingeniería — Departamento de Ingeniería de Sistemas**  
> **Asignatura:** Sistemas Operativos  
> **Docente:** John Corredor Franco, PhD  
> **Autor:** David Andrés Galindo Rojas  

---

## 📌 Descripción de la Asignatura

Este repositorio compila los laboratorios, talleres prácticos, *challenges* y proyectos de evaluación de rendimiento desarrollados en la asignatura de **Sistemas Operativos** de la carrera de Ingeniería de Sistemas en la Pontificia Universidad Javeriana.

El curso aborda el estudio, diseño e implementación de los componentes fundamentales de un sistema operativo moderno bajo arquitecturas **UNIX / GNU/Linux**, haciendo énfasis en la interacción directa entre el software de bajo nivel y el hardware (CPU, jerarquía de memoria y dispositivos de Entrada/Salida), la programación concurrente y paralela mediante el estándar **POSIX**, y el análisis cuantitativo de rendimiento (**High Performance Computing - HPC**).

---

## 🧭 Ejes Temáticos del Curso

### 1. Programación de Sistemas y Modularidad en C
* Gestión directa de memoria (aritmética de punteros, asignación dinámica `malloc`/`calloc`/`free` y direccionamiento).
* Diseño de software modular mediante separación de interfaces (`.h`), implementaciones (`.c`) y compilación automatizada con **GNU Make (`Makefile`)**.

### 2. Gestión de Procesos y Planificación de CPU
* Ciclo de vida de los procesos, bloque de control de procesos (**PCB**) y cambios de contexto.
* Creación de jerarquías de procesos mediante llamadas al sistema (`fork()`, `wait()`, `waitpid()`, `exec()`).
* Algoritmos de planificación del sistema operativo (maximización de *throughput*, minimización de tiempo de respuesta y equidad en el uso de CPU).
* Comunicación Interprocesos (**IPC**): tuberías sin nombre (`pipe`), tuberías nombradas (`FIFO` / `mkfifo`) y memoria compartida.

### 3. Concurrencia, Paralelismo y Sincronización (`POSIX Pthreads`)
* Concurrencia explícita e implícita, programas concurrentes, paralelos y distribuidos.
* Hilos de ejecución a nivel de kernel y usuario mediante la librería `<pthread.h>` (`pthread_create`, `pthread_join`, `pthread_exit`).
* Problemas clásicos de concurrencia (Productor-Consumidor con *buffer* circular, Lectores-Escritores) y **Condiciones de Carrera (*Race Conditions*)**.
* Control Pesimista vs. Control Optimista de la concurrencia.
* Mecanismos de exclusión mutua y señalización en **Secciones Críticas**:
  * Cerrojos **Mutex** (`pthread_mutex_t`, `pthread_mutex_lock`, `pthread_mutex_unlock`).
  * **Semáforos de Dijkstra** binarios y contadores (`<semaphore.h>`, `sem_init`, `sem_wait`, `sem_post`).
  * Variables de condición.

### 4. Evaluación de Rendimiento y Cómputo de Alto Desempeño (HPC)
* Diseño de experimentos y *benchmarking* sobre cargas de trabajo intensivas (como multiplicación de matrices clásicas y transpuestas).
* Comparación empírica de paralelismo: **Procesos (`fork`) vs. Hilos (`pthread`)** y aprovechamiento de arquitecturas multinúcleo.
* Métricas de rendimiento, **Speedup**, eficiencia, localidad espacial/temporal de caché y automatización de pruebas con scripts en **Bash** y **Perl**.

### 5. Administración de Memoria y Sistemas de Archivos
* Jerarquía de memoria, memoria virtual, paginación, segmentación y reemplazo de páginas.
* Interfaz del sistema de archivos UNIX, nodos-i (*inodes*), permisos, directorios y llamadas al sistema de E/S de bajo nivel.

---

## 🛠️ Estándares de Desarrollo y Compilación

Todos los módulos y entregas del repositorio se rigen bajo las normas de ingeniería y evaluación del curso:

1. **Documentación en Membrete:** Cada archivo de código fuente (`.c`), cabecera (`.h`) y `Makefile` incluye su encabezado técnico con autor, fecha, tema, objetivos e instrucciones.
2. **Compilación Limpia Automatizada:** Uso de `Makefile` con banderas estándar de enlace (`-lm`, `-lpthread`, `-Wall`).
3. **Cero Binarios en el Repositorio:** Ninguna carpeta almacena objetos ejecutables ni binarios compilados.

### Uso general en cada directorio de trabajo:

```bash
# Compilar un programa específico del taller
make <nombre_programa>

# Ejecutar el binario generado
./<nombre_programa> [argumentos]

# Eliminar todos los objetos ejecutables (limpieza obligatoria)
make clear
