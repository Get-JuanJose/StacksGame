#include "Pila.h"
#include<iostream>
#include"Nodo.h"
#include"Cola.h"
using namespace std;

pila_lista::pila_lista(int tam)
{
	limite = tam;
	tope = 0;
	punta = nullptr;
};

void pila_lista::apilar(int d)
{
	tope++;
	insertarInicio(d);
}
void pila_lista::JuegoPila(pila_lista* p1, pila_lista* p2)
{
	pila_lista* p3 = new pila_lista(4);
	int op, dec;
	do
	{
		op = 0; dec = 0;
		op = decPila(op);
		if (op == 1)
		{
			dec = decApilar(dec);
			if (dec == 2)
				p2->apilar(desapilar());
			else
				p3->apilar(p1->desapilar());
		}
		else
		{
			if (op == 2)
			{
				dec = decApilar(dec);
				if (dec == 1)
					p1->apilar(p2->desapilar());
				else
					p3->apilar(p2->desapilar());
			}
			else
			{
				dec = decApilar(dec);
				if (dec == 1)
					p1->apilar(p3->desapilar());
				else
					p2->apilar(p2->desapilar());
			}
		}
	} while (!win(p1, p2, p3));
	cout << "GANASTE";
}

bool pila_lista::win(pila_lista* p1, pila_lista* p2, pila_lista* p3)
{
	if ((p1->PilaCompleta() && p2->PilaCompleta()) || (p3->PilaCompleta() && p1->PilaCompleta()) || (p3->PilaCompleta() && p2->PilaCompleta()))
		return true;
	else
		return false;
}

bool pila_lista::PilaCompleta()
{
	int sw = 0;
	pila_lista* aux = new pila_lista(4);
	while (!pilaVacia())
	{
		if (punta->getDato() == 2)
		{
			while (punta->getDato() == 2 && !pilaVacia())
			{
				aux->apilar(desapilar());
				sw++;
			}
			if (sw == 4)
				return true;
			else
				return false;
		}
		else
		{
			while (punta->getDato() == 1 && !pilaVacia())
			{
				aux->apilar(desapilar());
				sw++;
			}
			if (sw == 4)
				return true;
			else
				return false;
		}
	}
	llenarPila(aux);
}

int pila_lista::decPila(int op)
{
	do
	{
		cout << "Cual pila desea modificar? ";
		cin >> op;
	} while (op != 1 && op != 2 && op != 3);
	return op;
}

int pila_lista::decApilar(int dec)
{
	do
	{
		cout << "A cual pila desea apilar? ";
		cin >> dec;
	} while (dec != 1 && dec != 2 && dec != 3);
	return dec;
}

int pila_lista::desapilar()//Similar al Get.
{
	Nodo* p = punta;
	int r = p->getDato();
	punta = punta->getliga();
	tope--;
	delete(p);
	return r;
}

bool pila_lista::pilaVacia()//Validacion vacia.
{
	bool r = false;
	if (tope == 0)
	{
		r = true;
	}
	return r;
}

bool pila_lista::pilaLlena()//Validacion llena(true = llena).
{
	if (tope == limite)
		return true;
	else
		return false;
}

void pila_lista::llenarPila(pila_lista* a)
{
	while (a->pilaVacia() == false)
	{
		apilar(a->desapilar());
	}
}

void pila_lista::insertarInicio(int d)
{
	Nodo* x = new Nodo();

	x->setDato(d);

	if (punta == nullptr)
	{
		punta = x;
	}
	else
	{
		x->setLiga(punta);
		punta = x;
	}
}


void pila_lista::mostrarPila()
{
	pila_lista* aux = new pila_lista(limite);
	int r = 0;
	while (pilaVacia() == false)
	{
		r = desapilar(); //Se vacia la pila principal.
		cout << "|" << r << "|" << endl;
		aux->apilar(r);
	}
	llenarPila(aux); //Se llena la pila auxiliar.
}
