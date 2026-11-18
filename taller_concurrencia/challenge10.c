/*********************************************
*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Challenge 10 - Orden de ejecucion con Semaforos
*Objetivos:
	-Coordinar la secuencia exacta de impresion (f3 -> f2 -> f1)
	-Uso de semaforos inicializados en 0 para señalizacion
********************************************/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_f2, sem_f1;                            // Semáforos globales para controlar el orden

void *f1(void *arg){                             // Tercer hilo en imprimir
    sem_wait(&sem_f1);                           // Espera la señal de f2 antes de imprimir
    printf(" porque soy el mejor!!");
    return NULL;
}

void *f2(void *arg){                             // Segundo hilo en imprimir
    sem_wait(&sem_f2);                           // Espera la señal de f3 antes de imprimir
    printf(" de forma rapida y divertida ");
    sem_post(&sem_f1);                           // Envía señal para desbloquear a f1
    return NULL;
}

void *f3(void *arg){                             // Primer hilo en imprimir
    printf(" Estoy aprendiendo ");               // Imprime de inmediato al iniciar
    sem_post(&sem_f2);                           // Envía señal para desbloquear a f2
    return NULL;
}

int main(){
    pthread_t thread01, thread02, thread03;      // Declaración de los 3 hilos Posix

    sem_init(&sem_f2, 0, 0);                     // Inicializados en 0 para bloquear desde el inicio
    sem_init(&sem_f1, 0, 0);

    pthread_create(&thread01, NULL, f1, NULL);   // Creación de los 3 hilos
    pthread_create(&thread02, NULL, f2, NULL);
    pthread_create(&thread03, NULL, f3, NULL);

    pthread_join(thread01, NULL);                 // Espera de finalización de los 3 hilos
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);

    printf("\n");
    sem_destroy(&sem_f2);                        // Elimina los semáforos de memoria
    sem_destroy(&sem_f1);
    return 0;
}
