#include "Figuras.h"
using namespace std;

string replaceNum(string s){
    //casteo como int
    int limite = static_cast<int>(s.size());

    for (int i = 0; i < limite; i++)
        if (s[i] == ','){
            s[i] = '.';
        }else if(s[i] == ';'){
            s[i] = '\0';
        }

    return s;
}

void separarPalabras(string s,string* &puntero)
{
    string aux = s;
    std::string delimiter = " ";
    size_t pos = 0;
    int i=0;


    //ver info de npos http://www.cplusplus.com/reference/string/string/npos/
    while ((pos = s.find(delimiter)) != std::string::npos)//mientras la posicion del espacio (delimiter) no sea la última de la linea
    {
        puntero[i]= s.substr(0, pos);//guardo en geeks[i] los caracteres desde 0 la cantidad de "pos" caracteres
        puntero[i]=replaceNum(puntero[i]);
        s.erase(0, pos + delimiter.length());//Elimina del vector un solo elemento ( posición ) o un rango de elementos([primero, último]), este caso es el segundo de modo que en la vuelta siguiente la posicion 0 va a ser donde está el espacio ahora.
        i++;
    }
    puntero[i]=s;
    puntero[i]=replaceNum(puntero[i]);
}


void Lectura()
{
    ifstream archivo;
    string texto;
    string* puntero=new string[4];

    archivo.open("Figuras.txt",ios::in);//abrimos en modo lectura
    if(archivo.fail())
    {
        cout<<"No se ha podido abrir archivo"<<endl;
        exit(1);
    }

    while(!archivo.eof())//mientras no sea el final del archivo
    {
        getline(archivo,texto);
        separarPalabras(texto,puntero);
    }

    for(int i=0;i<4;i++)
    {
    cout<<"puntero--> "<<*(puntero+i)<<endl;
    }

    archivo.close();//cerramos archivo
    //borrar puntero;

}

void BuscarFigura(string *&p)
{
	/*con constructor
	  if(*p[0]=="cilindro")
    {
    Cilindro c = constructorCilindro(*p[1],*p[2],*p[3]);
        	
	guardar en lista void lote(mismo nombre del archivo);
	*/



    /*opcion vieja
    if(*p[0]=="cilindro")
    {
    Cilindro c = new Struct Cilindro;
        c->radio=*p[1];
        c->perimetro=*p[2];
    }
    */


}
