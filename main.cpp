#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Figuras.h"
#include "Lectura.h"

using namespace std;

int main()
{
    t_figura *o_figura=NULL;
    Lectura(o_figura);
    mostrarLista(o_figura);

    return 0;
}
