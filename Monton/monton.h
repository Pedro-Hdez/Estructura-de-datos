#ifndef MONTON_H_INCLUDED
#define MONTON_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct nodo{
    nodo *padre, *hder, *hizq, *anterior, *siguiente;
    int valor;
};
/*******************************************************************************************************************************/

class monton{
    nodo *raiz, *principio, *fin, *donde;
    int como;
    enum como {HIZQ, HDER};

public:
    monton();
    ~monton();
    int agregar(int a);
    int sacar();
    void pintar();
    void subir(nodo *p);
    void bajar(nodo *p);
    void intercambiar(nodo *p, nodo *q);
};
//-----------------------------------------------------------------------------------------------------------------------------------

monton::monton(){
    raiz = principio = fin = donde = NULL;
    como = 999;
}
//-----------------------------------------------------------------------------------------------------------------------------------

int monton::agregar(int a){
    //Se crea un nuevo nodo y se inicializan todos sus atributos (se agrega a al valor del nodo).
    nodo *p;
    p = new nodo;
    p->valor = a;
    p->hizq = p->hder = p->padre = p->anterior = p->siguiente = NULL;

    /*
        Si la raiz es NULL, entonces p es el primer elemento en entrar al heap, por ello todos los apuntadores caen
        sobre él; además 'como' es igual HIZQ porque el siguiente elemento en entrar al montón se agregará como hijo
        izquierdo.
    */
    if(raiz == NULL){
        raiz = principio = fin = donde = p;
        como = HIZQ;
        return(1);
    }
    /*
        Si 'como' = HIZQ, entonces p se cuelga como hijo izquierdo del 'donde'; además, el 'donde' se convierte en el padre de p.
        Finalmente, 'como' ahora será HDER porque esta variable alterna cada vez entre HIZQ y HDER
    */
    else if(como == HIZQ){
        donde->hizq = p;
        p->padre = donde;
        como = HDER;
    }
    /*
        si 'como' = HDER, entonces p se cuelga como hijo derecho del 'donde'; además, el 'donde' se convierte en el padre de p.
        'como' se convierte en HDER porque 'como' siempre está alternando y, como ya se acabó el espacio en dicho nodo padre, entonces
        el 'donde' = al siguiente nodo de la lista.
    */
    else{
        donde->hder = p;
        p->padre = donde;
        como = HIZQ;
        donde = donde -> siguiente; /*POSIBLE ERROR!*/
    }

    //Se agrega el nodo 'p' al final de la lista doble
    p->anterior = fin;
    fin->siguiente = p;
    p->siguiente = NULL;
    fin = p;

    subir(p); // SE INTERCAMBIA P EN CASO DE SER NECESARIO
    return(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------

void monton::subir(nodo *p){
    while( p->padre != NULL && p->valor < (p->padre->valor) ){
        intercambiar(p, p->padre);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void monton::intercambiar(nodo *p, nodo *q){
    nodo *r;

    //Caso en el que q está arriba
    if(p->padre == q){ //Caso en el que q está arriba
        if(q->hder == p){ //p cuelga como hijo derecho
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

            p->hder = q;
            q->padre = p;
/*********************************************************************************************************/
        }
        else{ //p cuelga como hijo izquierdo
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
            //Arreglas a mano los punteros en conflicto
            q->hder = p;
            p->padre = q;
        }
        else{ //q cuelga como hijo izquierdo
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

    //Se conectan los padres
   /* if(q->padre == NULL) raiz = q;
    else{
        if(q->padre->hder == p) q->padre->hder = q;
        else q->padre->hizq = q;
    }

    if(p->padre == NULL) raiz = p;
    else{
        if(p->padre->hder == q) p->padre->hder = p;
        else p->padre->hizq = p;
    }*/

    //Se conectan los hijoz.
    if(q -> hizq != NULL) q->hizq->padre = q;
    if(q->hder != NULL) q->hder->padre = q;

    if(p->hizq != NULL) p->hizq ->padre = p;
    if(p->hder != NULL) p->hder->padre = p;

    //Se arreglan los vecinos en la lista
    if(p->anterior == q){
        r = q->anterior;
        p->anterior = r;
        q->anterior = p;

        r = p->siguiente;
        q->siguiente = r;
        p->siguiente = q;

        if(p->anterior == NULL){
            principio = p;
        }
        else{
            p->anterior->siguiente = p;
        }
        if(q->siguiente == NULL){
            fin = q;
        }
        else{
            q->siguiente->anterior = q;
        }
    }
    else if(q->anterior == p){
        r = p->anterior;
        q->anterior = r;
        p->anterior = q;

        r = q->siguiente;
        p->siguiente = r;
        q->siguiente = p;

        if(q->anterior == NULL){
            principio = q;
        }
        else{
            q->anterior->siguiente = q;
        }
        if(p->siguiente == NULL){
            fin = p;
        }
        else{
            p->siguiente->anterior = p;
        }
    }
    else{ //CASO GENERAL
        r = p->anterior;
        p->anterior = q->anterior;
        q->anterior = r;

        r = p->siguiente;
        p->siguiente = q->siguiente;
        q->siguiente = r;

        if(p->anterior == NULL){
            principio = p;
        }
        else{
            p->anterior->siguiente = p;
        }
        if(q->anterior == NULL){
            principio = q;
        }
        else{
            q->anterior->siguiente = q;
        }

        if(p->siguiente == NULL){
            fin = p;
        }
        else{
            p->siguiente->anterior = p;
        }
        if(q->siguiente == NULL){
            fin = q;
        }
        else{
            q->siguiente->anterior = q;
        }
    }

    if(donde == p){
        donde = q;
        return;
    }
    if(donde == q){
        donde = p;
        return;
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void monton::pintar(){
    std::string padre = "";
    std::string hizq = "";
    std::string hder = "";
    std::string valor = "";
    stringstream ss;
    nodo *p;

    p = principio;
    if(p == NULL){
        cout << "ARBOL VACIO";
        return;
    }

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

monton::~monton(){
    nodo *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    donde = raiz = principio = fin = NULL;
    como = 999;
    return;

}
//-----------------------------------------------------------------------------------------------------------------------------------
void monton::bajar(nodo *p){

    while( ( (p->hizq != NULL) && p->valor > p->hizq->valor) || ( (p->hder != NULL) && p->valor > p->hder->valor) ){
        if( (p->hizq->valor) < (p->hder->valor) ){
            intercambiar(p, p->hizq);
        }
        else{
            intercambiar(p,p->hder);
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------
int monton::sacar(){

    int valor;
    valor = raiz->valor;
    intercambiar(raiz, fin);
    //BORRAR EL ÚLTIMO ELEMENTO QUE AHORA ES EL MÁS CHICO DE TODOS
    //Desconectas el 'fin' del árbol
    if(fin->padre->hizq == fin) fin->padre->hizq = NULL;
    else fin->padre->hder = NULL;

    //Desconectas el 'fin' de la lista y lo eliminas
    fin = fin->anterior;
    delete(fin->siguiente);
    fin->siguiente = NULL;

    bajar(raiz);
    return(valor);

}
#endif // MONTON_H_INCLUDED
