/*********************************************
*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Challenge 05 - Hilos sin sincronizacion de orden
*Objetivos:
	-Creacion de 3 hilos con funciones independientes
	-Observar el orden de impresion
********************************************/

#include <stdio.h>
#include <pthread.h>

void *f1(void *arg){                             // Función que ejecuta el hilo 1
    printf(" porque soy el mejor!!");
    return NULL;
}

void *f2(void *arg){                             // Función que ejecuta el hilo 2
    printf(" de forma rapida y divertida ");
    return NULL;
}

void *f3(void *arg){                             // Función que ejecuta el hilo 3
    printf(" Estoy aprendiendo ");
    return NULL;
}

int main(){
    pthread_t thread01, thread02, thread03;       // Declaración de descriptores de hilos Posix

    pthread_create(&thread01, NULL, f1, NULL);   // Creación del hilo 01
    pthread_create(&thread02, NULL, f2, NULL);   // Creación del hilo 02
    pthread_create(&thread03, NULL, f3, NULL);   // Creación del hilo 03

    pthread_join(thread01, NULL);                // Espera a que terminen los 3 hilos
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);

    printf("\n");
    return 0;
}
