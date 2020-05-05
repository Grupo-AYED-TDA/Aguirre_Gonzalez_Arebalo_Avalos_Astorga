#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>

using namespace std;

struct t_figura;
void mostrarLista (t_figura *&ptrfigura);
void separarPalabras(string s,string *&p);
int ContarPalabras(string palabra);
void Lectura(t_figura *&o_figura);
void buscarFigura(int id, string *&p, t_figura *&o_figura);
string replaceNum(string s);
float convertirStringA_float(string variableString);
void llamarContructorDeLista(int id, string tipo, string color, string valor1, string valor2, t_figura *&o_figura);

#endif // LECTURA_H_INCLUDED
