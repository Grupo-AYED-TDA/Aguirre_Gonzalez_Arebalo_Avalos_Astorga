#include "Lectura.h"
#include "Figuras.h"
#include <list>
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

void separarPalabras(string s,string* &puntero)
{
    string aux;
    std::string delimiter = " ";
    size_t posDelimiter = 0;
    int i=0;

    //ver info de npos http://www.cplusplus.com/reference/string/string/npos/
    while ((posDelimiter = s.find(delimiter)) != std::string::npos)//mientras la posicion del espacio (delimiter) no sea la última de la linea
    {
        puntero[i]= s.substr(0, posDelimiter);//guardo en geeks[i] los caracteres desde 0 la cantidad de "pos" caracteres
        s.erase(0, posDelimiter + delimiter.length());//Elimina del vector un solo elemento (posición) o un rango de elementos([desde, hasta]), este caso es el segundo de modo que en la vuelta siguiente la posicion 0 va a ser donde está el espacio ahora.
        i++;
    }
    puntero[i]=s;
}


void Lectura(t_figura *&o_figura)
{
    ifstream archivo;//ifstream(tipo de variable para abrir un archivo)...  archivo (nombre de la variable)
    string texto;// variable string
    string* puntero=new string[5];
//    list<string> listaString;
    int id=0;
    archivo.open("Figuras.txt",ios::in);// con archivo.open le digo que quiero abrir un archivo (el archivo "FigurasEjemplo.txt") y con ios::in le digo que abro para leerlo

    if(archivo.fail())//si hay un error y no se abre el arvhivo
    {
        cout<<"No se ha podido abrir archivo"<<endl;//se muestra
        exit(1);//sale
    }

     //si se abre
    while(!archivo.eof())//mientras no sea el final del archivo
    {  id++;
        getline(archivo,texto);//Tomo lo que va encontrando (por linea, creo) en "archivo" y lo copio en "texto"
        separarPalabras(texto,puntero);//Mando un puntero a un vector y toda lo copiado (la linea) a separarlo (para guardar en las distintas posiciones del vector)
        buscarFigura(id, puntero, o_figura);
    }
      archivo.close();//cerramos archivo

}

void buscarFigura(int id, string *&p, t_figura *&o_figura)
{
        string tipo; string color; string valor1; string valor2;
        for(int i=0;i<5;i++)
        {
            switch(i) {
              case 0:tipo = *p;break;
              case 1:color = *(p+i);break;
              case 2:valor1 = *(p+i);break;
              case 3:valor2 = *(p+i);break;
              }

        }
       llamarContructorDeLista(id, tipo, color, valor1, valor2, o_figura);
}

void llamarContructorDeLista(int id, string tipo, string color, string valor1, string valor2, t_figura *&o_figura){
       string descripcion;
       float valor1f = convertirStringA_float(replaceNum(valor1));
       float valor2f = convertirStringA_float(replaceNum(valor2));

       if(tipo=="circulo"){
         descripcion = "Radio: "+valor1;
        constructor( id, valor1f, tipo, color, descripcion, o_figura);
       }
       if(tipo =="cubo"){
        descripcion = "Lado: "+valor1;
        constructor( id, valor1f, tipo, color, descripcion, o_figura);
       }
        if(tipo =="cilindro"){
        descripcion = "Radio: "+valor1+" Altura: "+valor2;
        constructor( id, valor1f+valor2f, tipo, color, descripcion, o_figura);
       }
       if(tipo =="rectangulo"){
        descripcion = "Base: "+valor1+" Altura: "+valor2;
        constructor( id, valor1f+valor2f, tipo, color, descripcion, o_figura);
       }
       if(tipo =="triangulo"){
        descripcion = "Base: "+valor1+" Altura: "+valor2;
        constructor( id, areaTriangulo(valor1f,valor2f), tipo, color, descripcion, o_figura);
       }
}

float convertirStringA_float(string variableString){

	char *str=const_cast< char *>(variableString.c_str());//castea string a char arrays
	float num;
    num = atof(str);//es como un atoi pero f de float
	return num;
}
