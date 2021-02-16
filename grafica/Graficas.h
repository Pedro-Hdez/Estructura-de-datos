/*
    Nombre: Graficas.h
    Autor: Pedro Andrés Hernández Amador.
    Fecha: mayo del 2019

    Descripción: Archivo de cabecera que contiene las clases involucradas
                 en el manejo de gráficas.
*/

#ifndef GRAFICAS_H_INCLUDED
#define GRAFICAS_H_INCLUDED

#include <iostream>
#define VACIO 99999

struct caja2;

/*
    Esta estructura representa a un nodo saliente de otro en la gráfica.
    numNodo: Valor del nodo.
    longitud: Longitud o peso del arco de ese saliente.
    *siguiente: Apuntador hacia el siguiente saliente del nodo original.
    *direccionNodo: Dirección del nodo al cuál hace referencia este saliente
*/
struct caja1{
    int numNodo;
    float longitud;
    caja1 *siguiente;
    caja2 *direccionNodo;
};
/*************************************************************************************************************************************************/

/*
    Esta clase representa a todos los salientes de algún nodo en la gráfica. Es una lista de struct caja1 ordenada por numNodo sin repetición.

    ATRIBUTOS
    *principio: Apuntador hacia el primer elemento de la lista.
    *anterior: Apuntador hacia el elemento anterior del cuál nos encontramos.
    *lugarAgregado: Apuntador hacia la dirección en donde agregamos ó encontramos un nodo saliente.
    encontrado: Variable que nos indica si algún nodo existe dentro de la lista.
    donde: Variable que nos indica en dónde debe agregarse un nodo en la lista.

    //FUNCIONES
    lista_arcos(): constructor de la clase.
    ~lista_arcos(): destructor de la clase.
    buscar(int a): función que busca un nodo en la lista.
    agregar(int a): agrega un nodo en la lista.
    pinitar(): imprime la lista ordenada (a los salientes de un nodo).
    *lugar_agregado(): regresa la dirección en donde fue agregado ó encontrado un nodo
    *principio(): regresa la dirección del primer nodo en la lista
    iniciar(): copia del constructor
    terminar(): copia del destructor


*/
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
    void pintar();
    caja1 *lugar_agregado();
    caja1 *Principio();
    void iniciar();
    void terminar();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct caja3;

/*
    Esta estructura representa un nodo en la gráfica. Es una lista ordenada por numNodo sin repetición.

    ATRIBUTOS:
    numNodo: número del nodo.
    bandera: Bandera que indica si el algoritmo de Dijkstra no ha tocado dicho nodo (0), si ya lo tocó (1) ó si el nodo ya cuenta con una ruta
             corta y se puede etiquetar como nodo definitivo (2).
    rutaCorta: Longitud de la ruta desde el nodo inicial hasta éste.
    *ancecesor: Nodo antecesor, es decir, el nodo anterior a éste en la ruta que traza el algoritmo de Dijkstra.
    *dirección: Dirección de este nodo en la Lista auxiliar de nodos etiquetados del algoritmo de Dijkstra.
    salientes: lista de nodos salientes.
    entrantes: lista de entrantes.
    *siguiente: nodo siguiente a éste en la lista de nodos de la gráfica.

*/
struct caja2{
    int numNodo;
    int bandera;
    float rutaCorta;
    caja2 *antecesor;
    caja3 *direccion;
    lista_arcos salientes, entrantes;
    caja2 *siguiente;
};
/*********************************************************************************************************************************************************************************************/

/*
    Esta función es el constructor de la clase lista_arcos
*/
lista_arcos::lista_arcos(){
    principio = anterior = lugarAgregado = NULL; //Todos los punteros se hacen NULL
    //Las variables toman su valor inicial.
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/*********************************************************************************************************************************************************************************************/

/*
    Esta función es una copia del constructor de la clase lista_arcos
*/
void lista_arcos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/*********************************************************************************************************************************************************************************************/

/*
    Esta función busca un nodo dentro de la lista de salientes de algún nodo.

    PARÁMETROS
    a: Número del nodo que queremos buscar
*/
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
/*********************************************************************************************************************************************************************************************/

/*
    Esta función agrega un nodo en la lista de salientes/entrantes de otro

    PARÁMETROS:
    a: Número del nodo que queremos agregar.
*/
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
/*********************************************************************************************************************************************************************************************/

/*
    Esta función imprime en pantalla todos los elementos de la lista (entrantes / salientes de algún nodo).
*/
void lista_arcos::pintar(){
    caja1 *p; p = principio; //Se crea un puntero tipo caja y se sitúa al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
        std::cout << p -> numNodo << "-" << p->direccionNodo->numNodo << " Longitud: " << p->longitud << " ; ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
/*********************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección en donde fue encontrado ó agregado un nodo saliente/entrante.
*/
caja1* lista_arcos::lugar_agregado(){
    return(lugarAgregado);
}
/*********************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección del primer elemento de la lista de salientes/entrantes.
*/
caja1 *lista_arcos::Principio(){
    return (principio);
}

/*********************************************************************************************************************************************************************************************/
/*
    Destructor de la clase lista_arcos
*/
lista_arcos::~lista_arcos(){
    caja1 *p;
    /*
        Te pones en el principio de la lista. Recorres el apuntador 'principio' hacia adelante y eliminar en principio anterior.
        El procedimiento se repite hasta que ya no existe ningún nodo en la lista.
    */
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }

    //Se resetean las variables.
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
    return;
}
/*********************************************************************************************************************************************************************************************/

/*
    Esta función es una copia del destructor de la clase lista_arcos
*/
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

/*
    Esta clase representa a todos los nodos de la gráfica. Es una lista de struct caja2 ordenada por numNodo sin repetición.

    ATRIBUTOS
    *principio: Apuntador hacia el primer elemento de la lista.
    *anterior: Apuntador hacia el elemento anterior del cuál nos encontramos.
    *lugarAgregado: Apuntador hacia la dirección en donde agregamos ó encontramos un nodo.
    encontrado: Variable que nos indica si algún nodo existe dentro de la lista.
    donde: Variable que nos indica en dónde debe agregarse un nodo en la lista.

    //FUNCIONES
    lista_nodoss(): constructor de la clase.
    ~lista_nodos(): destructor de la clase.
    buscar(int a): función que busca un nodo en la lista.
    agregar(int a): agrega un nodo en la lista.
    pinitar(): imprime la lista ordenada (a los salientes de un nodo).
    *lugar_agregado(): regresa la dirección en donde fue agregado ó encontrado un nodo
    iniciar(): copia del constructor
    terminar(): copia del destructor


*/
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
    void pintar();
    caja2* lugar_agregado();
    void iniciar();
    void terminar();
};
/********************************************************************************************************************************************************************************************/

/*
    Constructor de la clase lista_nodos
*/
lista_nodos::lista_nodos(){
    principio = anterior = lugarAgregado = NULL; //Todos los punteros se hacen NULL
    //Las varables toman su valor incial.
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función es una copia del constructor de la clase lista_nodos
*/
void lista_nodos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función busca un nodo dentro de la lista de nodos.

    PARÁMETROS
    a: Número del nodo que queremos buscar
*/
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
/********************************************************************************************************************************************************************************************/

/*
    Esta función agrega un nodo dentro de la lista de nodos.

    PARÁMETROS
    a: Número del nodo que queremos agregar.
*/
int lista_nodos::agregar(int a){
    caja2 *p; //Puntero tipo caja que nos servirá para agregar el valor a la estructura.
    buscar(a); //Se busca el número que queremos introducir.

    //Como no se consideran repeticiones, si el número se encontró, se regresa un cero porque no volverá a ser introducido a la estructura.
    if(encontrado == SI) return (0);

    //Si no se encontró, entonces se procede a agregar al número 'a'.
    p = new caja2; //Se crea una nueva caja.
    p -> numNodo = a; //Se introduce el valor 'a' a la caja.
    p->bandera = 0;
    p->rutaCorta = 0;
    p->antecesor = NULL;
    p->direccion = NULL;
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
/********************************************************************************************************************************************************************************************/

/*
    Esta función imprime en pantalla todos los elementos de la lista de nodos de la gráfica con sus salientes
    y entrantes.
*/
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
/********************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección en donde un nodo  fue agregado ó encontrado.
*/
caja2* lista_nodos::lugar_agregado(){
    return(lugarAgregado);
}
/********************************************************************************************************************************************************************************************/

/*
    Destructor de la clase lista_nodos
*/
lista_nodos::~lista_nodos(){
    caja2 *p;
    while(principio){ //Te pones en el principio.
        p = principio;
        principio = p -> siguiente; //Recorres el principio hacia adelante
        (p -> entrantes).terminar(); //Destruyes la lista_arcos de entrantrs
        (p -> salientes).terminar(); //Destruyes la lista_arcos de salientes
        delete p; //Destruyes el nodo
    }

    //Reseteas las variables
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
    return;
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función es una copia del destructor de la clase lista_nodos
*/
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

/*
    Esta estructura representa a un nodo procesado dentro de la lista de nodos etiquetados en el algoritmo de Dijkstra.

    ATRIBUTOS:
    *direccionNodo: Apuntador al nodo correspondiente dentro de la lista de nodos de la gráfica.
    longitud: Longitud o peso de la ruta desde el nodo origen hasta éste nodo.
    *siguiente: Apuntador hacia el siguiente elemento de la lista.
    *antes: Apuntador hacia el elemento anterior de la lista.
*/
struct caja3{
    caja2 *direccionNodo;
    float longitud;
    caja3 *siguiente, *antes;
};

/********************************************************************************************************************************************************************************************/

/*
    Esta clase representa a la lista de nodos etiquetados en el algoritmo de Dijkstra. Es una lista doble ordenada por el atributo
    longitud de la struct caja3.

    ATRIBUTOS:
    *anterior: apuntador hacia el nodo anterior del cuál nos encontramos en la lista doble.
    *principio: apuntador hacia el primer elemento de la lista doble.
    *fin: apuntador hacia el último elemento de la lista doble.
    *lugarAgregado: apuntador hacia la dirección en donde fue agregado ó encontrado un nodo dentro de la lista doble
    encontrado: variable que indica si un nodo se encontró ó no dentro de la lista doble.
    donde: variable que indica en dónde se encontró o en dónde debe introducirse un nuevo nodo en la lista doble.

    FUNCIONES:
    lista(): constructor
    iniciar(): copia del constructor
    ~lista(): destructor
    terminar(): copia del destructor
    buscar(float a): busca un nodo dentro de la lista doble.
    agregar(caja2 *q, float a): introduce un nodo procesado a la lista doble.
    *sacar(): regresa la dirección del primer nodo de la lista doble y lo saca de ella.
    borrar(float a): borra un nodo dentro de la lista doble.
    ajustar(caja3 *p, float a): ajusta la lista doble en caso de que algún nodo etiquetado disminuya la longitud
                                de la ruta desde el inicio hasta él.
    *lugar_agregado(): regresa la dirección en donde se encontró ó agregó un nodo en la lista doble.
*/
class lista{
     private:
        caja3 *anterior, *principio, *fin, *lugarAgregado;
        int encontrado;
        int donde;
        enum encontrado{SI, NO};
        enum donde{PRINCIPIO, ENMEDIO, FINAL};

    public:
        lista();
        void iniciar();
        ~lista();
        void terminar();
        void buscar(float a);
        int agregar(caja2 *q, float a);
        caja2 * sacar();
        int borrar(float a);
        void pintar();
        void ajustar (caja3 *p, float a);
        caja3 *lugar_agregado();
};
/********************************************************************************************************************************************************************************************/

/*
    Constructor de la clase lista
*/
lista::lista(){
    anterior = principio = fin = lugarAgregado = NULL; //Todos los punteros NULL
    //donde y encontrado toman sus valores iniciales
    encontrado = NO;
    donde = VACIO;
}
/********************************************************************************************************************************************************************************************/

/*
    Copia del constructor de la clase lista
*/
void lista::iniciar(){
    anterior = principio = fin = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
/********************************************************************************************************************************************************************************************/


/*
    Esta función busca un nodo dentro de la lista de nodos etiquetados.

    PARÁMETROS
    a: longitud del nodo a buscar
*/
void lista::buscar(float a){
    caja3 *p; //Puntero tipo caja3 que recorrerá la estructura.

    //Si la estructura está vacía entonces se indica que el dato no se encontró y que la lista está vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        lugarAgregado = NULL;
        return;
    }

    //Si la lista no está vacía, entonces se comenzará a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p->longitud == a){
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
        else if(p->longitud < a){
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
/********************************************************************************************************************************************************************************************/

/*
    Esta función agrega un nodo etiquetado a la lista doble auxiliar.

    PARÁMETROS
    *q: dirección en la lista de nodos del nodo a agregar
    a: longitud de la ruta desde el inicio hasta dicho nodo

    Regresa un 1 si se pudo agregar; en caso contrario, regresa un cero.
*/
int lista::agregar(caja2 *q, float a){
    caja3 *p; //Puntero tipo caja3 donde guardaremos el valor a agregar.
    buscar(a); //Se busca 'a'.

    p = new caja3; //Se crea una nueva caja3.
    p -> direccionNodo = q;//Se introduce el valor de 'a' a la caja.
    p->longitud = a;

    /*
    Si la lista está vacía, entonces los dos punteros de la caja son NULL (porque no existe nada antes ni después de éste elemento).
    Este primer elemento también representará el principio y el fin de la lista, por eso principio = fin  = p.
    */

    if(donde == VACIO){
        p -> siguiente = NULL;
        p -> antes = NULL;
        principio = p;
        fin = p;
    }
    /*
    Si se debe agregar al principio, entonces '*siguiente' de la caja que agregaremos apuntará al elemento que antes era el principio;
    el '*anterior' de la cajita a agregar será NULL (No habrá elemnto antes que el primero de la lista). Se conecta el puntero '*anterior'
    del siguiente dato con la cajita que hemos agregado. El puntero '*principio' toma también el valor de p.
    */
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        p -> antes = NULL;
        ( p -> siguiente ) -> antes = p;
        principio = p;
    }
    /*
    Si se debe agregar al final, entonces '*siguiente' de la caja que agregaremos debe ser NULL (no existe ningún elemento después del último).
    '*antes' de la caja que agregaremos deberá apuntar al que antes era el último elemento de la lista (*fin). Se conecta el puntero '*siguiente'
    de la caja que antes era la última con la nueva caja. El puntero '*fin' toma el valor de p.
    */
    else if(donde == FINAL){
        p -> siguiente = NULL;
        p -> antes = fin;
        (p -> antes) -> siguiente = p;
        fin = p;
    }
    /*
    Si se agrega enmedio de la lista, entonces se puentean los punteros usando la dirección '*anterior'
    */
    else{
        p -> siguiente = anterior -> siguiente;
        p -> antes = anterior;
        (p -> siguiente) -> antes = p;
        anterior -> siguiente = p;
    }
    lugarAgregado = p;
    return(1);
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función saca al primer elemento de la lista auxiliar (nodo con la longitud de ruta más corta) y regresa su dirección.
*/
caja2 *lista::sacar(){

    if(principio == NULL && fin == NULL) return (NULL); //Si la lista está vacía regresas un NULL
    caja3 *p; //Puntero para manipular la lista
    caja2 *q; //Puntero que almacenará la dirección del nodo a sacar

    p = principio;//te pones en el principio
    q = p->direccionNodo; // extraes la dirección del nodo contenida en el primer elemento de la lista
    principio = p -> siguiente; //recorres el principio

    //Si es el único elemento en la lista, entonces el fin también debe ser NULL
    if (p -> siguiente == NULL){
            fin = NULL;
    }
    else{ //Si no, desconectas el principio haciendo que la caja siguiente apunte a NULL hacia atrás.
        (p->siguiente)->antes = NULL;
    }

    delete(p); //Destruyes el primer elemento
    return(q); //Regresas la dirección almacenada.
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección en donde un nodo se ha agregado/encontrado dentro de la lista doble de nodos etiquetados.
*/
caja3 *lista::lugar_agregado(){
    return(lugarAgregado);
}

/********************************************************************************************************************************************************************************************/

/*
    Esta función borra un nodo dentro de la lista doble. Esto se hace en caso de ajustar la lista y se borra el nodo que contiene su
    longitud de rutaCorta desactualizada.

    PARÁMETROS
    float a: longitud de la ruta del nodo que queremos borrar.

    Regresa un 1 si se pudo borrar; en caso contrario, regresa un cero.
*/
int lista::borrar(float a){
    caja3 *p;
    buscar(a); //Buscas el nodo
    if(encontrado == NO) return(0); //Si no lo encuentras se acaba y regresas un cero.

    //Si se encontró, entonces desconectas el nodo de la lista.
    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
        if (p -> siguiente == NULL) fin = NULL;
        else (p -> siguiente) -> antes = NULL;
    }
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
        (p -> siguiente) -> antes = anterior;
    }
    else{
        p = fin;
        (p -> antes) -> siguiente = NULL;
        fin = anterior;
    }
    delete(p);//Borras el nodo.
    return(1); //Regresas un 1
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función imprime el contenido de la lista auxiliar.
*/
void lista::pintar(){
    caja3 *p;
    p = principio;

    while(p){
         if(p == principio)std::cout << "Nodo: " << p->direccionNodo->numNodo << ",  Longitud: " << p->longitud << std::endl;
         else std::cout << "Nodo: " << p->direccionNodo->numNodo << ", Longitud: " << p->longitud <<  ", Antecesor: " << p->direccionNodo->antecesor->numNodo << std::endl;
        p = p -> siguiente;
    }
    std::cout << "\b\b ";

}
/********************************************************************************************************************************************************************************************/
/*
    Esta función ajusta la lista de nodos etiquetados en caso de encontrar que un nood tiene la longitud de su ruta más corta
    desactualizada porque ésta siempre debe permanecer ordenada de menor a mayor.

    PARÁMETROS
    *p: dirección del dentro de la lista doble que queremos eliminar.
    a: ruta nueva que queremos cambiarle al nodo.
*/
void lista::ajustar(caja3 *p, float a){
    if(p -> longitud <= a) return; //Si la nueva ruta es mayor o igual que la que el nodo ya tiene, entonces no se hace nada.

    caja2 *q; //Puntero para guardar el contenido del nodo a borrar (dirección del nodo en cuestión pero dentro de la lista de nodos.)
    q = p->direccionNodo; //Guardas la dirección.

    //Borras el nodo desactualizado.
    borrar(p->longitud);

    //Agregas el nuevo nodo. Este contendrá la misma direcicón del nodo dentro de la lista de nodos y la longitud de ruta nueva.
    agregar(q, a);

    return;

}
/********************************************************************************************************************************************************************************************/

/*
    Destructor de la clase lista
*/
lista::~lista(){
    caja3 *p;
    while(principio){ //Te pones en el principio, recorres este apuntador hacia adelante y borras el nodo en donde te encuentras.
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    //Reseteas todos los punteros y las variables.
    anterior = principio = fin = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;

    return;
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función es una copia del destructor de la clase lista.
*/
void lista::terminar(){
    caja3 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    anterior = principio = fin = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;

    return;
}
/********************************************************************************************************************************************************************************************/

/*
    Esta clase representa a una gráfica.

    ATRIBUTOS
    A: lista de nodos.
    L: lista auxiliar (para implementar el algoritmo de Dijkstra).
    existeRuta: variable que indica si existe una ruta entre el nodo inicial y el nodo destino.

    FUNCIONES:
    grafica(): constructor.
    ~grafica(): destructor.
    agregar_arco(int a, int b, float l): agrega un arco con peso a la gráfica.
    rutaCorta(int a, int b): Implementación del algoritmo de Dijkstra.
    pintar(): imprime la gráfica.
*/
class grafica{
    lista_nodos A;
    lista L;
    int existeRuta;
public:
    grafica();
    ~grafica();
    void agregar_arco(int a, int b, float l);
    void rutaCorta(int a, int b);
    void pintar();
};
/********************************************************************************************************************************************************************************************/

/*
    Constructor de la clase grafica
*/
grafica::grafica(){
    A.iniciar(); //Constructor de la lista_nodos
    L.iniciar(); //constructor de la lisa auxiliar
    existeRuta = 0; //valor inicial de existeRuta
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función agrega un arco con peso entre dos nodos a la gráfica.

    PARÁMETROS
    a: primer nodo.
    b: segundo nodo.
    l: peso del arco entre el primer y segundo nodo.
*/
void grafica::agregar_arco(int a, int b, float l){
    caja1 *p; //puntero para localizar el saliente de a
    caja2 *q, *q2; //punteros para localizar los nodos

    A.agregar(a);//agregas el primer nodo a la lista de nodos
    q = q2 = A.lugar_agregado(); //los dos punteros se posan sobre este nodo.
    (q -> salientes).agregar(b); //agregas al segundo nodo en los salientes del primer nodo
    p = (q->salientes).lugar_agregado(); //en p guardas la dirección del saliente dentro de la lista de salientes del primer nodo.

    A.agregar(b);//agregas el segundo nodo
    q = A.lugar_agregado(); //en q localizas al segundo nodo dentro de la lista de nodos
    (p -> direccionNodo) = q; //en p(saliente del primer nodo) metes la dirección de ese saliente pero en la lista de nodos.
    (p -> longitud) = l; //agregas la longitud del arco al saliente del primer nodo
    (q ->entrantes).agregar(a); //Agregas al primer nodo en la lista de entrantes del segundo
    ((q->entrantes).lugar_agregado())->direccionNodo = q2; //metes la dirección del primer nodo en la caja entrante del segundo nodo
    ((q->entrantes).lugar_agregado())->longitud = l; //agregas la longitud del arco al entrante del segundo nodo.
}
/********************************************************************************************************************************************************************************************/

/*
    Esta función implementa el algoritmo de Dijkstra para encontrar la ruta más corta entre dos nodos de una gráfica

    PARÁMETROS
    a: nodo origen.
    b: nodo destino.
*/
void grafica::rutaCorta(int a, int b){
    caja2 *p; //puntero para manipular los nodos
    caja1 *q; //puntero para manipular a los salientes de los nodos.

    A.buscar(a); //buscas el nodo origen
    p = A.lugar_agregado(); //guardas la dirección del nodo origen

    //Comienzas a recorrer todos los nodos que faltan a partir del nodo origen
    while(p){
        p -> bandera = 2; //Se marca al nodo como definitivo

        //Si el nodo que marcaste como definitivo es el nodo destino, entonces has encontrado la ruta más corta
        if(p->numNodo == b){
            existeRuta = 1;
            L.terminar(); //Vacías la lista de nodos etiquetados
            while(p){ //Vuelves a llenar la lista de nodos etigquetados pero sólo con los nodos involucrados en la ruta más corta.
                L.agregar(p, p->rutaCorta);
                p = p->antecesor;
            }
            //Imprimes el resultado imprimiendo la lista auxiliar que ahora contiene los nodos de la ruta más corta.
            std::cout << "RUTA MAS CORTA ENTRE LOS NODOS " << a << " y " << b << std::endl;
            L.pintar();
            return;
        }

        //Si el nodo etiquetado no es el destino, entonces procedes a procesar todos los salientes de dicho nodo
        q = (p->salientes).Principio(); //Guardas la dirección del primer saliente del nodo.
        //Recorres todos los nodos salientes del nodo en cuestión
        while(q){
            /*
                Si la bandera es cero, se cambia a 1 porque el algoritmo ha lo tocó. Su ruta corta será la ruta que tiene el nodo de donde
                viene este saliente más la longitud del arco de este nodo. El antecesor de este nodo será el nodo de donde salió.
                Finalmente agregas este nodo a la lista de nodos etiquetados con la longitud de su ruta corta.
            */
            if( (q->direccionNodo)->bandera == 0 ){
                q->direccionNodo->bandera = 1;

                (q->direccionNodo)->rutaCorta = (p->rutaCorta) + (q->longitud);

                (q->direccionNodo)->antecesor = p;

                L.agregar( (q->direccionNodo), (p->rutaCorta) + (q->longitud) );


                (q->direccionNodo)->direccion = L.lugar_agregado();
            }
            /*
                Si la etiqueta del nodo ya es 1 (ya existe dentro de la lista de nodos etiquetados)
                y la ruta corta hasta este saliente, partiendo desde el nodo p, es menor
                a la ruta corta que previamente tiene, entonces se actualiza esta información en la lista de nodos
                etiquetados.
            */
            else if( (q->direccionNodo)->bandera == 1 && (p->rutaCorta)+(q->longitud) < (q->direccionNodo)->rutaCorta ){
                L.ajustar( (q->direccionNodo)->direccion, (p->rutaCorta) + (q->longitud) ); //Ajustas
                q->direccionNodo->antecesor = p; //Actualizas al antecesor del saliente
                q->direccionNodo->rutaCorta = (p->rutaCorta) + (q->longitud); //Actualizas la longitud de la ruta cortta del saliente

            }
            q = q->siguiente; //Procesas el siguiente saliente
        }
        p = L.sacar(); //Los nodos a etiquetar como definitivos serán los que cuenten con la ruta más corta dentro de la lista de nodos etiquetados.
    }
    /*
        Si el algoritmo se acaba, entonces no existe ruta corta.
    */
    if(existeRuta == 0){
        std::cout << "No existe ruta mas corta." << std::endl;
    }

}

/********************************************************************************************************************************************************************************************/

/*
    Esta función pinta la gráfica
*/
void grafica::pintar(){
    A.pintar(); //Se llama a la función pintar de la lista nodos.
}
/********************************************************************************************************************************************************************************************/

/*
    Destructor de la clase grafica.
*/
grafica::~grafica(){
    A.terminar();
    L.terminar();
}

#endif // GRAFICAS_H_INCLUDED
