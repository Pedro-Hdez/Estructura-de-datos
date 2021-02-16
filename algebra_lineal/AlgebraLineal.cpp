/*
    Nombre: AlgebraLineal.cpp
    Autor: Pedro Andr�s Hern�ndez Amador.
    Fecha: enero del 2019

    Descripci�n: Archivo de implementaci�n que contiene los cuerpos de las
                 funciones que realizan operaciones con vectores y matrices.
*/

#include <cstdlib>
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

/*
    Esta subrutina calcula la suma de 2 vectores.
    La direcci�n de los vectores que se suman est�n
    en p1 y q1; el resultado en r1. El tama�o de los
    vectores es n.
    La funci�n se llama con la instrucci�n:
    SumaVectores(p, q, r, n)
*/
void SumaVector(int *p1, int *q1, int *r1, int n){
    int *p11, *q11, *r11; //Copias de las direcciones
    int i; //Contador.
    p11 = p1; q11 = q1; r11 = r1; //se inicializan las copias de las direcciones.

    //Se copia la informaci�n al vector que guardar� el resultado.
    for (i = 0; i < n; p11++, q11++, r11++, i++){
        *r11 = *(p11) + *(q11); //Se suma componente a componente.
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la resta de 2 vectores.
    La direcci�n de los vectores que se suman est�n
    en p1 y q1; el resultado en r1. El tama�o de los
    vectores es n.
    La funci�n se llama con la instrucci�n:
    SumaVectores(p, q, r, n)
*/
void RestaVector(int *p1, int *q1, int *r1, int n){
    int *p11, *q11, *r11; //Copias de las direcciones
    int i; //Contador
    p11 = p1; q11 = q1; r11 = r1; //Se inicializan las copias de las direcciones

    //Se copia la informaci�n al vector que guardar� el resultado.
    for (i = 0; i < n; p11++, q11++, r11++, i++){
        *r11 = *(p11) - *(q11); //Se resta componente a componente.
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula el producto punto entre 2 vectores.
    La direcci�n de los vectores est�n en p1 y q1; n es el
    tama�o de los vectores. El valor regresado es el resultado
    de esta operaci�n.
    La funci�n se llama con la instrucci�n:
    ProductoPunto(p, q, n)
*/
float ProductoPunto(float *p1, float *q1, float n){
    float *p11, *q11, resultado; //Copias de las direcciones originales y variable que almacena el resultado.
    float i; //Contador
    p11 = p1; q11 = q1; resultado = 0; //Se copian las direcciones. El resultado se inicializa en cero.

    //Se multiplica componente a componente de los vectores y la suma se va almacenando en la variable resultado.
    for (i = 0; i < n; p11++, q11++, i++){
        resultado += (*p11) * (*q11);
    }

    return resultado; //Se devuelve el resultado de la operaci�n.
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la longitud de un vector.
    La direcci�n del vector est� en p1, n es el
    tama�o del vector. El valor regresado es el resultado
    de esta operaci�n.
    La funci�n se llama con la instrucci�n:
    NormaVector(p, n)
*/
float NormaVector(float *p1, float n){
    float *p11; //Copia de la direcci�n del vector.
    float resultado; //Variable que almacenar� el resultado.
    p11 = p1; resultado = 0; //Se copia la direcci�n y el resultado se inicializa en cero.

    //Se almacena la suma de los cuadrados de cada componente del vector.
    for(int i = 0 ; i < n ; p11++, i++){
        resultado += (*p11)*(*p11);
    }

    //Se devuelve el resultado de la operaci�n; es decir, la ra�z de la suma de las componentes al cuadrado.
    return sqrt(resultado);
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula el �ngulo entre 2 vectores.
    La direcci�n de los vectores est�n en p1 y q1; n es el
    tama�o de los vectores. El valor regresado es el resultado
    de esta operaci�n.
    La funci�n se llama con la instrucci�n:
    AnguloVectores(p, q, n)
*/
float AnguloVectores(float *p1, float *q1, int n){
    float *p11, *q11; //Copia de la direcci�n de los vectores.
    p11 = p1; q11 = q1; //Se copian las direcciones de los vectores.

    //Se regresa el coseno inverso del producto punto dividido entre el producto de las normas de los vectores.
    return acos( ProductoPunto(p11, q11, n) / ( NormaVector(p11, n) * NormaVector(q11, n)));
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina imprime un vector con n�meros reales como componentes. La direcci�n de �ste
    est� en p1 y n es su tama�o. La funci�n se llama con la instrucci�n:
    ImprimeVector(p, n)
*/
void ImprimeVector(float *p1, int n){
    float *p11; //Copia de la direcci�n del vector.
    p11 = p1; // se copia la

    for (int i = 0 ; i < n ; p11++, i++){
        cout << *p11 << ", ";
    }
    cout << "\b\b ";
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina imprime una matriz. La direcci�n del primer
    elemento de la matriz est� en p1; m es el n�mero de renglones
    y n es el n�mero de columnas.
    La funci�n se llama con la instrucci�n:
    ImprimeMatriz(p, m, n)
*/
void ImprimeMatriz(float *p1, int m, int n){
    float *p11; //Copia de la direcci�n de la matriz.
    int i, j; //Contadores
    p11 = p1; //Se copia la direcci�n en donde comienza la matriz.

    for (i = 0 ; i < m ; i++){ //Ciclo que gestiona los renglones

        for (j = 0 ; j < n; j++, p11++){ //Ciclo que gestiona las columnas.

            cout << *p11 << " "; //Se imprime cada elemento del rengl�n j.
        }

        //Despu�s de imprimir cada rengl�n se da un salto de l�nea para continuar imprimiendo el siguiente rengl�n.
        cout << endl;
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina suma dos matrices A[m][n] y B[m][n], el resultado
    se guarda en la matriz C[m][n]. La direcci�n del primer elemento
    de A se encuentra en p1, la direcci�n del primer elemento de
    B se encuentra en q1, la direcci�n del primer elemento de
    C est� en r1. m y n son el n�mero de renglones y columnas de
    las matrices respectivamente.
    La funci�n se llama con la instrucci�n:
    SumaMatrices(&A[0][0], &B[0][0], &C[0][0], m, n)
*/
void SumaMatrices(float *p1, float *q1, float *r1, int m, int n){
    float *p11, *q11, *r11; //Copia de las direcciones de las matrices.
    p11 = p1; q11 = q1, r11 = r1; //Se copian las direcciones.

    //Se suman componente a componente las matrices A y B.
    for (int i = 0; i < m*n ; i++, p11++, q11++, r11++){
        *r11 = *p11 + *q11;
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina resta dos matrices A[m][n] y B[m][n]; el resultado
    se guarda en la matriz C[m][n]. La direcci�n del primer elemento
    de A se encuentra en p1, la direcci�n del primer elemento de
    B se encuentra en q1, la direcci�n del primer elemento de
    C est� en r1. m y n son el n�mero de renglones y columnas de
    las matrices respectivamente.
    La funci�n se llama con la instrucci�n:
    SumaMatrices(&A[0][0], &B[0][0], &C[0][0], m, n)
*/
void RestaMatrices(float *p1, float *q1, float *r1, float m, float n){
    float *p11, *q11, *r11; //Copias de las direcciones de las matrices.
    p11 = p1; q11 = q1, r11 = r1; //Se copian las direcciones.

    //Se restan componente a componente las matrices A y B.
    for (int i = 0; i < m*n ; i++, p11++, q11++, r11++){
        *r11 = *p11 - *q11;
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n]
    por un vector B[n], el resultado se guarda en C[m]. La direcci�n
    del primer elemento de A se guarda en p1, la direcci�n del primer
    elemento de B se guarda en q1 y la direcci�n del primer elemento de
    C se guarda en r1. m y n son el n�mero de renglones y columnas
    respectivamente de la matriz A.
    La funci�n se llama con la siguiente instrucci�n:
    ProductoMatrizVector(&A[0][0], B, C, m, n)
*/
void ProductoMatrizVector(float *p1, float *q1, float *r1, int m, int n){

    //Copias de las direcciones de la matriz y los vectores y variable que almacenar� el resultado.
    float *p11, *q11, *r11, resultado;
    int i,j; //Contadores
    p11 = p1; q11 = q1; r11 = r1; //Se copian las direcciones.

    //Como el resultado de ejecuta barriendo rengl�n por rengl�n de la matriz, entonces �ste se efectuar� m veces.
    for (i = 0 ; i < m ; i++, r11++){
        resultado = 0; //El resultado se inicializa en cero cada vez que se cambia de rengl�n.

        //En cada iteraci�n el apuntador del vector se inicializa en el primer elemento de �ste porque se barrer�
        //completamente de arriba hacia abajo.
        q11 = q1;

        //Como se multiplicar� cada elemento del rengl�n de la matriz por cada elemento del vector, entonces este
        //proceso se repetir� n veces pues cada rengl�n de la matriz y el vector tienen n componentes.
        for (j = 0 ; j < n ; j++, p11 ++, q11++){
            resultado += (*p11) * (*q11); //Se acumula la suma de cada multiplicaci�n componente a componente.
        }

        *r11 = resultado; //Se coloca el resultado en la posici�n correpondiente en la matriz resultado.
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n].
    La direcci�n del prmier elemento de A se guarda en p1; esc es el n�mero escalar por
    el cu�l se multiplicar� la matriz; m y n son el n�mero de columnas y
    renglones respectivamente de las matrices A y B.
    La funci�n se llama con la siguiente instrucci�n:
    ProductoMatrizEscalar(&A[0][0], esc, m, n)
*/
void ProductoMatrizEscalar(float *p1, float esc, int m, int n){
    float *p11; //Copia de la matriz.
    p11 = p1;; //Se copia la direcci�n de la matriz.

    //Cada elemento se la matriz A se multiplica por el escalar.
    for (int i = 0; i < m*n ; i++, p11++){
        *p11 = (*p11) * esc;
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n]
    y una matriz  B[m][k], el resultado se guarda en C[m][k]. La direcci�n
    del primer elemento de A se guarda en p1, la direcci�n del primer
    elemento de B se guarda en q1 y la direcci�n del primer elemento de
    C se guarda en r1. m es el n�mero de renglones de las matrices A y C,
    n es el n�mero de columnas de A y k es el n�mero de columnas de las
    matrices B y C.
    La funci�n se llama con la siguiente instrucci�n:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProductoMatrices(float *p1, float *q1, float *r1, int m, int n, int k){
    //Copias de las direcciones de las matrices y variable que guardar� los resultados de las multiplicaciones.
    float *p11, *q11, *r11, resultado;
    int i, j, l; //Contadores.
    r11 = r1; //Se copia la direcci�n de la matriz resultado C.

    //El primer for controla el recorrido de los renglones de A (A cuenta con m renglones). Recordemos que se multiplica
    //cada rengl�n de A por TODAS las columnas de B.
    for(i = 0 ; i < m ; i++ ){

        /*El segundo for controla el recorrido sobre cada columna de la matriz B (cuenta con k columnas). Cuando un rengl�n de A
          se termina de multiplicar por una columna de B, entonces se obtiene una componente de la matriz resultado C. Por esta
          �ltima raz�n el apuntador de C (r11) se mueve de 1 en 1 sobre sus renglones.
        */
        for(j = 0 ; j < k ; j++, r11++){
            resultado = 0; //El resultado se inicializa en cero.

            /*
            La primera vez que se ejecute este segmento se multiplicar� el PRIMER renglon de A por la PRIMER columna de B
            y se calcular� la primer componente de la matriz resultado; la segunda vez, se multiplicar� el PRIMER rengl�n de A
            por la SEGUNDA columna de B y se calcular� la segunda componente de la matriz resultado y as� sucesivamente hasta
            barrer todas las columnas de B habiendo calculado todas las componentes del primer rengl�n de la matriz resultado.
            Luego, este ciclo se acaba y el contador i aumentar�. La segunda vez que se ingrese a este ciclo se tomar� el segundo
            rengl�n de A y el procedimiento se volver� a repetir calculando todas las componentes del segundo rengl�n de la matriz
            resultado y as� hasta terminar. Por eso, el apuntador de la matriz A se mover� de la forma: p11 = p1 + (n*i), esto
            garantiza que el apuntador caiga en el inicio del rengl�n con el que se est� trabajando para barrer todas las columnas de B.
            A su vez, el apuntador de B se mover� de la forma q11 = q1 + j porque debe situarse en el inicio de cada columna de la matriz B
            en cada iteraci�n.
            */
            p11 = p1+(n*i);
            q11 = q1 +j;

            /*
            Este ciclo calcula la multiplicaci�n del rengl�n en cuesti�n de A por la columna en cuesti�n de B.
            El apuntador de A (p11) dar� saltos de 1 en 1 porque recorrer� todas las componentes de este rengl�n.
            El apuntador de B (q11) dar� saltos de k en k porque en B se recorrer� columna por columna.
            */
            for (l = 0 ; l < n ; l++, p11++, q11 += k){
                resultado += (*p11) * (*q11); //En la variable resultado se almacena la suma de las multiplicaciones realizadas.
            }

            *r11 = resultado; //Se pone el resultado donde conrresponde en la matriz

            ImprimeMatriz(r1, m, k);
            cout << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n] y una matriz  B[m][k],
    el resultado se guarda en C[m][k]. La matriz resultante se llena de columna en columna
    y de izquierda a derecha. La direcci�n del primer elemento de A se guarda en p1, la direcci�n
    del primer elemento de B se guarda en q1 y la direcci�n del primer elemento de C se guarda en r1.
    m es el n�mero de renglones de las matrices A y C, n es el n�mero de columnas de A y k es el n�mero
    de columnas de las matrices B y C. La funci�n se llama con la siguiente instrucci�n:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatCol_IzqDer(float *p1, float *q1, float *r1, int m, int n, int k){
    float *p11, *q11, *r11, resultado;
    int i, j, l;

    /*
    El primer for va desde 0 a k porque se calcular� columna por columna del resultado
    de izquierda a derecha.
    */
    for(i = 0 ; i < k ; ++i){
        /*
        Las columnas del resultado siempre se van a calcular desde su primer elemento.
        Por eso cada vez que inicia el c�lculo de una nueva columna el apuntador r11
        se coloca en la "cabeza" de �sta.
        */
        r11 = r1 + i;
        /*
        El segundo for va desde 0 a m porque va a efectuar la multiplicaci�n de
        cada renglon de A (A tiene m renglones) por TODAS las columnas de B. El apuntador r11 (matriz resultante)dar� saltos de tama�o
        k porque recordemos que esta matriz se llenar� columna por columna.
        */
        for(j = 0 ; j < m ; j++, r11 += k){
            /*
            Siempre que se comienza a calcular una componente del resultado, la variable que
            lo va almacenando se debe inicializar en cero.
            */
            resultado = 0;

            /*
            La primera vez que se ejecute este ciclo de va a calcular el producto del PRIMER rengl�n de A por la PRIMER columna de B;
            la segunda vez, se va a multiplicar el SEGUNDO rengl�n de A por la PRIMER columna de B y as� sucesivamente hasta calcular
            toda la primer columna del resultado (matriz C), entonces se terminar� este segmento y el for exterior har� la segunda corrida
            donde ahora se tomar� la segunda columna de la matriz B. Entonces el apuntador de A se mover� de la manera p11 = p1 + (n*j) porque
            cada vez que se ejecute el ciclo saltar� n espacios, es decir, se acomodar� en el siguiente rengl�n de A. A su vez, el apuntador de B
            se mover�: q11 = q1 + i porque siempre comenzar� en la "cabeza" de la columna en turno.
            */
            p11 = p1 + (n*j);
            q11 = q1 + i;

            /*
            El tercer for va de 0 a n porque cada rengl�n de A y cada columna de B tiene n elementos.
            p11 se mover� de uno en uno (componente por componente del rengl�n de la matriz A) y q11
            se mover� de k en k (componente por componente de la columna de la matriz B).
            */
            for(l = 0 ; l < n ; l++, p11++, q11 += k){
                //Se va acumulando el resultado de las multiplicaciones de los componentes.
                resultado += (*p11) * (*q11);
            }
            //Se coloca el resultado en su correspondiente lugar en la matriz resultante.
            *r11 = resultado;
            //Se imprime toda la matriz resultante para apreciar el proceso de llenado por columnas.
            ImprimeMatriz(r1, m, k);
            cout << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n] y una matriz  B[m][k], el resultado se guarda en C[m][k].
    La matriz resultante se llena rengl�n por rengl�n comenzando desde el final hacia el primer elemento. (Se llena al rev�s
    que la multiplicaci�n convencional). La direcci�n del primer elemento de A se guarda en p1, la direcci�n del primer elemento
    de B se guarda en q1 y la direcci�n del primer elemento de C se guarda en r1. m es el n�mero de renglones de las matrices A
    y C, n es el n�mero de columnas de A y k es el n�mero de columnas de las matrices B y C. La funci�n se llama con la siguiente
    instrucci�n:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatRen_Abajo_y_DerIzq(float *p1, float *q1, float *r1, int m, int n, int k){
    float *p11, *q11, *r11, resultado; //Copias de las direcciones de las matrices y variable que almacenar� los resultados.
    int  i, j, l; //Contadores.

    /*
    Como la matriz resultante se llenar� desde el final hacia el principio, entonces al iniciar con el algoritmo su apuntador
    se posiciona en el �ltimo elemento de �sta.
    */
    r11 = r1 + (m*k) - 1;

    /*
    El primer for va desde (m-1) hasta 0 porque la multiplicaci�n se va a efectuar
    desde el �ltimo rengl�n y �ltimo elemento de la matriz A.
    */
    for(i = (m-1) ; i >= 0; i--){

        /*
        El segundo for va desde 0 a k porque el resultado se calcular� rengl�n por
        rengl�n, y cada rengl�n de la matriz resultante (C) cuenta con k elementos.
        El apuntador de la matriz resultante r11 ir� decreciendo en uno porque
        la matriz se llenar� desde atr�s iniciando con el �ltimo componente de �sta y
        finalizando el algoritmo en la primer componente de la misma matriz.
        */
        for(j = 0 ; j < k ; j++ , r11--){

            //Se inicializa en cero la variable que almacenar� los productos entre componentes.
            resultado = 0;

            /*
            El apuntador de la matriz A al principio se colocar� en el �ltimo rengl�n de abajo e ir�
            subiendo uno por uno hasta llegar al primero de arriba.
            */
            p11 = p1 + (n*i);
            /*
            El apuntador de la matriz B se colocar� en la �ltima columna e ir� barri�ndolas
            hacia atr�s hasta llegar a la primera de la izquierda.
            */
            q11 = q1 + (k-1-j);

            /*
            El tercer for ir� de 0 a n porque se multiplicar�n los renglones de la matriz A por
            las columnas de la matriz B y ambos cuentan con n componentes.
            El apuntador de la matriz A (p11) dar� saltos de uno en uno pues barrer� cada componente del rengl�n;
            el apuntador de la matriz B (q11) dar� saltos de k en k pues barrer� cada componente de la columna.
            */
            for(l = 0 ; l < n ; l++, p11++, q11 += k){

                //Se va acumulando el resultado de los productos en la variable auxiliar.
                resultado += (*p11) * (*q11);
            }
            /*
            Se coloca el resultado obtenido con los productos entre componentes de renglones de A
            y columnas de B en el lugar que le corresponde (Estos resultados se ir�n acomodando de
            derecha a izquierda comenzando con el �ltimo componente de la matriz y terminando en
            el primer elemento de la misma matriz.)
            */
            *r11 = resultado;

            //Se imprime toda la matriz para ilustrar el proceso de llenado de la matriz resultante.
            ImprimeMatriz(r1, m, k);
            cout << endl << endl;
        }

    }

}
/****************************************************************************************************************************************************/


/********************SISTEMAS DE ECUACIONES LINEALES********************/

/*
Esta funci�n intercambia dos regiones de memoria. En la resoluci�n de sistemas de ecuaciones, esta subrutina nos
ayudar� intercambiando renglones de matrices. La direcci�n del primer rengl�n se encuentra en p, la direcci�n del
segundo rengl�n se encuentra en q, n es el n�mero de elementos con los que cuentan los renglones. La funci�n se llama
con la siguiente instrucci�n:
Intercambiar(p, q, n);
*/
void Intercambiar(float *p, float *q, int n){
    float *p1, *q1, a; //Copia de las direcciones y variable auxiliar.
    int i; //Contador.

    p1 = p; q1 = q; //Se copian las direcciones de los renglones.

    //Se intercambia cada componente usando la variable auxiliar a, para no perder la informaci�n al momento del intercambio.
    for(i = 0 ; i < n ; i++, *p1++, *q1++){
        a = *p1;
        *p1 = *q1;
        *q1 = a;
    }
}
/****************************************************************************************************************************************************/
/*
Esta funci�n divide entre el n�mero pivote todo un rengl�n (o parte de �ste) de una matriz.
La direcci�n del rengl�n se encuentra en p, n es el n�mero de elementos con
los que cuenta el rengl�n. Se regresa el valor del pivote. La subrutina se llama con la instrucci�n:
HacerUno(p, n);
*/
float HacerUno(float *p, int n){
    float *p1, valor; //Copia de la direcci�n y variable que guardar� el valor pivote.
    p1 = p; //Se copia la direcci�n.
    valor = *p1; //El valor pivote es el primer elemento del rengl�n o segmento de rengl�n que se lee.
    *p = 1.00; //El pivote en la matriz original se intercambia por un 1 (para evitar un 0.999...).
    p1++; //Como el lugar del pivote ya es 1, entonces el apuntador se recorre un lugar.

    /*
    A partir de donde se encuentra el apuntador y hasta el final del rengl�n (n) se comienzan a dividir
    los valores que se encuentren en �ste entre el valor del pivote.
    */
    for(int i = 1 ; i < n ; i++, p1++){
        *p1 = *p1 / valor;

    }

    return valor; //Se regresa el valor del pivote para modificar el vector del sistema de ecuaciones lineales.
}
/****************************************************************************************************************************************************/

/*
Esta subrutina divide entre un pivote todas las componentes de un rengl�n de una matriz. Se usar� para modificar la matriz
identidad al momento de calcular una matriz inversa. p es la direcci�n del rengl�n de la matriz identidad, valor es el valor
del pivote, n es el n�mero de elementos con los que cuenta el rengl�n. La funci�n se llama con la siguiente instrucci�n:
HacerUno_Mat(p, valorPivote, n).
*/
void HacerUno_Mat(float*p, float valor, int n){
    float *p1; //Copia de la direcci�n del rengl�n.
    p1 = p; //Se copia la direcci�n del rengl�n.

    //Todos los elementos del rengl�n se dividen entre el valor pivote.
    for(int i = 0; i < n ; i++, p1++){
        *p1 /= valor;
    }
}
/****************************************************************************************************************************************************/
/*
Esta subrutina modifica una regi�n de memoria (rengl�n de la matriz identidad) al momento de hacer ceros debajo del pivote de la matriz original
al buscar una matriz inversa. Deberemos aplicar la misma operaci�n que aplicamos en el rengl�n de la matriz original a todos los dem�s elementos
del rengl�n correspondiente en la matriz identidad. p almacena la direcci�n del "rengl�n de abajo" que nos auxiliar� para modificar el "rengl�n
de arriba" cuya direcci�n se encuentra en q; valor almacena el valor que se utiliz� para lograr un cero en la matriz original. n es el n�mero
de elementos con los que cuenta el rengl�n de la matriz identidad.
*/
void HacerCero_Mat(float*p, float *q, float valor, int n){
    float *p1, *q1; //Copia de las direcciones.
    p1 = p ; q1 = q; //Se copian las direcciones.

    /*
    Se aplica la misma operaci�n que se utiliz� para lograr un cero en la matriz original a cada elemento del rengl�n
    correspondiente de la matriz identidad.
    */
    for(int i = 0; i < n ; i++, p1++, q1++){
        *q1 = *q1 - (valor * (*p1) );
    }
}
/****************************************************************************************************************************************************/

/*
Esta funci�n divide entre el n�mero pivote todo un rengl�n (o parte de �ste) de una matriz pero lo hace de
derecha a izquierda. La direcci�n del rengl�n se encuentra en p, n es el n�mero de elementos con
los que cuenta el rengl�n. Se regresa el valor del pivote, es decir, el n�mero por el cu�l se dividi�
el rengl�n. La subrutina se llama con la instrucci�n:
HacerUno_DerIzq(p, n);
*/
float HacerUno_DerIzq(float *p, int n){
    float *p1, valor; //Copia de la direcci�n y variable que almacenar� el valor del pivote.
    p1 = p; //Se copia la direcci�n.
    valor = *p1; //El valor por el que se dividir� todo el rengl�n se toma del pivote (inicio del rengl�n).
    *p = 1.00; //El pivote se hace directamente el 1 (para evitar el resultado: 0.999...)
    p1--; //El puntero se recorre hacia la izquierda

    //Se divide cada componente del rengl�n entre el valor del pivote hasta que llega al primer elemento del rengl�n.
    for(int i = n ; i > 1 ; i--, p1--){
        *p1 = *p1 / valor;

    }

    return valor;
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de alg�n pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operaci�n a todo el rengl�n en donde el cero se produjo. p es la direcci�n del "rengl�n de arriba"
donde se encuentra el pivote; q es la direcci�n del "rengl�n de abajo" donde se producir� el cero, n es el n�mero de
elementos con el que cuentan los renglones. Se regresa el valor que pertenec�a al elemento que se hizo cero para
usarlo posteriormente en la modificaci�n del vector del sistema de ecuaciones. La funci�n se llama con la sentencia:
HacerCero(p, q, n);
*/
 float HacerCero(float *p, float *q, int n){
    float *p1, *q1, valor; //Copia de las direcciones y variable que almacenar� el valor del elemento que se convertir� en cero.
    p1 = p; q1 = q; //Se copian las direcciones.
    valor = *q1; //Se toma el valor del primer elemento del "rengl�n de abajo" (El que se convertir� en cero).

    //Se aplica la misma operaci�n a todos los elementos del "rengl�n de abajo."
    for(int i = 0 ; i < n ; i++, p1++, q1++){
        *q1 = *q1 -( valor * (*p1) );
    }

    return valor; //Se regresa el valor que pertenec�a al elemento que ahora es cero.
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de alg�n pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operaci�n a todo el rengl�n en donde el cero se produjo. Este procedimiento, en este caso, se
efect�a de derecha a izquierda. p es la direcci�n del "rengl�n de arriba" donde se encuentra el pivote; q es la direcci�n
del "rengl�n de abajo" donde se producir� el cero, n es el n�mero de elementos con el que cuentan los renglones. Se regresa
el valor que pertenec�a al elemento que se hizo cero para usarlo posteriormente en la modificaci�n del vector del sistema de
ecuaciones. La funci�n se llama con la sentencia:
HacerCero_DerIzq(p, q, n);
*/
float HacerCero_DerIzq(float *p, float *q, int n){
    float *p1, *q1, valor;//Copia de las direcciones y variable que almacenar� el valor del elemento que se convertir� en cero.
    p1 = p; q1 = q; //Se copian las direcciones.
    valor = *q1;  //Se toma el valor del primer elemento del "rengl�n de abajo" (El que se convertir� en cero)

    //Se aplica la misma operaci�n a todos los elementos del "rengl�n de abajo" barri�ndolo de derecha a izquierda.
    for(int i = n ; i >= 1 ; i--, p1--, q1--){
        *q1 = *q1 -( valor * (*p1) );
    }

    return valor; //Se regresa el valor que pertenec�a al elemento que ahora es cero.
}
/****************************************************************************************************************************************************/
/*
Esta subrutina se encarga de escalonar una matriz y lograr unos en la diagonal principal; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector,
n es la dimensi�n del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz(&A[0][0], v, n).
*/
void ReducirMatriz(float *p, float *v, int n){
    /*
    valor es la variable que almacenar� el n�mero con el cu�l se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la direcci�n en donde se har�n los 1's; q1 es la direcci�n en donde se har�n
    los 0's, v1 es la direcci�n del vector; pivoteAuxMat y auxVect son apuntadores auxiliares que recorrer�n la matriz y el
    vector respectivamente en busca del pivote m�s grande (pivoteo parcial).
    */
    float *p1, *q1, *v1, valor, *pivoteAuxMat, *auxVect;
    int i, j, k; //Contadores

    //Se copia la direcci�n de la matriz y del vector.
    p1 = p; //Primer pivote.
    v1 = v; //Primer componente del vector afectada.
    /*
    Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y englones se ver�n afectadas. Por eso
    todo el procedimiento general se repetir� n veces. p1 dar� saltos de n+1 porque los pivotes est�n debajo del anterior y un espacio
    m�s a la derecha (diagonal). v1, al ser un vector, dar� saltos de 1 en 1 porque en cada iteraci�n se modificar� una sola componente a la vez:
    primero la primera, despu�s la segunda y as� sucesivamente.
    */
    for(i = 0 ; i < n; i++, p1 += n+1, v1++){

        //PIVOTEO PARCIAL
        pivoteAuxMat = p1 + n; //Se comenzar� a buscar un pivote m�s grande desde justo debajo de donde est� el pivote en turno.
        auxVect = v1 + 1;//De igual manera, el vector ir� siguiendo el movimiento por columnas que el apuntador de la matriz haga.
        /*
        Con este ciclo se recorrer� toda la columna en cuesti�n y todo el vector a la vez en busca de un pivote m�s grande.
        El ciclo se repetir� n -(i+1) porque cada vez habr� una componente menos debajo del pivote por explorar.
        */
        for(k = 0 ; k < n - (i + 1) ; k++, pivoteAuxMat += n, auxVect++){
            /*
            Si se encuentra un pivote m�s grande en la matriz entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se env�a la direcci�n p1 -i y
            pivoteAuxMat -i porque debemos enviar la direcci�n de donde comienza el rengl�n.
            */
            if(*pivoteAuxMat > *p1){
                Intercambiar(p1 - i, pivoteAuxMat - i, n); //Intercambia rengl�n en la matriz.
                Intercambiar(v1, auxVect, 1); //Intercambia componente en el vector
                ImprimeMatriz(p, n, n);
                cout << endl << endl;
                ImprimeVector(v, n);
                cout << endl << endl << endl;
            }
        }
        //SE HACEN LOS UNOS

        /*
        Se hace uno todo el rengl�n del pivote, el valor del pivote se guarda en la variable valor.
        se env�a el tama�o de n-i porque cada vez habr� una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Despu�s, se usa el valor para dividir la componente del vector
        en cuesti�n.
        */
        valor = HacerUno(p1, n-i);
        *v1 /= valor;
        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        // SE HACEN LOS CEROS

        q1 = p1 + n; //El primer cero que se har� en la columna en turno se encuentra debajo del pivote.

        /*
        Con este ciclo se har�n ceros todas las componentes que se encuentren debajo del pivote. Se
        repetir� n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteraci�n del
        procedimiento habr� un cero menos por hacer en las columnas. q1 da ssaltos de n en n porque
        recorrer� toda la columna en turno y har� ceros esos espacios, auxVect dar� saltos de v1 + j + 1
        porque siempre se encontrar� una componente despu�s del espacio que est� en turno (a la altura del
        pivote de la matriz).
        Primero se hace cero la componente debajo del pivote en cuesti�n, se modifica todo ese rengl�n
        y el valor que se encontraba al inicio del rengl�n modificado (el que se hizo cero) se guarda en la variable valor
        para posteriormente modificar el vector de la misma manera que la matriz.
        */
        for( j = 0; j < n - ( i+1 ); j++, q1 += n ){
            valor = HacerCero(p1, q1, n-i);
            auxVect = v1 + j + 1;
            *auxVect = *auxVect - (valor * (*v1));
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(v, n);
            cout << endl << endl << endl;
        }

    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros a la derecha; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector, n es la dimensi�n
del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosAbajoDer(float *p, float *v, int n){
     /*
    valor es la variable que almacenar� el n�mero con el cu�l se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la direcci�n en donde se har�n los 1's; q1 es la direcci�n en donde se har�n
    los 0's, v1 es la direcci�n del vector; auxMat y auxVect son apuntadores auxiliares que recorrer�n la matriz y el
    vector respectivamente en busca del pivote m�s grande (pivoteo parcial).
    */
    float *p1, *q1, *v1,*auxMat, *auxVect, valor;
    int i, j, k; //Contadores


    //El apuntador de la matriz A se inicializa en la "cabeza" de la �ltima columna de la matriz.
    p1 = p + (n-1);
    //Como el apuntador de la matriz se mantiene en el primer rengl�n, entonces el apuntador del vector apunta hacia su primer componente.
    v1 = v;

    /*
    Como el ciclo recorrer� todas las columnas de la matriz haciendo unos y ceros donde corresponda, entonces el ciclo en general se
    ejecutar� n veces, el apuntador p1 (matriz) se ir� escalonando hacia atr�s, por eso dar� saltos de n-1; al hace esto, bajar�
    rengl�n a rengl�n, por lo que el apuntador del vector (v1) ir� sigui�ndolo y se mover� de 1 en 1 por sus componentes hasta llegar
    a la �ltima que corresponde con el �ltimo rengl�n de la matriz.
    */
    for(i = 0 ; i < n; i++, p1 += n-1, v1++){

        //PIVOTAJE PARCIAL

        auxMat = p1+n; //Se comenzar� a buscar un pivote m�s grande desde justo debajo de donde est� el pivote en turno.
        auxVect = v1 + 1; //De igual manera, el vector ir� siguiendo el movimiento por columnas que el apuntador de la matriz haga.

        /*
        Con este ciclo se recorrer� toda la columna en cuesti�n y todo el vector a la vez en busca de un pivote m�s grande.
        El ciclo se repetir� n -(i+1) veces porque cada vez habr� una componente menos debajo del pivote por explorar.
        */
        for(j = 0; j < n-(i+1) ; j++, auxMat += n, auxVect ++){
            /*
            Si se encuentra un pivote m�s grande en la matriz, entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se env�a la direcci�n p1 - n-i-1 y
            pivoteAuxMat - n-i-1 porque debemos enviar la direcci�n de donde comienza el rengl�n.
            */
            if(*auxMat > *p1){
                Intercambiar(p1-(n-i-1), auxMat-(n-i-1), n);
                Intercambiar(v1, auxVect, 1);
                ImprimeMatriz(p, n, n);
                cout << endl << endl;
                ImprimeVector(v, n);
                cout << endl << endl << endl;
            }
        }

        //HACER UNOS

        /*
        Se hace uno todo el rengl�n del pivote, el valor del pivote se guarda en la variable valor.
        se env�a el tama�o de n-i porque cada vez habr� una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Despu�s, se usa el valor para dividir la componente del vector
        en cuesti�n. En este caso, se utiliza la funci�n HacerUno_DerIzq porque precisamente la divisi�n se har�
        de derecha a izquierda hasta llegar al primer elemento del rengl�n que se est� modificando.
        */
        valor = HacerUno_DerIzq(p1, n-i);
        *v1 /= valor;
        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        //HACER CEROS

        q1 = p1+n;

        /*
        Con este ciclo se har�n ceros todas las componentes que se encuentren debajo del pivote. Se
        repetir� n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteraci�n del
        procedimiento habr� un cero menos por hacer en las columnas. q1 da saltos de n en n porque
        recorrer� toda la columna en turno y har� ceros esos espacios, auxVect dar� saltos de v1 + k + 1
        porque siempre se encontrar� una componente despu�s del espacio que est� en turno (a la altura del
        pivote de la matriz).
        Primero se hace cero la componente debajo del pivote en cuesti�n, se modifica todo ese rengl�n
        y el valor que se encontraba al inicio del rengl�n modificado (el que se hizo cero) se guarda en la variable valor
        para posteriormente modificar el vector de la misma manera que la matriz.
        */
        for(k = 0; k < n-(i+1); k++, q1 += n){
            auxVect = v1 + k + 1;
            valor = HacerCero_DerIzq(p1, q1, n-i );
            *auxVect = *auxVect - (valor * (*v1));
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(v, n);
            cout << endl << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros abajo y a la derecha.
p almacena la direccion de la matriz A[n][n], q es la direcci�n del vector v de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se llama con la siguiente sentencia:
ResolverSEL_CerosAbajoDer(&A[0][0], v, n)
*/
void ResolverSEL_CerosAbajoDer(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenar� el valor de las componentes del vector.
    int i, j; //Contadores

    /*
    Primeramente se extrae el valor de la �ltima componente del vector porque es la que conocemos; en la segunda iteraci�n se tomar�
    la pen�ltima componente y as� sucesivamente. Posteriormente, el apuntador del vector se sit�a al inicio de �ste y el puntero de
    la matriz se sit�a en la columna en turno: En la primera iteraci�n p se acomodar� al inicio de la primer fila; en la segunda
    iteraci�n, se acomodar� en la siguiente columna y as� sucesivamente.
    */
    for(i = 0 ; i < n-1 ; i++){
        valor = *( q + (n-i-1) );
        q1 = q;
        p1 = p+i;

        /*
        Este ciclo multiplica toda toda una columna de la matriz por el elemento en turno del vector y posteriormente cada uno de
        estos valores se le restan a su correspondiente componente en el vector.
        */
        for(j = 0 ; j < n-i-1; j++, p1 += n, q1++){
            *q1 = *q1 - (valor * (*p1));
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(q, n);
            cout << endl << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros abajo y a la izquierda (forma normal).
p almacena la direccion de la matriz A[n][n]; q es la direcci�n del vector de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se invoca con la siguiente llamada:
ResolverSEL(&A[0][0], v, n)
*/
void ResolverSEL(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenar� el valor de las componentes del vector.
    int i, j; //Contadores.

    /*
    Primeramente se extrae el valor de la �ltima componente del vector porque es la que conocemos; en la segunda iteraci�n se tomar�
    la pen�ltima componente y as� sucesivamente. Posteriormente, el apuntador del vector se sit�a al inicio de �ste y el puntero de
    la matriz se sit�a en la columna en turno: En la primera iteraci�n p se acomodar� al inicio de la �ltima fila; en la segunda
    iteraci�n, se acomodar� en la columna de su izquierda y as� sucesivamente.
    */
    for(i = 0; i < n - 1 ; i++){
        valor = *( q+(n-i-1) );
        q1 = q;
        p1 = p + (n-i-1);

        /*
        Este ciclo multiplica toda toda una columna de la matriz por el elemento en turno del vector y posteriormente cada uno de
        estos valores se le restan a su correspondiente componente en el vector.
        */
        for(j = 0; j < (n-i-1); j++, p1 += n, q1++){
            *q1 = *q1 - ( valor * (*p1) );
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(q, n);
            cout << endl << endl << endl;

        }
    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros arriba y a la derecha; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector, n es la dimensi�n
del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaDer(float *p, float *v, int n){
    /*
    valor es la variable que almacenar� el n�mero con el cu�l se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la direcci�n en donde se har�n los 1's; q1 es la direcci�n en donde se har�n
    los 0's, v1 es la direcci�n del vector; pivoteAuxMat y pivoteAuxVect son apuntadores auxiliares que recorrer�n la matriz y el
    vector respectivamente en busca del pivote m�s grande (pivoteo parcial).
    */
    float *p1, *q1, *v1, *pivoteAuxMat, *pivoteAuxVect, valor;
    int i, j, k;

    /*
    Por la posici�n en donde haremos los ceros, este algoritmo comenzar� desde el �ltimo elemento de la matriz y se ir� recorriendo
    hacia atr�s; entonces, p1 apuntar� al �ltimo elemento de la matriz y v1 apuntar� al �ltimo elemento del vector.
    */
    v1 = v + n-1;
    p1 = p + (n*n) - 1;


    /*
    Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y renglones se ver�n afectadas. Por eso
    todo el procedimiento general se repetir� n veces. p1 dar� saltos de n+1 hacia tr�s porque los pivotes est�n debajo del anterior y un espacio
    m�s a la izquierda (diagonal). v1, al ser un vector, dar� saltos de 1 en 1 hacia atr�s porque en cada iteraci�n se modificar� una sola
    componente a la vez: primero la primera, despu�s la segunda y as� sucesivamente.
    */
    for(i = 0 ; i < n ; i++, p1 -= n+1, v1--){

        //PIVOTEO PARCIAL

        /*
        La posici�n de donde se comenzar�n a buscar pivotes m�s grandes comenzar�n justo arriba del pivote "original" en turno.
        De manera similar, el pivote auxiliar en el vector comenzar� justo arriba del pivote original en turno.
        */
        pivoteAuxMat = p1 - n;
        pivoteAuxVect = v1 - 1;

        /*
        Con este ciclo se recorrer� toda la columna en cuesti�n hacia arriba y todo el vector a la vez en busca de un pivote m�s grande.
        El ciclo se repetir� n -(i+1) porque cada vez habr� una componente menos arriba del pivote por explorar.
        */
        for(j = 0 ; j < n - (i+1) ; j++, pivoteAuxMat -= n, pivoteAuxVect--){

            /*
            Si se encuentra un pivote m�s grande en la matriz, entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se env�a la direcci�n p1 - n-i-1 y
            pivoteAuxMat - n-i-1 porque debemos enviar la direcci�n de donde comienza el rengl�n.
            */
            if(*pivoteAuxMat > *p1){
                Intercambiar( p1-(n-i-1), pivoteAuxMat - (n-i-1), n);
                Intercambiar(v1, pivoteAuxVect, 1);
                ImprimeMatriz(p, n, n);
                cout << endl << endl;
                ImprimeVector(v, n);
                cout << endl << endl << endl;
            }
        }

        //HACER UNOS

        /*
        Se hace uno todo el rengl�n del pivote de derecha a izquierda, por eso se utiliza la funci�n
        HacerUno_DerIzq. El valor del pivote se guarda en la variable valor;
        se env�a el tama�o de n-i porque cada vez habr� una componente menos para dividir (la que va
        quedando a la derecha del pivote). Despu�s, se usa el valor para dividir la componente del vector
        en cuesti�n.
        */
        valor = HacerUno_DerIzq(p1, n-i);
        *v1 /= valor;

        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        //HACER CEROS
        q1 = p1 - n; //El primer cero que se har� se encuentra justo arriba del pivote de la columna en turno.

        /*
        Con este ciclo se har�n ceros todas las componentes que se encuentren arriba del pivote. Se
        repetir� n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteraci�n del
        procedimiento habr� un cero menos por hacer en las columnas. q1 da ssaltos de n en n hacia atr�s porque
        recorrer� hacia arriba toda la columna en turno y har� ceros esos espacios, pivoteAuxVect dar� saltos de v1 - (k + 1)
        porque siempre se encontrar� una componente antes del espacio que est� en turno (a la altura del
        pivote de la matriz). Primero se hace cero la componente arriba del pivote en cuesti�n, se modifica todo ese rengl�n
        y el valor que se encontraba al inicio del rengl�n modificado (el que se hizo cero) se guarda en la variable valor
        para posteriormente modificar el vector de la misma manera que la matriz.
        */
        for(k = 0 ; k < n - (i+1) ; k++, q1 -= n){
            valor = HacerCero_DerIzq(p1, q1, n-i);
            pivoteAuxVect = v1 - (k+1);
            *pivoteAuxVect = *pivoteAuxVect - (valor * (*v1));
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(v, n);
            cout << endl << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular superior con los ceros arriba y a la izquierda; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector, n es la dimensi�n
del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz_CerosArribaIzq(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaIzq(float *p, float *v, int n){

    /*
    valor es la variable que almacenar� el n�mero con el cu�l se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la direcci�n en donde se har�n los 1's; q1 es la direcci�n en donde se har�n
    los 0's, v1 es la direcci�n del vector; auxMat y auxVect son apuntadores auxiliares que recorrer�n la matriz y el
    vector respectivamente en busca del pivote m�s grande (pivoteo parcial).
    */
    float *p1, *q1, *v1,*auxMat, *auxVect, valor;
    int i, j, k; //Contadores

    /*
    Por la posici�n en donde haremos los ceros, este algoritmo comenzar� desde el inicio del �ltimo rengl�n y se ir� recorriendo
    hacia adelante; entonces, p1 apuntar� al primer elemento del �ltimo rengl�n de la matriz y v1 apuntar� al �ltimo elemento del vector.
    */
    p1 = p +  n*(n-1);
    v1 = v + (n-1);

    /*
    Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y renglones se ver�n afectadas. Por eso
    todo el procedimiento general se repetir� n veces. p1 dar� saltos de n-1 hacia tr�s porque los pivotes est�n arriba del anterior y un espacio
    m�s a la derecha (diagonal). v1, al ser un vector, dar� saltos de 1 en 1 hacia atr�s porque en cada iteraci�n se modificar� una sola
    componente a la vez: primero la �ltima, despu�s la pen�ltima y as� sucesivamente.
    */
    for(i = 0 ; i < n ; i++, p1 -= (n-1), v1-- ){

        //PIVOTEO PARCIAL

         /*
        La posici�n de donde se comenzar�n a buscar pivotes m�s grandes comenzar�n justo arriba del pivote "original" en turno.
        De manera similar, el pivote auxiliar en el vector comenzar� justo arriba del pivote original en turno.
        */
        auxMat = p1 - n;
        auxVect = v1-1;

        /*
        Con este ciclo se recorrer� toda la columna en cuesti�n hacia arriba y todo el vector a la vez en busca de un pivote m�s grande.
        El ciclo se repetir� n -(i+1) porque cada vez habr� una componente menos arriba del pivote por explorar.
        */
        for(j = 0; j < n - (i+1) ; j++, auxMat -= n, auxVect--){
            /*
            Si se encuentra un pivote m�s grande en la matriz, entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se env�a la direcci�n p1 - i y
            auxMat - i porque debemos enviar la direcci�n de donde comienza el rengl�n.
            */
            if(*auxMat > *p1){
                Intercambiar(p1-i, auxMat-i, n);
                Intercambiar(v1, auxVect, 1);
                ImprimeMatriz(p, n, n);
                cout << endl << endl;
                ImprimeVector(v, n);
                cout << endl << endl << endl;
            }
        }

        //HACER UNOS

        /*
        Se hace uno todo el rengl�n del pivote de izquierda a derecha, por eso se utiliza la funci�n
        HacerUno normal. El valor del pivote se guarda en la variable valor;
        se env�a el tama�o de n-i porque cada vez habr� una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Despu�s, se usa el valor para dividir la componente del vector
        en cuesti�n.
        */
        valor = HacerUno(p1, n-i);
        *v1 /= valor;
        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        //HACER CEROS

        q1 = p1 - n; //El primer cero que se har� se encuentra justo arriba del pivote de la columna en turno.

        /*
        Con este ciclo se har�n ceros todas las componentes que se encuentren arriba del pivote. Se
        repetir� n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteraci�n del
        procedimiento habr� un cero menos por hacer en las columnas. q1 da ssaltos de n en n hacia atr�s porque
        recorrer� hacia arriba toda la columna en turno y har� ceros esos espacios, pivoteAuxVect dar� saltos de v1 - (k + 1)
        porque siempre se encontrar� una componente antes del espacio que est� en turno (a la altura del
        pivote de la matriz). Primero se hace cero la componente arriba del pivote en cuesti�n, se modifica todo ese rengl�n
        y el valor que se encontraba al inicio del rengl�n modificado (el que se hizo cero) se guarda en la variable valor
        para posteriormente modificar el vector de la misma manera que la matriz.
        */
        for(k = 0; k < n - (i+1) ; k++, q1 -= n){
            valor = HacerCero(p1, q1, n-i);
            auxVect = v1 - (k+1);
            *auxVect = *auxVect - ( valor * (*v1) );

            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(v, n);
            cout << endl << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros arriba y a la izquierda.
p almacena la direccion de la matriz A[n][n]; q es la direcci�n del vector de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se invoca con la siguiente llamada:
ResolverSEL_CerosArribaIzq(&A[0][0], v, n)
*/
void ResolverSEL_CerosArribaIzq(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenar� el valor de las componentes del vector.
    int i, j; //Contadores.

    /*
    Primeramente se extrae el valor de la primer componente del vector porque es la que conocemos; en la segunda iteraci�n se tomar�
    la segunda componente y as� sucesivamente. Posteriormente, el apuntador del vector se sit�a al final de �ste y el puntero de
    la matriz se sit�a al final de la columna en turno: En la primera iteraci�n p se acomodar� al final de la �ltima columna; en la segunda
    iteraci�n, se acomodar� al final de la columna de su izquierda y as� sucesivamente.
    */
    for(i = 0 ; i < n-1 ; i++){
        valor = *(q+i);
        p1 = p + ( n*n ) - (i + 1);
        q1 = q + (n - 1);

        /*
        Este ciclo multiplica toda toda una columna de la matriz por el elemento en turno del vector y posteriormente cada uno de
        estos valores se le restan a su correspondiente componente en el vector.
        */
        for(j = 0 ; j < n-(i+1) ; j++, p1 -= n, q1 --){
            *q1 = *q1 - (valor * (*p1));
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(q, n);
            cout << endl << endl << endl;
        }
    }
}
/****************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros arriba y a la derecha.
p almacena la direccion de la matriz A[n][n]; q es la direcci�n del vector de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se invoca con la siguiente llamada:
ResolverSEL_CerosArribaDer(&A[0][0], v, n)
*/
void ResolverSEL__CerosArribaDer(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenar� el valor de las componentes del vector.
    int i, j; //Contadores

    p1 = p; q1 = q; //Se copian las direcciones

    /*
    Primeramente se extrae el valor de la primer componente del vector porque es la que conocemos; en la segunda iteraci�n se tomar�
    la segunda componente y as� sucesivamente. Posteriormente, el apuntador del vector se sit�a al final de �ste y el puntero de
    la matriz se sit�a al final de la columna en turno: En la primera iteraci�n p se acomodar� al final de la primer columna; en la segunda
    iteraci�n, se acomodar� al final de la columna de su derecha y as� sucesivamente.
    */
    for(i = 0; i < n-1 ; i++){
        valor = *(q + i);

        q1 = q + (n-1);
        p1 = p + ( n*(n-1) + i);

         /*
        Este ciclo multiplica toda una columna de la matriz por el elemento en turno del vector y posteriormente cada uno de
        estos valores se le restan a su correspondiente componente en el vector.
        */
        for(j = 0; j < n-i-1 ; j++, p1 -= n, q1--){
            *q1 = *q1 - (valor * (*p1) );
            ImprimeMatriz(p, n, n);
            cout << endl << endl;
            ImprimeVector(q, n);
            cout << endl << endl << endl;
        }
    }
}
/*************************************************************************************************************************************************************************/
/*
Esta subrutina calcula la inversa de una matriz A[n][n]. p Es la direcci�n de la matriz A; q es la direcci�n en donde queremos que el resultado se almacene;
n es el orden de las matrices.
*/
void MatrizInversa(float *p, float *q, int n){
    /*
    p1 y q1 son las copias de las direcciones de las matrices; auxA y auxB son punteros auxiliares que nos ayudar�n en el pivoteo parcial;
    la variable valor almacena los valores con los cuales se lograron ceros y unos en la matriz original para posteriormente alterar la matriz
    identidad.
    */
    float *p1, *q1, *auxA, *auxB, valor;
    int i, j, k; //Contadores

    q1 = q; //Se copia la direcci�n de la matriz en donde se almacenar� el resultado.

    //CREAMOS LA MATRIZ IDENTIDAD

    //la matriz se llena de ceros.
    for(i = 0 ; i < (n*n) ; i++, q1 ++){
        *q1 = 0;
    }
    q1 = q;

    //La matriz se llena de ceros.
    for(i = 0 ; i < n ; i++, q1 += (n+1)){
        *q1 = 1;
    }

    //Se copian las direcciones de ambas matrices.
    p1 = p;
    q1 = q;

    //CEROS ABAJO

    /*
    Comienza a escalonarse la matriz. Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y renglones se
    ver�n afectadas. Por eso todo el procedimiento general se repetir� n veces. p1 dar� saltos de n+1 porque los pivotes est�n debajo del anterior y un espacio
    m�s a la derecha (diagonal). v1 de igual manera dar� saltos de n en n porque ir� "siguiendo" al puntero de la matriz original.
    */
    for(i = 0 ; i < n; i++, p1 += n+1, q1 = q + (n*i) ){

        //PIVOTEO PARCIAL

        //Los pivotes auxiliares se sit�an debajo de los pivotes originales.
        auxA = p1+n; auxB = q1 + n;

        /*
        Con este ciclo se recorrer� toda la columna en cuesti�n de la matriz A en busca de un pivote m�s grande; de igual manera el puntero de la matriz identidad
        recorrer� toda la primer columna de esta matriz. El ciclo se repetir� n -(i+1) veces porque cada vez habr� una componente menos debajo del pivote de A por explorar.
        */
        for(j = 0 ; j < n - (i+1) ; j++, auxA += n, auxB += n){

            /*
            Si se encuentra un pivote m�s grande en la matriz entonces se intercambian esos dos renglones de A y de la matriz identidad.
            Para los cambios en A se env�a la direcci�n p1 -i y pivoteAuxMat -i porque debemos enviar la direcci�n de donde comienza el rengl�n.
            En el caso de la matriz identidad simplemente se env�a la direeci�n de q1 y auxB porque estos dos punteros siempre se mantienen en
            el inicio de los renglones de esta matriz.
            */
            if(*auxA > *p1){
                Intercambiar(p1-i, auxA-i, n);
                Intercambiar(q1, auxB, n);
                cout << "Matriz A" << endl;
                ImprimeMatriz(p, n, n);
                cout << endl << endl << "Matriz identidad" << endl;
                ImprimeMatriz(q, n, n);
                cout << endl << endl;
            }
        }

        //HACER UNOS
         /*
        Se hace uno todo el rengl�n del pivote, el valor del pivote se guarda en la variable valor.
        se env�a el tama�o de n-i porque cada vez habr� una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Despu�s, se usa el valor para dividir toda la columna de la matriz identidad;
        para ello, se utiliza la funci�n HacerUno_Mat.
        */
        valor = HacerUno(p1, n-i);
        HacerUno_Mat(q1, valor, n);
        cout << "VALOR PARA HACER 1!!!: " << valor << endl;
        cout << "Matriz A" << endl;
        ImprimeMatriz(p, n, n);
        cout << endl << endl << "Matriz identidad" << endl;
        ImprimeMatriz(q, n, n);
        cout << endl << endl;

        //HACER CEROS
        /*
        El puntero auxA  es el que recorrer� la columna en turno de la matirz A; �ste apunta hacia el n�mero que se encuentra debajo del pivote; de
        igual manera, el apuntador auxB se sit�a debajo del rengl�n de la matriz identidad que es congruente con el pivote en cuesti�n de la matriz A.
        Es como si auxB "siguiera" a auxA.
        */
        auxA = p1 + n; auxB = q1 + n;

        /*
        Con este ciclo se har�n ceros todas las componentes que se encuentren debajo del pivote. Se
        repetir� n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteraci�n del
        procedimiento habr� un cero menos por hacer en las columnas. auxA da ssaltos de n en n porque
        recorrer� toda la columna en turno y har� ceros esos espacios, auxB tambi�n dar� saltos de n en n
        porque siempre ir� siguiendo los pasos del puntero auxMat.
        Primero se hace cero la componente debajo del pivote en cuesti�n, se modifica todo ese rengl�n
        y el valor que se encontraba al inicio del rengl�n modificado (el que se hizo cero) se guarda en la variable valor
        para posteriormente modificar todo el rengl�n correspondiente de la matriz identidad con la funci�n:
        HacerCero_Mat.
        */

        for(k = 0 ; k < n - (i+1); k++, auxA += n, auxB += n){
            valor = HacerCero(p1, auxA, n-i);
            HacerCero_Mat(q1, auxB, valor, n);
            cout << "Matriz A" << endl;
            ImprimeMatriz(p, n, n);
            cout << endl << endl << "Matriz identidad" << endl;
            ImprimeMatriz(q, n, n);
            cout << endl << endl;
        }
    }
    cout << "------------------------------------------" << endl << "Ceros arriba" << endl;
    //-----------------------------------------------------------------------------------------------------------------------------------------

    //CEROS ARRIBA
    /*
    Este procedimiento se comenzar� a hacer al rev�s que el anterior; es decir, se comenzar� a efectuar desde el final de la matriz.
    p1 se sit�a justo arriba del �ltimo pivote que ten�amos de la matriz porque este ser� el primer valor que se har� cero.
    q1 va a apuntar al inicio del �ltimo rengl�n de la matriz identidad.
    */
    p1 = p + (n*n) - (n+1);
    q1 = q + n*(n-1);

    /*
    El procedimiento en general se va a repetir n-1 veces porque arriba del pivote del primer rengl�n no existe ning�n cero.
    p1 dar� saltos de n+1 hacia atr�s porque el primer cero a generar en la columna que sigue (izquierda) se localiza arriba del
    pivote en el que estamos y justo a la izquierda. q1 dar� saltos de n hacia atr�s, este �ltimo puntero siempre se mantendr� en el
    inicio de los renglones de la matriz inversa.
    */
    for(i = 0 ; i < n-1 ; i++, p1 -= (n+1), q1 -= n){
        /*
        Los punteros que har�n el recorrido ser�n auxA y auxB. auxB comienza arriba de q1 porque justamente el rengl�n auxB (rengl�n a modificar)
        ser� el modificado usando los datos que se encuentren en el rengl�n de abajo  (q1).
        */
        auxA = p1;
        auxB = q1 - n;

        /*
        Este ciclo es el que controlar� la realizaci�n de ceros en una columna.
        Se repetir� n - (i+1) veces porque en cada columna siempre habr� un cero menos a generar.
        auxA dar� saltos de n en n hacia atr�s porque una vez que haga ceros una componente de la columna, proseguir� con la siguiente que se encuentra
        arriba; de igual manera, el apuntador auxB, que es el puntero de la matriz identidad, dar� saltos hacia arriba porque ir� siguiendo el paso del
        puntero auxA.
        */
        for(j = 0 ; j < n - (i+1); j++, auxB -= n, auxA -= n){

            valor = *auxA;//Se guarda el valor que hay en el lugar donde se generar� un cero.
            *auxA = 0; //Se genera el cero
            /*
            Se utiliza el valor guardado para alterar congruentemente el rengl�n correspondiente en la matriz identidad.
            se env�an las direcciones de q1 y auxB; recordemos que estos punteros siempre se mantienen en el inicio de los
            renglones de la matriz identidad.
            */
            HacerCero_Mat(q1, auxB, valor, n);
            cout << "Matriz A" << endl;
            ImprimeMatriz(p, n, n);
            cout << endl << endl << "Matriz identidad (*MATRIZ INVERSA*)" << endl;
            ImprimeMatriz(q, n, n);
            cout << endl << endl;

        }
    }
}
