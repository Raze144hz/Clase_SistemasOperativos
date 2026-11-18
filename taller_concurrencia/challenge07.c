/*********************************************
*Autor: David Andrés Galindo Rojas
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Challenge 07 - Acumulacion con Hilos y Mutex
*Objetivos:
	-Paralelizar suma y resta con hilos Posix
	-Evitar condicion de carrera sobre variable global sum
********************************************/

#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 900000000                      // Número de ciclos por hilo
long long sum = 0;                               // Variable Global compartida
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Inicialización del Mutex

void* function(void *arg){                       // Función ejecutada por los hilos
    int valor = *(int *)arg;                     // Casteo del argumento (+1 o -1)
    for (int i = 0; i < NUM_LOOPS; i++){
        pthread_mutex_lock(&mutex);              // Bloqueo antes de modificar sum
        sum += valor;
        pthread_mutex_unlock(&mutex);            // Desbloqueo del Mutex
    }
    return NULL;
}

int main(void){
    pthread_t id01, id02;                        // Identificadores de los dos hilos
    int val1 = 1, val2 = -1;                     // Valores de incremento y decremento

    pthread_create(&id01, NULL, function, &val1);// Creación de hilo sumador (+1)
    pthread_create(&id02, NULL, function, &val2);// Creación de hilo restador (-1)

    pthread_join(id01, NULL);                    // Espera por finalización de ambos hilos
    pthread_join(id02, NULL);

    pthread_mutex_destroy(&mutex);               // Destrucción del Mutex
    printf("Sum = %lld\n", sum);                 // Imprime Sum = 0 sin condición de carrera
    return 0;
}
