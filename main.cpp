#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Figuras.h"
#include "Lectura.h"

using namespace std;

/* PRE: Pecibe una lista (cargada) de lecturas y una lista (vacia) fuguras
   POST: Por cada nodo de la lista lectura llamó a cargarConstructorDeFiguras
   pasandole un nodo de lista lectura y la lista figura completa*/
void recorrerFigurasYCargarConstructorDeFiguras(t_lectura *&ptrLectura, t_figura *&o_figura);

/* PRE: Recibe un nodo (cargado) de lista lectura y la lista figura completa
   POST: Se llamó al constructor y se asingnaro cada atributo del nodo a cada
   parametro que requiere el constructor*/
void cargarConstructorDeFiguras(int id, t_lectura *&ptrLectura, t_figura *&o_figura);


int main(int argc, char** argv) {

	t_figura *o_figura=NULL;//Se genera una lista figura en null
	t_lectura *o_lectura = NULL; //Se genera una lista lectura en null
    Lectura(o_lectura); //Lectura lee un archivo y carga una lista de lectura
//    mostrarLista(o_lectura); //muestra la lista de datos obtenidos del archivo con un id agregado al principio de cada renglón
    recorrerFigurasYCargarConstructorDeFiguras(o_lectura,o_figura);
    mostrarLista(o_figura);
    return 0;
}

void recorrerFigurasYCargarConstructorDeFiguras(t_lectura *&ptrLectura,t_figura *&o_figura){
  t_lectura *actual=new t_lectura();
  actual=ptrLectura;
    int id = 0;
	while(actual != NULL)
	{
	    id++;
        cargarConstructorDeFiguras(id, actual,o_figura);
		actual=actual->siguiente;
	}
}

void cargarConstructorDeFiguras(int id, t_lectura *&ptrLectura, t_figura *&o_figura){
       string descripcion;
       float valor1f = convertirStringA_float(replaceNum(ptrLectura->p[2]));
       float valor2f = convertirStringA_float(replaceNum(ptrLectura->p[3]));
       if(ptrLectura->p[0] == "circulo"){
        descripcion = "Radio: "+ptrLectura->p[2];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaCirculo(valor1f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "cubo"){
        descripcion = "Lado: "+ptrLectura->p[2];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaCubo(valor1f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "cilindro"){
        descripcion = "Radio: "+ptrLectura->p[2]+" Altura: "+ptrLectura->p[3];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaCilindro(valor1f,valor2f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "rectangulo"){
        descripcion = "Base: "+ptrLectura->p[2]+" Altura: "+ptrLectura->p[3];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaRectangulo(valor1f,valor2f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "triangulo"){
        descripcion = "Base: "+ptrLectura->p[2]+" Altura: "+ptrLectura->p[3];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaTriangulo(valor1f,valor2f), descripcion, o_figura);
       }
}









//float convertirStringA_float(string variableString){
//
//  char *str=const_cast< char *>(variableString.c_str());//castea string a char arrays
//  float num;
//    num = atof(str);//es como un atoi pero f de float
//  return num;
//}
//
//
//int main ()
//{
//    printf("Hola ");
//  string v = "6.6";
//    float numero = convertirStringA_float(string v);
//  cout<<"   "<<numero;
//
//  return 0;
//}
//; //chino
