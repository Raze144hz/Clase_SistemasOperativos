/****************************************************
		Pontificia Universidad Javeriana
-Autor: David Andres Galindo Rojas
-Fecha: 11 de  noviembre del 2026
-Tema: Creacion de hilos con API posix
-Objetivos:
	+Creacion de funcion
	+Instancia de vectores Posix
	+Llamadas de funcion
*****************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

static void *funcionHilo(void *arg){             //Se crea la función para la creacion de los hilos
    size_t job = *(size_t*)arg;			 //size_t castea a tipos de datos num
    printf("Trabajo %zu \n", job);
    return NULL;
}

int main(int argc, char *argv[]){
    int N = (int)atoi(argv[1]); //ingreso por consola de N 
    size_t trabajos[N]; //vector trabajos para tamaño N que sera ingresado al bucle 
    pthread_t hilos[N]; //instancia de vector hilos

    for(int i=0; i<N;i++){     // Instanciación de los N hilos y asignación de su ID de trabajo evitando condiciones de carrera
        trabajos[i] = i;
        pthread_create(&hilos[i], NULL, funcionHilo, trabajos+i);
    }

    for(int i=0; i<N;i++){
        pthread_join(hilos[i], NULL);      // Sincronización: el hilo principal espera a que todos los hilos hijos terminen su ejecución
    }

    return 0;
}
