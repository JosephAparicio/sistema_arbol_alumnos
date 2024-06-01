/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Cola.h"

void construir( Cola & cola){
    cola.cabeza = nullptr;
    cola.fin = nullptr;
    cola.longitud = 0;
}

bool esColaVacia(const struct Cola & cola){
    return cola.cabeza == nullptr;
}

int longitud(struct Cola cola){
    return cola.longitud;
}

NodoC * crearNodo(int elemento, NodoC * siguiente){

    struct NodoC * nuevoNodo = new struct NodoC;
    
    nuevoNodo->elem = elemento;
    nuevoNodo->sig = siguiente; 
    return nuevoNodo;
}

void encolar( Cola & cola, int elemento){
    NodoC * nuevoNodo = crearNodo(elemento, nullptr);
    NodoC * ultimoNodo = cola.fin; /*obtiene el Ãºltimo nodo*/
    if (ultimoNodo == nullptr){
        cola.cabeza = nuevoNodo;
        cola.fin = nuevoNodo;
    }
    else{
        ultimoNodo->sig = nuevoNodo;
        cola.fin = nuevoNodo;
    }            
    cola.longitud++;  
}

int desencolar( Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía, no se puede desencolar"<<endl;
        exit(1);
    }
    int elemento = cola.cabeza;
    eliminaCabeza(cola);
    return elemento;
}

void eliminaCabeza( Cola  & cola){
    NodoC * nodoEliminar = cola.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃƒÂ¡ vacÃƒÂ­a";
        exit(1);
    }
    else{
        cola.cabeza = cola.cabeza->sig;
        if(cola.cabeza == nullptr)
            cola.cabeza = nullptr;
        delete nodoEliminar;
        cola.longitud--;
    }
}

void imprime(const struct Cola & cola){
    imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}

