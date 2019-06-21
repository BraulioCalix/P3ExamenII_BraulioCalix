#include "Militar.h"
#include <vector>
using std::vector;
#ifndef NODOARBOL_H
#define NODOARBOL_H
class NodoArbol{
private:
    Militar* militar;
    vector <NodoArbol*> nodohijo;
public:
    NodoArbol();
    NodoArbol(Militar*);
    Militar* getMilitar();
    vector <NodoArbol*> getVector();
};
#endif