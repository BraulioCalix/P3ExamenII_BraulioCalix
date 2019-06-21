#include "Militar.h"
Militar::Militar(){

}
Militar::Militar(string name,string code,string age, string range ){
    nombre=name;
    codigo=code;
    edad=age;
    rango=range;
}
string Militar::getNombre(){
    return nombre;
}
string Militar::getRango(){
    return rango;
}   
