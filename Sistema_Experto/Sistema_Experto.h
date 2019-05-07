#ifndef SISTEMA_EXPERTO_H_INCLUDED
#define SISTEMA_EXPERTO_H_INCLUDED

#define VACIO 99999
#include <iostream>
#include <string>

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
    cuantos = 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void lista_arcos::iniciar(){
    principio = anterior = lugarAgregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
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
    cuantos = 0;
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
    cuantos = 0;
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int lista_arcos::Cuantos(){
    caja1 *p;
    p = principio;
    while(p){
        cuantos++;
        p = p->siguiente;

    }
    return(cuantos);
}

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

struct caja3{
    caja2 *direccion;
    caja3 *siguiente;
};

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
//----------------------------------------------------------------------------------------------------------------------------------------------------

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
//----------------------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------------------

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
//----------------------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

SE::SE(){
    A.iniciar();
    B.iniciar();
    solucion = 0;
}

SE::~SE(){
    A.terminar();
    B.terminar();
    solucion = 0;
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

void SE::correr(string preguntas[40]){
 caja2 *dir; //Puntero que almacenará la dirección del nodo pregunta en el que estamos
 caja1 *saliente, *salientePila;
 caja2 *pila; // Puntero que recorrerá a los salientes de un nodo pregunta
 int pregunta = 1; //Dirección de los textos de las preguntas.
 int respuesta; //Respuesta del usuario
 int respSaliente; //Respuesta que se enviará a todos los salientes de las preguntas
 int conclusion;
 int redundante = 0;
 int indice = 1;

 caja2 *conc1,*conc2,*conc3,*conc4,*conc5,*conc6,*conc7;
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

 //La función se detendrá hasta haber recorrido todo el arreglo de preguntas
 while(pregunta != 40){
    if(conc1->valorVerdad == 0 && conc2->valorVerdad == 0 && conc3->valorVerdad == 0 &&
       conc4->valorVerdad == 0 && conc5->valorVerdad == 0 && conc6->valorVerdad == 0 &&
       conc7->valorVerdad == 0){
        cout << "NO PUEDO ADIVINAR EL ANIMAL EN EL QUE ESTAS PENSANDO. SORRY" << endl << endl;
        return;
    }

    A.buscar(pregunta); //Se busca una pregunta
    dir = A.lugar_agregado(); //Se guarda su dirección

    saliente = dir->salientes.Principio();
    redundante = 0;
    while(saliente){
        if(saliente->direccionNodo->valorVerdad != -1) redundante++;
        saliente = saliente->siguiente;
    }
    //Si la pregunta no tiene valor de verdad y no es redundante, entonces se hace.
    if(dir->valorVerdad == -1 && (redundante != dir->salientes.Cuantos() || redundante == 0) ){
        cout << indice++ << ": " << preguntas[pregunta] << endl;
        cin >> respuesta;
        //La pregunta actual toma el valor que el usuario le dio
        dir->valorVerdad = respuesta;

        //El puntero 'saliente' se posiciona en el primer saliente de este nodo pregunta para recorrerlos todos.
        saliente = dir->salientes.Principio();

        //Se recorren todos los salientes de la pregunta
        while(saliente){
            //Se decide el valor a enviar de acuerdo a la variable cambiaValor de los salientes
            if(saliente->cambiaValor == 0) respSaliente = respuesta;
            else{
                if(respuesta == 1) respSaliente = 0;
                else respSaliente = 1;
            }

            /*
            Se decide si el 'valorVerdad' se hace cero o 'Cuantos' se incrementa
            De acuerdo al valor de verdad recibido y al tipo de conectivo del saliente;
            además se checa si el saliente adquiere un valor de verdad para introducirlo
            a la pila y "desparramar" ese valor a donde se debe.
            */
            if(saliente->direccionNodo->conectivo == 1){
                if(respSaliente == 0){
                    saliente->direccionNodo->valorVerdad = 0;
                    B.Agregar(saliente->direccionNodo);
                }
                else saliente->direccionNodo->cuantos++;

                if(saliente->direccionNodo->cuantos == saliente->direccionNodo->totales){
                    saliente->direccionNodo->valorVerdad = 1;
                    B.Agregar(saliente->direccionNodo);
                    if(saliente->direccionNodo->numNodo == 21 || saliente->direccionNodo->numNodo == 22 ||
                       saliente->direccionNodo->numNodo == 23 || saliente->direccionNodo->numNodo == 24 ||
                       saliente->direccionNodo->numNodo == 25 || saliente->direccionNodo->numNodo == 26 ||
                       saliente->direccionNodo->numNodo == 27 ){
                        solucion = 1;
                        conclusion = saliente->direccionNodo->numNodo;
                        pregunta = 40;
                        break;
                   }
                }

            }
            else if(saliente->direccionNodo->conectivo == 0){
                if(respSaliente == 0) saliente->direccionNodo->cuantos++;
                else{
                    saliente->direccionNodo->valorVerdad = 1;
                    B.Agregar(saliente->direccionNodo);
                    if(saliente->direccionNodo->numNodo == 21 || saliente->direccionNodo->numNodo == 22 ||
                       saliente->direccionNodo->numNodo == 23 || saliente->direccionNodo->numNodo == 24 ||
                       saliente->direccionNodo->numNodo == 25 || saliente->direccionNodo->numNodo == 26 ||
                       saliente->direccionNodo->numNodo == 27 ){
                        solucion = 1;
                        conclusion = saliente->direccionNodo->numNodo;
                        pregunta = 40;
                        break;
                   }
                }

                if(saliente->direccionNodo->cuantos == saliente->direccionNodo->totales){
                    saliente->direccionNodo->valorVerdad = 0;
                    B.Agregar(saliente->direccionNodo);
                }
            }

            //SE PROCESA LA PILA DE LOS NODOS QUE YA ADQUIRIERON VALOR
            pila = B.Sacar();
            while(pila){
                salientePila = pila->salientes.Principio();
                respSaliente = pila->valorVerdad;

                while(salientePila){
                    if(salientePila->cambiaValor == 0) respSaliente = pila->valorVerdad;
                    else{
                        if(pila->valorVerdad == 1) respSaliente = 0;
                        else respSaliente = 1;
                    }

                    if(salientePila->direccionNodo->conectivo == 1){
                        if(respSaliente == 0){
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
                                    solucion = 1;
                                    conclusion = salientePila->direccionNodo->numNodo;
                                    pregunta = 40;
                                    break;
                               }
                            }

                        }
                    }
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
                                    solucion = 1;
                                    conclusion = salientePila->direccionNodo->numNodo;
                                    pregunta = 40;
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
                    salientePila = salientePila->siguiente;
                }
                pila = B.Sacar();
            }
            saliente = saliente->siguiente;

        }
        if(solucion == 1){
            cout << preguntas[conclusion];
            return;
        }
        pregunta++;
    }
    else pregunta++;
 }
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
