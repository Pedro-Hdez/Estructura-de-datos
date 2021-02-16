#include <cstdlib>
#include <iostream>
#include <time.h>
#include "EstructurasDeDatos.h"

using namespace std;

struct cliente{
    int minutosCajera; //Minutos que tardará con la cajera.
    int minEspera;

    cliente *siguiente;
};
//----------------------------------------------------------------------------------------------------

struct cajera{
    public:

        int minutosFaltantes;
        int atendidos;
};

/****************************************************************************************************************************************************/

class colaBanco{

    public:
        cliente *principio, *fin;
        int horaBanco, minutosBanco; //Hora dentro del banco
        int cuantos;
        int numCajeras;
        int atendidos;
        int tamanoMaxCola;
        int maxEspera;
        cajera cajeras[6];

    public:
        colaBanco();
        ~colaBanco();

        void Agregar(cliente *c); //Método para agregar elementos a la pila.
        int Sacar(); //Método para sacar elementos de la pila.
        void Pintar(); //Método para imprimir la pila.
        int Cuantos(); //Método para imprimir la cantidad de elementos existentes en la pila.
        void PintarHora();
};
//----------------------------------------------------------------------------------------------------

colaBanco::colaBanco(){
    principio = fin = NULL;
    horaBanco = 9;
    minutosBanco = -1;
    cuantos = 0;
    numCajeras = 6;
    atendidos = 0;
    tamanoMaxCola = 0;
    maxEspera = 0;
}
//----------------------------------------------------------------------------------------------------

void colaBanco::Agregar(cliente *c){
    cliente *p = c;

    if(principio == NULL){
        p -> siguiente = NULL;
        principio = p;
        fin = p;
    }

    else{
        p -> siguiente = NULL;
        fin -> siguiente = p;
        fin = p;
    }
    cuantos ++;

}
//----------------------------------------------------------------------------------------------------

int colaBanco::Sacar(){
    cliente *p;
    int minutos;

    if(principio == NULL){
        return (VACIO);
    }
    else{
        p = principio;
        minutos = p -> minutosCajera;
        principio = p -> siguiente;
        delete p;
    }

    cuantos --;

    if(principio == NULL){
        fin = NULL;
    }

    return (minutos);

}
//----------------------------------------------------------------------------------------------------

int colaBanco::Cuantos(){
return (cuantos);
}

void colaBanco::PintarHora(){
    cout << horaBanco << " : " << minutosBanco;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void colaBanco::Pintar(){
    cliente *p; p = principio;
    while(p){
        std::cout << "" << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}


//----------------------------------------------------------------------------------------------------------------------------------------------------

colaBanco:: ~colaBanco(){
    cliente *p;
    cajera *q;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }

    principio = fin = NULL;
    horaBanco = 9;
    minutosBanco = -1;
    cuantos = 0;
    for(int i = 0 ; i < numCajeras ; i++){
        delete &cajeras[i];
    }

    return;
}

/****************************************************************************************************************************************************/

int main(){
    srand(time(NULL));
    int atendidoss = 0;
    int clientesLlegando;
    int menorTiempoCajera;
    cliente *c, *aux;
    colaBanco cola;
    bool atendido;
    int minutosCajera;
    int tiempoEsperaAprox;
    int minutos = 420;

    for(int i = 0 ; i < cola.numCajeras ; i++){
        cola.cajeras[i].minutosFaltantes = 0;
        cola.cajeras[i].atendidos = 0;

    }

    //Este ciclo while controla el tiempo de un día en el banco.
    while(minutos > 0){

        cola.minutosBanco++;
        if(cola.minutosBanco == 60){
            cola.horaBanco++;
            cola.minutosBanco = 0;
            if(cola.horaBanco == 16){
                break;
            }
        }
        cout << "HORA DEL BANCO: " << cola.horaBanco << " : " << cola.minutosBanco << endl << endl;
        clientesLlegando = 0 + rand() % 3; //Número de clientes que llegan al banco por minuto.
        cout << "clientes llegando: " << clientesLlegando << endl;
        atendidoss += clientesLlegando;
        cout <<"Hasta el momento van: " << atendidoss << " personas " << endl << endl;



        //Este ciclo recorre a la cajera para actualizar su estado
        for(int i = 0 ; i < cola.numCajeras ; i++){
            /*
            Si los minutos faltantes de la cajera son diferentes de cero, entonces significa que está atendiento a alguien,
            y como ya pasó un minuto, entonces se le resta un minuto a ese tiempo; si no, simplemente se ignora.
            */
            if(cola.cajeras[i].minutosFaltantes != 0){
                cola.cajeras[i].minutosFaltantes--;
                /*
                Si los minutos faltantes de alguna cajera ha llegado a cero, significa que ha terminado de atender a una persona, entonces
                la persona a la que estaba atendiendo se elimina.
                */
                if( cola.cajeras[i].minutosFaltantes == 0){
                    cola.cajeras[i].atendidos++;
                    cola.atendidos++;
                }
            }
        }
        aux = cola.principio;
        while(aux){
            aux -> minEspera++;
            aux = aux -> siguiente;
        }

        if(clientesLlegando == 0 ){
             for(int m = 0 ; m < cola.numCajeras ; m++ ){
                cout << "Minutos faltantes de la cajera " << m+1 << " " << cola.cajeras[m].minutosFaltantes << endl;

                if(cola.principio != NULL){
                    if(cola.cajeras[m].minutosFaltantes == 0){
                        if(cola.principio -> minEspera > cola.maxEspera) cola.maxEspera = cola.principio -> minEspera;
                        cola.cajeras[m].minutosFaltantes = cola.Sacar();
                    }
                }
            }
            cout << endl << endl;
        }
        else{
            for(int i = 0 ; i < clientesLlegando ; i++){

                //Se registra un nuevo cliente, la hora de llegada al banco y los minutos que tardará con la cajera.
                c = new cliente;
                c -> minEspera = 0;
                atendido = false;
                minutosCajera = c -> minutosCajera = 1 + rand() % 10;


                cout << endl << "El cliente "<< i+1 << " necesita "<< minutosCajera << " minutos" << endl;

                for(int m = 0 ; m < cola.numCajeras ; m++ ){
                    cout << "Minutos faltantes de la cajera " << m+1 << " " << cola.cajeras[m].minutosFaltantes << endl;
                }


                cout << endl << endl;


                //Se recorre el arreglo de las cajeras en busca de una desocupada
                for(int j = 0 ; j < cola.numCajeras ; j++){
                    if(cola.cajeras[j].minutosFaltantes == 0){ //Si se encuentra cajera desocupada, entonces se le asigna un cliente

                        if(cola.principio == NULL){
                            cola.cajeras[j].minutosFaltantes = minutosCajera;
                            atendido = true;
                            break;
                        }
                        else{
                            if(cola.principio -> minEspera > cola.maxEspera) cola.maxEspera = cola.principio -> minEspera;
                            cola.cajeras[j].minutosFaltantes = cola.Sacar();
                        }
                    }

                }

                for(int k = 0 ; k < cola.numCajeras ; k++){

                    if(cola.cajeras[k].minutosFaltantes != 0){ //Si se encuentra cajera desocupada, entonces se le asigna un cliente
                        cout << "La cajera " << k+1 << "Está ocupada y le restan " << cola.cajeras[k].minutosFaltantes <<" minutos" << endl;
                    }
                }
                //Si no se encontró cajera desocupada, entonces el cliente se agrega a la cola
                if(!atendido){
                    //Se calcula, con una aproximación, si el cliente que ha llegado al banco alcanzará a ser atendido.
                    tiempoEsperaAprox = 0;
                    aux = cola.principio;
                    while(aux){
                        tiempoEsperaAprox += aux -> minutosCajera;
                        aux = aux -> siguiente;
                    }

                    if( minutos - (tiempoEsperaAprox + c -> minutosCajera) >= 0 ){

                            cout << "SE HA AGREGADO A UNA PERSONA" << endl << endl;
                            cola.Agregar(c);
                            //Se cuenta la longitud de la cola cada vez que alguien se forma
                            if(cola.Cuantos() > cola.tamanoMaxCola) cola.tamanoMaxCola = cola.Cuantos();

                            cout << endl << "En la cola hay " << cola.Cuantos() << " personas formadas"<< endl;

                    }
                    else{
                        cout << "LA PERSONA NO PODRA SER ATENDIDA." << endl;
                        delete(c);
                    }
                }
            }
        }

        aux = cola.principio;
        int contador = 1;
        while(aux){
            cout << contador << " persona: " << "minCajera = " << aux -> minutosCajera << "  ;  " << " minEspera = " << aux -> minEspera << endl;
            contador++;
            aux = aux -> siguiente;
        }
        cout << "Atendidos hasta el momento: " << cola.atendidos << endl;
        cout << "//-----------------------------------------------------------------------------------------------------------------" << endl << endl << endl << endl;

        minutos--;
    }

    for(int i = 0 ; i < cola.numCajeras ; i++){
        if(cola.cajeras[i].minutosFaltantes != 0){
            cola.cajeras[i].atendidos++;
            cola.atendidos++;
        }
    }

    cout << endl << "El banco ha cerrado" << endl;
    cout << "Se atendieron a: " << cola.atendidos << " personas" << endl;
    for(int i = 0 ; i < cola.numCajeras ; i++){
        cout << "La cajera " << i+1 << " atendio a: " << cola.cajeras[i].atendidos << " personas" << endl;
    }
    cout << "Max tiempo de espera: " << cola.maxEspera << endl;
    cout << "Max tamaño de la cola: " << cola.tamanoMaxCola << endl;
    system("pause");
    return 0;
}
