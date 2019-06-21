#include "NodoArbol.h"
NodoArbol::NodoArbol(){

}
Militar* NodoArbol::getMilitar(){
    return militar;
}
NodoArbol::NodoArbol(Militar* nodo){
militar=nodo;
}
vector <NodoArbol*> NodoArbol::getVector(){
    return nodohijo;
}