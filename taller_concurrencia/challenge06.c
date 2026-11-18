/*********************************************
*Autor: David Andrés Galindo Rojas 
*Institucion: Pontificia Universidad Javeriana
*Materia: Sistemas Operativos
*Fecha: 17/11/2026
*Tema: Challenge 06 - Acumulacion secuencial
*Objetivos:
	-Suma y resta iterativa sobre variable global
	-Comparativa base antes de paralelizar con hilos
********************************************/

#include <stdio.h>

#define NUM_LOOPS 900000000                      // Cantidad de iteraciones del bucle
long long sum = 0;                               // Variable GLOBAL acumuladora

void function(int valor){                        // Función que modifica la variable global
    for (int i = 0; i < NUM_LOOPS; i++){
        sum += valor;                            // Incremento o decremento directo
    }
}

int main(void){
    function(1);                                 // Incrementa 900 millones de veces
    function(-1);                                // Decrementa 900 millones de veces
    printf("Sum = %lld\n", sum);                 // Imprime resultado final, sum = 0
    return 0;

}
