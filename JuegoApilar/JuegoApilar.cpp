#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <wchar.h>
#include"pila.h"
#include <wchar.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    pila_lista* p1 = new pila_lista(4);
    p1->apilar(2);
    p1->apilar(1);
    p1->apilar(2);
    p1->apilar(1);
    pila_lista* p2 = new pila_lista(4);
    p2->apilar(1);
    p2->apilar(2);
    p2->apilar(1);
    p2->apilar(2);

    cout << "Bienvenido a apilar y desapilar de manera que quedan dos pilas ordenadas, una con dos y otra con unos El juego " << endl;

    cout << "Pila 1" << endl;
    p1->mostrarPila();
    cout << endl;

    cout << "Pila 2" << endl;
    p2->mostrarPila();
    cout << endl;

    cout << "Pila 3" << endl << "Vacía" << endl;

    cout << "Pulse enter para empezar..." << endl;
    cin.get();

    p1->JuegoPila(p1, p2);
}
