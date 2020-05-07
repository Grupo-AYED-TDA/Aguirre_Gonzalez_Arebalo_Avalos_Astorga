#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
#include "Lectura.h"

using namespace std;


string replaceNum(string s){
    int limite = static_cast<int>(s.size());//casteo como "int" el resultado de "palabra.size()" que es de tipo size_t (esto lo hice porque me arrojaba un warning por comparar con int en el for)
    for(int i=0; i<limite; i++)
    {
       if (s[i] == ','){
          s[i] = '.';
      }else if(s[i] == ';'){
          s[i] = '\0';
      }
    }

    return s;
}

void separarPalabras(string s, t_lectura *&lectura_delinea)
{
    string aux;
    std::string delimiter = " ";
    size_t posDelimiter = 0;

    t_lectura *nueva_lec =  new t_lectura();
    int i=0;
    while ((posDelimiter = s.find(delimiter)) != std::string::npos)//mientras la posicion del espacio (delimiter) no sea la última de la linea
    {
        nueva_lec->p[i] = s.substr(0, posDelimiter);//guardo en geeks[i] los caracteres desde 0 la cantidad de "pos" caracteres
        s.erase(0, posDelimiter + delimiter.length());//Elimina del vector un solo elemento (posición) o un rango de elementos([desde, hasta]), este caso es el segundo de modo que en la vuelta siguiente la posicion 0 va a ser donde está el espacio ahora.
    i++;
    }

    nueva_lec->p[i] = s;
    //PARA ORDENAR:
    t_lectura *aux1 = lectura_delinea;//1 creo una lista auxiliar y guardo los datos de lista
    t_lectura *aux2;//creo una lista auxiliar
    while(aux1 != NULL){//mientras la lista tenga algo y el input_id sea mayor a los que hay en la lista
        aux2 = aux1;// aux2 pasa contener lo del primer nodo que encuentro en la lista y tambien aux2 va a apuntar a lo que apuntaba el primer nodo que encuentro en la lista
        aux1 = aux1->siguiente;// paso a la siguiente posición (al siguiente nodo)
        //al salir del while tengo un nuevo orden en aux2
     }

   if(lectura_delinea == aux1){//si no entra al while
     lectura_delinea = nueva_lec;//2  los datos del nuevo nodo los guardo en la lista y el siguente de lista apunta a nuevo nodo
   }
    else{//si entró (entonces  mi lista tiene un nuevo orden, y esta en aux2)
       aux2->siguiente = nueva_lec; //el nuevo nodo va a ser el siguiente todo lo que haya en aux2
   }

   nueva_lec->siguiente = aux1; //entre o no al while, todo lo que haya en aux1 va a ser lo siguiente de nuevo nodo
//NOTA: si entró al whille la lista queda  aux2 ---> nueva_lec --> aux1  Y  si NO entró al whille la lista queda nueva_lec --> aux1

}

void Lectura(t_lectura *&o_lectura)
{
    ifstream archivo;//ifstream(tipo de variable para abrir un archivo)...  archivo (nombre de la variable)
    string texto;// variable string
    archivo.open("Figuras.txt",ios::in);// con archivo.open le digo que quiero abrir un archivo (el archivo "FigurasEjemplo.txt") y con ios::in le digo que abro para leerlo

    if(archivo.fail())//si hay un error y no se abre el arvhivo
    {
        cout<<"No se ha podido abrir archivo"<<endl;//se muestra
        exit(1);//sale
    }
     //si se abre
    while(!archivo.eof())//mientras no sea el final del archivo
    {
        getline(archivo,texto);//Tomo lo que va encontrando (por linea, creo) en "archivo" y lo copio en "texto"
        separarPalabras(texto, o_lectura);
    }
      archivo.close();//cerramos archivo

}

void mostrarLista (t_lectura *&ptrLectura){
t_lectura *actual=new t_lectura();
actual=ptrLectura;

	while(actual != NULL)
	{
		cout<<endl<<" Tipo: "<<actual->p[0]
		<<", color: "<<actual->p[1]<<", valor: "<<actual->p[2]
		<<", valor2: "<<actual->p[3]<<endl;

		actual=actual->siguiente;
	}
}

float convertirStringA_float(string variableString){

	char *str=const_cast< char *>(variableString.c_str());//castea string a char arrays
	float num;
    num = atof(str);//es como un atoi pero f de float
	return num;
}
