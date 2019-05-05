#ifndef SISTEMA_EXPERTO_H_INCLUDED
#define SISTEMA_EXPERTO_H_INCLUDED

#define VACIO 99999
#include <iostream>

using namespace::std;

struct caja2;

struct caja1{
    int numNodo;
    caja2 *direccionNodo;
    int cambiaValor;
    caja1 * siguiente;
};
/**************************************************************************************************************************************************************************************************/

class lista_arcos{
    caja1 *principio, *anterior, *lugarAgregado;
    int encontrado, donde;
    enum encontrado{SI, NO};
    enum donde{PRINCIPIO, ENMEDIO, FINAL};

public:
    lista_arcos();
    void iniciar();

    ~lista_arcos();
    void terminar();

    void buscar(int a);
    int agregar(int numNodo, int cambiaValor);
    void pintar();
    caja1 *lugar_agregado();
    caja1 *Principio();
};

struct caja2{
    int numNodo;
    int bandera;
    int cuantos;
    int totales;
    int conectivo;
    int valorVerdad;
    caja2 *siguiente;
    lista_arcos salientes;
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

lista_arcos::lista_arcos(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_arcos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

lista_arcos::~lista_arcos(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_arcos::terminar(){
    caja1 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_arcos::buscar(int a){
    caja1 *p; //Puntero tipo caja que recorrerá la estructura.

    //Si la estructura está vacía entonces se indica que el dato no se encontró y que la lista está vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    //Si la lista no está vacía, entonces se comenzará a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p -> numNodo == a){
            encontrado = SI;
            lugarAgregado = p;
            if(p == principio){ //Si se encuentra al principio, entonces donde = PRINCIPIO.
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //Si la siguiente dirección es NULL, entonces significa que estamos en el final de la lista.
                donde = FINAL;
             }
             else{ //Si no estamos al principio ni al final de la lista ordenada, entonces encontramos el número enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
        /*
        Como estamos ordenando números de menor a mayor, entonces si encontramos algún número menor a 'a', simplemente seguimos recorriendo
        la estructura.
        */
        else if(p -> numNodo < a){
            encontrado = NO; //Se indica que no se ha encontrado aún.
            anterior = p; //El puntero '*anterior' toma el valor de la dirección en donde nos encontramos.
            p = p -> siguiente; //Finalmente p se pone sobre la siguiente caja de la lista ordenada.
        }
        /*
        Como estamos ordenando números de menor a mayor, entonces, si encontramos algún número mayor a 'a', significa que nuestro nuevo
        valor debe agregarse una posición antes de este número mayor con el que nos encontramos.
        */
        else{
            encontrado = NO; //Se indica que 'a' no ha sido encontrado.
            if(principio == p){ //Si el primer elemento que checamos resultó ser mayor, entonces significa que 'a' debe agregarse al principio.
                donde = PRINCIPIO;
            }
            else{ //Si no lo encontramos al principio, entonces forzosamente debe de agregarse en algún lugar enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
    }
    /*
    Si el ciclo se acaba y se recorre toda la lista sin encontrar ningún número mayor, entonces significa que el número que queremos
    encontrar es mayor a todos los que existen dentro de la lista ordenada; por lo tanto, no ha sido encontrado y debe agregarse al final.
    */
    encontrado = NO;
    donde = FINAL;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int lista_arcos::agregar(int nodo, int cambiaValor){
    caja1 *p; //Puntero tipo caja que nos servirá para agregar el valor a la estructura.
    buscar(nodo); //Se busca el número que queremos introducir.

    //Como no se consideran repeticiones, si el número se encontró, se regresa un cero porque no volverá a ser introducido a la estructura.
    if(encontrado == SI) return (0);

    //Si no se encontró, entonces se procede a agregar al número 'a'.
    p = new caja1; //Se crea una nueva caja.
    p->numNodo = nodo; //Se introduce el valor 'a' a la caja.
    p->cambiaValor = cambiaValor;
    lugarAgregado = p;

    /*
    Si la lista ordenada está vacia, entonces el puntero '*siguiente' de la caja será NULL (porque después de esta cajita no existirá
    otra) y el puntero '*principio' tomará la dirección de esta caja que hemos agregado.
    */
    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    /*
    Si se debe agregar al principio, entonces el puntero '*siguiente' de la caja apuntará hacia el valor que, hasta el momento,
    estaba al principio de la estructura; como hemos agregadoa un valor antes del primer elemento de la lista, entonces el puntero
    '*principio' se recorre hacia atrás y tomará la dirección del elemento que recién hemos agregado.
    */
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    /*
    Si debemos agregar al final, entonces el puntero '*siguiente' de nuestra caja será NULL (pues no existirá nada después). En este
    caso, el puntero '*anterior' se encontrará sobre el último elemento de la lista hasta este momento; entonces, el puntero
    'anterio -> siguiente' tomara el valor de p porque ahora '*p' será la última cajita de la estructura.
    */
    else if(donde == FINAL){
        p -> siguiente = NULL;
        anterior -> siguiente = p;
    }
    /*
    Si no se agregará al principio ni al final, entonces se agregará enmedio; para esto los puntero
    se "puentean" de la siguiente manera:
    */
    else{
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }
    return (1); //Se regresa un 1 porque el valor pudo ser agregado.
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

caja1* lista_arcos::lugar_agregado(){
    return(lugarAgregado);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

caja1 *lista_arcos::Principio(){
    return (principio);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void lista_arcos::pintar(){
    caja1 *p; p = principio; //Se crea un puntero tipo caja y se sitúa al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
        cout << "Nodo: " << p->direccionNodo->numNodo << " ; Cambio: " << p->cambiaValor << endl;
        p = p -> siguiente;
    }
    cout << "\b\b ";
}
/**************************************************************************************************************************************************************************************************/


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

struct caja3{
    caja2 *direccion;
};

/**************************************************************************************************************************************************************************************************/

class lista_nodos{
    caja2 *principio, *anterior, *lugarAgregado;
    int encontrado, donde;
    enum encontrado {SI, NO};
    enum donde{PRINCIPIO, ENMEDIO, FINAL};
    enum tipo{PREGUNTA, CONCLUSION, CLAUSULA};
    enum conectivo{AND, OR};

public:
    lista_nodos();
    ~lista_nodos();
    void buscar(int a);
    int agregar(int nodo[8]);
    void pintar();
    void iniciar();
    void terminar();
    caja2* lugar_agregado();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

lista_nodos::lista_nodos(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_nodos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_nodos::terminar(){
    caja2 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }

    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

lista_nodos::~lista_nodos(){
    caja2 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }

    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_nodos::buscar(int a){
    caja2 *p; //Puntero tipo caja que recorrerá la estructura.

    //Si la estructura está vacía entonces se indica que el dato no se encontró y que la lista está vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    //Si la lista no está vacía, entonces se comenzará a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p -> numNodo == a){
            encontrado = SI;
            lugarAgregado = p;
            if(p == principio){ //Si se encuentra al principio, entonces donde = PRINCIPIO.
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //Si la siguiente dirección es NULL, entonces significa que estamos en el final de la lista.
                donde = FINAL;
             }
             else{ //Si no estamos al principio ni al final de la lista ordenada, entonces encontramos el número enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
        /*
        Como estamos ordenando números de menor a mayor, entonces si encontramos algún número menor a 'a', simplemente seguimos recorriendo
        la estructura.
        */
        else if(p -> numNodo < a){
            encontrado = NO; //Se indica que no se ha encontrado aún.
            anterior = p; //El puntero '*anterior' toma el valor de la dirección en donde nos encontramos.
            p = p -> siguiente; //Finalmente p se pone sobre la siguiente caja de la lista ordenada.
        }
        /*
        Como estamos ordenando números de menor a mayor, entonces, si encontramos algún número mayor a 'a', significa que nuestro nuevo
        valor debe agregarse una posición antes de este número mayor con el que nos encontramos.
        */
        else{
            encontrado = NO; //Se indica que 'a' no ha sido encontrado.
            if(principio == p){ //Si el primer elemento que checamos resultó ser mayor, entonces significa que 'a' debe agregarse al principio.
                donde = PRINCIPIO;
            }
            else{ //Si no lo encontramos al principio, entonces forzosamente debe de agregarse en algún lugar enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
    }
    /*
    Si el ciclo se acaba y se recorre toda la lista sin encontrar ningún número mayor, entonces significa que el número que queremos
    encontrar es mayor a todos los que existen dentro de la lista ordenada; por lo tanto, no ha sido encontrado y debe agregarse al final.
    */
    encontrado = NO;
    donde = FINAL;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int lista_nodos::agregar(int nodo[7]){
    caja2 *p; //Puntero tipo caja que nos servirá para agregar el valor a la estructura.
    buscar( nodo[0] ); //Se busca el número que queremos introducir.

    //Como no se consideran repeticiones, si el número se encontró, se regresa un cero porque no volverá a ser introducido a la estructura.
    if(encontrado == SI) return (0);

    //Si no se encontró, entonces se procede a agregar al número 'a'.
    p = new caja2; //Se crea una nueva caja.
    //Se introduce el valor 'a' a la caja.
    p->numNodo = nodo[0];
    p->bandera = nodo[1];
    p->cuantos = nodo[2];
    p->totales = nodo[3];
    p->conectivo = nodo[4];
    p->valorVerdad = nodo[5];
    p->siguiente = NULL;
    lugarAgregado = p;

    /*
    Si la lista ordenada está vacia, entonces el puntero '*siguiente' de la caja será NULL (porque después de esta cajita no existirá
    otra) y el puntero '*principio' tomará la dirección de esta caja que hemos agregado.
    */
    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    /*
    Si se debe agregar al principio, entonces el puntero '*siguiente' de la caja apuntará hacia el valor que, hasta el momento,
    estaba al principio de la estructura; como hemos agregadoa un valor antes del primer elemento de la lista, entonces el puntero
    '*principio' se recorre hacia atrás y tomará la dirección del elemento que recién hemos agregado.
    */
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    /*
    Si debemos agregar al final, entonces el puntero '*siguiente' de nuestra caja será NULL (pues no existirá nada después). En este
    caso, el puntero '*anterior' se encontrará sobre el último elemento de la lista hasta este momento; entonces, el puntero
    'anterio -> siguiente' tomara el valor de p porque ahora '*p' será la última cajita de la estructura.
    */
    else if(donde == FINAL){
        p -> siguiente = NULL;
        anterior -> siguiente = p;
    }
    /*
    Si no se agregará al principio ni al final, entonces se agregará enmedio; para esto los puntero
    se "puentean" de la siguiente manera:
    */
    else{
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }
    return (1); //Se regresa un 1 porque el valor pudo ser agregado.
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_nodos::pintar(){

    caja2 *p; p = principio; //Se crea un puntero tipo caja y se sitúa al principio de la lista ordenada.
    while(p){
        cout << "NODO: " << endl;
        cout << p->numNodo << " " << p->bandera << " " << p->cuantos << " " << p->totales << " " << p->conectivo << " " << p->valorVerdad << endl;
        cout << "SALIENTES: " << endl;
        (p->salientes).pintar();
        cout << "-----------------------------------------------------------------------------" << endl << endl;
        p = p->siguiente;
    }

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

caja2* lista_nodos::lugar_agregado(){
    return(lugarAgregado);
}
/**************************************************************************************************************************************************************************************************/

class SE{
    lista_nodos A;

public:
    SE();
    ~SE();
    void agregar_arco(int nodo1[7], int nodo2[7]);
    void pintar();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

SE::SE(){
    A.iniciar();
}

SE::~SE(){
    A.terminar();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void SE::agregar_arco(int nodo1[7], int nodo2[7]){
    caja1 *p;
    caja2 *q, *q2;
    A.agregar(nodo1);
    q = q2 = A.lugar_agregado();
    (q -> salientes).agregar(nodo2[0], nodo2[6]);
    p = (q->salientes).lugar_agregado();

    A.agregar(nodo2);
    q = A.lugar_agregado();
    (p -> direccionNodo) = q;

}

void SE::pintar(){
    A.pintar();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // SISTEMA_EXPERTO_H_INCLUDED
