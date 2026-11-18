/*********************************************

*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 4/11/2026
*Tema: Creacion de hilos con API posix
*Objetivos:
	-Creacion de Hilo
	-Llamadas de funcion

********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funcionHilo(void *arg){            //Se crea la función para HILOS
    printf("El hilo esta entrando....\n");
    sleep(2);
    printf("El hilo esta saliendo....\n");
    return NULL;
}

int main(){
    pthread_t   hilo;                  //Se declaran los hilos
    int hiloCreacion = pthread_create(&hilo, NULL, funcionHilo, NULL);
    if(hiloCreacion){
        printf("Fallo de creación de HILO....\n");
    } else {
        printf("HILO creado con ID: %d \n", hiloCreacion);
    }

    hiloCreacion = pthread_join(hilo, NULL);
    if(hiloCreacion)                     //Se verifica si sale
        printf("Fallo de salida de HILO....\n");


    printf("Fin del programa..\n\n");
    return 0;
}
