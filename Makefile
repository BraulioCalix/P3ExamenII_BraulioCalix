Main : Main.o Militar.o NodoArbol.o
	g++ Main.o Militar.o NodoArbol.o -lncurses -o Main
Militar.o: Militar.cpp Militar.h
	g++ -c Militar.cpp
NodoArbol.o: NodoArbol.cpp NodoArbol.h
	g++ -c NodoArbol.cpp
Main,o: Main.cpp Main.h
	g++ -c Main.cpp
