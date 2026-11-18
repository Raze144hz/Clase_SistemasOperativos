/***********************************************
*Autor: David Andrés Galindo Rojas
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Sincronizacion Hilos Pthreads (Con Mutex)
*Objetivos:
	-Implementacion de exclusion mutua con pthread_mutex_t
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t BLOQUEO;                         // Variable GLOBAL para el Mutex

void *funcion(void *job){                        // Función para ejecutar el hilo sincronizado
    pthread_mutex_lock(&BLOQUEO);                // Bloqueo de la sección critica
    size_t IDh = *(size_t *)job;                 // Casteo del ID del trabajo
    int cont = 5 * IDh;
    printf("\n Hilo %zu ha iniciado\n", IDh);

    for (int i = 0; i < 230; i++){               // Ciclo de procesamiento
        cont *= (cont + 1);
    }

    printf("\n Hilo %zu ha finalizado\n", IDh);
    pthread_mutex_unlock(&BLOQUEO);              // Desbloqueo de la sección critica
    return NULL;
}

int main(){
    size_t jobs[3];                              // Vector de identificadores de trabajo
    pthread_t hilos[3];                          // Declaración de los hilos Posix
    int i = 0;
    int error;

    if (pthread_mutex_init(&BLOQUEO, NULL) != 0){    // Inicialización y verificación del Mutex
        printf("\n Fallo de inicialización de MUTEX\n");
        return 1;
    }

    while (i < 3){                               // Lanzamiento de los 3 hilos
        jobs[i] = i;
        error = pthread_create(&hilos[i], NULL, &funcion, jobs + i);
        if (error != 0)
            printf("\nError en la creación de hilos: [%s]", strerror(error));
        i++;
    }

    pthread_join(hilos[0], NULL);                // Espera de finalización de los 3 hilos
    pthread_join(hilos[1], NULL);
    pthread_join(hilos[2], NULL);

    pthread_mutex_destroy(&BLOQUEO);             // Se libera la memoria utilizada por Mutex
    return 0;
}
