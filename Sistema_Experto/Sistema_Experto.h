/*
    Nombre: Sitema_Experto.h
    Autor: Pedro Andrés Hernández Amador.
    Fecha: mayo del 2019

    Descripción: Archivo de cabecera que incluye las funciones para implementar un sistema experto.
*/
#ifndef SISTEMA_EXPERTO_H_INCLUDED
#define SISTEMA_EXPERTO_H_INCLUDED

#define VACIO 99999
#include <iostream>
#include <string>

using namespace::std;

struct caja2;

/*
    Esta estructura representa a un nodo saliente de una pregunta/cláusula en el sistema experto.
    numNodo: Valor del nodo.
    camviaValor: señala si se le debe mandar un valor de verdad contrario al nodo saliente.
    *siguiente: Apuntador hacia el siguiente saliente del nodo original.
    *direccionNodo: Dirección de la pregunta/cláusula al cuál hace referencia este saliente
*/
struct caja1{
    int numNodo;
    caja2 *direccionNodo;
    int cambiaValor;
    caja1 * siguiente;
};
/**************************************************************************************************************************************************************************************************/

/*
    Esta clase representa a todos los salientes de alguna pregunta/cláusula en el sistema experto.
    Es una lista de struct caja1 ordenada por numNodo sin repetición.

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
    int cuantos(): regresa el número de salientes que tiene una pregunta/clausula
    *lugar_agregado(): regresa la dirección en donde fue agregado ó encontrado un nodo
    *principio(): regresa la dirección del primer nodo en la lista
    iniciar(): copia del constructor
    terminar(): copia del destructor


*/
class lista_arcos{
    caja1 *principio, *anterior, *lugarAgregado;
    int encontrado, donde;
    int cuantos;
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
    int Cuantos();
    caja1 *lugar_agregado();
    caja1 *Principio();
};
/**************************************************************************************************************************************************************************************************/

/*
    Esta estructura representa a una pregunta/cláusula en el sistema experto. Es una lista ordenada por numNodo sin repetición.

    ATRIBUTOS:
    numNodo: número del nodo.
    bandera: Bandera que indica si el nodo es pregunta ó conclusion
    cuantos: cuenta la cantidad de valores de verdad que han llegado al nodo.
    totales: cantidad de valores de verdad que se necesitan para que este nodo tome un valor de verdad definitivo
    conectivo: conectivo logico del nodo 1 = Y ; 2 = O
    valorVerdad: valor de verdad definitivo del nodo.
    *siguiente: nodo siguiente a éste en la lista de preguntas/conclusiones del sistema experto.
    salientes: lista de salientes de este nodo.

*/
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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función es el constructor de la clase lista_arcos
*/
lista_arcos::lista_arcos(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/**************************************************************************************************************************************************************************************************/
/*
    Esta función es una copia del constructor de la clase lista_arcos
*/
void lista_arcos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/**************************************************************************************************************************************************************************************************/

/*
    Destructor de la clase lista_arcos
*/
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
/**************************************************************************************************************************************************************************************************/

/*
    Copia del destructor de la clase lista_arcos
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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función cuenta cuántos salientes tiene una pregunta/clausula. Regrsa dicho resultado.
*/
int lista_arcos::Cuantos(){
    caja1 *p;
    p = principio;
    while(p){
        cuantos++;
        p = p->siguiente;

    }
    return(cuantos);
}
/**************************************************************************************************************************************************************************************************/

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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función agrega un nodo en la lista de salientes de una pregunta/clausula

    PARÁMETROS:
    nodo: Número del nodo que queremos agregar.
    cambiaValor: tipo de cambiaValor que queremos que el saliente tenga.
*/
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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección en donde fue encontrado ó agregado un nodo saliente/entrante.
*/
caja1* lista_arcos::lugar_agregado(){
    return(lugarAgregado);
}
/**************************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección del primer elemento de la lista de salientes/entrantes.
*/
caja1 *lista_arcos::Principio(){
    return (principio);
}

/**************************************************************************************************************************************************************************************************/
/*
    Esta función imprime en pantalla todos los elementos de la lista (entrantes / salientes de algún nodo).
*/
void lista_arcos::pintar(){
    caja1 *p; p = principio; //Se crea un puntero tipo caja y se sitúa al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
        cout << "Nodo: " << p->direccionNodo->numNodo << " ; Cambio: " << p->cambiaValor << endl;
        p = p -> siguiente;
    }
    cout << "\b\b ";
}
/**************************************************************************************************************************************************************************************************/

/*
    Esta clase representa a todas las preguntas, conclusiones y cláusulas del sistema experto.
    Es una lista de struct caja2 ordenada por numNodo sin repetición.

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
    agregar(int nodo[7]): agrega un nodo en la lista.
    pinitar(): imprime la lista ordenada (a los salientes de un nodo).
    iniciar(): copia del constructor
    terminar(): copia del destructor
    *lugar_agregado(): regresa la dirección en donde fue agregado ó encontrado un nodo

*/
class lista_nodos{
    caja2 *principio, *anterior, *lugarAgregado;
    int encontrado, donde;
    enum encontrado {SI, NO};
    enum donde{PRINCIPIO, ENMEDIO, FINAL};

public:
    lista_nodos();
    ~lista_nodos();
    void buscar(int a);
    int agregar(int nodo[7]);
    void pintar();
    void iniciar();
    void terminar();
    caja2* lugar_agregado();
};
/**************************************************************************************************************************************************************************************************/

/*
    Constructor de la clase lista_nodos
*/
lista_nodos::lista_nodos(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
/**************************************************************************************************************************************************************************************************/

/*
    Esta función es una copia del constructor de la clase lista_nodos
*/
void lista_nodos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;

}
/**************************************************************************************************************************************************************************************************/

/*
    Copia del destructor de la clase lista_nodos
*/
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
/**************************************************************************************************************************************************************************************************/

/*
    Destructor de la clase lista_nodos
*/
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
/**************************************************************************************************************************************************************************************************/

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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función agrega un nodo dentro de la lista de nodos.

    PARÁMETROS
    nodo[7]: arreglo con todos los elementos que debe contener un nodo (bandera, cuantos, conectivo,...) incluyendo un saliente.
*/
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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función imprime en pantalla todos los elementos de la lista de nodos de la gráfica con sus salientes
    y entrantes.
*/
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
/**************************************************************************************************************************************************************************************************/

/*
    Esta función regresa la dirección en donde un nodo  fue agregado ó encontrado.
*/
caja2* lista_nodos::lugar_agregado(){
    return(lugarAgregado);
}
/**************************************************************************************************************************************************************************************************/

/*
    Esta estructura representa a un nodo que ya adquirió valor de verdad dentro de la pila auxiliar que nos ayuda a recibir este tipo de nodos
    para exparcir su valor de verdad hacia sus correspondientes salientes.

    ATRIBUTOS:
    *direccion: direccion del nodo pero dentro de la lista de nodos.
    *siguiente: Apuntador hacia el siguiente elemento de la pila.
*/
struct caja3{
    caja2 *direccion;
    caja3 *siguiente;
};
/**************************************************************************************************************************************************************************************************/

/*
    Esta clase es una pila auxiliar del sistema experto. En ésta introduciremos todos los nodos que vayan adquiriendo valor de verdad para
    posteriormente desparramar dicho valor de verdad hacia todos los salientes de el nodo que estamos procesando dentro de la pila.
*/
class pila{
    //ATRIBUTOS
    private:
        caja3 *principio; //puntero que apunta al principio de la pila.
    //MÉTODOS
    public:
        pila(); //Constructor de la clase.
        void iniciar();
        ~pila();//Destructor de la clase.
        void terminar();
        void Agregar(caja2 *saliente); //Método para agregar elementos a la pila.
        caja2 * Sacar(); //Método para sacar elementos de la pila.
        void Pintar(); //Método para imprimir la pila.
};
/**************************************************************************************************************************************************************************************************/

/*
    Este método es el constructor de la clase pila. Inicializa el puntero 'principio' como NULL porque no
    existe ningún elemento dentro de la pila; por este mismo motivo la variable 'cuantos' toma el valor de cero.
*/
pila::pila(){
    principio = NULL;
}
void pila::iniciar(){
    principio = NULL;
}
/**************************************************************************************************************************************************************************************************/
/*
    Esta función agrega el número 'a' a la pila.
*/
void pila::Agregar(caja2 *saliente){
    caja3 *p; //Puntero tipo caja.
    p = new caja3;
    p->direccion = saliente; //Se crea una nueva caja.

    /*
    Si no existe ningun elemento en la pila, entonces el dato
    en cuestión se introduce al princiío de ésta; como será el
    único elemento, el apuntador '*siguiente' de esta caja será NULL.
    */
    if(principio == NULL){
        p -> siguiente = NULL;
        principio = p;
    }
    /*
    Si ya existe algún elemento en la pila, entonce el nuevo dato se introduce
    antes que el que ya estaba, de esta manera queda "arriba" de él; con lo que
    el nuevo elemento toma el lugar del principio de la cola(cima).
    */
    else{
        p -> siguiente = principio;
        principio = p;
    }
    return;
}
/**************************************************************************************************************************************************************************************************/

//Esta función se encarga de sacar el último elemento de la pila, muestra su valor y libera la memoria ocupada por éste.
caja2 * pila::Sacar(){
    caja3 *p;
    caja2 *direccion;

    //Si no hay nada en la píla, entonces se regresa el valor VACIO.
    if(principio == NULL){
        return(NULL);
    }
    /*
    Si existe algún elemento en la pila, entonces el puntero '*p' se coloca sobre este (que se encuentra en la cima) y, como será eliminado,
    entonces el siguiente elemento se convierte en el primero de la estructura.
    */
    else{
        direccion = principio->direccion;
        p = principio;
        principio = p -> siguiente;
    }
    delete p; //Se libera la memoria ocupada por el dato en cuestión.
    return (direccion); //Se regresa eel valor que el dato extraído tenía.
}
/**************************************************************************************************************************************************************************************************/
/*
Esta función imprime en pantalla los datos que están en la pila.
*/
void pila::Pintar(){
    caja3 *p; p = principio; //Se crea un puntero a caja y se posiciona al principio de la pila.
    //Mientras p no sea NULL (mientras no recorra todas las cajitas) se imprime su contenido.
    while(p){
        std::cout << p->direccion->numNodo << " " << endl;
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
/**************************************************************************************************************************************************************************************************/
/*
El destructor de la pila libera la memoria que ocupan los datos que están en la estructura
y reinician los atributos de la pila.
*/
pila:: ~pila(){
    caja3 *p;//Puntero a caja
    /*
    Mientras el puntero principio no sea NULL, el puntero p se posiciona sobre el principio, el
    principio se recorre un espacio y se libera la memoria ocupada por p.
    */

    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    //Se reinician las variables.
    principio = NULL;
    return;
}
/**************************************************************************************************************************************************************************************************/

/*
    Copia del destructor de la clase pila
*/
void pila::terminar(){
    caja3 *p;//Puntero a caja
    /*
    Mientras el puntero principio no sea NULL, el puntero p se posiciona sobre el principio, el
    principio se recorre un espacio y se libera la memoria ocupada por p.
    */

    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    //Se reinician las variables.
    principio = NULL;
    return;
}
/****************************************************************************************************************************************************/

/*
    Esta clase representa a un sistema experto.

    ATRIBUTOS
    A: lista de preguntas, respuestas, cláusulas.
    B: Pila auxiliar en donde se introducen todos los nodos que han adquirido valor de verdad
    solucion: solucion del sistema experto.

    FUNCIONES
    SE: constructor
    ~SE: destructor
    agregar_arcp(int nodo[7], int nodo2[7]): agrega al nodo1 a la lista de nodos y al nodo2 como saliente del nodo1
    pintar: pinta la lista de nodos.
    correr(string preguntas[40]): corre el sistema experto.
*/
class SE{
    lista_nodos A;
    pila B;
    int solucion;

public:
    SE();
    ~SE();
    void agregar_arco(int nodo1[7], int nodo2[7]);
    void pintar();
    void correr(string preguntas[40]);
};
/**************************************************************************************************************************************************************************************************/
/*
    Constructor de la clase SE
*/
SE::SE(){
    A.iniciar();
    B.iniciar();
    solucion = 0;
}
/**************************************************************************************************************************************************************************************************/

/*
    Destructor de la clase SE
*/
SE::~SE(){
    A.terminar();
    B.terminar();
    solucion = 0;
}
/**************************************************************************************************************************************************************************************************/

/*
    Esta función agrega un nodo y a un saliente al sistema experto

    PARAMETROS
    nodo1[7]: banderas del primer nodo y un saliente
    nodo2[7]: banderas del segundo nodo que será saliente del 1
*/
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
/**************************************************************************************************************************************************************************************************/
/*
    Esta función pinta la lista de nodos del sistema experto.
*/
void SE::pintar(){
    A.pintar();
}
/**************************************************************************************************************************************************************************************************/

/*
    Esta función corre el sistema experto.

    PARÁMETROS
    preguntas[40]: recibe la lista de preguntas/conclusiones/clausulas con el cuál el sistema experto trabaja.
*/
void SE::correr(string preguntas[40]){
 caja2 *dir; //Puntero que almacenará la dirección del nodo pregunta en el que estamos
 caja1 *saliente, *salientePila; //Punteros que recorrerán los salientes de los nodos pregunta y los nodos de la pila.
 caja2 *pila; // Puntero que recorrerá la pila de nodos con valor de verdad.
 int pregunta = 1; //Dirección de los textos de las preguntas.
 int respuesta; //Respuesta del usuario
 int respSaliente; //Respuesta que se enviará a todos los salientes de las preguntas
 int redundante = 0; //Contador que cuenta los salientes de una pregunta que ya tienen valor de verdad.
 int indice = 1; //Índice de las preguntas que se van haciendo (Estilo).

 caja2 *conc1,*conc2,*conc3,*conc4,*conc5,*conc6,*conc7; //Punteros a las conclusiones.

 //SE BUSCAN Y SE GUARDAN EN UN PUNTERO LAS DIRECCIONES DE LAS CONCLUSIONES DEL SISTEMA EXPERTO
 A.buscar(21);
 conc1 = A.lugar_agregado();
 A.buscar(22);
 conc2 = A.lugar_agregado();
 A.buscar(23);
 conc3 = A.lugar_agregado();
 A.buscar(24);
 conc4 = A.lugar_agregado();
 A.buscar(25);
 conc5 = A.lugar_agregado();
 A.buscar(26);
 conc6 = A.lugar_agregado();
 A.buscar(27);
 conc7 = A.lugar_agregado();

 //COMIENZA LA EJECUCIÓN DEL SISTEMA EXPERTO

 //La función se detendrá hasta haber recorrido todo el arreglo de preguntas
 while(solucion == 0 && pregunta <= 20){
    //Amtes de comenzar se verifica que por lo menos una conclusión sea plausible para seguir con el proceso.
    if(conc1->valorVerdad == 0 && conc2->valorVerdad == 0 && conc3->valorVerdad == 0 &&
       conc4->valorVerdad == 0 && conc5->valorVerdad == 0 && conc6->valorVerdad == 0 &&
       conc7->valorVerdad == 0){
        cout << "NO PUEDO ADIVINAR EL ANIMAL EN EL QUE ESTAS PENSANDO. SORRY" << endl << endl;
        return;
    }

    A.buscar(pregunta); //Se busca la pregunta
    dir = A.lugar_agregado(); //Se guarda su dirección

    /*
        Se coloca un puntero en los salientes de la pregunta para recorrerlos y contar
        cuántos ya tienen valor de verdad. Si la suma de los salientes con valor de verdad
        es igual al número total de salientes, entonces la pregunta es redundante y se omite
    */
    saliente = dir->salientes.Principio();
    redundante = 0;
    while(saliente){
        if(saliente->direccionNodo->valorVerdad != -1) redundante++;
        saliente = saliente->siguiente;
    }

    //Si la pregunta no tiene valor de verdad y no es redundante, entonces se hace.
    if(dir->valorVerdad == -1 && (redundante != dir->salientes.Cuantos() || redundante == 0) &&
        dir->numNodo <= 20){
        cout << indice++ << ": " << preguntas[pregunta] << endl;
        cin >> respuesta;

        //Si la respuesta es diferente de "NO SÉ", entonces se comienzan a distribuir todos los valores, si no, se salta.
        if(respuesta != 2){
            //La pregunta actual toma el valor que el usuario le dio
            dir->valorVerdad = respuesta;

            /*
                El puntero 'saliente' se posiciona en el primer saliente de este nodo pregunta para recorrerlos todos
                y distribuir la respuesta que el usuario dió.
            */
            saliente = dir->salientes.Principio();

            //Se recorren todos los salientes de la pregunta
            while(saliente){
                //Se decide el valor a enviar de acuerdo a la variable cambiaValor de los salientes
                if(saliente->cambiaValor == 0) respSaliente = respuesta; //Si no se cambia valor, entonces se deja igual
                else{ //Si hay que cambiar de valor, entonces la respuesta que el usuario dio se niega.
                    if(respuesta == 1) respSaliente = 0;
                    else respSaliente = 1;
                }

                /*
                Se decide si el 'valorVerdad' se hace cero o 'Cuantos' se incrementa
                De acuerdo al valor de verdad recibido y al tipo de conectivo del saliente;
                además se checa si el saliente adquiere un valor de verdad para introducirlo
                a la pila y "desparramar" ese valor a donde se debe.
                */

                //CONECTIVO 'Y'
                if(saliente->direccionNodo->conectivo == 1){
                    //Si recibe un 0, entonce automáticamente se hace falso y como el nodo tomo valor de verdad, entonces se agrega a la pila
                    if(respSaliente == 0){
                        saliente->direccionNodo->valorVerdad = 0;
                        B.Agregar(saliente->direccionNodo);
                    }
                    else saliente->direccionNodo->cuantos++; //Si se recibe un uno, entonces la variable cuantos se ve incrementada en una unidad.

                    /*
                        Como es conectivo 'Y', cuando la variable 'cuantos' = 'totales', el nodo toma el valor de verdadero, si este nodo
                        es una conclusión, entonces el sistema experto termina de ejecutarse.
                    */
                    if(saliente->direccionNodo->cuantos == saliente->direccionNodo->totales){
                        saliente->direccionNodo->valorVerdad = 1; //Se hace verdadero el valor de verdad del nodo.
                        B.Agregar(saliente->direccionNodo); //Como acaba de tomar valor de verdad, entonces se agrega a la pila
                        //Si el nodo que adquirió valor de verdad = 1 es una conclusión, entonces termina la ejecución.
                        if(saliente->direccionNodo->numNodo == 21 || saliente->direccionNodo->numNodo == 22 ||
                           saliente->direccionNodo->numNodo == 23 || saliente->direccionNodo->numNodo == 24 ||
                           saliente->direccionNodo->numNodo == 25 || saliente->direccionNodo->numNodo == 26 ||
                           saliente->direccionNodo->numNodo == 27 ){
                            solucion = saliente->direccionNodo->numNodo;
                            break;
                       }
                    }
                }
                // CONECTIVO 'O'
                else if(saliente->direccionNodo->conectivo == 0){
                    //Si recibe un 0, entonces la variable cuantos se ve incrementada en una unidad.
                    if(respSaliente == 0) saliente->direccionNodo->cuantos++;
                    else{
                        //Si recibe un 1, entonce automáticamente se hace verdadero y como el nodo tomó valor de verdad, entonces se agrega a la pila
                        saliente->direccionNodo->valorVerdad = 1;
                        B.Agregar(saliente->direccionNodo);

                        //Si el nodo que adquirió valor de verdad = 1 es una conclusión, entonces termina la ejecución.
                        if(saliente->direccionNodo->numNodo == 21 || saliente->direccionNodo->numNodo == 22 ||
                           saliente->direccionNodo->numNodo == 23 || saliente->direccionNodo->numNodo == 24 ||
                           saliente->direccionNodo->numNodo == 25 || saliente->direccionNodo->numNodo == 26 ||
                           saliente->direccionNodo->numNodo == 27 ){
                            solucion = saliente->direccionNodo->numNodo;
                            break;
                       }
                    }

                    /*
                        Como es conectivo 'O', cuando la variable 'cuantos' = 'totales', el nodo toma el valor de falso y se agrega a la pila.
                    */

                    if(saliente->direccionNodo->cuantos == saliente->direccionNodo->totales){
                        saliente->direccionNodo->valorVerdad = 0;
                        B.Agregar(saliente->direccionNodo);
                    }
                }

                /*
                  En todo el bloque anterior tal vez algunos nodos entraron a la pila (adquirieron valor de verdad), entonces
                  se deben procesar para distribuir los valores de éstos hacia donde corresponda y, en su defecto, seguir agregando
                  más elementos.
                */
                pila = B.Sacar(); //El apuntador pila toma el valor del primer elemento de la pila (si está vacía, entonces no se hará nada)
                while(pila){
                    salientePila = pila->salientes.Principio(); //Se procesarán todos los salientes del nodo.
                    respSaliente = pila->valorVerdad; //El valor de verdad que se enviará a la pila será el valor de verdad del nodo en cuestión.

                    /*
                        En este ciclo se barren todos los salientes del nodo en cuestión y el valor de verdad de éste se distribuye
                    */
                    while(salientePila){
                        //Se decide si se cambia el valor o se mantiene, de acuerdo al conectivo del saliente.
                        if(salientePila->cambiaValor == 0) respSaliente = pila->valorVerdad;
                        else{
                            if(pila->valorVerdad == 1) respSaliente = 0;
                            else respSaliente = 1;
                        }

                        //Se decide qué hacer en caso de que el saliente tenga conectivo 'Y'
                        if(salientePila->direccionNodo->conectivo == 1){
                            if(respSaliente == 0){
                                    /*
                                        Cuando vamos a asignar valor de verdad a nodos desde la pila primero hay que checar que dicho nodo
                                        no tenga valor de verdad. Esto en el caso de que con anterioridad ya haya adquirido un valor de verdad
                                        en otra parte del código.
                                    */
                                if(salientePila->direccionNodo->valorVerdad != 0){
                                    salientePila->direccionNodo->valorVerdad = 0;
                                    B.Agregar(salientePila->direccionNodo);
                                }

                            }
                            else salientePila->direccionNodo->cuantos++;

                            if(salientePila->direccionNodo->cuantos == salientePila->direccionNodo->totales){
                                if(salientePila->direccionNodo->valorVerdad != 1){
                                    salientePila->direccionNodo->valorVerdad = 1;
                                    B.Agregar(salientePila->direccionNodo);
                                    if(salientePila->direccionNodo->numNodo == 21 || salientePila->direccionNodo->numNodo == 22 ||
                                       salientePila->direccionNodo->numNodo == 23 || salientePila->direccionNodo->numNodo == 24 ||
                                       salientePila->direccionNodo->numNodo == 25 || salientePila->direccionNodo->numNodo == 26 ||
                                       salientePila->direccionNodo->numNodo == 27 ){
                                        solucion = salientePila->direccionNodo->numNodo;
                                        break;
                                   }
                                }

                            }
                        }
                        //Se decide qué hacer en caso de que el saliente tenga conectivo 'O'
                        else if(salientePila->direccionNodo->conectivo == 0){
                            if(respSaliente == 0) salientePila->direccionNodo->cuantos++;
                            else{
                                if(salientePila->direccionNodo->valorVerdad != 1){
                                    salientePila->direccionNodo->valorVerdad = 1;
                                    B.Agregar(salientePila->direccionNodo);
                                    if(salientePila->direccionNodo->numNodo == 21 || salientePila->direccionNodo->numNodo == 22 ||
                                       salientePila->direccionNodo->numNodo == 23 || salientePila->direccionNodo->numNodo == 24 ||
                                       salientePila->direccionNodo->numNodo == 25 || salientePila->direccionNodo->numNodo == 26 ||
                                       salientePila->direccionNodo->numNodo == 27 ){
                                        solucion = salientePila->direccionNodo->numNodo;
                                        break;
                                   }
                                }
                            }

                            if(salientePila->direccionNodo->cuantos == salientePila->direccionNodo->totales){
                                if(salientePila->direccionNodo->valorVerdad != 0){
                                    salientePila->direccionNodo->valorVerdad = 0;
                                    B.Agregar(salientePila->direccionNodo);
                                }
                            }
                        }
                        salientePila = salientePila->siguiente; //Se procesa el siguiente saliente del nodo de la pila
                    }
                    pila = B.Sacar(); //Se procesa el siguiente nodo en la pila
                }
                saliente = saliente->siguiente; //Se procesa el siguiente saliente de la pregunta.
            }
            //Si la solución tomó el valor de 1, entonces significa que el sistema llegó a una conclusión; se imprime y se termina el programa.
            if(solucion != 0){
                cout << preguntas[solucion];
                return;
            }
        }
        pregunta++; //Si la respuesta del usuario fue 2 (No sé), entonces esa pregunta se salta.
    }
    else pregunta++; //Cuando ya se ha procesado completamente una pregunta, se procede a hacer la siguiente y procesarla.
 }

 //En caso de que se termine el programa y no haya una conclusión, entonces se procede a imprimir las posibles opciones que el sistema experto tenía como respuesta
 cout << "NO PUDE ADIVINAR EL ANIMAL EN EL QUE ESTAS PENSANDO, PERO ESTA / ESTAS FUERON LAS OPCIONES MAS CERCANAS: " << endl;
 if(conc1->valorVerdad == -1) cout << preguntas[21] << endl;
 if(conc2->valorVerdad == -1) cout << preguntas[22] << endl;
 if(conc3->valorVerdad == -1) cout << preguntas[23] << endl;
 if(conc4->valorVerdad == -1) cout << preguntas[24] << endl;
 if(conc5->valorVerdad == -1) cout << preguntas[25] << endl;
 if(conc6->valorVerdad == -1) cout << preguntas[26] << endl;
 if(conc7->valorVerdad == -1) cout << preguntas[27] << endl;
}
#endif // SISTEMA_EXPERTO_H_INCLUDED
