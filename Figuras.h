#ifndef FIGURAS_H_INCLUDED
#define FIGURAS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lectura.h"
using namespace std;


/* material=area */

struct t_figura{
int id;
float area;
string tipo;
string color;
string descripcion;
t_figura *siguiente;
};





//el color es el primer parametro modificar
int generadorId();//se usa el mismo para todas las figuras se debe llamar en el constructor;
t_figura constructor(float area,string tipo,string color,string texto);//implementar calculo de area en los constructores (mati)
void setId();
float getId();
float setArea();
float getArea();
void setColor();
string getColor();
void setDescripcion();
string getDescripcion();
void setTipo();
string getTipo();



float areaCirculo(float radio); //mati
float areaCubo(float lado); //franco astorga
float areaCilindro(float radio,float altura);//franco aguirre
float areaRectangulo(float base float altura);//chino
float areaTriangulo(float cateto1 float cateto2);//sergio
 



void totalfigura(t_figura *&ptrfigura);//franco astorga

void totalfiguracolor(t_figura *&ptrfigura);//franco aguirre

void mostrarOrdenProduccionPorColor(t_figura *&ptrfigura);//chino

void mostrarOrdenPorArea(t_figura *&ptrfigura);//mati


//



/*a desarrollar:
Una vez que termina un lote de producción (cada archivo es un lote), se necesita saber para
cada figura:
Que ​ Tipo de Figura ​ es: if(*p[0]=="cilindro") cout<<"es un cilindro"--- se resuelve getTipo()
Que ​ Color ​ posee.        							     getColor(); 
Que ​ Cantidad de Plástico ​ se usó (sería la suma de las áreas de las figuras): 	     get area(); 
Además, se necesitan saber:
○ Los ​ Totales ​ por Figura 

+ total por Figura-Color. 

sergio lectura y llamaria a los constructores
cada uno hace un constructor






*/



#endif // FIGURAS_H_INCLUDED
