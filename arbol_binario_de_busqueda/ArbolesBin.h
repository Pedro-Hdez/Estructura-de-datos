/*
    Nombre: ArbolesBin.h
    Autor: Pedro Andrés Hernández Amador.
    Fecha: mayo del 2019

    Descripción: Archivo de cabecera que incluye las funciones, clases y estructuras que gestionan el funcionamiento
                 de un árbol binario de búsqueda.
*/


#ifndef ARBOLESBIN_H_INCLUDED
#define ARBOLESBIN_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
    Esta estructura representa un nodo del árbol.

    ATRIBUTOS
    los punteros: padre, hder, hizq son para conectar los nodos en el árbol
    los punteros: anterior, siguiente son para conectar los nodos en la lista doble
    la variable valor es la que almacena el valor del nodo.
*/
struct nodo{
    nodo *padre, *hder, *hizq, *anterior, *siguiente;
    int valor;
};
/***************************************************************************************************************************************************/
/*
    Esta clase representa a un árbol de búsqueda binario

    ATRIBUTOS:
    donde: Padre del nodo que se encontró ó nodo en donde se agregará/borrará un hijo.
    raiz: raiz del árbol
    principio: principio de la lista ordenada. Coincide con la raiz.
    fin: último elemento de la lista ordenada.
    encontrado: indica si algún nodo buscado se encontró en el árbol
    como: indica cómo se encontró colgado un nodo en el árbol o si es la raiz de éste.

    FUNCIONES:
    arbol(): constructor
    ~arbol(): destructor
    buscar(int a): busca un nodo en el árbol
    agregar(int a): agrega un nodo al árbol (no se admiten repeticiones)
    pintar(): imprime en pantalla el árbol
    borrar(): se usa para gestionar el borrado de un nodo
    borrar1(nodo *p1): borra un nodo sin hijos o con un sólo hijo
    intercambiar(nodo *p, nodo *q): intercambia dos nodos del árbol
    intercambiarVecinos(nodo *p1, nodo *q1): intercambia los punteros (vecinos) de dos nodos en el árbol
*/
class arbol{
    nodo *donde, *raiz, *principio, *fin;
    int encontrado, como;
    enum encontrado {SI, NO};
    enum como {HDER, HIZQ, RAIZ};

public:
    arbol();
    ~arbol();
    void buscar (int a);
    int agregar(int a);
    void pintar();
    int borrar(int a);
    void borrar1(nodo *p1);
    void intercambiar(nodo *p, nodo *q);
    void intercambiarVecinos(nodo *p1, nodo *q1);

};
/***************************************************************************************************************************************************/

/*
    Esta función es el constructor de la clase arbol.
*/
arbol::arbol(){
    donde = raiz = principio = fin = NULL;
    encontrado = NO;
    donde = NULL;
    como = RAIZ;
}
/***************************************************************************************************************************************************/

/*
    Esta función es el destructor de la clase arbol.
*/
arbol::~arbol(){
    nodo *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    donde = raiz = principio = fin = NULL;
    encontrado = NO;
    donde = NULL;
    como = RAIZ;
    return;
}
/***************************************************************************************************************************************************/

/*
    Esta función busca un número dentro del árbol.

    PARÁMETROS
    a: el número a buscar dentro del nodo.
*/

void arbol::buscar(int a){
    nodo *p;
    p = raiz;

    //Si el árbol está vacío, entonces el nodo automáticamente se agregará como raiz
    if(p == NULL){
        encontrado = NO;
        donde = NULL;
        como = RAIZ;

        return;
    }

    while(p){
        if(p->valor == a){
            encontrado = SI;
            if(p == raiz){
                donde = NULL;
                como = RAIZ;
                return;
            }

            donde = p->padre;
            if(donde -> hder == p){
                como = HDER;
            }
            else{
                como = HIZQ;
            }
            return;
        }
        else if(p -> valor > a){
            if(p->hizq == NULL){
                encontrado = NO;
                donde = p;
                como = HIZQ;
                return;
            }
            else{
                donde = p;
                p = p->hizq;
            }
        }
        if(p->valor < a){
            if(p->hder == NULL){
                encontrado = NO;
                donde = p;
                como = HDER;
                return;
            }
            else{
                donde = p;
                p = p->hder;
            }
        }
    }
}
/***************************************************************************************************************************************************/

/*
    Esta función agrega un número al árbol.

    PARÁMETROS
    a: el número a agregar.

    Regresa un 1 si se pudo agregar el número; en caso contario, regresa un 0.
*/
int arbol::agregar(int a){
    nodo *p;
    buscar(a);

    if(encontrado == SI) return(0);

    p = new nodo;
    p -> valor = a;
    p->hder = p->hizq = p->anterior = p->padre = p->siguiente = NULL;

    //ARBOL
    if(como == RAIZ){
        raiz = p;
        p->padre = NULL;
    }
    else if(como == HDER){
        donde->hder = p;
        p->padre = donde;
    }
    else{
        donde->hizq = p;
        p->padre = donde;
    }

    //LISTA DOBLE
    if(como == RAIZ){
        p->anterior = p->siguiente = NULL;
        principio = p;
        fin = p;
        return(1);
    }
    if(como == HDER){
        p->anterior = donde;
        p->siguiente = donde->siguiente;
        donde->siguiente = p;
        if(p->siguiente == NULL){
            fin = p;
        }
        else{
            (p->siguiente)->anterior = p;
        }
    }
    else{
        p->siguiente = donde;
        p->anterior = donde->anterior;
        donde -> anterior = p;
        if(p->anterior == NULL){
            principio = p;
        }
        else{
            (p->anterior)->siguiente = p;
        }
    }
    return(1);
}
/***************************************************************************************************************************************************/

/*
    Esta función imprime en pantalla la información del árbol
*/
void arbol::pintar(){
    std::string padre = "";
    std::string hizq = "";
    std::string hder = "";
    std::string valor = "";
    stringstream ss;
    nodo *p;
    p = principio;


    while(p){
        if(raiz == NULL){
        valor = "Arbol vacío";
        }
        else{
            ss << p->valor;
            valor = ss.str();
        }
        ss.str("");

        if(p->padre == NULL){
            padre = "null";
        }
        else{
            ss << p->padre->valor;
            padre = ss.str();
        }
        ss.str("");

        if(p->hizq == NULL){
            hizq = "null";
        }
        else{
            ss << p->hizq->valor;
            hizq = ss.str();
        }
        ss.str("");

        if(p->hder == NULL){
            hder = "null";
        }
        else{
            ss << p->hder->valor;
            hder = ss.str();
        }
        ss.str("");

        cout << "NODO: " << valor << endl << "PADRE: " << padre << endl
             << "HIJO IZQU: " << hizq << endl << "HIJO DER: " << hder << endl << endl;
        p = p->siguiente;
    }
}
/***************************************************************************************************************************************************/

/*
    Esta función intercambia dos nodos dentro del árbol.

    PARÁMETROS
    p: la dirección del primer nodo
    q: la dirección del segundo nodo
*/
void arbol::intercambiar(nodo *p, nodo *q){
    nodo *r;

    //Caso en el que q está arriba
    if(p->padre == q){ //Caso en el que q está arriba
        if(q->hder == p){ //p cuelga como hijo derecho
            intercambiarVecinos(p, q);

            p->hder = q;
            q->padre = p;
        }
        else{ //p cuelga como hijo izquierdo
            intercambiarVecinos(p, q);

            p->hizq = q;
            q->padre = p;
        }

        //Se conectan los padres
        if(q->padre == NULL) raiz = q;
        else{
            if(q->padre->hder == q) q->padre->hder = q;
            else q->padre->hizq = q;
        }

        if(p->padre == NULL) raiz = p;
        else{
            if(p->padre->hder == q) p->padre->hder = p;
            else p->padre->hizq = p;
        }
    }
    //Caso en el que p está arriba
    else if(q->padre == p){
        if(p->hder == q){ //q cuelga como hijo derecho
            intercambiarVecinos(p, q);

            //Arreglas a mano los punteros en conflicto
            q->hder = p;
            p->padre = q;
        }
        else{ //q cuelga como hijo izquierdo
            intercambiarVecinos(p, q);

            q->hizq = p;
            p->padre = q;
        }
        //Se conectan los padres
        if(q->padre == NULL) raiz = q;
        else{
            if(q->padre->hder == p) q->padre->hder = q;
            else q->padre->hizq = q;
        }

        if(p->padre == NULL) raiz = p;
        else{
            if(p->padre->hder == p) p->padre->hder = p;
            else p->padre->hizq = p;
        }
    }
    //CASO GENERAL
    else{

        intercambiarVecinos(p, q);

        //Se conectan los padres
        if(q->padre == NULL) raiz = q;
        else{
            if(q->padre->hder == p) q->padre->hder = q; /********/ //DUDA!!!!!
            else q->padre->hizq = q;
        }

        if(p->padre == NULL) raiz = p;
        else{
            if(p->padre->hder == q) p->padre->hder = p;
            else p->padre->hizq = p;
        }
    }

    //SE ARREGLAN LOS VECINOS

    //Se conectan los hijoz.
    if(q -> hizq != NULL) q->hizq->padre = q;
    if(q->hder != NULL) q->hder->padre = q;

    if(p->hizq != NULL) p->hizq ->padre = p;
    if(p->hder != NULL) p->hder->padre = p;
}
/*********************************************************************************************************/

/*
    Esta función borra un nodo del árbol

    PARÁMETROS
    a: el número del nodo a borrar

    Regresa un 1 si se pudo borrar el número; en caso contrario, regresa un 0.
*/
int arbol::borrar(int a){
    nodo *p;
    buscar(a);

    if(encontrado == NO) return(0);

    if(como == RAIZ){
        p = raiz;
    }
    else if(como == HDER){
        p = donde->hder;
    }
    else{
        p = donde->hizq;
    }

    //SI TIENE DOS HIJOS SE INVOCA A LA FUNCIÓN INTERCAMBIAR
    if(p->hder != NULL && p->hizq != NULL){
        //Si queremos borrar la raiz y no hay ningún número menor que ella, entonces lo intercambiamos por el siguiente
        if(p->anterior == NULL){
            intercambiar(p, p->siguiente);
            //Se ajustan las variables 'como' y 'donde'
            donde = p->padre;
            if(p->padre->hizq == p) como = HIZQ;
            else como = HDER;
        }

        else{
            //Si sí existe algún anterior, entonces se intercambia por ese
            intercambiar(p, p->anterior);
            //Se ajustan las variables 'como' y 'donde'
            donde = p->padre;
            if(p->padre->hizq == p) como = HIZQ;
            else como = HDER;
        }

    }

    //SE BORRA EL NODO CON BORRAR 1.
    borrar1(p);
    return(1);
}
/*********************************************************************************************************/

/*
    Esta función borra un nodo que tiene 0 o 1 hijo.

    PARÁMETROS
    p1: la dirección del nodo a borrar
*/
void arbol::borrar1(nodo *p1){
    nodo *p = p1;

    //EL NODO SE DESCONECTA DEL ÁRBOL
    if(p->hder == NULL && p->hizq == NULL){ //CASO DE NODO SIN HIJOS
        //¿Caso de ser raiz?
        if(como == RAIZ){
            raiz = NULL;
        }

        //SE VERIFICA SI CUELGA COMO HIJO IZQUIERDO O DERECHO
        else if(como == HDER){
            donde->hder = NULL;
        }
        else{
            donde->hizq = NULL;
        }
    }
    else if(p->hder != NULL){
        //¿Checamos caso raiz?
        if(como == RAIZ){
            raiz = (p->hder);
            (p->hder)->padre = NULL;
        }
        else if(como == HDER){
            (donde->hder) = (p->hder);
            (p->hder)->padre = donde;
        }
        else{
            (donde->hizq)=p->hder;
            (p->hder)->padre = donde;
        }
    }
    else{
        //¿Checamos caso raiz?
        if(como == RAIZ){
            raiz = (p->hizq);
            (p->hizq)->padre = NULL;
        }
        else if(como == HDER){
            (donde->hder) = p->hizq;
            (p->hizq)->padre = donde;
        }
        else{
            (donde->hizq) = p->hizq;
            (p->hizq)->padre = donde;
        }
    }

    //EL NODO SE DESCONECTA DE LA RAIZ
    if(p == principio){
        if(principio == fin){
            principio = fin = NULL;
        }
        else{
            principio = p->siguiente;
            (p->siguiente)->anterior = NULL;
        }

    }
    else if(p == fin){
        fin = p->anterior;
        (p->anterior)->siguiente = NULL;

    }
    else{
        (p->anterior)->siguiente = p->siguiente;
        (p->siguiente)->anterior = p->anterior;
    }

    //Se borra el nodo
    delete p;
}
/*********************************************************************************************************/

/*
    Esta función intercambia los vecinos del árbol (padres e hijos) entre dos nodos

    PARÁMETROS:
    p1: la dirección del primer nodo
    q1: la dirección del segundo nodo
*/
void arbol::intercambiarVecinos(nodo *p1, nodo *q1){
    nodo *p, *q, *r; //Copias
    p = p1; q = q1;

    //Intercambias los padres
    r = p->padre;
    p->padre = q->padre;
    q->padre = r;

    //Intercambias los hijos derechos
    r = p->hder;
    p->hder = q->hder;
    q->hder = r;

    //Intercambias los hijos izquierdos
    r = p->hizq;
    p->hizq = q->hizq;
    q->hizq = r;
}
#endif // ARBOLESBIN_H_INCLUDED
