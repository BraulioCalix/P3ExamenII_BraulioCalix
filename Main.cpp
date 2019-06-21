#include "Militar.h"
#include "NodoArbol.h"
#include <iostream>
#include "ncurses.h"
#include <fstream>
using std::ofstream;
using namespace std;
#include <vector>
using std::vector;
int main(){

    //NodoArbol* raiz= new NodoArbol(new Militar("Yagabarish  Skrobernov","M_17","72","general"));
    vector<Militar*> militares;
    bool programa=true; //bool que maneja todo el programa
    while (programa==true){
        cout << "ingrese que desea hacer:"<< endl 
        <<"1) crear ejercito"<< endl 
        <<"2) visualizar ejercito"<< endl
        <<"3) salir"<< endl;
        int menu=0;
        cin>> menu;
        militares.push_back(new Militar("Yagabarish  Skrobernov","M_17","72","General"));
        switch (menu){
        case 1:{
            cout << "ingreso crear ejercito"<< endl;
            cout <<"el general sera Yagabarish  Skrobernov"<< endl;
            
            cout << "que tipo de militar desea agregar: "<< endl
                 <<"1) coronel 2) mayor 3) Capitan 4) teniente 5) Sargento 6) Cabo 7) Soldado"<< endl;
            int opCrear=0;
            cin>> opCrear;
            bool crear=false;
            string nombre="",edad="",rango="",codigo="";
            cout << "ingrese el nombre: "<< endl;
            cin>> nombre;
            cout << "ingrese el codigo: "<< endl;
            cin >> codigo;
            cout << "ingrese la edad: "<< endl;
            cin >> edad;
            if(opCrear==1){// coronel
                rango="Coronel";
                
                crear=true;
            }else if(opCrear==2){// mayor
                rango ="Mayor";
                crear=true;
            }else if (opCrear==3){// capitan
                rango="Capitan";
                crear=true;
            }else if(opCrear==4){//teniente
                rango="Teniente";
                crear=true;
            }else if(opCrear==5){//sargento
                rango="Sargento";
                crear=true;
            }else if(opCrear==6){// cabo
                rango="Cabo";
                crear=true;
            }else if(opCrear==7){// soldado
                rango="Soldado";
                crear=true;
            }
            if (crear==true){
                militares.push_back(new Militar(nombre,codigo,edad,rango));
            }else{
                cout<< "no ingreso un valor valido para el rango"<< endl;
            }
            
        }break;
        case 2:{
            cout << "ingrese el nombre con el que desea guardar el archivo (sin el .txt): "<<endl;
            string nombre="";
            cin>> nombre;
            ofstream outFile;
            string archivo="";
            archivo=nombre;
            archivo+=".txt";
	        outFile.open(archivo,std::ios::app);for (int i = 0; i < militares.size(); i++){
                    if (militares[i]->getRango()=="General"){
                            outFile<<"* "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    if (militares[i]->getRango()=="Coronel"){
                            outFile<<"  > "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                        
                    }
                    if (militares[i]->getRango()=="Mayor"){
                        outFile<<"      ^ "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    if (militares[i]->getRango()=="Capitan"){
                        outFile<<"          - "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    if (militares[i]->getRango()=="Teniente"){
                        outFile<<"              -/ "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    if (militares[i]->getRango()=="Sargento"){
                        outFile<<"                  % "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    if (militares[i]->getRango()=="Cabo"){
                        outFile<<"                      } "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    if (militares[i]->getRango()=="Soldado"){
                        outFile<<"                          @ "<<militares[i]->getRango()<<"-"<<militares[i]->getNombre()<<endl;
                    }
                    
                }
            outFile.close(); 
            initscr();
            bool sigue=false; 
            if (has_colors()){
                start_color();
                init_pair(1,COLOR_GREEN,COLOR_WHITE);//original
                init_pair(2,COLOR_GREEN,COLOR_BLACK);//letra n
                init_pair(3,COLOR_BLACK,COLOR_WHITE);// letra i
                init_pair(4,COLOR_BLUE,COLOR_RED);//letra c
                init_pair(5,COLOR_BLUE,COLOR_WHITE);//letra l
                bkgd(COLOR_PAIR(1));
                for (int i = 0; i < militares.size(); i++){
                    if (militares[i]->getRango()=="General"){
                        printw("%s%s%s    *",militares[i]->getRango(),'-',militares[i]->getNombre());
                        refresh();
                    }
                    if (militares[i]->getRango()=="Coronel"){
                        printw("%s%s%s        *",militares[i]->getRango(),"-",militares[i]->getNombre());
                        refresh();
                    }
                    if (militares[i]->getRango()=="Mayor"){
                        printw("%s%s%s            *",militares[i]->getRango(),"-",militares[i]->getNombre());
                    refresh();
                    }
                    if (militares[i]->getRango()=="Capitan"){
                        printw("%s%s%s            *",militares[i]->getRango(),"-",militares[i]->getNombre());
                        refresh();
                        }
                    if (militares[i]->getRango()=="Teniente"){
                        printw("%s%s%s                *",militares[i]->getRango(),"-",militares[i]->getNombre());
                        refresh();
                    }
                    if (militares[i]->getRango()=="Sargento"){
                        printw("%s%s%s                    *",militares[i]->getRango(),"-",militares[i]->getNombre());
                    refresh();
                    }
                    if (militares[i]->getRango()=="Cabo"){
                        printw("%s%s%s                        *",militares[i]->getRango(),"-",militares[i]->getNombre());
                    refresh();
                    }
                    
                    if (militares[i]->getRango()=="Soldado"){
                        printw("%s%s%s                            *",militares[i]->getRango(),"-",militares[i]->getNombre());
                    refresh();
                    }
                }
                
                refresh();
                noecho();
                refresh();
                while(sigue==false){
                    char letra=' ';
                    letra=getch();
                    if (letra=='n'){
                        bkgd(COLOR_PAIR(2));
                        refresh();
                    }if (letra=='i'){
                        bkgd(COLOR_PAIR(3));
                        refresh();
                    }if (letra=='c'){
                        bkgd(COLOR_PAIR(4));
                        refresh();
                    }if(letra=='l'){
                        bkgd(COLOR_PAIR(5));
                        refresh();
                    }if(letra=='x'){
                        refresh();
                        endwin();
                        sigue=true;
                    }
                }// fin while
            }//fin if colors
            
        }break;       
            case 3:{
                cout<< "va a salirse del programa"<< endl;
                programa=false;
            }break;
        default:{
            cout<< "ingreso un dato invalido"<< endl;
           
        }break;
        }
    }
    return 0;
}