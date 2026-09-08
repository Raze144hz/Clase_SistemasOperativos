
/************************************
 * Ponticficia Universidad Javeriana
 *
 * Autor: Galindo, David
 * Fecha: 26 de Agosto 2026
 * Materia: Sistemas Operativos
 * Laboratorio: Memoria
 * Objetivos:
 *    - Implementar en funcionas la funcion principal
 *    - Implementar una funcion: suma de matrices
 *    - Implementar un fichero de funciones
 *    - Implementar un ficher de iterfaz de funciones
 *    - Crear un fichero de Automtizacion de Compilacion
 *    - Documentar y anunciar las instrucciones significativas
 *    - Comprimir todo y enviarlo a asignacion
 *
 * Fichero: Funciones
************************************/

#include <stdio.h>   //Interfaz de entrada salida
#include <stdlib.h>
#include <time.h>
#include "modulo.h" 

//Funcion para ingreso de valores y tamaño de matriz
void funcIngreso(int entrada){
    if(entrada != 2){
	printf("\n Use: \n\n\t $ejecutable valor \n\n");
	exit(0);
    }
}
//Funcion para inicializar matriz aleatoria 1.0 y 10.0
void iniMatrix(double *mat, int dim){
    srand(time(NULL));                          //Se crea semilla para aleatoriedad
    for(int i=0; i<dim*dim;i++)                     //Se recorre todo el vector
            mat[i] = (double)rand()/RAND_MAX*(10.0-1.0);
}
//Funcion imprimir matriz
void impMatrix(double *mat, int dim){
	if(dim < 12){
	if(dim<=10 && dim >=1){
	    for(int i=0; i<dim*dim;i++){ 
		if(i%dim==0) printf("\n");                       //Recorrido todo el vector
	            printf(" %f ", mat[i]);
		}
	}
	printf(  "\n=======================================\n ");

}
}
//Funcion suma de matrices C = A + B
void sumaMatrix(double *matA, double *matB, double *matC, int dim){
	for(int i=0; i<dim*dim; i++)               //Recorrido por el vector
		for(int j=0; j<dim; j++)
			matC[i]=matA[i]+matB[i];

}
