#include "abb.h"
#include <cmath>

void construir( ABB &A )
{
    A.raiz = NULL;  // todo arbol empieza vacio
}

NodoABB* crearNodoABB( Elemento e )
{
    // todo nodo que sea crea es siempre una hoja
    NodoABB *p;
    p = new NodoABB;  // se crea el nodo en memoria
    p->hizq = NULL;
    p->elem = e;
    p->hder = NULL;
    return p; // se retorna la direccion del nodo creado
}

void insertar( ABB &A, Elemento e )
{
    NodoABB *p, *q, *pq;
    p = crearNodoABB( e );     // se crea el nodo como hoja
    if ( A.raiz == NULL ) // arbol vacio
        A.raiz = p;  // el nodo insertado se convierte en la raiz del árbol
    else  // el árbol no está vacío
    {
        // hay que encontrar la ubicación que le corresponde al nuevo nodo
        q = A.raiz;
        pq = NULL;
        while ( q != NULL )
        {
            pq = q;
            if ( e < q->elem )
                q = q->hizq;
            else
                q = q->hder;
        }
        if ( e < pq->elem )
            pq->hizq = p;
        else
            pq->hder = p;
    }
}

// devuelve la dirección del nodo raiz del árbol
NodoABB* obtenerRaiz( ABB A )
{
    return A.raiz;
}

// muestra el contenido del árbol en orden
void mostrarEnOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnOrden( pAI);  // se recorre en orden el subarbol izquierdo
        cout << pR->elem << " ";  // se visita la raiz
        mostrarEnOrden( pAD);  // se recorre en orden el subarbol derecho
    }
}

// muestra el contenido del árbol en preorden
void mostrarEnPreOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        cout << pR->elem << " ";  // se visita la raiz
        mostrarEnPreOrden( pAI);  // se recorre en preorden el subarbol izquierdo
        mostrarEnPreOrden( pAD);  // se recorre en preorden el subarbol derecho
    }
}

// muestra el contenido del árbol en postorden
void mostrarEnPostOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnPostOrden( pAI);  // se recorre en postorden el subarbol izquierdo
        mostrarEnPostOrden( pAD);  // se recorre en postorden el subarbol derecho
        cout << pR->elem << " ";   // se visita la raiz
    }
}

// retorna true si el elemento e se encuentra en el árbol
// retorne false en caso contrario
bool buscar( ABB A, Elemento e )
{
    NodoABB *p;
    p = A.raiz;
    while ( p != NULL )
    {
        if ( e == p->elem )  // si lo encuentra retorna true
            return true;
        else
            if ( e < p->elem )
                p = p->hizq;   // continua la búsqueda en el subárbol izquierdo
            else
                p = p->hder;   // continua la búsqueda en el subárbol derecho
    }
    return false;  // si no lo encuentra retorna false
}

// retorna el valor del elemento menor del árbol
// el menor siempre se encuentra en el extremo izquierdo del árbol
Elemento menor( NodoABB *pR )
{
    NodoABB *p;
    p = pR;
    while ( p->hizq != NULL )
        p = p->hizq;
    return p->elem;
}

// retorna el valor del elemento mayor del árbol
// el mayor siempre se encuentra en el extremo derecho del árbol
Elemento mayor( NodoABB *pR )
{
    NodoABB *p;
    p = pR;
    while ( p->hder != NULL )
        p = p->hder;
    return p->elem;
}

// devuleve la cantidad de nodos que contiene el árbol
int contarNodos( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int nodosAI, nodosAD;
    if ( pR == NULL )  // caso base: arbol vacio: no tiene nodos
        return 0;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        nodosAI = contarNodos( pAI); // cuenta los nodos del subárbol izquierdo
        nodosAD = contarNodos( pAD); // cuenta los nodos del subárbol derecho
        return nodosAI + nodosAD + 1;  // le suma 1 ( el nodo raiz )
    }
}

// retorna la suma de los datos contenidos en el árbol
int sumarNodos( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int sumaAI, sumaAD;
    if ( pR == NULL )  // caso base: arbol vacio
        return 0;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        sumaAI = sumarNodos( pAI); // suma los datos del subárbol izquierdo
        sumaAD = sumarNodos( pAD); // suma los datos del subárbol derecho
        return sumaAI + sumaAD + pR->elem;  // le suma el dato contenido en la raiz
    }
}

void copiar( ABB &B, NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        insertar( B, pR->elem );  
        copiar( B, pAI );  
        copiar( B, pAD );  
    }
}

int altura( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int alturaAI, alturaAD;
    if ( pR == NULL )  // caso base: arbol vacio
        return -1;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        alturaAI = altura( pAI); // halla altura del subárbol izquierdo
        alturaAD = altura( pAD); // halla altura del subárbol derecho
        return 1 + max(alturaAI, alturaAD);  
    }
}

int contarHojas( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int hojasAI, hojasAD;
    if ( pR == NULL )  // caso base: arbol vacio
        return 0;
    else
    {
        if ( pR->hizq == NULL && pR->hder == NULL )
            return 1;
        pAI = pR->hizq;
        pAD = pR->hder;
        hojasAI = contarHojas( pAI); // cuenta las hojas del subárbol izquierdo
        hojasAD = contarHojas( pAD); // cuenta las hojas del subárbol derecho
        return hojasAI + hojasAD;  
    }
}

void eliminar( NodoABB *&pR, Elemento e )
{
    NodoABB *p;
    Elemento menorDerecha;
    if ( pR != NULL )
    {
        if ( pR->elem == e )
        {
            if ( pR->hder == NULL )
            {
            	p = pR;
            	pR = pR->hizq;
            	delete p;
            }
            else
		if( pR->hizq == NULL )
            	{
                    p = pR;
                    pR = pR->hder;
                    delete p;
		}
		else
		{
                    menorDerecha = menor(pR->hder);
                    pR->elem = menorDerecha;
                    eliminar( pR->hder, menorDerecha);
		}
        }
        else
            if ( e < pR->elem )
                eliminar( pR->hizq, e );
            else
                eliminar( pR->hder, e );
    }
}