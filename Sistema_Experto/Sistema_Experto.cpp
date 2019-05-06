#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#include "Sistema_Experto.h"
using namespace::std;

int main(){

    SE a;

    int nodo[14];
    int nodo1[7], nodo2[7];
    string preguntas_conclusiones[40];
    ifstream sist;


    int componente;
    sist.open("nodos.txt");
    if (!sist){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    int i = 0;
    string texto;
    while(sist){
        if(i < 13){
            sist >> texto;
            istringstream cadena(texto);
            cadena >> componente;
            nodo[i] = componente;
            i++;

        }
        else{
            for(int k = 0 ; k < 6 ; k++){
                nodo1[k] = nodo[k];
            }
            for(int k = 6 ; k < 13 ; k++){
                nodo2[k-6] = nodo[k];
            }
            a.agregar_arco(nodo1, nodo2);
            i = 0;
        }
    }

    a.pintar();

    ifstream sist2;
    sist2.open("preguntas.txt");
    if (!sist2){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    i = 1;
    while(sist2){
        sist2 >> preguntas_conclusiones[i];
        i++;
    }
    cout << endl << endl << "PREGUNTAS, CONCLUSIONES, CLÁUSULAS INTERMEDIAS" << endl;
    for(int k = 1 ; k < 40 ; k++){
        cout << k << ": " << preguntas_conclusiones[k] << endl;
    }
    a.correr(preguntas_conclusiones);

    return 0;

}
