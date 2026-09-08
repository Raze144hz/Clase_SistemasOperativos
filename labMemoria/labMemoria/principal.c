/****************************************
 * Pontificia Universidad Javeriana
 *
 * Autor: Galindo, David
 * Fecha: 26 de Agosto 2026
 * Materia: Sistemas Operativos
 * Laboratorio: Memoria 
 * Objetivos:
 *   -Implementar en funcionas la funcion principal
 *   - Implementar una funcion: suma de matrices
 *   - Implementar un fichero de funciones
 *   - Implementar un ficher de iterfaz de funciones
 *   - Crear un fichero de Automtizacion de Compilacion
 *   - Documentar y anunciar las instrucciones significativas
 *   - Comprimir todo y enviarlo a asignacion
 *
 * Fichero: principal
*****************************************/

    #include <stdio.h>   //Interfaz de Input Output
    #include <stdlib.h>
    #include <time.h>
    #include "modulo.h"  //Interfaz Aretesanal 

    //Funcion principal del programa que llama a la interfaz modulo.h
    int main(int argc, char *argv[]){

    //Funcion de modulo.h para validar argumentos de entrada
    funcIngreso(argc);

    //Variables iniciales
    double *matrixA;   //Matrix A :Puntero Unidimensional
    double *matrixB;   //Matrix B :Puntero Unidimensional
    double *matrixC;   //Matrix resultado matixA+matrixB
    int N = (int)atoi(argv[1]); //Casting a entero el 2 argumento

    //reserva de memoria de las 3 matrices principales en una sol dimension
    matrixA = (double *)malloc(N*N*sizeof(double));
    matrixB = (double *)malloc(N*N*sizeof(double));
    matrixC = (double *)malloc(N*N*sizeof(double));
    
    //Inicializacion de matrices
    iniMatrix(matrixA, N);
    iniMatrix(matrixB, N);
    //Impreaion de matrices
    impMatrix(matrixA, N);
    impMatrix(matrixB, N);

    //Suma de matrices matrixC = matrixA + matrixB
    sumaMatrix(matrixA, matrixB, matrixC, N);

    //Impresion matriz resulado matrixC
    impMatrix(matrixC, N);

    //liberar reserva de memoria

    
    free(matrixA);
	free(matrixB);
	free(matrixC);
    
 
    return 0;
}
