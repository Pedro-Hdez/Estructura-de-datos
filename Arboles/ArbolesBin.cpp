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

    cout << "ARBOL ORIGINAL" << endl;
    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;

    cout << "BORRE EL NODO 50" << endl;
    a.borrar(50);
    a.pintar();
    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "BORRE EL NODO 60" << endl;
    a.borrar(60);
    a.pintar();
    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "BORRE EL NODO 85 y 40" << endl;
    a.borrar(85);
    a.borrar(40);
    a.pintar();
    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "BORRE EL NODO 9" << endl;
    a.borrar(9);
    a.pintar();
    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "BORRE EL NODO 49" << endl;
    a.borrar(49);
    a.pintar();
    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "BORRE EL NODO 27" << endl;
    a.borrar(27);
    a.pintar();
}
