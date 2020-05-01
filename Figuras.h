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

struct Circulo{
float radio;
float area;
string color;
float materialEmpleado;
};

struct Cilindro{
float radio;
float altura;
float area;
string color;
float materialEmpleado;
};

struct Cubo{
float lado;
float area;
string color;
float materialEmpleado;
};

struct Triangulo{
float cateto1;
float cateto2;
float hipotenusa;
float area;
string color;
float materialEmpleado;
};

struct Rectangulo{
int id;//autoincrementable
float base;
float altura;
float area;
string color;
float materialEmpleado;
};




//el color es el primer parametro modificar
int generadorId();//se usa el mismo para todas las figuras se debe llamar en el constructor;
Circulo constructorCirculo(float radio,string color);//implementar calculo de area en los constructores
Cilindro constructorCilindro(float radio,float altura,string color);
Cubo constructorCubo(float lado,string color);
Triangulo constructorTriangulo(float cateto1,float cateto2,string color);
Rectangulo constructorRectangulo(float base,float altura,string color);
void setRadioCirculo();
void setColorCirculo();
float setAreaCirculo();
float getAreaCirculo();
float getRadioCirculo();
string getColorCirculo(); 


/*a desarrollar:
Una vez que termina un lote de producción (cada archivo es un lote), se necesita saber para
cada figura:
Que ​ Tipo de Figura ​ es: if(*p[0]=="cilindro") cout<<"es un cilindro"
Que ​ Color ​ posee.        getColor;
Que ​ Cantidad de Plástico ​ se usó (sería la suma de las áreas de las figuras): get area o getmaterialEmpleado;
Además, se necesitan saber:
○ Los ​ Totales ​ por Figura y por Figura-Color. totalcilindro= if(*p[0]=="cilindro"){totalcilindro=+1); /totalcilindrorojo=if((blalbla){total+1}
○ Dentro de cada color, mostrar en qué ​ Orden se fueron produciendo las "distintas" figuras. crear una lista por color recorriendo la lista de figuras(sean la misma o distintas listas esto se define si usamos lista void o lista por tipo de estructura)
○ Un listado que muestre las figuras ordenadas por el tamaño de sus áreas.


la primer opcion seria que cada figura sea una estructura separada con atributos como radio, altura.lado etc


la segunda opcion seria considerar al constructor como la maquina que fabrica, con lo cual esos atributos ya no se pueeden modificar por lo tanto
funcionan solo como parametros de entrada. las figuras quedarian todas como un mismo tipo de estructura con 4 atributos:
id 
tipo 
area
color
en esta opcion area no podria tener un set. ¿quien llama al set?






*/





/*

¿las figuras son tridimensionales o planas? el cubo no es plano el circulo y el triangulo no son paralepipedos por ej
¿el rinde del plastico es igual al area o al volumen en el caso del cilindro?


*/


#endif // FIGURAS_H_INCLUDED
