#ifndef GRAFICAS_4_H_INCLUDED
#define GRAFICAS_4_H_INCLUDED

#include <iostream>
#define VACIO 99999

struct caja2;

struct caja1{
    int numNodo;
    float longitud;
    caja1 *siguiente;
    caja2 *direccionNodo;
};

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
    caja1 *Principio();
    void iniciar();
    void terminar();
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct caja3;

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
        std::cout << p -> numNodo << "-" << p->direccionNodo->numNodo << " Longitud: " << p->longitud << " ; ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
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

struct caja3{
    caja2 *direccionNodo;
    float longitud;
    caja3 *siguiente, *antes;
};

/********************************************************************************************************************************************************************************************/

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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

lista::lista(){
    anterior = principio = fin = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista::iniciar(){
    anterior = principio = fin = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
}

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
//----------------------------------------------------------------------------------------------------------------------------------------------------

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
//----------------------------------------------------------------------------------------------------------------------------------------------------

caja2 *lista::sacar(){

    if(principio == NULL && fin == NULL) return (NULL);
    caja3 *p;
    caja2 *q;

    p = principio;
    q = p->direccionNodo;
    principio = p -> siguiente;
    if (p -> siguiente == NULL) fin = NULL;
    else (p -> siguiente) -> antes = principio;

    delete(p);
    return(q);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

caja3 *lista::lugar_agregado(){
    return(lugarAgregado);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista::borrar(float a){
    caja3 *p;
    buscar(a);
    if(encontrado == NO) return(0);

    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
        if (p -> siguiente == NULL) fin = NULL;
        else (p -> siguiente) -> antes = principio;
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
    delete(p);
    return(1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void lista::ajustar(caja3 *p, float a){
    if(p -> longitud <= a) return;

    std::cout << "VOY A AJUSTAR EL NODO: " << p->direccionNodo->numNodo << "con la longitud " << p->longitud << std::endl;
    caja2 *q; float ruta;
    q = p->direccionNodo;

    std::cout << "BORRE EL NODO: " << p->direccionNodo->numNodo << "con la longitud " << p->longitud << std::endl;
    borrar(p->longitud);
    pintar();
    std::cout << "\n";
    std::cout << "AGREGARE EL NODO: " << q->numNodo << "con la longitud " << a << std::endl;
    agregar(q, a);
    std::cout << "Lista que se supone que esta actualizada"<< std::endl;
    pintar();
    std::cout << "\n";

    return;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------------------------------------
lista::~lista(){
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
//----------------------------------------------------------------------------------------------------------------------------------------------------

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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

grafica::grafica(){
    A.iniciar();
    L.iniciar();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void grafica::agregar_arco(int a, int b, float l){
    caja1 *p;
    caja2 *q, *q2;
    A.agregar(a);
    q = q2 = A.lugar_agregado();
    (q -> salientes).agregar(b);
    p = (q->salientes).lugar_agregado();

    A.agregar(b);
    q = A.lugar_agregado();
    (p -> direccionNodo) = q;
    (p -> longitud) = l;
    (q ->entrantes).agregar(a);
    ((q->entrantes).lugar_agregado())->direccionNodo = q2;
    ((q->entrantes).lugar_agregado())->longitud = l;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void grafica::rutaCorta(int a, int b){
    caja2 *p;
    caja1 *q;

    A.agregar(a);
    p = A.lugar_agregado();

    while(p){
        p -> bandera = 2;
        std::cout << "NODO DEFINITIVO: " << p->numNodo << std::endl << std::endl;

        if(p->numNodo == b){
            existeRuta = 1;
            L.terminar();
            while(p){
                L.agregar(p, p->rutaCorta);
                p = p->antecesor;
            }
            L.pintar();
            return;
        }

        q = (p->salientes).Principio();
        while(q){
            std::cout << "Estoy en el nodo " << q->direccionNodo->numNodo << "con bandera: " << q->direccionNodo->bandera << std::endl;
            std::cout << "LISTA: " << std::endl;
            L.pintar();
            std::cout << "\n";

            if( (q->direccionNodo)->bandera == 0 ){
                q->direccionNodo->bandera = 1;
                std::cout << "Nodo: " << q->direccionNodo->numNodo << ", " << "Bandera: " << q->direccionNodo->bandera << std::endl;
                (q->direccionNodo)->rutaCorta = (p->rutaCorta) + (q->longitud);
                std::cout << "Ruta corta: " << (p->rutaCorta) + (q->longitud) << std::endl;
                (q->direccionNodo)->antecesor = p;
                L.agregar( (q->direccionNodo), (p->rutaCorta) + (q->longitud) );
                std::cout << "LISTA: " << std::endl;
                L.pintar();
                std::cout << "\n";
                (q->direccionNodo)->direccion = L.lugar_agregado();
            }
            else if( (q->direccionNodo)->bandera == 1 && (p->rutaCorta)+(q->longitud) < (q->direccionNodo)->rutaCorta ){
                L.ajustar( (q->direccionNodo)->direccion, (p->rutaCorta) + (q->longitud) );
                q->direccionNodo->antecesor = p;
                q->direccionNodo->rutaCorta = (p->rutaCorta) + (q->longitud);
                std::cout << "LISTA: " << std::endl;
                L.pintar();
                std::cout << "\n";

            }
            q = q->siguiente;
        }
        p = L.sacar();
    }
    if(existeRuta == 1){
        std::cout << "RUTA MAS CORTA: " << std::endl;
        L.pintar();
    }
    else std::cout << "No existe ruta mas corta." << std::endl;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void grafica::pintar(){
    A.pintar();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

grafica::~grafica(){
    A.terminar();
    L.terminar();
}

#endif // GRAFICAS_4_H_INCLUDED