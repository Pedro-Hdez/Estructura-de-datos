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

    cout << "BORRE EL NODO 17" << endl;

    a.borrar(17);
    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;

     cout << "BORRE EL NODO 78" << endl;

    a.borrar(78);
    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;
     cout << "BORRE EL NODO 83" << endl;

    a.borrar(83);
    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;
     cout << "BORRE EL NODO 10" << endl;

    a.borrar(10);
    a.pintar();
    cout << "------------------------------------------------------------------------" << endl;

}
