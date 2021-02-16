/*
    Nombre: monton.cpp
    Autor: Pedro Andrés Hernández Amador.
    Fecha: mayo del 2019

    Descripción: Archivo de implementación de un montón (Min Heap).
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "monton.h"

using namespace std;

int main(){
    monton a;
    int nodo;
    ifstream monton;



    monton.open("monton.txt");
    if (!monton){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }


    while (!monton.eof())
    {
        monton >> nodo;
        a.agregar(nodo);
    }

    cout << "MONTON ORIGINAL: "<< endl;
    a.pintar();
    cout << "----------------------------------------------" << endl << endl;

    cout << "SE SACA EL NODO: " << a.sacar() << ": " <<endl;
    a.pintar();
    cout << "----------------------------------------------" << endl << endl;

    cout << "SE SACA EL NODO: " << a.sacar() << ": " <<endl;
    a.pintar();
    cout << "----------------------------------------------" << endl << endl;

    cout << "SE SACA EL NODO: " << a.sacar() << ": " <<endl;
    a.pintar();
    cout << "----------------------------------------------" << endl << endl;

    cout << "SE METE EL NODO: 20" << ": " <<endl;
    a.agregar(20);
    a.pintar();
    cout << "----------------------------------------------" << endl << endl;

   cout << "SE METE EL NODO: 10" << ": " <<endl;
    a.agregar(10);
    a.pintar();
    cout << "----------------------------------------------" << endl << endl;

    cout << "SE METE EL NODO: 100" << ": " <<endl;
    a.agregar(100);
    a.pintar();
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl << endl;

    cout << "A continuación, borro todos los nodos y dejo el último: " << endl;
    for(int i = 0 ; i < 21 ; i++){
        cout << "SE BORRO EL NODO: " << a.sacar() << endl;
    }
    a.agregar(4);
    a.agregar(20);
    a.agregar(0);
    a.pintar();


}
