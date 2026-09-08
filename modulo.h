/****************************************
 
 *   - Nombre: David Andres Galindo Rojas 
 *   - INTERFAZ DE FUNCIONES 
 +   - Fecha: 26 de agosto de 2026
 *   - Laboratorio de Memoria

*****************************************/

#ifndef _MODULO_H_
#define _MODULO_H_

//Funcion para ingreso de valores y tamaño de matriz
void funcIngreso(int entrada);

//Funcion para inicializar matriz aleatoria 1.0 y 10.0
void iniMatrix(double *mat, int dim);

//Funcion imprimir matriz
void impMatrix(double *mat, int dim);

//Funcion suma de matrices C = A + B
void sumaMatrix(double *matA, double *matB, double *matC, int dim);

#endif
