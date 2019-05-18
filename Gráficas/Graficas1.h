#ifndef GRAFICAS_H_INCLUDED
#define GRAFICAS_H_INCLUDED

#include <iostream>
#define VACIO 99999

struct caja1{
    int numNodo;
    caja1 *siguiente;
};

/*********************************************************************************************************************************************************************************************/

class lista_arcos{
    caja1 *principio, *anterior, *lugarAgregado;
    int encontrado, donde, cuantos;
    enum encontrado{SI, NO};
    enum donde{PRINCIPIO, ENMEDIO, FINAL};

public:
    lista_arcos();
    ~lista_arcos();
    void buscar(int a);
    int agregar(int a);
    int borrar(int a);
    void pintar();
    caja1 *lugar_agregado();
    void iniciar();
    void terminar();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

lista_arcos::lista_arcos(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista_arcos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

int lista_arcos::agregar(int a){
    caja1 *p; //Puntero tipo caja que nos servirá para agregar el valor a la estructura.
    buscar(a); //Se busca el número que queremos introducir.

    //Como no se consideran repeticiones, si el número se encontró, se regresa un cero porque no volverá a ser introducido a la estructura.
    if(encontrado == SI) return (0);

    //Si no se encontró, entonces se procede a agregar al número 'a'.
    p = new caja1; //Se crea una nueva caja.
    p -> numNodo = a; //Se introduce el valor 'a' a la caja.
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

    cuantos ++; //Se incrementa el número de datos dentro de la estructura
    return (1); //Se regresa un 1 porque el valor pudo ser agregado.
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int lista_arcos::borrar(int a){
    caja1 *p; //Puntero tipo caja que nos ayudará a recorrer la lista.
    buscar(a); //Se busca el número.

    if(encontrado == NO) return (0); //Si no se encuentra, entonces no puede eliminarse y se regresa un 0.

    /*
    Si se encuentra al principio, entonces '*p' se posiciona sobre el puntero '*principio'; entonces, como el primer
    elemento se va a eliminar, el número siguiente pasará a ser el primero; por lo tanto principio = p -> siguiente.
    */
    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }
    /*
    Si se encuentra en medio, entonces utilizamos al puntero '*anterior' para poner a '*p' sobre el elemento que queremos
    eliminar; después, se "puentea" el apuntador '*siguiente' de la caja con dirección '*anterior'
    */
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }
    /*
    Si no se encontró al principio ni enmedio, entonces se encontró al final. Utilizamos el puntero '*anterior' para posicionarnos sobre
    el último elemento; después, 'anterior -> siguiente' será NULL, porque después del elemento '*anterior' ahora ya no habrá nada.
    */
    else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete(p); //Se elimina el dato deseado.
    cuantos--; //Se decrementa el número de datos dentro de la lista.
    return (1); //Se regresa un 1 porque sí pudimos eliminar el dato.
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista_arcos::pintar(){
    caja1 *p; p = principio; //Se crea un puntero tipo caja y se sitúa al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
        std::cout << p -> numNodo << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

caja1* lista_arcos::lugar_agregado(){
    return(lugarAgregado);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
    cuantos = 0;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
    cuantos = 0;
    return;
}

/*******************************************************************************************************************************************************************************************/

struct caja2{
    int numNodo;
    lista_arcos salientes, entrantes;
    caja2 *siguiente;
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class lista_nodos{
    caja2 *principio, *anterior, *lugarAgregado;
    int encontrado, donde, cuantos;
    enum encontrado {SI, NO};
    enum donde{PRINCIPIO, ENMEDIO, FINAL};

public:
    lista_nodos();
    ~lista_nodos();
    void buscar(int a);
    int agregar(int a);
    int borrar(int a);
    void pintar();
    void iniciar();
    void terminar();
    caja2* lugar_agregado();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

lista_nodos::lista_nodos(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista_nodos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int lista_nodos::agregar(int a){
    caja2 *p; //Puntero tipo caja que nos servirá para agregar el valor a la estructura.
    buscar(a); //Se busca el número que queremos introducir.

    //Como no se consideran repeticiones, si el número se encontró, se regresa un cero porque no volverá a ser introducido a la estructura.
    if(encontrado == SI) return (0);

    //Si no se encontró, entonces se procede a agregar al número 'a'.
    p = new caja2; //Se crea una nueva caja.
    p -> numNodo = a; //Se introduce el valor 'a' a la caja.
    (p -> salientes).iniciar();
    (p -> entrantes).iniciar();
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

    cuantos ++; //Se incrementa el número de datos dentro de la estructura
    return (1); //Se regresa un 1 porque el valor pudo ser agregado.
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int lista_nodos::borrar(int a){
    caja2 *p; //Puntero tipo caja que nos ayudará a recorrer la lista.
    buscar(a); //Se busca el número.

    if(encontrado == NO) return (0); //Si no se encuentra, entonces no puede eliminarse y se regresa un 0.

    /*
    Si se encuentra al principio, entonces '*p' se posiciona sobre el puntero '*principio'; entonces, como el primer
    elemento se va a eliminar, el número siguiente pasará a ser el primero; por lo tanto principio = p -> siguiente.
    */
    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }
    /*
    Si se encuentra en medio, entonces utilizamos al puntero '*anterior' para poner a '*p' sobre el elemento que queremos
    eliminar; después, se "puentea" el apuntador '*siguiente' de la caja con dirección '*anterior'
    */
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }
    /*
    Si no se encontró al principio ni enmedio, entonces se encontró al final. Utilizamos el puntero '*anterior' para posicionarnos sobre
    el último elemento; después, 'anterior -> siguiente' será NULL, porque después del elemento '*anterior' ahora ya no habrá nada.
    */
    else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete(p); //Se elimina el dato deseado.
    cuantos--; //Se decrementa el número de datos dentro de la lista.
    return (1); //Se regresa un 1 porque sí pudimos eliminar el dato.
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista_nodos::pintar(){
    caja2 *p; p = principio; //Se crea un puntero tipo caja y se sitúa al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
       std::cout << "NODO: " << p -> numNodo << std::endl;
        std::cout << "ENTRANTES: ";
        (p -> entrantes).pintar();
        std::cout << std::endl << "SALIENTES: ";
        (p -> salientes).pintar();
        std::cout << std::endl << "/****************************************************************/" << std::endl;
        p = p -> siguiente;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

caja2* lista_nodos::lugar_agregado(){
    return(lugarAgregado);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

lista_nodos::~lista_nodos(){
    caja2 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        (p -> entrantes).terminar();
        (p -> salientes).terminar();
        delete p;
    }

    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista_nodos::terminar(){
    caja2 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        (p -> entrantes).terminar();
        (p -> salientes).terminar();
        delete p;
    }

    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
    return;
}

/********************************************************************************************************************************************************************************************/

class grafica{
    lista_nodos A;
public:
    grafica();
    ~grafica();
    void agregar_arco(int a, int b);
    void pintar();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

grafica::grafica(){
    A.iniciar();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void grafica::agregar_arco(int a, int b){
    caja2 *p;
    A.agregar(a);
    p = A.lugar_agregado();
    (p -> salientes).agregar(b);
    A.agregar(b);
    p = A.lugar_agregado();
    (p -> entrantes).agregar(a);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void grafica::pintar(){
    A.pintar();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

grafica::~grafica(){
    A.terminar();
}

#endif // GRAFICAS_H_INCLUDED
