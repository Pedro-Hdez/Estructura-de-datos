#include <cstdlib>
#include <iostream>
#include "EstructurasDeDatos.h"
#include <time.h>
#include <cstring>

using namespace std;

struct caja1{
    string nombre;
    string apellido;
    caja1 *siguiente;
};
/****************************************************************************************************************************************************/

class datos{
    //ATRIBUTOS
    private:
        caja1 *principio, *lugar;
        int cuantos;

    //MÉTODOS
    public:
        datos(); //Constructor de la clase.
        ~datos();//Destructor de la clase.
        void Agregar(string a, string b); //Método para agregar elementos a la pila.
        caja1* lugarAgregado();
        int Cuantos();
        void Pintar();
        void crear();
        void limpiar();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------

//CONSTRUCTOR
datos::datos(){
    principio = lugar = NULL;
    cuantos = 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void datos::Agregar(string a, string b){
    caja1 *p;
    p = new caja1;
    p -> nombre = a;
    p -> apellido = b;


    if(principio == NULL){
        p -> siguiente = NULL;
        principio = p;
    }
    else{
        p -> siguiente = principio;
        principio = p;
    }
    cuantos ++;
    lugar = p;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

caja1* datos::lugarAgregado(){
    return (lugar);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int datos::Cuantos(){
    return (cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void datos::Pintar(){
    caja1 *p; p = principio;
    while(p){
        std::cout <<"( " << p -> nombre << ", " << p -> apellido << " )" << endl;
        p = p -> siguiente;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

datos::~datos(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }

    principio = lugar = NULL;
    cuantos = 0;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void datos::crear(){
    principio = lugar = NULL;
    cuantos = 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void datos::limpiar(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }

    principio = lugar = NULL;
    cuantos = 0;
    return;
}
/****************************************************************************************************************************************************/

class orden1{
    private:
        caja1 *principio, *anterior;
        int cuantos;
        int encontrado;
        int donde;
        enum encontrado {SI, NO};
        enum donde {PRINCIPIO, ENMEDIO, FINAL};

    public:
        orden1();
        ~orden1();
        void buscar(caja1 *q);
        int agregar(caja1 *q);
        int borrar(caja1 *q);
        void pintar();
        int Cuantos();
        void crear();
        void limpiar();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------
orden1::orden1(){
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void orden1::buscar(caja1 *q){
    caja1 *p;

    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    p = principio;
    while(p){
        if( p -> nombre == q -> nombre && p -> apellido == q -> apellido){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //CREO QUE PUEDE ELIMINARSE ESTE CASO
                donde = FINAL;
             }
             else{
                donde = ENMEDIO;
            }
            return;
        }
        else if(p -> nombre == q -> nombre && p -> apellido != q -> apellido){
            if(p -> apellido > q -> apellido){
                if(p == principio){
                    encontrado == NO;
                    donde = PRINCIPIO;
                }
                else{
                    encontrado = NO;
                    donde  = ENMEDIO;
                }
                return;
            }
            else{
                encontrado = NO;
                anterior = p;
                p = p -> siguiente;
            }

        }
        else if(p -> nombre < q -> nombre){
            encontrado = NO;
            anterior = p;
            p = p -> siguiente;
        }
        else{
            encontrado = NO;
            if(principio == p){
                donde = PRINCIPIO;
            }
            else{
                donde = ENMEDIO;
            }
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int orden1::borrar(caja1 *q){
    caja1 *p;
    buscar(q);

    if(encontrado == NO) return (0);

    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }
    else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete(p);
    cuantos --;
    return (1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int orden1::agregar(caja1 *q){
    caja1 *p;
    buscar(q); //Se hace bolas??

    p = new caja1;
    p -> nombre = q -> nombre;
    p -> apellido = q -> apellido;

    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    else{
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }

    cuantos ++;
    return (1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void orden1::pintar(){
    caja1 *p; p = principio;
    while(p){
        std::cout <<"( " << p -> nombre << ", " << p -> apellido << " )" << endl;
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int orden1::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
orden1::~orden1(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void orden1::crear(){
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void orden1::limpiar(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
    return;
}
/*****************************************************************************************************************************************/
//ESTE ES EL ORDEN 2
class orden2{
    private:
        caja1 *principio, *anterior;
        int cuantos;
        int encontrado;
        int donde;
        enum encontrado {SI, NO};
        enum donde {PRINCIPIO, ENMEDIO, FINAL};

    public:
        orden2();
        ~orden2();
        void buscar(caja1 *p);
        int agregar(caja1 *p);
        int borrar(caja1 *p);
        void pintar();
        int Cuantos();
        void crear();
        void limpiar();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------
orden2::orden2(){
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void orden2::buscar(caja1 *q){
    caja1 *p;

    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    p = principio;
    while(p){
        if( p -> apellido == q -> apellido && p -> nombre == q -> nombre){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //CREO QUE PUEDE ELIMINARSE ESTE CASO
                donde = FINAL;
             }
             else{
                donde = ENMEDIO;
            }
            return;
        }
        else if(p -> apellido == q -> apellido && p -> nombre != q -> nombre){
            if(p -> nombre > q -> nombre){
                if(p == principio){
                    encontrado == NO;
                    donde = PRINCIPIO;
                }
                else if(p -> siguiente == NULL){
                    encontrado = NO;
                    donde = ENMEDIO;
                }
                else{
                    encontrado = NO;
                    donde  = ENMEDIO;
                }
                return;
            }
            else{
                encontrado = NO;
                anterior = p;
                p = p -> siguiente;
            }

        }
        else if(p -> apellido < q -> apellido){
            encontrado = NO;
            anterior = p;
            p = p -> siguiente;
        }
        else{
            encontrado = NO;
            if(principio == p){
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){
                donde = FINAL;
             }
            else{
                donde = ENMEDIO;
            }
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int orden2::borrar(caja1 *q){
    caja1 *p;
    buscar(q);

    if(encontrado == NO) return (0);

    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }
    else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete(p);
    cuantos --;
    return (1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int orden2::agregar(caja1 *q){
    caja1 *p;
    buscar(q);

    p = new caja1;
    p -> nombre = q -> nombre;
    p -> apellido = q -> apellido;

    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    else{
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }

    cuantos ++;
    return (1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void orden2::pintar(){
    caja1 *p; p = principio;
    while(p){
        std::cout <<"( " << p -> nombre << ", " << p -> apellido << " )" << endl;
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int orden2::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
orden2::~orden2(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void orden2::crear(){
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void orden2::limpiar(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
    return;
}
/****************************************************************************************************************************************************/
class BD{
    datos listadatos;
    orden1 A;
    orden2 B;

    public:
        BD();
        ~BD();
        void agregar(string a, string b);
        void pintar1();
        void borrar1(string a, string b);
        void pintar2();
        void borrar2(string a, string b);

        void pintarDatos();
        int cuantosTotales();
        int cuantosOrden1();
        int cuantosOrden2();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------
BD::BD(){
    listadatos.crear();
    A.crear();
    B.crear();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BD::agregar(string a, string b){
    listadatos.Agregar(a, b);
    A.agregar(listadatos.lugarAgregado());
    B.agregar(listadatos.lugarAgregado());
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BD::pintarDatos(){
    listadatos.Pintar();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BD::pintar1(){
    A.pintar();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BD::pintar2(){
    B.pintar();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int BD::cuantosTotales(){
    return(listadatos.Cuantos());
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
BD::~BD(){
    listadatos.limpiar();
    A.limpiar();
    B.limpiar();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int BD::cuantosOrden1(){
    return(A.Cuantos());
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int BD::cuantosOrden2(){
    return(B.Cuantos());
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BD::borrar1(string a, string b){
    caja1 *p = new caja1;;
    p -> nombre = a;
    p -> apellido = b;
    A.borrar(p);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BD::borrar2(string a, string b){
    caja1 *p = new caja1;
    p -> nombre = a;
    p -> apellido = b;
    B.borrar(p);
}
/****************************************************************************************************************************************************/
int main(){
    BD bd;
    srand(time(NULL));
    int a, b;

    bd.agregar("pedro", "hernandez");
    bd.agregar("pedro", "hernandez");
    bd.agregar("pedro", "hernandez");
    bd.agregar("luis", "thomson");
    bd.agregar("simon", "belmont");
    bd.agregar("kevin", "spacey");
    bd.agregar("carmen","amador");
    bd.agregar("soy","gay");
    bd.agregar("soy","lesbiana");
    bd.agregar("mela","pelas");
    bd.agregar("andres","iniesta");
    bd.agregar("bunbury","lopez");
    bd.agregar("mon","laferte");
    bd.agregar("pedro","amador");
    bd.agregar("rocio","ramon");
    bd.agregar("pedro","hernandez");
    bd.agregar("carmen","amador");
    bd.agregar("elmillonario","carrillo");
    bd.agregar("elpinche","comander");
    bd.agregar("luis","thomson");



    cout << endl << "PILA DE LA BASE DE DATOS ( " << bd.cuantosTotales() << " datos en total)" << endl;
    bd.pintarDatos();

    cout << endl << endl << "ORDEN POR NOMBRE ( " << bd.cuantosOrden1() << " datos en total)" << endl;
    bd.pintar1();

    cout << endl << endl << "ORDEN POR APELLIDO ( " << bd.cuantosOrden2() << " datos en total)" << endl;
    bd.pintar2();

    cout << endl << endl << "BORRANDO EL DATO: (ROCIO, RAMON) 2 veces: ";

    bd.borrar1("ROCIO", "RAMON");
    bd.borrar1("ROCIO", "RAMON");
    cout << endl << endl << "ORDEN POR NOMBRE ( " << bd.cuantosOrden1() << " datos en total)" << endl;
    bd.pintar1();

    bd.borrar2("ROCIO", "RAMON");
    bd.borrar2("ROCIO", "RAMON");
    cout << endl << endl << "ORDEN POR APELLIDO ( " << bd.cuantosOrden2() << " datos en total)" << endl;
    bd.pintar2();

}
