#include <iostream>
#include <cstdlib>
#include <fstream>

#include "monton.h"

using namespace std;

int main(){
    monton a;
    int nodo;
    ifstream monton;

   /* monton.open("monton.txt");
    if (!monton){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    while(monton){
        monton >> nodo;
        a.agregar(nodo);
    }

    cout << "MONTON: " << endl;*/
    a.agregar(20);
    a.agregar(50);
    a.agregar(100);

    cout << "------------------------------------------------------------------------" << endl;
}
