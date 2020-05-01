#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

//void separarPalabras(string s);
void separarPalabras(string s,string* &puntero);
int ContarPalabras(string palabra);
void Lectura();
string replaceNum(string s);

#endif // LECTURA_H_INCLUDED
