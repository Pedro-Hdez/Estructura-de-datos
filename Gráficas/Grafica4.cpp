#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Graficas4.h"

using namespace std;

int main(){
    grafica g;
    int a, b;
    float l;
    ifstream grafica;

    grafica.open("grafica.txt");
    if (!grafica){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    while(grafica){
        grafica >> a;
        grafica >> b;
        grafica >> l;
        g.agregar_arco(a,b,l);
    }
    cout << "GRÁFICA" << endl;
    g.pintar();
    cout << endl << "**********************************************************************************************" << endl;
    cout << "ALGORITMO DE DIJKSTRA" << endl;
    g.rutaCorta(1, 6);

    return 0;
}
