#ifndef ESTRUCTURASDEDATOS_H_INCLUDED
#define ESTRUCTURASDEDATOS_H_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

#define VACIO 999999999

/*
    Esta estructura se utiliza para agregar datos tipo entero a las pilas, colas y listas ordenadas
    sin repetici�n y con poca repetici�n.
    La variable 'valor' almacena el n�mero que deseamos introducir; el puntero 'siguiente'
    almacena la direcci�n de la siguiente caja dentro de las estructuras de datos.
*/
struct caja{
    int valor;
    caja *siguiente;
};
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
    Esta estructura se utiliza para agregar datos tipo entero a la lista ordenada con mucha repetici�n.
    La variable 'valor' almacena el n�mero que deseamos introducir; la variable 'n' representa el n�mero
    de veces que el valor se repite dentro de la lista ordenada; el puntero 'siguiente' almacena la direcci�n
    de la siguiente caja dentro de las estructuras de datos.
*/
struct caja2{
    int valor;
    int n;
    caja2 *siguiente;
};
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
    Esta estructura se utiliza para agregar datos tipo entero a la lista ordenada doblemente ligada.
    La variable 'valor' almacena el n�mero que deseamos introducir; el puuntero 'antes' almacena la
    direcci�n de la caja anterior; el puntero 'siguiente' almacena la direcci�n
    de la siguiente caja.
*/
struct caja3{
    int valor; //Valor que deseamos agregar a la pila.
    caja3 *antes, *siguiente; //Puntero que apuntar� al siguiente elemento en la pila.
};
/****************************************************************************************************************************************************/
/*
    Esta clase representa una pila. Los datos se guardan despu�s de los que ya han sido introducidos con anterioridad. Para manipularlos
    se accede al �ltimo elemento agregado.

    *ATRIBUTOS*
    -El puntero 'principio' almacena la direcci�n en donde comienza la pila.
    -La variable 'cuantos' indica la cantidad de datos que existen dentro de la pila.

    *M�TODOS*
    -El constructor inicializa las variables '*principio' y cuantos.
    -El destructor libera la memoria utilizada por la pila y resetea los valores
     de las variables '*principio' y 'cuantos'.
    -Agregar(a): Agrega un n�mero entero a la pila.
    -Sacar(): Accede al �ltimo elemento de la pila, regresa su valor y lo destruye.
    -Pintar(): Imprime en pantalla el contenido de la pila.
    -Cuantos(): Regresa el valor de la variable 'cuantos' que indica el n�mero de elemtnos
     que se encuentran dentro de la pila.
*/
class pila{
    //ATRIBUTOS
    private:
        caja *principio; //puntero que apunta al principio de la pila.
        int cuantos; //Variable que guardar� el n�mero de elementos que tiene la pila dentro.

    //M�TODOS
    public:
        pila(); //Constructor de la clase.
        ~pila();//Destructor de la clase.
        void Agregar(int a); //M�todo para agregar elementos a la pila.
        int Sacar(); //M�todo para sacar elementos de la pila.
        void Pintar(); //M�todo para imprimir la pila.
        int Cuantos(); //M�todo para imprimir la cantidad de elementos existentes en la pila.
};
//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
    Este m�todo es el constructor de la clase pila. Inicializa el puntero 'principio' como NULL porque no
    existe ning�n elemento dentro de la pila; por este mismo motivo la variable 'cuantos' toma el valor de cero.
*/
pila::pila(){
    principio = NULL;
    cuantos = 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
    Esta funci�n agrega el n�mero 'a' a la pila.
*/
void pila::Agregar(int a){
    caja *p; //Puntero tipo caja.
    p = new caja; //Se crea una nueva caja.
    p -> valor = a; //Se introduce el valor dado a la caja.

    /*
    Si no existe ningun elemento en la pila, entonces el dato
    en cuesti�n se introduce al princi�o de �sta; como ser� el
    �nico elemento, el apuntador '*siguiente' de esta caja ser� NULL.
    */
    if(principio == NULL){
        p -> siguiente = NULL;
        principio = p;
    }
    /*
    Si ya existe alg�n elemento en la pila, entonce el nuevo dato se introduce
    antes que el que ya estaba, de esta manera queda "arriba" de �l; con lo que
    el nuevo elemento toma el lugar del principio de la cola(cima).
    */
    else{
        p -> siguiente = principio;
        principio = p;
    }
    cuantos ++; //Se incrementa la variable que cuenta los elementos que hay en la pila.
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

//Esta funci�n se encarga de sacar el �ltimo elemento de la pila, muestra su valor y libera la memoria ocupada por �ste.
int pila::Sacar(){
    caja *p;
    int valor; //Variable que almacenar� el valor del dato a sacar.

    //Si no hay nada en la p�la, entonces se regresa el valor VACIO.
    if(principio == NULL){
        return(VACIO);
    }
    /*
    Si existe alg�n elemento en la pila, entonces el puntero '*p' se coloca sobre este (que se encuentra en la cima) y, como ser� eliminado,
    entonces el siguiente elemento se convierte en el primero de la estructura.
    */
    else{
        p = principio;
        principio = p -> siguiente;
    }

    valor = p -> valor; //Se guarda el valor del dato en la variable 'valor'.
    delete p; //Se libera la memoria ocupada por el dato en cuesti�n.
    cuantos --; //Se decrementa la variable que almacena el n�mero de datos que existen en la pila.
    return (valor); //Se regresa eel valor que el dato extra�do ten�a.
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
Esta funci�n nos indica el n�mero de datos que existen dentro de la p�la.
*/
int pila::Cuantos(){
return (cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
Esta funci�n imprime en pantalla los datos que est�n en la pila.
*/
void pila::Pintar(){
    caja *p; p = principio; //Se crea un puntero a caja y se posiciona al principio de la pila.
    //Mientras p no sea NULL (mientras no recorra todas las cajitas) se imprime su contenido.
    while(p){
        std::cout << p -> valor << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
El destructor de la pila libera la memoria que ocupan los datos que est�n en la estructura
y reinician los atributos de la pila.
*/
pila:: ~pila(){
    caja *p;//Puntero a caja
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
    cuantos = 0;
    return;
}
/****************************************************************************************************************************************************/
/*
    Esta clase representa una cola. Los datos se guardan despu�s de los que ya han sido introducidos con anterioridad(al final). Para manipularlos
    se accede desde el primer elemento que fue introducido (desde el principio).

    *ATRIBUTOS*
    -El puntero 'principio' almacena la direcci�n en donde comienza la cola (dir. del primer elemento).
    -El puntero 'fin' almacea la direcci�n en donde termina la cola (dir. del �ltimo elemento).
    -La variable 'cuantos' indica la cantidad de datos que existen dentro de la cola.

    *M�TODOS*
    -El constructor inicializa las variables '*principio', '*fin' y 'cuantos'.
    -El destructor libera la memoria utilizada por la pila y resetea los valores
     de las variables '*principio', '*fin' y cuantos.
    -Agregar(int a): Agrega un n�mero entero a la cola.
    -Sacar(): Accede al primer elemento de la cola (direcci�n 'principio'), regresa su valor y lo destruye.
    -Pintar(): Imprime en pantalla el contenido de la cola.
    -Cuantos(): Regresa el valor de la variable 'cuantos' que indica el n�mero de elemtnos
     que se encuentran dentro de la pila.
*/
class cola{
    private:
        caja *principio, *fin;
        int cuantos;

    public:
        cola();
        ~cola();

        void Agregar(int a); //M�todo para agregar elementos a la pila.
        int Sacar(); //M�todo para sacar elementos de la pila.
        void Pintar(); //M�todo para imprimir la pila.
        int Cuantos(); //M�todo para imprimir la cantidad de elementos existentes en la pila.
};
//----------------------------------------------------------------------------------------------------

//El constructor inicializa las variables de la cola. Los punteros como NULL y la variable entera 'cuantos' con valor de cero.
 cola::cola(){
    principio = fin = NULL;
    cuantos = 0;
}
//----------------------------------------------------------------------------------------------------

//Este m�todo agrega un n�mero entero a la cola.
void cola::Agregar(int a){
    caja *p;//Puntero tipo caja.
    p = new caja;//Se crea una nueva caja.
    p -> valor = a; //El valor que queremos introducir a la cola se guarda en la caja.

    /*
    Si la cola est� vac�a, entonces el puntero '*siguiente' de la caja se hace NULL porque
    despu�s del principio no hay nada; los punteros '*principio' y '*fin' se colocan sobre la
    caja, pues justamente la caja(*p) representa el principio y el fin de la cola.
    */
    if(principio == NULL){
        p -> siguiente = NULL;
        principio = p;
        fin = p;
    }
    /*
    Si existe alg�n elemento dentro de la cola, significa que el elemento a introducir ser� el �ltimo de la cola;
    entonces el puntero '*siguiente' de la caja a introducir se hace NULL; el puntero '*siguiente' de la caja que estaba
    antes al final ahora toma el valor de '*p', y el puntero '*fin' se recorre y se sit�a sobre la caja que acabamos de
    agregar a la estructura.
    */
    else{
        p -> siguiente = NULL;
        fin -> siguiente = p;
        fin = p;
    }
    cuantos ++; //Se incrementa la variable que indica el n�mero de elementos en la cola.

}
//----------------------------------------------------------------------------------------------------

//Esta funci�n se encarga de sacar el �ltimo �rimer elemento de la cola, muestra su valor y libera la memoria ocupada por �ste.
int cola::Sacar(){
    caja *p; //Se crea un nuevo puntero tipo caja.
    int valor; //Variable que almacenar� el valor que vamos a sacar de la cola.

    //Si la cola est� vac�a, entonces se regresa el valor VACIO.
    if(principio == NULL){
        return(VACIO);
    }
    /*
    Si la cola no est� vacia, entonces '*p' se posiciona en el principio; el puntero '*principio' se recorre al siguiente elemento
    y la variable 'valor' almacena el contenido de la caja en donde est� '*p'; finalmente se libera la memoria de la cajita que hemos sacado.
    */
    else{
        p = principio;
        principio = p -> siguiente;
        valor = p -> valor;
        delete p;
    }

    cuantos --; //Se decrementa la viable que indica cu�ntos datos hay en la cola.

    /*
    Como los datos se extraen desde el principio, entonces el puntero '*fin' no se altera al menos
    que el elemento extra�do haya sido el �nico existente en la cola.
    */
    if(principio == NULL){
        fin = NULL;
    }

    return (valor); //Se regresa el valor que exist�a dentro de la caja que hemos destruido.

}
//----------------------------------------------------------------------------------------------------

//Este m�todo regresa el n�mero de elementos que existen en la cola.
int cola::Cuantos(){
return (cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
Esta funci�n imprime en pantalla los datos que est�n en la cola.
*/
void cola::Pintar(){
    caja *p; p = principio; //Se crea un puntero tipo caja y se posiciona al principio de la cola.
    //Mientras '*p' no sea NULL se recorre la cola desde el principio hasta el final y se imprime el contenido de las cajas.
    while(p){
        std::cout << p -> valor << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
El destructor de la cola libera la memoria que ocupan los datos que est�n en la estructura
y reinician los atributos de la cola.
*/
cola:: ~cola(){
    caja *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = fin = NULL;
    cuantos = 0;
    return;
}

/****************************************************************************************************************************************************/
/*
    Esta clase representa una lista ordenada sin repeticiones. Los datos se guardan de menor a mayor dentro de la estructura.

    *ATRIBUTOS*
    -El puntero 'principio' almacena la direcci�n en donde comienza la lista ordenada.
    -El puntero '*anterior' almacena la direcci�n de la caja anterior a la que
     estamos, nos ayudar� al momento de recorrer la estructura y realizar cambios en ella.
    -La variable 'cuantos' indica la cantidad de datos que existen dentro de la pila.
    -La variable 'Encontrado' nos indica si alg�n elemento que estemos buscando existe
     dentro de la lista ordenada.
    -La variable 'donde' nos indica en donde se encuentra alg�n elemento que busquemos.

    *M�TODOS*
    -El constructor inicializa los punteros: '*principio', '*anterior'; y las varianbles
     'cuantos', 'encontrado', 'donde'.
    -El destructor libera la memoria utilizada por la lista ordenada y resetea los valores
     de los atributos.
    -buscar(int a): Busca el valor 'a' dentro de la lista ordenada.
    -agregar(int a): Agrega un n�mero entero a la pila.
    -borrar(): Elimina de la lista ordenada alg�n dato.
    -pintar(): Imprime en pantalla el contenido de la lista ordenada.
    -Cuantos(): Regresa el valor de la variable 'cuantos' que indica el n�mero de elemtnos
     que se encuentran dentro de la lista.
*/
class lista_Ord{
    private:
        caja *principio, *anterior;
        int cuantos;
        int encontrado;
        int donde;
        enum encontrado {SI, NO};
        enum donde {PRINCIPIO, ENMEDIO, FINAL};

    public:
        lista_Ord();
        ~lista_Ord();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();
        int Cuantos();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------

//Se inicializan los atributos de la lista ordenada.
lista_Ord::lista_Ord(){
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
Este m�todo busca un n�mero entero dentro de la lista ordenada y, mediante los atributos 'encontrado' y 'donde'
indica si el dato fue encontrado y en d�nde se encontr�.
*/
void lista_Ord::buscar(int a){
    caja *p; //Puntero tipo caja que recorrer� la estructura.

    //Si la estructura est� vac�a entonces se indica que el dato no se encontr� y que la lista est� vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    //Si la lista no est� vac�a, entonces se comenzar� a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p -> valor == a){
            encontrado = SI;
            if(p == principio){ //Si se encuentra al principio, entonces donde = PRINCIPIO.
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //Si la siguiente direcci�n es NULL, entonces significa que estamos en el final de la lista.
                donde = FINAL;
             }
             else{ //Si no estamos al principio ni al final de la lista ordenada, entonces encontramos el n�mero enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces si encontramos alg�n n�mero menor a 'a', simplemente seguimos recorriendo
        la estructura.
        */
        else if(p -> valor < a){
            encontrado = NO; //Se indica que no se ha encontrado a�n.
            anterior = p; //El puntero '*anterior' toma el valor de la direcci�n en donde nos encontramos.
            p = p -> siguiente; //Finalmente p se pone sobre la siguiente caja de la lista ordenada.
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces, si encontramos alg�n n�mero mayor a 'a', significa que nuestro nuevo
        valor debe agregarse una posici�n antes de este n�mero mayor con el que nos encontramos.
        */
        else{
            encontrado = NO; //Se indica que 'a' no ha sido encontrado.
            if(principio == p){ //Si el primer elemento que checamos result� ser mayor, entonces significa que 'a' debe agregarse al principio.
                donde = PRINCIPIO;
            }
            else{ //Si no lo encontramos al principio, entonces forzosamente debe de agregarse en alg�n lugar enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
    }
    /*
    Si el ciclo se acaba y se recorre toda la lista sin encontrar ning�n n�mero mayor, entonces significa que el n�mero que queremos
    encontrar es mayor a todos los que existen dentro de la lista ordenada; por lo tanto, no ha sido encontrado y debe agregarse al final.
    */
    encontrado = NO;
    donde = FINAL;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

//Este m�todo agrega un n�mero entero a la lista ordenada, regresa un 1 si pudo ser agregado y un 0 en caso contrario.
int lista_Ord::agregar(int a){
    caja *p; //Puntero tipo caja que nos servir� para agregar el valor a la estructura.
    buscar(a); //Se busca el n�mero que queremos introducir.

    //Como no se consideran repeticiones, si el n�mero se encontr�, se regresa un cero porque no volver� a ser introducido a la estructura.
    if(encontrado == SI) return (0);

    //Si no se encontr�, entonces se procede a agregar al n�mero 'a'.
    p = new caja; //Se crea una nueva caja.
    p -> valor = a; //Se introduce el valor 'a' a la caja.

    /*
    Si la lista ordenada est� vacia, entonces el puntero '*siguiente' de la caja ser� NULL (porque despu�s de esta cajita no existir�
    otra) y el puntero '*principio' tomar� la direcci�n de esta caja que hemos agregado.
    */
    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    /*
    Si se debe agregar al principio, entonces el puntero '*siguiente' de la caja apuntar� hacia el valor que, hasta el momento,
    estaba al principio de la estructura; como hemos agregadoa un valor antes del primer elemento de la lista, entonces el puntero
    '*principio' se recorre hacia atr�s y tomar� la direcci�n del elemento que reci�n hemos agregado.
    */
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    /*
    Si debemos agregar al final, entonces el puntero '*siguiente' de nuestra caja ser� NULL (pues no existir� nada despu�s). En este
    caso, el puntero '*anterior' se encontrar� sobre el �ltimo elemento de la lista hasta este momento; entonces, el puntero
    'anterio -> siguiente' tomara el valor de p porque ahora '*p' ser� la �ltima cajita de la estructura.
    */
    else if(donde == FINAL){
        p -> siguiente = NULL;
        anterior -> siguiente = p;
    }
    /*
    Si no se agregar� al principio ni al final, entonces se agregar� enmedio; para esto los puntero
    se "puentean" de la siguiente manera:
    */
    else{
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }

    cuantos ++; //Se incrementa el n�mero de datos dentro de la estructura
    return (1); //Se regresa un 1 porque el valor pudo ser agregado.
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

//Este m�todo elimina un dato de la lista ordenada. Regresa un 1 si el n�mero puede eliminarse; en caso contrario, se regresa un 0.
int lista_Ord::borrar(int a){
    caja *p; //Puntero tipo caja que nos ayudar� a recorrer la lista.
    buscar(a); //Se busca el n�mero.

    if(encontrado == NO) return (0); //Si no se encuentra, entonces no puede eliminarse y se regresa un 0.

    /*
    Si se encuentra al principio, entonces '*p' se posiciona sobre el puntero '*principio'; entonces, como el primer
    elemento se va a eliminar, el n�mero siguiente pasar� a ser el primero; por lo tanto principio = p -> siguiente.
    */
    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }
    /*
    Si se encuentra en medio, entonces utilizamos al puntero '*anterior' para poner a '*p' sobre el elemento que queremos
    eliminar; despu�s, se "puentea" el apuntador '*siguiente' de la caja con direcci�n '*anterior'
    */
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }
    /*
    Si no se encontr� al principio ni enmedio, entonces se encontr� al final. Utilizamos el puntero '*anterior' para posicionarnos sobre
    el �ltimo elemento; despu�s, 'anterior -> siguiente' ser� NULL, porque despu�s del elemento '*anterior' ahora ya no habr� nada.
    */
    else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete(p); //Se elimina el dato deseado.
    cuantos--; //Se decrementa el n�mero de datos dentro de la lista.
    return (1); //Se regresa un 1 porque s� pudimos eliminar el dato.
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo imprime en pantalla los datos de la lista ordenada.
void lista_Ord::pintar(){
    caja *p; p = principio; //Se crea un puntero tipo caja y se sit�a al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
        std::cout << p -> valor << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo regresa el n�mero de datos con los que cuenta la lista ordenada.
int lista_Ord::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//El destructor libera la memoria ocupada por todos los datos y resetea el valor de los atributos.
lista_Ord:: ~lista_Ord(){
    caja *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    principio = anterior = NULL;
    cuantos = 0;
    return;
}
/****************************************************************************************************************************************************/
/*
    Esta clase representa una lista ordenada con pocas repeticiones. Los datos se guardan de menor a mayor dentro de la estructura.

    *ATRIBUTOS*
    -El puntero '*principio' almacena la direcci�n en donde comienza la lista ordenada.
    -El puntero '*anterior' almacena la direcci�n de la caja anterior a la que
     estamos, nos ayudar� al momento de recorrer la estructura y realizar cambios en ella.
    -La variable 'cuantos' indica la cantidad de datos que existen dentro de la pila.
    -La variable 'Encontrado' nos indica si alg�n elemento que estemos buscando existe
     dentro de la lista ordenada.
    -La variable 'donde' nos indica en donde se encuentra alg�n elemento que busquemos.

    *M�TODOS*
    -El constructor inicializa los punteros: '*principio', '*anterior'; y las varianbles
     'cuantos', 'encontrado', 'donde'.
    -El destructor libera la memoria utilizada por la lista ordenada y resetea los valores
     de los atributos.
    -buscar(int a): Busca el valor 'a' dentro de la lista ordenada.
    -agregar(int a): Agrega un n�mero entero a la pila.
    -borrar(): Elimina de la lista ordenada alg�n dato.
    -pintar(): Imprime en pantalla el contenido de la lista ordenada.
    -Cuantos(): Regresa el valor de la variable 'cuantos' que indica el n�mero de elemtnos
     que se encuentran dentro de la lista.
*/
class lista_Ord_PocaRepeticion{
    private:
        caja *principio, *anterior;
        int cuantos;
        int encontrado;
        int donde;
        enum encontrado {SI, NO};
        enum donde {PRINCIPIO, ENMEDIO, FINAL};

    public:
        lista_Ord_PocaRepeticion();
        ~lista_Ord_PocaRepeticion();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();
        int Cuantos();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Se inicializan los atributos de la clase.
lista_Ord_PocaRepeticion::lista_Ord_PocaRepeticion(){
    principio = anterior = NULL;
    cuantos = 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

//Este m�todo busca un n�mero entero dentro de la lista ordenada.
void lista_Ord_PocaRepeticion::buscar(int a){
    caja *p; //Puntero tipo caja que recorrer� la estructura.

    //Si la estructura est� vac�a entonces se indica que el dato no se encontr� y que la lista est� vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    //Si la lista no est� vac�a, entonces se comenzar� a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p -> valor == a){
            encontrado = SI;
            if(p == principio){ //Si se encuentra al principio, entonces donde = PRINCIPIO.
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //Si la siguiente direcci�n es NULL, entonces significa que estamos en el final de la lista.
                donde = FINAL;
             }
             else{ //Si no estamos al principio ni al final de la lista ordenada, entonces encontramos el n�mero enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces si encontramos alg�n n�mero menor a 'a', simplemente seguimos recorriendo
        la estructura.
        */
        else if(p -> valor < a){
            encontrado = NO; //Se indica que no se ha encontrado a�n.
            anterior = p; //El puntero '*anterior' toma el valor de la direcci�n en donde nos encontramos.
            p = p -> siguiente; //Finalmente p se pone sobre la siguiente caja de la lista ordenada.
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces, si encontramos alg�n n�mero mayor a 'a', significa que nuestro nuevo
        valor debe agregarse una posici�n antes de este n�mero mayor con el que nos encontramos.
        */
        else{
            encontrado = NO; //Se indica que 'a' no ha sido encontrado.
            if(principio == p){ //Si el primer elemento que checamos result� ser mayor, entonces significa que 'a' debe agregarse al principio.
                donde = PRINCIPIO;
            }
            else{ //Si no lo encontramos al principio, entonces forzosamente debe de agregarse en alg�n lugar enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
    }
    /*
    Si el ciclo se acaba y se recorre toda la lista sin encontrar ning�n n�mero mayor, entonces significa que el n�mero que queremos
    encontrar es mayor a todos los que existen dentro de la lista ordenada; por lo tanto, no ha sido encontrado y debe agregarse al final.
    */
    encontrado = NO;
    donde = FINAL;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Ord_PocaRepeticion::agregar(int a){
    caja *p; //Puntero tipo caja que nos servir� para agregar el valor a la estructura.
    buscar(a); //Se busca el n�mero que queremos introducir.

    p = new caja; //Se crea una nueva caja.
    p -> valor = a; //Se introduce el valor 'a' a la caja.

    /*
    Si la lista ordenada est� vacia, entonces el puntero '*siguiente' de la caja ser� NULL (porque despu�s de esta cajita no existir�
    otra) y el puntero '*principio' tomar� la direcci�n de esta caja que hemos agregado.
    */
    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    /*
    Si se debe agregar al principio, entonces el puntero '*siguiente' de la caja apuntar� hacia el valor que, hasta el momento,
    estaba al principio de la estructura; como hemos agregadoa un valor antes del primer elemento de la lista, entonces el puntero
    '*principio' se recorre hacia atr�s y tomar� la direcci�n del elemento que reci�n hemos agregado.
    */
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    /*
    Si no se agregar� al principio, entonces se agregar� enmedio (tambi�n funciona para agregar al final); para esto los puntero
    se "puentean" de la siguiente manera:
    */
    else{
        p -> siguiente = anterior -> siguiente; //En caso de agregar al final, p -> sigunete ser� NULL.
        anterior -> siguiente = p;
    }

    cuantos ++; //Se incrementa el n�mero de datos dentro de la estructura
    return (1); //Se regresa un 1 porque el valor pudo ser agregado.
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Ord_PocaRepeticion::borrar(int a){
    caja *p; //Puntero tipo caja que nos ayudar� a recorrer la lista.
    buscar(a); //Se busca el n�mero.

    if(encontrado == NO) return (0); //Si no se encuentra, entonces no puede eliminarse y se regresa un 0.

    /*
    Si se encuentra al principio, entonces '*p' se posiciona sobre el puntero '*principio'; entonces, como el primer
    elemento se va a eliminar, el n�mero siguiente pasar� a ser el primero; por lo tanto principio = p -> siguiente.
    */
    if(donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }
    /*
    Si se encuentra en medio, entonces utilizamos al puntero '*anterior' para poner a '*p' sobre el elemento que queremos
    eliminar; despu�s, se "puentea" el apuntador '*siguiente' de la caja con direcci�n '*anterior'
    */
    else if(donde == ENMEDIO){
        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }
    /*
    Si no se encontr� al principio ni enmedio, entonces se encontr� al final. Utilizamos el puntero '*anterior' para posicionarnos sobre
    el �ltimo elemento; despu�s, 'anterior -> siguiente' ser� NULL, porque despu�s del elemento '*anterior' ahora ya no habr� nada.
    */
    else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete(p); //Se elimina el dato deseado.
    cuantos--; //Se decrementa el n�mero de datos dentro de la lista.
    return (1); //Se regresa un 1 porque s� pudimos eliminar el dato.
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo imprime en pantalla los datos.
void lista_Ord_PocaRepeticion::pintar(){
    caja *p; p = principio; //Se crea un puntero tipo caja y se sit�a al principio de la lista ordenada.
    while(p){ //Se imprimen todos los valores que forman parte de la estructura.
        std::cout << p -> valor << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo regresa el n�mero de datos con los que cuenta la lista ordenada.
int lista_Ord_PocaRepeticion::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo libera la memoria ocupada por los datos de la lista ordenada y resetea los atributos de la clase.
lista_Ord_PocaRepeticion::~lista_Ord_PocaRepeticion(){
    caja *p;
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
/*
    Esta clase representa una lista ordenada con muchas repeticiones. Los datos se guardan de menor a mayor dentro de la estructura.

    *ATRIBUTOS*
    -El puntero '*principio' almacena la direcci�n en donde comienza la lista ordenada.
    -El puntero '*anterior' almacena la direcci�n de la caja anterior a la que
     estamos, nos ayudar� al momento de recorrer la estructura y realizar cambios en ella.
    -La variable 'cuantos' indica la cantidad de datos que existen dentro de la pila.
    -La variable 'Encontrado' nos indica si alg�n elemento que estemos buscando existe
     dentro de la lista ordenada.
    -La variable 'donde' nos indica en donde se encuentra alg�n elemento que busquemos.

    *M�TODOS*
    -El constructor inicializa los punteros: '*principio', '*anterior'; y las varianbles
     'cuantos', 'encontrado', 'donde'.
    -El destructor libera la memoria utilizada por la lista ordenada y resetea los valores
     de los atributos.
    -buscar(int a): Busca el valor 'a' dentro de la lista ordenada.
    -agregar(int a): Agrega un n�mero entero a la pila.
    -borrar(): Elimina de la lista ordenada alg�n dato.
    -pintar(): Imprime en pantalla el contenido de la lista ordenada.
    -Cuantos(): Regresa el valor de la variable 'cuantos' que indica el n�mero de elemtnos
     que se encuentran dentro de la lista.
*/
class lista_Ord_MuchaRepeticion{
    private:
        caja2 *principio, *anterior;
        int cuantos;
        int encontrado;
        int donde;
        enum encontrado {SI, NO};
        enum donde {PRINCIPIO, ENMEDIO, FINAL};

    public:
        lista_Ord_MuchaRepeticion();
        ~lista_Ord_MuchaRepeticion();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();
        int Cuantos();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------

//Se inicializan los atributos de la clase.
lista_Ord_MuchaRepeticion::lista_Ord_MuchaRepeticion(){
    principio = anterior = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void lista_Ord_MuchaRepeticion::buscar(int a){

    caja2 *p; //Puntero tipo caja2 que recorrer� la estructura.

    //Si la estructura est� vac�a entonces se indica que el dato no se encontr� y que la lista est� vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    //Si la lista no est� vac�a, entonces se comenzar� a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p -> valor == a){
            encontrado = SI;
            if(p == principio){ //Si se encuentra al principio, entonces donde = PRINCIPIO.
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //Si la siguiente direcci�n es NULL, entonces significa que estamos en el final de la lista.
                donde = FINAL;
             }
             else{ //Si no estamos al principio ni al final de la lista ordenada, entonces encontramos el n�mero enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces si encontramos alg�n n�mero menor a 'a', simplemente seguimos recorriendo
        la estructura.
        */
        else if(p -> valor < a){
            encontrado = NO; //Se indica que no se ha encontrado a�n.
            anterior = p; //El puntero '*anterior' toma el valor de la direcci�n en donde nos encontramos.
            p = p -> siguiente; //Finalmente p se pone sobre la siguiente caja de la lista ordenada.
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces, si encontramos alg�n n�mero mayor a 'a', significa que nuestro nuevo
        valor debe agregarse una posici�n antes de este n�mero mayor con el que nos encontramos.
        */
        else{
            encontrado = NO; //Se indica que 'a' no ha sido encontrado.
            if(principio == p){ //Si el primer elemento que checamos result� ser mayor, entonces significa que 'a' debe agregarse al principio.
                donde = PRINCIPIO;
            }
            else{ //Si no lo encontramos al principio, entonces forzosamente debe de agregarse en alg�n lugar enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
    }
    /*
    Si el ciclo se acaba y se recorre toda la lista sin encontrar ning�n n�mero mayor, entonces significa que el n�mero que queremos
    encontrar es mayor a todos los que existen dentro de la lista ordenada; por lo tanto, no ha sido encontrado y debe agregarse al final.
    */
    encontrado = NO;
    donde = FINAL;
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Ord_MuchaRepeticion::agregar(int a){
    caja2 *p; //Puntero tipo caja2 con el que introduciremos a 'a' a  la estructura.
    buscar(a); //Se busca la caja

    //Si no se encuentra el valor, entonces se crea una caja para introducir a 'a'
    if(encontrado == NO){
        p = new caja2; //Se crea una nueva caja2
        p -> valor = a; //Se introduce el valor a la caja.
        p -> n = 1; //El n�mero que se ha repetido 'a' hasta entonces ser� de 1.
        /*
        Si la lista ordenada est� vacia, entonces el puntero '*siguiente' de la caja ser� NULL (porque despu�s de esta cajita no existir�
        otra) y el puntero '*principio' tomar� la direcci�n de esta caja que hemos agregado.
        */
        if(donde == VACIO){
            p -> siguiente = NULL;
            principio = p;
        }
        /*
        Si se debe agregar al principio, entonces el puntero '*siguiente' de la caja apuntar� hacia el valor que, hasta el momento,
        estaba al principio de la estructura; como hemos agregadoa un valor antes del primer elemento de la lista, entonces el puntero
        '*principio' se recorre hacia atr�s y tomar� la direcci�n del elemento que reci�n hemos agregado.
        */
        else if(donde == PRINCIPIO){
            p -> siguiente = principio;
            principio = p;
        }
        /*
        Si no se agregar� al principio, entonces se agregar� enmedio (tambi�n funciona para agregar al final); para esto los puntero
        se "puentean" de la siguiente manera:
        */
        else{
            p -> siguiente = anterior -> siguiente; //En caso de agregar al final, p -> sigunete ser� NULL.
            anterior -> siguiente = p;
        }
    }

    //Si ya exist�a una caja con el valor de 'a', entonces nadam�s se le incrementar� en 1 el contador de repeticiones a dicha caja.
    else{
        if(donde == PRINCIPIO){
            principio -> n++;
        }
        else{
            anterior -> siguiente -> n++;
        }
    }

    cuantos++; //Se incrementa el contador de datos.
    return(1); //Se regresa un 1 porque 'a' s� pudo ser agregado.
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Ord_MuchaRepeticion::borrar(int a){
    caja2 *p; //Apuntador tipo caja2.
    buscar(a); //Se busca el dato 'a'.

    //Si no se encuentra, entonces no puede eliminarse y se regresa un cero.
    if(encontrado == NO) return(0);

    //Si se encuentra al principio, entonces '*p' se sit�a en el primer elemento de la lista.
    if(donde == PRINCIPIO){
        p = principio;
        if(p -> n > 1) p -> n--; //Si existe m�s de una vez en la lista, entonces s�lo se decrementa en 1 el contador de repeticiones de 'a'.
        else{ //Si el contador es = 1 significa que 'a' �nicamente existe una vez dentro de la lista ordenada; por lo tanto, se elimina toda la caja.
            principio = p -> siguiente; //Se recorre el apuntador '*princip�o' a la siguiente caja.
            delete(p);
        }
    }
    else{
        p = anterior -> siguiente; //Se utiliza el puntero '*anterior' para colocarse sobre el la cajita que nos interesa.
        if(p -> n > 1) p -> n--; //Si existe m�s de una vez, entonces s�lo se decrementa el contador de ocurrencias.
        else{ //Si s�lo existe una vez, entonces se puentean los punteros para eliminar toda la caja.
            anterior -> siguiente = p -> siguiente;
            delete(p);
        }
    }
    cuantos --; //Se decrementa el contador de datos de la lista.
    return(1); //Se regresa un 1 porque el dato pudo ser elminado.
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo imprime los datos que se encuentran dentro de la lista ordenada.
void lista_Ord_MuchaRepeticion::pintar(){
    caja2 *p; //Puntero con el que recorreremos la lista.
    p = principio; //Nos colocamos al principio de la estructura.

    while(p){ //Se recorre la estructura leyendo el contador de ocurrencias de cada caja.
        for(int i = 0 ; i < p -> n; i++){
            cout << p -> valor << ", ";
        }
        p = p -> siguiente; //'*p' se recorre al siguiente dato.
    }
    cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Este m�todo regresa el n�mero de datos que existen dentro de la lista ordenada.
int lista_Ord_MuchaRepeticion::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//El destructor libera la memoria usada por los datos de la lista y resetea los atributos de la clase.
lista_Ord_MuchaRepeticion::~lista_Ord_MuchaRepeticion(){
    caja2 *p;
    p = principio;

    while(p){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    anterior = principio = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;

}
/****************************************************************************************************************************************************/
/*
    Esta clase representa una lista ordenada doble; es decir, que puede recorrerse de principio a fin y viceversa.
    Los datos se guardan de menor a mayor dentro de la estructura.

    *ATRIBUTOS*
    -El puntero '*principio' almacena la direcci�n en donde comienza la lista ordenada.
    -El puntero '*anterior' almacena la direcci�n de la caja anterior a la que
     estamos, nos ayudar� al momento de recorrer la estructura y realizar cambios en ella.
    -El puntero '*fin' almacena la direcci�n en donde termina la estructura.
    -La variable 'cuantos' indica la cantidad de datos que existen dentro de la pila.
    -La variable 'Encontrado' nos indica si alg�n elemento que estemos buscando existe
     dentro de la lista ordenada.
    -La variable 'donde' nos indica en donde se encuentra alg�n elemento que busquemos.

    *M�TODOS*
    -El constructor inicializa los punteros: '*principio', '*anterior'; y las varianbles
     'cuantos', 'encontrado', 'donde'.
    -El destructor libera la memoria utilizada por la lista ordenada y resetea los valores
     de los atributos.
    -buscar(int a): Busca el valor 'a' dentro de la lista ordenada.
    -agregar(int a): Agrega un n�mero entero a la pila.
    -borrar(): Elimina de la lista ordenada alg�n dato.
    -pintar_principio(): Imprime en pantalla el contenido de la lista ordenada de principio a fin (datos de menor a mayor).
    -pintar_final(): Imprime en pantalla el contenido de la lista ordenada de fin a principio (datos de mayor a menor).
    -Cuantos(): Regresa el valor de la variable 'cuantos' que indica el n�mero de elemtnos
     que se encuentran dentro de la lista.
*/
class lista_Doble{
    private:
        caja3 *anterior, *principio, *fin;
        int encontrado;
        int donde;
        enum encontrado{SI, NO};
        enum donde{PRINCIPIO, ENMEDIO, FINAL};
        int cuantos;

    public:
        lista_Doble();
        ~lista_Doble();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar_principio();
        void pintar_final();
        int Cuantos();

};
//----------------------------------------------------------------------------------------------------------------------------------------------------
//El constrructor inicializa los atributos.
lista_Doble::lista_Doble(){
    anterior = principio = fin = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void lista_Doble::buscar(int a){
    caja3 *p; //Puntero tipo caja2 que recorrer� la estructura.

    //Si la estructura est� vac�a entonces se indica que el dato no se encontr� y que la lista est� vacia.
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    //Si la lista no est� vac�a, entonces se comenzar� a recorrer desde el principio hasta el final.
    p = principio;
    while(p){

        //Si se encuentra el dato, entonces la variable encontrado toma el valor de SI.
        if(p -> valor == a){
            encontrado = SI;
            if(p == principio){ //Si se encuentra al principio, entonces donde = PRINCIPIO.
                donde = PRINCIPIO;
            }else if(p -> siguiente == NULL){ //Si la siguiente direcci�n es NULL, entonces significa que estamos en el final de la lista.
                donde = FINAL;
             }
             else{ //Si no estamos al principio ni al final de la lista ordenada, entonces encontramos el n�mero enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces si encontramos alg�n n�mero menor a 'a', simplemente seguimos recorriendo
        la estructura.
        */
        else if(p -> valor < a){
            encontrado = NO; //Se indica que no se ha encontrado a�n.
            anterior = p; //El puntero '*anterior' toma el valor de la direcci�n en donde nos encontramos.
            p = p -> siguiente; //Finalmente p se pone sobre la siguiente caja de la lista ordenada.
        }
        /*
        Como estamos ordenando n�meros de menor a mayor, entonces, si encontramos alg�n n�mero mayor a 'a', significa que nuestro nuevo
        valor debe agregarse una posici�n antes de este n�mero mayor con el que nos encontramos.
        */
        else{
            encontrado = NO; //Se indica que 'a' no ha sido encontrado.
            if(principio == p){ //Si el primer elemento que checamos result� ser mayor, entonces significa que 'a' debe agregarse al principio.
                donde = PRINCIPIO;
            }
            else{ //Si no lo encontramos al principio, entonces forzosamente debe de agregarse en alg�n lugar enmedio de la estructura.
                donde = ENMEDIO;
            }
            return;
        }
    }
    /*
    Si el ciclo se acaba y se recorre toda la lista sin encontrar ning�n n�mero mayor, entonces significa que el n�mero que queremos
    encontrar es mayor a todos los que existen dentro de la lista ordenada; por lo tanto, no ha sido encontrado y debe agregarse al final.
    */
    encontrado = NO;
    donde = FINAL;
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Doble::agregar(int a){
    caja3 *p; //Puntero tipo caja3 donde guardaremos el valor a agregar.
    buscar(a); //Se busca 'a'.

    p = new caja3; //Se crea una nueva caja3.
    p -> valor = a; //Se introduce el valor de 'a' a la caja.

    /*
    Si la lista est� vac�a, entonces los dos punteros de la caja son NULL (porque no existe nada antes ni despu�s de �ste elemento).
    Este primer elemento tambi�n representar� el principio y el fin de la lista, por eso principio = fin  = p.
    */

    if(donde == VACIO){
        p -> siguiente = NULL;
        p -> antes = NULL;
        principio = p;
        fin = p;
    }
    /*
    Si se debe agregar al principio, entonces '*siguiente' de la caja que agregaremos apuntar� al elemento que antes era el principio;
    el '*anterior' de la cajita a agregar ser� NULL (No habr� elemnto antes que el primero de la lista). Se conecta el puntero '*anterior'
    del siguiente dato con la cajita que hemos agregado. El puntero '*principio' toma tambi�n el valor de p.
    */
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        p -> antes = NULL;
        ( p -> siguiente ) -> antes = p;
        principio = p;
    }
    /*
    Si se debe agregar al final, entonces '*siguiente' de la caja que agregaremos debe ser NULL (no existe ning�n elemento despu�s del �ltimo).
    '*antes' de la caja que agregaremos deber� apuntar al que antes era el �ltimo elemento de la lista (*fin). Se conecta el puntero '*siguiente'
    de la caja que antes era la �ltima con la nueva caja. El puntero '*fin' toma el valor de p.
    */
    else if(donde == FINAL){
        p -> siguiente = NULL;
        p -> antes = fin;
        (p -> antes) -> siguiente = p;
        fin = p;
    }
    /*
    Si se agrega enmedio de la lista, entonces se puentean los punteros usando la direcci�n '*anterior'
    */
    else{
        p -> siguiente = anterior -> siguiente;
        p -> antes = anterior;
        (p -> siguiente) -> antes = p;
        anterior -> siguiente = p;
    }
    cuantos ++; //Se incrementa el n�mero de datos que e
    return(1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Doble::borrar(int a){
    caja3 *p;
    buscar(a);
    if(encontrado == NO) return(0);

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
    cuantos--;
    delete(p);
    return(1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void lista_Doble::pintar_principio(){
    caja3 *p;
    p = principio;

    while(p){
        std::cout << p -> valor << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}


//----------------------------------------------------------------------------------------------------------------------------------------------------

void lista_Doble::pintar_final(){
    caja3 *p;
    p = fin;

    while(p){
        cout << p -> valor << ", ";
        p = p -> antes;
    }
    cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Doble::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

lista_Doble::~lista_Doble(){
    caja3 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    anterior = principio = fin = NULL;
    cuantos = 0;
    encontrado = NO;
    donde = VACIO;

}

/****************************************************************************************************************************************************/

class lista_Doble_ConMitad{
    private:
        caja3 *anterior, *principio, *mitad, *fin;
        int encontrado;
        int donde;
        enum encontrado{SI, NO};
        enum donde{PRINCIPIO,MITAD,  ENMEDIO, FINAL};
        int mayores;
        int menores;
        int cuantos;

    public:
        lista_Doble_ConMitad();
        ~lista_Doble_ConMitad();
        void buscar(int a);
        int agregar(int a);
        void pintar_ascendente();
        void pintar_descendente();
        int Cuantos();
        int valorMitad();
        int Mayores();
        int Menores();
        int Principio();
        int Final();
};
//----------------------------------------------------------------------------------------------------------------------------------------------------

lista_Doble_ConMitad::lista_Doble_ConMitad(){
    anterior = principio = mitad = fin = NULL;
    encontrado = NO;
    donde = VACIO;
    mayores = 0;
    menores = 0;
    cuantos = 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

void lista_Doble_ConMitad::buscar(int a){
    caja3 *p;
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    if(a < (mitad -> valor)){
        p = principio;
    }
    else if(a > (mitad -> valor)){
        p = mitad;
    }

    if(p == principio){

        if(principio == mitad){
            if(a < mitad -> valor){
                encontrado = NO;
                donde = PRINCIPIO;
                menores++;
                return;
            }
            if (a > mitad -> valor){
                encontrado = NO;
                donde = FINAL;
                mayores++;
                return;
            }
        }
        else{
            while(mitad -> siguiente != p){
                if(p -> valor == a){
                    encontrado = SI;
                    if(p == principio){
                        donde = PRINCIPIO;
                    }
                    else if(p == mitad){
                        donde = MITAD;
                    }
                    else{
                        donde = ENMEDIO;
                    }
                    return;
                }

                if(p -> valor < a){
                    encontrado = NO;
                    anterior = p;
                    p = p -> siguiente;
                }

                if(p -> valor > a){
                    encontrado = NO;
                    if(p == principio){
                        donde = PRINCIPIO;
                    }
                    else{
                        donde = ENMEDIO;
                    }
                    menores ++;
                    return;
                }
            }
            encontrado = NO;
            donde = ENMEDIO;
            menores ++;
            return;
        }
    }

    if(mitad == p){
        while(p != NULL){

            if(p -> valor == a){
                encontrado = SI;
                return;
            }

            else if(p -> valor < a){
                encontrado = NO;
                anterior = p;
                p = p -> siguiente;
            }
            else{
                encontrado = NO;
                donde = ENMEDIO;
                mayores++;
                return;
            }
        }
        encontrado = NO;
        donde = FINAL;
        mayores++;
        return;
    }

}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Doble_ConMitad::agregar(int a){
    caja3 *p;
    buscar(a);
    if(encontrado == SI) return(0);

    p = new caja3;
    p -> valor = a;

    if(donde == VACIO){
        p -> antes = NULL;
        p -> siguiente = NULL;
        principio = fin = mitad = p;
    }
    else if(donde == PRINCIPIO){
        p -> antes = NULL;
        p -> siguiente = principio;
        principio = p;
        (p -> siguiente) -> antes = p;
    }
    else if(donde == ENMEDIO){
        p -> siguiente = anterior -> siguiente;
        p -> antes = anterior;
        anterior -> siguiente = p;
        (p -> siguiente) -> antes = p;
    }
    else{
        p -> siguiente = NULL;
        p -> antes = fin;
        fin = p;
        (p -> antes) -> siguiente = p;
    }

    if(mayores == (menores - 2) ){
        mitad = mitad -> antes;
        menores--;
        mayores++;
    }

    if(mayores == (menores + 1)){
        mitad = mitad -> siguiente;
        mayores--;
        menores++;
    }


    cuantos++;
    return(1);

}
void lista_Doble_ConMitad::pintar_ascendente(){
    caja3 *p;
    p = principio;

    while(p){
        std::cout << p -> valor << ", ";
        p = p -> siguiente;
    }
    std::cout << "\b\b ";
}


//----------------------------------------------------------------------------------------------------------------------------------------------------

void lista_Doble_ConMitad::pintar_descendente(){
    caja3 *p;
    p = fin;

    while(p){
        cout << p -> valor << ", ";
        p = p -> antes;
    }
    cout << "\b\b ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

int lista_Doble_ConMitad::Cuantos(){
    return(cuantos);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int lista_Doble_ConMitad::valorMitad(){
    return(mitad -> valor);
}

int lista_Doble_ConMitad::Mayores(){
    return(mayores);
}

int lista_Doble_ConMitad::Menores(){
    return(menores);
}

int lista_Doble_ConMitad::Principio(){
    return(principio -> valor);
}
int lista_Doble_ConMitad::Final(){
    return(fin -> valor);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
lista_Doble_ConMitad::~lista_Doble_ConMitad(){
    caja3 *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    anterior = principio = mitad = fin = NULL;
    cuantos = 0;
    mayores = 0;
    menores = 0;
    encontrado = NO;
    donde = VACIO;

}


#endif // ESTRUCTURASDEDATOS_H_INCLUDED
