#ifndef FIGURAS_H_INCLUDED
#define FIGURAS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

using namespace std;

struct t_figura{
    int id;
    string tipo;
    string color;
    float area;
    string descripcion;
    t_figura *siguiente;
};


const float pi=3.14159265359;

/*PRE: Recibe; int id,string tipo,string color, float area (calculada) ,string descripcion (en descripcion van los valores
   y etiqueta de radio, lado, base y/o altura, que se usó, según el tipo de figura, para calcular el area) y una lista figura
  POST: Se crgó cada parametro recibido a los atributos del nodo de lista figura, ordenando la lista*/
void constructor(int id,string tipo,string color, float area,string descripcion, t_figura *&lista);
/*PRE: Recibe una lista figura
  POST: Mostró la lista de figura, cada atributo con una etiqueta*/
void mostrarLista(t_figura *&o_figura);
void setId(int &id_global,t_figura *&ptrfigura);
float getId(t_figura *&ptrfigura);
void setArea(float area_calculada, t_figura *&ptrfigura);
float getArea(t_figura *&ptrfigura);
void setColor(string colorinput, t_figura *&ptrfigura);
string getColor(t_figura *&ptrfigura);
void setDescripcion(string texto, t_figura *&ptrfigura);
string getDescripcion(t_figura *&ptrfigura);
void setTipo(string inputTipo, t_figura *&ptrfigura);
string getTipo(t_figura *&ptrfigura);



float areaCirculo(float radio); //mati
float areaCubo(float lado); //franco astorga
float areaCilindro(float radio,float altura);//franco aguirre
float areaRectangulo(float base, float altura);//chino
/*PRE: Recibe base y altura en float
  POST: Retorna el area del triangulo en float*/
float areaTriangulo(float base, float altura);//sergio


void totalfigura(t_figura *&ptrfigura);//franco astorga
//void totalfiguracolor(t_figura *&ptrfigura);//franco aguirre HECHO
void mostrarOrdenProduccionPorColor(t_figura *&ptrfigura);//chino
void mostrarOrdenPorArea(t_figura *&ptrfigura);//mati

set<string> getTiposFigura(t_figura *&ptrfigura); // Trae todos los tipos distintos de figuras encontrados en el lote
set<string> getColores(t_figura *&ptrfigura); // Trae todos los tipos distintos de colores encontrados en el lote
float getTotalFiguraXColor(t_figura *&ptrfigura,string tipoFigura,string color); // Retorna la suma de las areas que coincidan con los parametros recibidos
void mostrarTotalesTotalFiguraXColor(t_figura *&ptrfigura); // Imprime el area de las combinaciones posibles entre color y tipo de figura existente


/*a desarrollar:
Una vez que termina un lote de producción (cada archivo es un lote), se necesita saber para
cada figura:
Que ​ Tipo de Figura ​ es: if(*p[0]=="cilindro") cout<<"es un cilindro"--- se resuelve getTipo()
Que ​ Color ​ posee.        							     getColor();
Que ​ Cantidad de Plástico ​ se usó (sería la suma de las áreas de las figuras): 	     get area();
Además, se necesitan saber:
○ Los ​ Totales ​ por Figura
+ total por Figura-Color.
sergio lectura y llamaria al constructor
*/



#endif // FIGURAS_H_INCLUDED
