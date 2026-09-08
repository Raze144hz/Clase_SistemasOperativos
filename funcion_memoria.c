
/*******************************************************************************

Institucion: Pontificia Universidad Javeriana
Autor: David Andres Galindo Rojas
Fecha: 7 de septiembre del 2026
Trabajo: Laboratorio de funciones con memoria

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*Se reserva memoria estática con valor 4*/
#define CAPACIDAD_INICIAL 4

/*Se crea una estructura de datos para manipulación de Vectores*/
typedef struct vectorDin{
    int capacidad;
    int totalElementos;
    void **elemento;
} vectorDin;

/*Función para creación e inicio del vector*/
void iniVector(vectorDin *V){
    V->capacidad = CAPACIDAD_INICIAL;
    V->totalElementos = 0;
    V->elemento = malloc(sizeof(void *) * V->capacidad);
}

/*Función para la redimensíón del vector*/
static void resizeVector(vectorDin *V, int capacidad){
    printf("Redimensión: %d a %d\n", V->capacidad, capacidad);
    void **elemento = realloc(V->elemento, sizeof(void *)*capacidad);
    if(elemento){
        V->elemento  = elemento;
        V->capacidad = capacidad;
    }
}
/*Obtiene el valor del vector en una posición determinada*/
void *getVector(vectorDin *V, int indice){
    if (indice >= 0 && indice < V->totalElementos)
        return V->elemento[indice];
    return NULL;
}

/*Agrega un nuevo elemento al final del vector*/
void addVector(vectorDin *V, void *elemento){
    if (V->capacidad == V->totalElementos)
        resizeVector(V, V->capacidad * 2);
    V->elemento[V->totalElementos++] = elemento;
}

/*Devuelve la cantidad de elementos actuales*/
int totalVector(vectorDin *V){
    return V->totalElementos;
}

/*Elimina un elemento en una posición y compacta el vector*/
void borrarVector(vectorDin *V, int indice){
    if (indice < 0 || indice >= V->totalElementos)
        return;

    V->elemento[indice] = NULL;

    for (int i = indice; i < V->totalElementos - 1; i++) {
        V->elemento[i] = V->elemento[i + 1];
        V->elemento[i + 1] = NULL;
    }

    V->totalElementos--;
    if (V->totalElementos > 0 && V->totalElementos == V->capacidad / 4)
        resizeVector(V, V->capacidad / 2);
}

/*Cambia el contenido de una posición concreta*/
void setVector(vectorDin *V, int indice, void *elemento){
    if (indice >= 0 && indice < V->totalElementos)
        V->elemento[indice] = elemento;
}

/*Libera la memoria reservada por el vector*/
void liberarVector(vectorDin *V){
    free(V->elemento);
}

int main(void){
    /*Creación de vector para su edicion*/
    vectorDin editor;
    /*Inicialización del vector*/
    iniVector(&editor);

    /*Primera redimensión: 4 a 8*/
    resizeVector(&editor, 8);

    /*Agregar la primera frase*/
    addVector(&editor, "Hola");
    addVector(&editor, " Profesional");
    addVector(&editor, " en");
    addVector(&editor, " Formación");

    /*Imprimir primera salida*/
    for (int i = 0; i < totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
    printf("\n\n");

    /*Segunda redimensión: 8 a 4*/
    resizeVector(&editor, 4);

    /*Reducimos el contenido y agregamos el mundo para que quede "Hola Mundo"*/
    borrarVector(&editor, 1);
    borrarVector(&editor, 1);
    setVector(&editor, 1, " Mundo");

    /*Imprimir segunda salida*/
    for (int i = 0; i < totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
    printf("\n");

    /*Liberar memoria*/
    liberarVector(&editor);

    return 0;
}