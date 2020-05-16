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
  POST: Mostr� la lista de lectura, cada atributo con una etiqueta*/
void mostrarLista (t_lectura *&ptrLectura);
/*PRE: Recibe una l�nea de texto y una lista Lectura
  POST: Agreg� la l�nea de texto a un nudo de la lista lectura poniendo cada palabra de
   la l�nea de texto en un atributo de un nodo de la lista lectura, ordenando la lista*/
void separarPalabras(string s, t_lectura*& lectura_delinea);
/*PRE: Recibe un string
  POST: Cont� cu�ntas palabras tiene el String y retorna el resultado en tipo entero*/
int ContarPalabras(string palabra);
/*PRE: Recibe una lista lectura
  POST: Ley� un archivo y guardo cada l�nea del archivo en un nodo de la lista lectura*/
void Lectura(t_lectura *&o_lectura);
/*PRE: Recibe un string
  POST: Reemplaz� los punto y coma por espacios y las comas por puntos y retorna el string*/
string replaceNum(string s);
/*PRE: Recibe una variable que tiene cargado un n�mero en tipo String
  POST: Devuelve esa variable que recibi� pero en tipo float*/
float convertirStringA_float(string variableString);


#endif // LECTURA_H_INCLUDED

