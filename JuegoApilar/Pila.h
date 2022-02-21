#pragma once
#include "Nodo.h"
#include "Cola.h"
class pila_lista
{
private:
	//Atributos.
	Nodo* punta;
	int limite, tope;

	//Metodos.
public:
	pila_lista(int);//Constructor.
	void apilar(int);//Set.
	int desapilar(); //Get.
	void JuegoPila(pila_lista*, pila_lista*);
	bool pilaVacia();
	bool pilaLlena();
	void llenarPila(pila_lista*);//Pasar datos, de pila llena a pila vacia.
	bool PilaCompleta();
	void mostrarPila();
	int decPila(int);
	int decApilar(int);
	bool win(pila_lista*, pila_lista*, pila_lista*);
	void insertarInicio(int);
};