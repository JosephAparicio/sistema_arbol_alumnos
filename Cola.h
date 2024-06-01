/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Cola.h
 * Author: josep
 *
 * Created on 1 de junio de 2024, 12:11 PM
 */

#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;

typedef int Elemento;

typedef struct nodoC
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodoC *sig;  // sig es la direcciÃƒÂ³n del siguiente nodo
} NodoC;

typedef struct
{
    NodoC *cabeza; // cima almacena la direccion del primer nodo de la pila
    NodoC *fin;
    int longitud; // cantidad de nodos de la pila
} Cola;

void construir( Cola & cola);
bool esColaVacia(const struct Cola & cola);
NodoC * crearNodo(int elemento, NodoC * siguiente);
void encolar( Cola & cola, int elemento);
int desencolar( Cola & cola);
int longitud(struct Cola cola);
void imprime(const struct Cola & cola);
void destruirCola( Cola & cola);

#endif /* COLA_H */

