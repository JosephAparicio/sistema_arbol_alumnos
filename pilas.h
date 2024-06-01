/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   pilas.h
 * Author: josep
 *
 * Created on 25 de septiembre de 2023, 10:45 AM
 */

#ifndef PILAS_H
#define PILAS_H

#include <iostream>

typedef int Elemento;

typedef struct nodoP
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodoP *sig;  // sig es la direcciÃ³n del siguiente nodo
} NodoP;

typedef struct
{
    NodoP *cima; // cima almacena la direccion del primer nodo de la pila
    int longitud; // cantidad de nodos de la pila
} Pila;

void construir( Pila &P );
bool esPilaVacia( Pila P );
NodoP* crearNodoPila( Elemento e, NodoP *s );
void apilar( Pila &P, Elemento e );
void mostrar( Pila P );
Elemento desapilar( Pila &P );
void destruir( Pila &P );
Pila copiar( Pila &P );

#endif /* PILAS_H */

