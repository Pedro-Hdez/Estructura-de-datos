#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Graficas.h"


using namespace std;

int main(){
    grafica g;
    int a, b, nArcos;
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
        g.agregar_arco(a,b);
    }

    g.pintar();

    return 0;

