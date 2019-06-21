#include <iostream>
using std::string;
#ifndef MILITAR_H
#define MILITAR_H
class Militar{
protected: 
string nombre;
string codigo;
string edad;
string rango;
    
public:
    Militar();
    Militar(string,string,string,string);
    string getNombre();
    string getRango();
};
#endif
