/*
    Nombre: monton.h
    Autor: Pedro Andr�s Hern�ndez Amador.
    Fecha: mayo del 2019

    Descripci�n: Archivo de cabecera que contiene todas las funciones, clases y estructuras que gestionan el funcionamiento
                 de un mont�n (Min Heap).
*/

#ifndef MONTON_H_INCLUDED
#define MONTON_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
    Esta estructura representa un nodo del �rbol.

    ATRIBUTOS
    los punteros: padre, hder, hizq son para conectar los nodos en el �rbol
    los punteros: anterior, siguiente son para conectar los nodos en la lista doble
    la variable valor es la que almacena el valor del nodo.
*/
struct nodo{
    nodo *padre, *hder, *hizq, *anterior, *siguiente;
    int valor;
};
/*******************************************************************************************************************************/

/*
    Esta clase representa a un mont�n (MIN HEAP). Esta estructura de datos es un �rbol binario casi completo y tiene la caracter�stica de que
    cada nodo padre es menor a cualquiera de sus dos hijos

    ATRIBUTOS:
    donde: Padre del nodo en donde se agregar�/borrar� un hijo.
    raiz: raiz del �rbol
    principio: principio de la lista ordenada. Coincide con la raiz.
    fin: �ltimo elemento de la lista ordenada.
    como: indica c�mo est� colgado un nodo en el �rbol

    FUNCIONES:
    monton(): constructor
    ~monton(): destructor
    agregar(int a): agrega un nodo al �rbol
    sacar(): saca la ra�z del �rbol
    pintar(): imprime en pantalla el �rbol
    subir(): Intercambia un nodo con su padre mientras el padre sea mayor
    bajar(): intercambia un nodo con alguno de sus hijos hasta que los dos hijos de �ste sean mayores que �l.
    intercambiar(nodo *p, nodo *q): intercambia dos nodos del �rbol
    intercambiarVecinos(nodo *p1, nodo *q1): intercambia los punteros (vecinos) de dos nodos en el �rbol
*/
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
    void intercambiarVecinos(nodo *p1, nodo *q1);
};
/*******************************************************************************************************************************/

/*
    Esta funci�n es el constructor de la clase monton.
*/
monton::monton(){
    raiz = principio = fin = donde = NULL;
    como = 999;
}
/*******************************************************************************************************************************/

/*
    Esta funci�n agrega un n�mero al mont�n.

    PAR�METROS
    a: el n�mero a agregar.

    Regresa un 1 si se pudo agregar el n�mero.
*/
int monton::agregar(int a){
    //Se crea un nuevo nodo y se inicializan todos sus atributos (se agrega a al valor del nodo).
    nodo *p;
    p = new nodo;
    p->valor = a;
    p->hizq = p->hder = p->padre = p->anterior = p->siguiente = NULL;

    /*
        Si la raiz es NULL, entonces p es el primer elemento en entrar al heap, por ello todos los apuntadores caen
        sobre �l; adem�s 'como' es igual HIZQ porque el siguiente elemento en entrar al mont�n se agregar� como hijo
        izquierdo.
    */
    if(raiz == NULL){
        raiz = principio = fin = donde = p;
        como = HIZQ;
        return(1);
    }
    /*
        Si 'como' = HIZQ, entonces p se cuelga como hijo izquierdo del 'donde'; adem�s, el 'donde' se convierte en el padre de p.
        Finalmente, 'como' ahora ser� HDER porque esta variable alterna cada vez entre HIZQ y HDER
    */
    else if(como == HIZQ){
        donde->hizq = p;
        p->padre = donde;
        como = HDER;
    }
    /*
        si 'como' = HDER, entonces p se cuelga como hijo derecho del 'donde'; adem�s, el 'donde' se convierte en el padre de p.
        'como' se convierte en HDER porque 'como' siempre est� alternando y, como ya se acab� el espacio en dicho nodo padre, entonces
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
/*******************************************************************************************************************************/
/*
    Esta funci�n sube un nodo hasta que el padre de �ste sea menor que �l

    PAR�METROS
    p: direcci�n del nodo a subir
*/
void monton::subir(nodo *p){
    while( p->padre != NULL && p->valor < (p->padre->valor) ){
        intercambiar(p, p->padre);
    }
}
/*******************************************************************************************************************************/

/*
    Esta funci�n intercambia dos nodos dentro del mont�n y dentro de la lista ordenada.

    PAR�METROS
    p: la direcci�n del primer nodo
    q: la direcci�n del segundo nodo
*/
void monton::intercambiar(nodo *p, nodo *q){
    nodo *r;

    //Caso en el que q est� arriba
    if(p->padre == q){ //Caso en el que q est� arriba
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
    //Caso en el que p est� arriba
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
/*******************************************************************************************************************************/

/*
    Esta funci�n imprime en pantalla la informaci�n del �rbol
*/
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
        valor = "Arbol vac�o";
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
/*******************************************************************************************************************************/

/*
    Esta funci�n es el destructor de la clase mont�n
*/
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
/*******************************************************************************************************************************/

/*
    Esta funci�n intercambia un nodo con alguno de sus hijos mientras �ste sea mayor que ellos.

    PAR�METROS
    p: la direcci�n del nodo a bajar
*/
void monton::bajar(nodo *p){

    nodo *q;
    //VAS A BAJAR MIENTRAS TENGAS HIJOS, SI NO TIENE, ENTONCES NO TENDR� NODO CON EL CU�L INTERCAMBIARSE
    while(p->hizq != NULL || p->hder != NULL){

        if (p->hder != NULL && p->hizq == NULL) q = p->hder; //Si el hijo derecho existe y el izquierdo no, entonces se toma el hijo derecho.
        else if(p->hder == NULL && p->hizq != NULL) q = p->hizq; //Si el hijo derecho no existe y el izquierdo s�, entonces se toma el hijo izquierdo.
        else{  //CASO EN EL QUE LOS DOS HIJOS EXISTEN

            if(p->hder->valor < p->hizq->valor) q = p->hder; //Si el hder es menor al hizq, entonces se toma como candidato al hder.
            else q = p->hizq; //Si el hizq es menor al hder, entonces se toma como candidato al hizq.

        }
        //AHORA SE DECIDE SI SE BAJA EL NODO O NO
        if(p->valor < q->valor) return; //Si el valor de p ya es menor que el candidato, entonces significa que ya est� todo acomodado y se acaba el proceso.
        else intercambiar(p, q); //Si el valor de p sigue siendo mayor que el candidato (q), entonces se intercambia.

    }
}
/*******************************************************************************************************************************/

/*
    Esta funci�n saca a la ra�z del �rbol, es decir, el elemento m�s peque�o del heap.

    Regresa el valor de la ra�z.
*/
int monton::sacar(){

    nodo *p;
    int valor;

    //CASO CUANDO EL MONT�N EST� VAC�O, ENTONCES SE REGRESA UN VALOR 'VACIO'
    if(raiz == NULL) return(999);

    //CASO CUANDO EL MONT�N �NICAMENTE CUENTA CON UN ELEMENTO
    if(principio == fin){

        p = principio; //te pones en el principio
        valor = p->valor; //Guardas el valor del nodo

        raiz = donde = NULL; //Desconectas del �rbol

        principio = fin = NULL; //Desconectas de la lista doble

        delete(p); //Eliminas el nodo
        return(valor); //Regresas el valor del nodo.

    }
    else{ //CASO CUANDO EL MONT�N TIENE M�S DE UN ELEMENTO.

        valor = raiz->valor; //Como se saca de la ra�z, entonces guardas el valor de �sta para regresarlo cuando todo el proceso acabe.
        intercambiar(principio, fin); //Intercambias el principio por el fin.
        p = fin; //Te pones en el fin para borrarlo

        //DESCONECTAS A P (fin) DEL �RBOL

        //Haces NULL el lado del padre en el que p est� conectado y reajustas las variables 'como' y 'donde'
        if(p->padre->hizq == p){
            p->padre->hizq = NULL;
            como = HIZQ;
            donde = p->padre;
        }
        else{
            p->padre->hder = NULL;
            como = HDER;
            donde = p->padre;
        }

        //DESCONECTAS A P (fin) DE LA LISTA DOBLE
        //Conviertes al pen�ltimo en el 'fin'
        p->anterior->siguiente = NULL;
        fin = p->anterior;

        delete(p); //Borras el nodo

        //COMIENZAS A BAJAR LA RA�Z (principio) PARA AJUSTAR EL MONT�N
        p = principio; //Te pones en el principio / raiz
        bajar(p); //Bajas este nodo hasta donde corresponda
        return(valor); //Regresas el valor que ten�a el nodo que sacaste.
    }

}
/*******************************************************************************************************************************/

/*
    Esta funci�n intercambia los vecinos del �rbol (padres e hijos) entre dos nodos

    PAR�METROS:
    p1: la direcci�n del primer nodo
    q1: la direcci�n del segundo nodo
*/
void monton::intercambiarVecinos(nodo *p1, nodo *q1){
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
#endif // MONTON_H_INCLUDED
