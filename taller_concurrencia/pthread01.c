/*********************************************

*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 4/11/2026
*Tema: Creacion de hilos con API posix
*Objetivos:
	-Implementacion de semaforos
	-Introduccion a Hilos
	-Llamadas de funcion
********************************************/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>


sem_t MUTEX;                                //Creacion de variable GLOBAL para semaforo

void *funcionHilo(void *arg){               // Función para que ejecuta el hilo
    sem_wait(&MUTEX);
    printf("\nHilo esta entrando... \n");        
    sleep(4);                               //funcion que duerme al hilo
    printf("\nHilo esta saliendo... \n");       
    sem_post(&MUTEX);                       //desbloqueo del hilo
}

int main(){
    sem_init(&MUTEX,0,1);                    //Saber si esta bloqueada
    pthread_t   hilo01, hilo02;             //Declaración tipo de datos de los hilos Posix
    pthread_create(&hilo01,NULL,funcionHilo,NULL);
    sleep(4);                              
    pthread_create(&hilo02,NULL,funcionHilo,NULL);
    pthread_join(hilo01,NULL);              //espera a que se termine el hilo01
    pthread_join(hilo02,NULL);   
    sem_destroy(&MUTEX);                    //Elimino la ubicacion de memoria que se estaba utilizando del semaforo
    return 0;                              
} 
