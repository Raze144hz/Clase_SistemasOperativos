/*********************************************
*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Sincronizacion Hilos Pthreads (Sin Mutex)
*Objetivos:
	-Evidenciar condicion de carrera y desorden en salida
	-Creacion de multiples hilos con bucle while
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *funcion(void *job){                        // Función que ejecuta cada hilo sin bloqueo
    size_t IDh = *(size_t *)job;                 // Casteo del identificador del hilo
    int cont = 5 * IDh;                          // Inicialización de variable local según ID
    printf("\n Hilo %zu ha iniciado\n", IDh);

    for (int i = 0; i < 230; i++){               // Ciclo de carga
        cont *= (cont + 1);
    }

    printf("\n Hilo %zu ha finalizado\n", IDh);  // Sin mutex, por lo que el orden de salida es impredecible
    return NULL;
}

int main(){
    size_t jobs[3];                              // Vector de trabajos
    pthread_t hilos[3];                          // Vector de descriptores de hilos Posix
    int i = 0;
    int error;

    while (i < 3){                               // Creación de los 3 hilos
        jobs[i] = i;
        error = pthread_create(&hilos[i], NULL, &funcion, jobs + i);
        if (error != 0)                          // Verificación de error en creación
            printf("\nError en la creación de hilos: [%s]", strerror(error));
        i++;
    }

    pthread_join(hilos[0], NULL);                // Espera a que finalice cada hilo
    pthread_join(hilos[1], NULL);
    pthread_join(hilos[2], NULL);

    return 0;
}
