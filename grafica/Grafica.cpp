/*
    Nombre: Grafica.cpp
    Autor: Pedro Andrés Hernández Amador.
    Fecha: mayo del 2019

    Descripción: Archivo de implementación del algoritmo de Dijksrtra.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Graficas.h"

using namespace std;

int main(){
    grafica g; //Gráfica.
    int a, b; //Nodos
    float l; //Longitud del arco entre a y b
    ifstream grafica;

    /*SE LEE EL ARCHIVO DE TEXTO QUE CONTIENE LA GRÁFICA*/
    grafica.open("grafica.txt");
    if (!grafica){
        cout << "Error en la apertura del archivo...\n\n";
        system("pause");
        return 1;
    }

    while(grafica){
        grafica >> a; //Se extrae el primer nodo
        grafica >> b; //Se extrae el segundo nodo
        grafica >> l; //Se extrae la longitud del arco entre el primer nodo y el segundo
        g.agregar_arco(a,b,l); //Se agrega este arco a la gráfica
    }

    /*SE IMPRIME LA GRÁFICA COMPLETA*/
    cout << "GRÁFICA" << endl;
    g.pintar();
    cout << endl << "**********************************************************************************************" << endl;

    /*SE IMPLEMENTA EL ALGORITMO DE DIJKSTRA ENTRE LOS NODOS DADOS*/
    cout << "ALGORITMO DE DIJKSTRA" << endl;
    g.rutaCorta(1, 8);

    return 0;
}
