#include <iostream>
#include <cstdlib>
#include <fstream>

#include "ArbolesBin.h"

using namespace std;

int main(){
    arbol a;
    int nodo;
    ifstream arbol;

    arbol.open("arbol.txt");
    if (!arbol){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    while(arbol){
        arbol >> nodo;
        a.agregar(nodo);
    }

    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;

    a.borrar1(1);
    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;
    a.borrar1(2);
    a.pintar();



}
