#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#include "Sistema_Experto.h"
using namespace::std;

int main(){

    SE a;

    int nodo1[8], nodo2[9];
    ifstream sist;

    int componente;
    int saliente;

    sist.open("preguntas_conclusiones.txt");
    if (!sist){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    int i = 0;
    string texto;
    while(sist){
        if(i < 8){
            sist >> texto;
            istringstream cadena(texto);
            cadena >> componente;
            nodo1[i] = componente;
            i++;

        }
    }
    a.pintar();

}
