#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Figuras.h"

using namespace std;

void constructor(int input_id,string input_tipo,string input_color, float input_area,string texto, t_figura *&lista){
	        t_figura *nueva_figura = new t_figura();//creo un nuevo nodo

            nueva_figura->id = input_id;
            nueva_figura->area = input_area;
            nueva_figura->tipo = input_tipo;
            nueva_figura->color = input_color;
            nueva_figura->descripcion = texto;

            t_figura *aux1 = lista;//1 creo una lista auxiliar y guardo los datos de lista
            //lista = nueva_figura;//2  los datos del nuevo nodo(nueva_figura) los guardo en la lista y el siguente de lista apunta a nuevo nodo
            //nueva_figura->siguiente= aux1;//3  el siuente de nuevo nodo va a ser lo ultimo que haya en lista (la primera vez es null)
                                     //con 1, 2 y 3 agrego el nodo siempre al principio, sin odenar la lista
            //PARA ORDENAR saco el 2 y 3 y AGREGO:
            t_figura *aux2;//creo una lista auxiliar
            while((aux1 != NULL) && (aux1->id < input_id)){//mientras la lista tenga algo y el input_id sea mayor a los que hay en la lista
                aux2 = aux1;// aux2 pasa contener lo del primer nodo que encuentro en la lista y tambien aux2 va a apuntar a lo que apuntaba el primer nodo que encuentro en la lista
                aux1 = aux1->siguiente;// paso a la siguiente posición (al siguiente nodo)
                //al salir del while tengo un nuevo orden en aux2
             }
           if(lista == aux1){//si no entra al while
             lista = nueva_figura;//2  los datos del nuevo nodo(nueva_figura) los guardo en la lista y el siguente de lista apunta a nuevo nodo
           }
            else{//si entró (entonces  mi lista tiene un nuevo orden, y esta en aux2)
               aux2->siguiente = nueva_figura; //el nuevo nodo va a ser el siguiente todo lo que haya en aux2
           }
           nueva_figura->siguiente = aux1; //entre o no al while, todo lo que haya en aux1 va a ser lo siguiente de nuevo nodo (nueva_figura)
           //NOTA: si entró al whille la lista queda  aux2 ---> nueva_figura --> aux1  Y  si NO entró al whille la lista queda nueva_figura --> aux1
}

void mostrarLista(t_figura *&ptrfigura)
{
    t_figura *actual=new t_figura();
    actual=ptrfigura;
	while(actual != NULL)
	{
		cout<<endl<<"ID: "<<actual->id<<", tipo: "<<actual->tipo
		<<", color: "<<actual->color<<", area: "<<actual->area
		<<"  ------>descripcion--> "<<actual->descripcion<<endl;
		actual=actual->siguiente;
	}
}


float areaTriangulo(float base, float altura){
  return base*altura/2;
}

float areaCubo(float lado){
  return (lado * lado) * 6;
}

float areaRectangulo(float base, float altura){
  return base*altura;
}

float areaCilindro(float radio,float altura){
    return 2 * pi * radio * (radio + altura);
}

float areaCirculo(float radio){
	return pi*(radio*radio);
}

float getId(t_figura *&ptrfigura){
  return ptrfigura->id;
}

void setArea(float area_calculada, t_figura *&ptrfigura){
  ptrfigura->area=area_calculada;
}


float getArea(t_figura *&ptrfigura){
  return ptrfigura->area;
}
void setColor(string colorinput, t_figura *&ptrfigura){
	ptrfigura->color=colorinput;
}
string getColor(t_figura *&ptrfigura){
	return ptrfigura->color;
}
void setDescripcion(string texto, t_figura *&ptrfigura){
	ptrfigura->descripcion=texto;

}
string getDescripcion(t_figura *&ptrfigura){
	return ptrfigura->descripcion;
}

void setTipo(string inputTipo, t_figura *&ptrfigura){
	ptrfigura->tipo=inputTipo;
}
string getTipo(t_figura *&ptrfigura){
   return ptrfigura->tipo;
}

set<string> getColores(t_figura *&ptrfigura)
{
    t_figura * aux = ptrfigura;
    set <string> listaS;

    while(aux!=NULL)
    {
        listaS.insert(getColor(aux));
        aux = aux->siguiente;
    }

    return listaS;
}

set<string> getTiposFigura(t_figura *&ptrfigura)
{
    t_figura * aux = ptrfigura;
    set <string> listaS;

    while(aux!=NULL)
    {
        listaS.insert(getTipo(aux));
        aux = aux->siguiente;
    }

    return listaS;
}

float getTotalFiguraXColor(t_figura *&ptrfigura,string tipoFigura,string color){
    t_figura * aux = ptrfigura;
    float total = 0;

    while(aux != NULL){
        if(getTipo(aux)==tipoFigura && getColor(aux)==color){
            total += getArea(aux);
        }

        aux = aux->siguiente;
    }

    return total;
}

void mostrarTotalesTotalFiguraXColor(t_figura *&ptrfigura){
    set<string> color = getColores(ptrfigura);
    set<string> tipo = getTiposFigura(ptrfigura);
    set <string> :: iterator it;
    set <string> :: iterator it2;

    cout<<"AREA TOTAL POR FIGURA Y COLOR"<<endl<<endl;

    for(it2 = tipo.begin(); it2 != tipo.end(); ++it2){
        cout<<*it2<<":"<<endl;
        for(it = color.begin(); it != color.end(); ++it){
                if(getTotalFiguraXColor(ptrfigura,*it2,*it)>0){
                    cout<<"\t"<<*it<<": "<<getTotalFiguraXColor(ptrfigura,*it2,*it)<<endl;
                }
        }
        cout<<endl;
    }
}

float totalfigura(t_figura *&ptrfigura){

    float total=0;
    t_figura *actual=new t_figura();
    actual=ptrfigura;

	while(actual != NULL)
	{
		total+=actual->area;

		actual=actual->siguiente;

	}


    return total;
}

