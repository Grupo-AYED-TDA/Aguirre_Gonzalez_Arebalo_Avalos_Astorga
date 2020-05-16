#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


struct t_lectura{//Lista
	string p[4];
	t_lectura *siguiente;
};
/*PRE: Recibe una lista lectura
  POST: Mostró la lista de lectura, cada atributo con una etiqueta*/
void mostrarLista (t_lectura *&ptrLectura);
/*PRE: Recibe una línea de texto y una lista Lectura
  POST: Agregó la línea de texto a un nudo de la lista lectura poniendo cada palabra de
   la línea de texto en un atributo de un nodo de la lista lectura, ordenando la lista*/
void separarPalabras(string s, t_lectura*& lectura_delinea);
/*PRE: Recibe un string
  POST: Contó cuántas palabras tiene el String y retorna el resultado en tipo entero*/
int ContarPalabras(string palabra);
/*PRE: Recibe una lista lectura
  POST: Leyó un archivo y guardo cada línea del archivo en un nodo de la lista lectura*/
void Lectura(t_lectura *&o_lectura);
/*PRE: Recibe un string
  POST: Reemplazó los punto y coma por espacios y las comas por puntos y retorna el string*/
string replaceNum(string s);
/*PRE: Recibe una variable que tiene cargado un número en tipo String
  POST: Devuelve esa variable que recibió pero en tipo float*/
float convertirStringA_float(string variableString);


#endif // LECTURA_H_INCLUDED

