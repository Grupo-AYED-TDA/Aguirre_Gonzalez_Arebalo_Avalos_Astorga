#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Figuras.h"
#include "Lectura.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	t_figura *o_figura=NULL;

	t_lectura *o_lectura = NULL;

	//Lectura deberia retornar un structura de lectura
    Lectura(o_lectura);

    mostrarLista(o_figura);



 //Test para probar que funciona TotalFigura , sumas las tres areas
    /*
    llamarContructorDeLista(1, "circulo","rojo","10","10",o_figura);
    llamarContructorDeLista(2, "triangulo","azul","10","10",o_figura);
    llamarContructorDeLista(3, "cubo","verde","10","10",o_figura);
    mostrarLista(o_figura);

    cout<<"TotalFigura-> "<<totalfigura(o_figura);

    */
}
