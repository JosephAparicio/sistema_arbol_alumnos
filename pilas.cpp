/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include "pilas.h"

using namespace std;

void construir( Pila &P )
{
    // se crea la pila vacia
    P.cima = NULL;
    P.longitud = 0;
}

bool esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return P.longitud == 0;
}

NodoP* crearNodoPila( Elemento e, NodoP *s )
{
    NodoP *p;
    p = new NodoP; // se crea un nodo y su direccion se almacena en p
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void apilar( Pila &P, Elemento e )
{
    NodoP *p;
    p = crearNodoPila( e, P.cima );
    P.cima = p;
    P.longitud++;
}

void mostrar( Pila P )
{
    NodoP *p;
    int i;
    if ( esPilaVacia(P) )
        cout << "Pila vacia" << endl << endl;
    else
    {
        p = P.cima;
        for(i=1; i<=P.longitud; i++)
        {
            cout << p->elem << endl;
            p = p->sig;
        }
        cout << endl;
    }
}

// solo se usara esta funcion si la pila tiene datos
Elemento desapilar( Pila &P )
{
    NodoP *p;
    Elemento e;
    p = P.cima;
    e = p->elem;
    P.cima = p->sig;
    P.longitud--;
    delete p;
    return e;
}

void destruir( Pila &P )
{
    int i;
    NodoP *p, *q;
    if ( !esPilaVacia(P) )
    {
        p = P.cima;
        for(i=1; i<=P.longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        P.cima = NULL;
        P.longitud = 0;
    }
}

Pila copiar( Pila &P )
{
    Pila Q, R;
    Elemento x;
    construir(Q);
    construir(R);
    while ( !esPilaVacia(P) )
    {
        x = desapilar(P);
        apilar( Q, x);
    }
    while ( !esPilaVacia(Q) )
    {
        x = desapilar(Q);
        apilar( P, x);
        apilar( R, x);
    }
    return R;
}