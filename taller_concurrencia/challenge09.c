/*********************************************
*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Challenge 09 - Balance con Semaforos
*Objetivos:
	-Sincronizacion de incremento y decremento con sem_t
	-Proteccion de variable compartida balance
********************************************/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

long balance = 0;                                // Variable global de balance
sem_t mutex;                                     // Semáforo binario para exclusión mutua

void *increment(void *arg){                      // Hilo que incrementa el balance
    for(long i = 0; i < 10000000; i++){
        sem_wait(&mutex);                        // Espera y bloquea el semáforo P0
        balance++;                               // Sección crítica
        sem_post(&mutex);                        // Libera el semáforo P1
    }
    pthread_exit(NULL);
}

void *decrement(void *arg){                      // Hilo que decrementa 
    for(long j = 0; j < 10000000; j++){
        sem_wait(&mutex);                        // Espera y bloquea el semáforo P0
        balance--;                               // Sección crítica
        sem_post(&mutex);                        // Libera el semáforo P1
    }
    pthread_exit(NULL);
}

int main(){
    sem_init(&mutex, 0, 1);                      // Inicializa el semáforo binario en 1
    pthread_t thread1, thread2;                  // Declaración de hilos Posix

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);                 // Espera a que terminen los dos hilos
    pthread_join(thread2, NULL);

    printf("Value of balance is :%ld\n", balance);
    sem_destroy(&mutex);                         // Elimina el semáforo de memoria
    return 0;
}
