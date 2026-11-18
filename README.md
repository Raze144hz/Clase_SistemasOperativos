# 🧵 Concurrencia y Sincronización POSIX (Pthreads & Semáforos)

![Language](https://img.shields.io/badge/Lenguaje-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![OS](https://img.shields.io/badge/OS-Ubuntu_Linux-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![POSIX](https://img.shields.io/badge/API-POSIX_Pthreads-4EAA25?style=for-the-badge&logo=gnu-bash&logoColor=white)
![Build](https://img.shields.io/badge/Build-Makefile-427819?style=for-the-badge&logo=cmake&logoColor=white)

> **Pontificia Universidad Javeriana — Bogotá**  
> **Departamento de Ingeniería de Sistemas**  
> **Materia:** Sistemas Operativos  
> **Docente:** John Corredor Franco, PhD  
> **Autor:** David Andrés Galindo Rojas  
> **Fecha:** 17 de noviembre de 2026  

---

## 📌 Descripción General

Este repositorio contiene la implementación modular en lenguaje **C** de los laboratorios y *challenges* prácticos sobre **Concurrencia y Sincronización de Hilos** utilizando el estándar **POSIX (`<pthread.h>` y `<semaphore.h>`)**.

El proyecto aborda desde la creación y gestión del ciclo de vida de múltiples hilos hasta la resolución de **condiciones de carrera (*Race Conditions*)** y sincronización de **secciones críticas** mediante mecanismos de control pesimista (**Mutex** y **Semáforos Binarios/Contadores**).

---

## 📂 Estructura del Proyecto

| Archivo Fuente | Ejecutable | Tema / Concepto Principal | Mecanismo Utilizado |
| :--- | :--- | :--- | :--- |
| `Concurrencia.c` | `Concurrencia` | Creación dinámica de un vector de $N$ hilos e asignación de trabajos (`Job %zu`). | `pthread_create`, `pthread_join` |
| `pthread01.c` | `pthread01` | Introducción a semáforos y protección de sección crítica temporizada (`sleep(4)`). | `sem_t`, `sem_wait`, `sem_post` |
| `pthread02.c` | `pthread02` | Creación de un hilo con validación de códigos de retorno e identificación de estado. | `pthread_create`, `pthread_join` |
| `sincronizacion01.c` | `sincronizacion01` | Ejecución concurrente de 3 hilos **sin exclusión mutua** (evidencia de desorden en salida). | Condición de Carrera |
| `sincronizacion02.c` | `sincronizacion02` | Sincronización de sección crítica para garantizar ejecución serializada y ordenada. | `pthread_mutex_t` (`BLOQUEO`) |
| `challenge05.c` | `challenge05` | Impresión concurrente de fragmentos de texto en 3 hilos sin control de orden. | Planificación libre del SO |
| `challenge06.c` | `challenge06` | Acumulación secuencial (+1 y -1) de $900,000,000$ de iteraciones sobre variable global. | Ejecución Secuencial Base |
| `challenge07.c` | `challenge07` | Paralelización del `challenge06` con 2 hilos protegiendo la variable compartida `sum`. | `PTHREAD_MUTEX_INITIALIZER` |
| `challenge08.c` | `challenge08` | Control de entrada y salida en sección crítica (`Entered race` / `Exiting race`). | Semáforo Binario (`sem_init`) |
| `challenge09.c` | `challenge09` | Incremento y decremento concurrente ($10,000,000$ ciclos) sobre `balance` compartido. | Exclusión Mutua con `sem_t` |
| `challenge10.c` | `challenge10` | Señalización estricta de orden de ejecución (`f3` $\rightarrow$ `f2` $\rightarrow$ `f1`) mediante semáforos. | Semáforos inicializados en `0` |

---

## ⚙️ Compilación y Automatización (`Makefile`)

El proyecto cuenta con un archivo `Makefile` que automatiza la compilación enlazando las librerías matemáticas (`-lm`) y de hilos POSIX (`-lpthread`).

### 1. Compilar un programa específico
```bash
make Concurrencia
make pthread01
make pthread02
make sincronizacion01
make sincronizacion02
make challenge05
make challenge06
make challenge07
make challenge08
make challenge09
make challenge10
