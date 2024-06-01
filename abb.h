#ifndef ABB_H
#define ABB_H

#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    struct nodo *hizq;  // puntero al hijo izquierdo
    Elemento elem;      // dato
    struct nodo *hder;  // puntero al hijo derecho
} NodoABB;

typedef struct
{
    NodoABB *raiz;   // puntero a la raiz del árbol
} ABB;

void construir( ABB &A );
NodoABB* crearNodoABB( Elemento e );
void insertar( ABB &A, Elemento e );
NodoABB* obtenerRaiz( ABB A );
void mostrarEnOrden( NodoABB *pR );
void mostrarEnPreOrden( NodoABB *pR );
void mostrarEnPostOrden( NodoABB *pR );
bool buscar( ABB A, Elemento e );
Elemento menor( NodoABB *pR );
Elemento mayor( NodoABB *pR );
int contarNodos( NodoABB *pR );
int sumarNodos( NodoABB *pR );
void copiar( ABB &B, NodoABB *pR );
int altura( NodoABB *pR );
int contarHojas( NodoABB *pR );
void eliminar( NodoABB *&pR, Elemento e );


#endif /* ABB_H */

