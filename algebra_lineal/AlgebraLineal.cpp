/*
    Nombre: AlgebraLineal.cpp
    Autor: Pedro Andrés Hernández Amador.
    Fecha: enero del 2019

    Descripción: Archivo de implementación que contiene los cuerpos de las
                 funciones que realizan operaciones con vectores y matrices.
*/

#include <cstdlib>
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

/*
    Esta subrutina calcula la suma de 2 vectores.
    La dirección de los vectores que se suman están
    en p1 y q1; el resultado en r1. El tamaño de los
    vectores es n.
    La función se llama con la instrucción:
    SumaVectores(p, q, r, n)
*/
void SumaVector(int *p1, int *q1, int *r1, int n){
    int *p11, *q11, *r11; //Copias de las direcciones
    int i; //Contador.
    p11 = p1; q11 = q1; r11 = r1; //se inicializan las copias de las direcciones.

    //Se copia la información al vector que guardará el resultado.
    for (i = 0; i < n; p11++, q11++, r11++, i++){
        *r11 = *(p11) + *(q11); //Se suma componente a componente.
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la resta de 2 vectores.
    La dirección de los vectores que se suman están
    en p1 y q1; el resultado en r1. El tamaño de los
    vectores es n.
    La función se llama con la instrucción:
    SumaVectores(p, q, r, n)
*/
void RestaVector(int *p1, int *q1, int *r1, int n){
    int *p11, *q11, *r11; //Copias de las direcciones
    int i; //Contador
    p11 = p1; q11 = q1; r11 = r1; //Se inicializan las copias de las direcciones

    //Se copia la información al vector que guardará el resultado.
    for (i = 0; i < n; p11++, q11++, r11++, i++){
        *r11 = *(p11) - *(q11); //Se resta componente a componente.
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula el producto punto entre 2 vectores.
    La dirección de los vectores están en p1 y q1; n es el
    tamaño de los vectores. El valor regresado es el resultado
    de esta operación.
    La función se llama con la instrucción:
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

    return resultado; //Se devuelve el resultado de la operación.
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la longitud de un vector.
    La dirección del vector está en p1, n es el
    tamaño del vector. El valor regresado es el resultado
    de esta operación.
    La función se llama con la instrucción:
    NormaVector(p, n)
*/
float NormaVector(float *p1, float n){
    float *p11; //Copia de la dirección del vector.
    float resultado; //Variable que almacenará el resultado.
    p11 = p1; resultado = 0; //Se copia la dirección y el resultado se inicializa en cero.

    //Se almacena la suma de los cuadrados de cada componente del vector.
    for(int i = 0 ; i < n ; p11++, i++){
        resultado += (*p11)*(*p11);
    }

    //Se devuelve el resultado de la operación; es decir, la raíz de la suma de las componentes al cuadrado.
    return sqrt(resultado);
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula el ángulo entre 2 vectores.
    La dirección de los vectores están en p1 y q1; n es el
    tamaño de los vectores. El valor regresado es el resultado
    de esta operación.
    La función se llama con la instrucción:
    AnguloVectores(p, q, n)
*/
float AnguloVectores(float *p1, float *q1, int n){
    float *p11, *q11; //Copia de la dirección de los vectores.
    p11 = p1; q11 = q1; //Se copian las direcciones de los vectores.

    //Se regresa el coseno inverso del producto punto dividido entre el producto de las normas de los vectores.
    return acos( ProductoPunto(p11, q11, n) / ( NormaVector(p11, n) * NormaVector(q11, n)));
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina imprime un vector con números reales como componentes. La dirección de éste
    está en p1 y n es su tamaño. La función se llama con la instrucción:
    ImprimeVector(p, n)
*/
void ImprimeVector(float *p1, int n){
    float *p11; //Copia de la dirección del vector.
    p11 = p1; // se copia la

    for (int i = 0 ; i < n ; p11++, i++){
        cout << *p11 << ", ";
    }
    cout << "\b\b ";
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina imprime una matriz. La dirección del primer
    elemento de la matriz está en p1; m es el número de renglones
    y n es el número de columnas.
    La función se llama con la instrucción:
    ImprimeMatriz(p, m, n)
*/
void ImprimeMatriz(float *p1, int m, int n){
    float *p11; //Copia de la dirección de la matriz.
    int i, j; //Contadores
    p11 = p1; //Se copia la dirección en donde comienza la matriz.

    for (i = 0 ; i < m ; i++){ //Ciclo que gestiona los renglones

        for (j = 0 ; j < n; j++, p11++){ //Ciclo que gestiona las columnas.

            cout << *p11 << " "; //Se imprime cada elemento del renglón j.
        }

        //Después de imprimir cada renglón se da un salto de línea para continuar imprimiendo el siguiente renglón.
        cout << endl;
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina suma dos matrices A[m][n] y B[m][n], el resultado
    se guarda en la matriz C[m][n]. La dirección del primer elemento
    de A se encuentra en p1, la dirección del primer elemento de
    B se encuentra en q1, la dirección del primer elemento de
    C está en r1. m y n son el número de renglones y columnas de
    las matrices respectivamente.
    La función se llama con la instrucción:
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
    se guarda en la matriz C[m][n]. La dirección del primer elemento
    de A se encuentra en p1, la dirección del primer elemento de
    B se encuentra en q1, la dirección del primer elemento de
    C está en r1. m y n son el número de renglones y columnas de
    las matrices respectivamente.
    La función se llama con la instrucción:
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
    Esta subrutina calcula la multiplicación de una matriz A[m][n]
    por un vector B[n], el resultado se guarda en C[m]. La dirección
    del primer elemento de A se guarda en p1, la dirección del primer
    elemento de B se guarda en q1 y la dirección del primer elemento de
    C se guarda en r1. m y n son el número de renglones y columnas
    respectivamente de la matriz A.
    La función se llama con la siguiente instrucción:
    ProductoMatrizVector(&A[0][0], B, C, m, n)
*/
void ProductoMatrizVector(float *p1, float *q1, float *r1, int m, int n){

    //Copias de las direcciones de la matriz y los vectores y variable que almacenará el resultado.
    float *p11, *q11, *r11, resultado;
    int i,j; //Contadores
    p11 = p1; q11 = q1; r11 = r1; //Se copian las direcciones.

    //Como el resultado de ejecuta barriendo renglón por renglón de la matriz, entonces éste se efectuará m veces.
    for (i = 0 ; i < m ; i++, r11++){
        resultado = 0; //El resultado se inicializa en cero cada vez que se cambia de renglón.

        //En cada iteración el apuntador del vector se inicializa en el primer elemento de éste porque se barrerá
        //completamente de arriba hacia abajo.
        q11 = q1;

        //Como se multiplicará cada elemento del renglón de la matriz por cada elemento del vector, entonces este
        //proceso se repetirá n veces pues cada renglón de la matriz y el vector tienen n componentes.
        for (j = 0 ; j < n ; j++, p11 ++, q11++){
            resultado += (*p11) * (*q11); //Se acumula la suma de cada multiplicación componente a componente.
        }

        *r11 = resultado; //Se coloca el resultado en la posición correpondiente en la matriz resultado.
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicación de una matriz A[m][n].
    La dirección del prmier elemento de A se guarda en p1; esc es el número escalar por
    el cuál se multiplicará la matriz; m y n son el número de columnas y
    renglones respectivamente de las matrices A y B.
    La función se llama con la siguiente instrucción:
    ProductoMatrizEscalar(&A[0][0], esc, m, n)
*/
void ProductoMatrizEscalar(float *p1, float esc, int m, int n){
    float *p11; //Copia de la matriz.
    p11 = p1;; //Se copia la dirección de la matriz.

    //Cada elemento se la matriz A se multiplica por el escalar.
    for (int i = 0; i < m*n ; i++, p11++){
        *p11 = (*p11) * esc;
    }
}
/****************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicación de una matriz A[m][n]
    y una matriz  B[m][k], el resultado se guarda en C[m][k]. La dirección
    del primer elemento de A se guarda en p1, la dirección del primer
    elemento de B se guarda en q1 y la dirección del primer elemento de
    C se guarda en r1. m es el número de renglones de las matrices A y C,
    n es el número de columnas de A y k es el número de columnas de las
    matrices B y C.
    La función se llama con la siguiente instrucción:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProductoMatrices(float *p1, float *q1, float *r1, int m, int n, int k){
    //Copias de las direcciones de las matrices y variable que guardará los resultados de las multiplicaciones.
    float *p11, *q11, *r11, resultado;
    int i, j, l; //Contadores.
    r11 = r1; //Se copia la dirección de la matriz resultado C.

    //El primer for controla el recorrido de los renglones de A (A cuenta con m renglones). Recordemos que se multiplica
    //cada renglón de A por TODAS las columnas de B.
    for(i = 0 ; i < m ; i++ ){

        /*El segundo for controla el recorrido sobre cada columna de la matriz B (cuenta con k columnas). Cuando un renglón de A
          se termina de multiplicar por una columna de B, entonces se obtiene una componente de la matriz resultado C. Por esta
          última razón el apuntador de C (r11) se mueve de 1 en 1 sobre sus renglones.
        */
        for(j = 0 ; j < k ; j++, r11++){
            resultado = 0; //El resultado se inicializa en cero.

            /*
            La primera vez que se ejecute este segmento se multiplicará el PRIMER renglon de A por la PRIMER columna de B
            y se calculará la primer componente de la matriz resultado; la segunda vez, se multiplicará el PRIMER renglón de A
            por la SEGUNDA columna de B y se calculará la segunda componente de la matriz resultado y así sucesivamente hasta
            barrer todas las columnas de B habiendo calculado todas las componentes del primer renglón de la matriz resultado.
            Luego, este ciclo se acaba y el contador i aumentará. La segunda vez que se ingrese a este ciclo se tomará el segundo
            renglón de A y el procedimiento se volverá a repetir calculando todas las componentes del segundo renglón de la matriz
            resultado y así hasta terminar. Por eso, el apuntador de la matriz A se moverá de la forma: p11 = p1 + (n*i), esto
            garantiza que el apuntador caiga en el inicio del renglón con el que se está trabajando para barrer todas las columnas de B.
            A su vez, el apuntador de B se moverá de la forma q11 = q1 + j porque debe situarse en el inicio de cada columna de la matriz B
            en cada iteración.
            */
            p11 = p1+(n*i);
            q11 = q1 +j;

            /*
            Este ciclo calcula la multiplicación del renglón en cuestión de A por la columna en cuestión de B.
            El apuntador de A (p11) dará saltos de 1 en 1 porque recorrerá todas las componentes de este renglón.
            El apuntador de B (q11) dará saltos de k en k porque en B se recorrerá columna por columna.
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
    Esta subrutina calcula la multiplicación de una matriz A[m][n] y una matriz  B[m][k],
    el resultado se guarda en C[m][k]. La matriz resultante se llena de columna en columna
    y de izquierda a derecha. La dirección del primer elemento de A se guarda en p1, la dirección
    del primer elemento de B se guarda en q1 y la dirección del primer elemento de C se guarda en r1.
    m es el número de renglones de las matrices A y C, n es el número de columnas de A y k es el número
    de columnas de las matrices B y C. La función se llama con la siguiente instrucción:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatCol_IzqDer(float *p1, float *q1, float *r1, int m, int n, int k){
    float *p11, *q11, *r11, resultado;
    int i, j, l;

    /*
    El primer for va desde 0 a k porque se calculará columna por columna del resultado
    de izquierda a derecha.
    */
    for(i = 0 ; i < k ; ++i){
        /*
        Las columnas del resultado siempre se van a calcular desde su primer elemento.
        Por eso cada vez que inicia el cálculo de una nueva columna el apuntador r11
        se coloca en la "cabeza" de ésta.
        */
        r11 = r1 + i;
        /*
        El segundo for va desde 0 a m porque va a efectuar la multiplicación de
        cada renglon de A (A tiene m renglones) por TODAS las columnas de B. El apuntador r11 (matriz resultante)dará saltos de tamaño
        k porque recordemos que esta matriz se llenará columna por columna.
        */
        for(j = 0 ; j < m ; j++, r11 += k){
            /*
            Siempre que se comienza a calcular una componente del resultado, la variable que
            lo va almacenando se debe inicializar en cero.
            */
            resultado = 0;

            /*
            La primera vez que se ejecute este ciclo de va a calcular el producto del PRIMER renglón de A por la PRIMER columna de B;
            la segunda vez, se va a multiplicar el SEGUNDO renglón de A por la PRIMER columna de B y así sucesivamente hasta calcular
            toda la primer columna del resultado (matriz C), entonces se terminará este segmento y el for exterior hará la segunda corrida
            donde ahora se tomará la segunda columna de la matriz B. Entonces el apuntador de A se moverá de la manera p11 = p1 + (n*j) porque
            cada vez que se ejecute el ciclo saltará n espacios, es decir, se acomodará en el siguiente renglón de A. A su vez, el apuntador de B
            se moverá: q11 = q1 + i porque siempre comenzará en la "cabeza" de la columna en turno.
            */
            p11 = p1 + (n*j);
            q11 = q1 + i;

            /*
            El tercer for va de 0 a n porque cada renglón de A y cada columna de B tiene n elementos.
            p11 se moverá de uno en uno (componente por componente del renglón de la matriz A) y q11
            se moverá de k en k (componente por componente de la columna de la matriz B).
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
    Esta subrutina calcula la multiplicación de una matriz A[m][n] y una matriz  B[m][k], el resultado se guarda en C[m][k].
    La matriz resultante se llena renglón por renglón comenzando desde el final hacia el primer elemento. (Se llena al revés
    que la multiplicación convencional). La dirección del primer elemento de A se guarda en p1, la dirección del primer elemento
    de B se guarda en q1 y la dirección del primer elemento de C se guarda en r1. m es el número de renglones de las matrices A
    y C, n es el número de columnas de A y k es el número de columnas de las matrices B y C. La función se llama con la siguiente
    instrucción:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatRen_Abajo_y_DerIzq(float *p1, float *q1, float *r1, int m, int n, int k){
    float *p11, *q11, *r11, resultado; //Copias de las direcciones de las matrices y variable que almacenará los resultados.
    int  i, j, l; //Contadores.

    /*
    Como la matriz resultante se llenará desde el final hacia el principio, entonces al iniciar con el algoritmo su apuntador
    se posiciona en el último elemento de ésta.
    */
    r11 = r1 + (m*k) - 1;

    /*
    El primer for va desde (m-1) hasta 0 porque la multiplicación se va a efectuar
    desde el último renglón y último elemento de la matriz A.
    */
    for(i = (m-1) ; i >= 0; i--){

        /*
        El segundo for va desde 0 a k porque el resultado se calculará renglón por
        renglón, y cada renglón de la matriz resultante (C) cuenta con k elementos.
        El apuntador de la matriz resultante r11 irá decreciendo en uno porque
        la matriz se llenará desde atrás iniciando con el último componente de ésta y
        finalizando el algoritmo en la primer componente de la misma matriz.
        */
        for(j = 0 ; j < k ; j++ , r11--){

            //Se inicializa en cero la variable que almacenará los productos entre componentes.
            resultado = 0;

            /*
            El apuntador de la matriz A al principio se colocará en el último renglón de abajo e irá
            subiendo uno por uno hasta llegar al primero de arriba.
            */
            p11 = p1 + (n*i);
            /*
            El apuntador de la matriz B se colocará en la última columna e irá barriéndolas
            hacia atrás hasta llegar a la primera de la izquierda.
            */
            q11 = q1 + (k-1-j);

            /*
            El tercer for irá de 0 a n porque se multiplicarán los renglones de la matriz A por
            las columnas de la matriz B y ambos cuentan con n componentes.
            El apuntador de la matriz A (p11) dará saltos de uno en uno pues barrerá cada componente del renglón;
            el apuntador de la matriz B (q11) dará saltos de k en k pues barrerá cada componente de la columna.
            */
            for(l = 0 ; l < n ; l++, p11++, q11 += k){

                //Se va acumulando el resultado de los productos en la variable auxiliar.
                resultado += (*p11) * (*q11);
            }
            /*
            Se coloca el resultado obtenido con los productos entre componentes de renglones de A
            y columnas de B en el lugar que le corresponde (Estos resultados se irán acomodando de
            derecha a izquierda comenzando con el último componente de la matriz y terminando en
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
Esta función intercambia dos regiones de memoria. En la resolución de sistemas de ecuaciones, esta subrutina nos
ayudará intercambiando renglones de matrices. La dirección del primer renglón se encuentra en p, la dirección del
segundo renglón se encuentra en q, n es el número de elementos con los que cuentan los renglones. La función se llama
con la siguiente instrucción:
Intercambiar(p, q, n);
*/
void Intercambiar(float *p, float *q, int n){
    float *p1, *q1, a; //Copia de las direcciones y variable auxiliar.
    int i; //Contador.

    p1 = p; q1 = q; //Se copian las direcciones de los renglones.

    //Se intercambia cada componente usando la variable auxiliar a, para no perder la información al momento del intercambio.
    for(i = 0 ; i < n ; i++, *p1++, *q1++){
        a = *p1;
        *p1 = *q1;
        *q1 = a;
    }
}
/****************************************************************************************************************************************************/
/*
Esta función divide entre el número pivote todo un renglón (o parte de éste) de una matriz.
La dirección del renglón se encuentra en p, n es el número de elementos con
los que cuenta el renglón. Se regresa el valor del pivote. La subrutina se llama con la instrucción:
HacerUno(p, n);
*/
float HacerUno(float *p, int n){
    float *p1, valor; //Copia de la dirección y variable que guardará el valor pivote.
    p1 = p; //Se copia la dirección.
    valor = *p1; //El valor pivote es el primer elemento del renglón o segmento de renglón que se lee.
    *p = 1.00; //El pivote en la matriz original se intercambia por un 1 (para evitar un 0.999...).
    p1++; //Como el lugar del pivote ya es 1, entonces el apuntador se recorre un lugar.

    /*
    A partir de donde se encuentra el apuntador y hasta el final del renglón (n) se comienzan a dividir
    los valores que se encuentren en éste entre el valor del pivote.
    */
    for(int i = 1 ; i < n ; i++, p1++){
        *p1 = *p1 / valor;

    }

    return valor; //Se regresa el valor del pivote para modificar el vector del sistema de ecuaciones lineales.
}
/****************************************************************************************************************************************************/

/*
Esta subrutina divide entre un pivote todas las componentes de un renglón de una matriz. Se usará para modificar la matriz
identidad al momento de calcular una matriz inversa. p es la dirección del renglón de la matriz identidad, valor es el valor
del pivote, n es el número de elementos con los que cuenta el renglón. La función se llama con la siguiente instrucción:
HacerUno_Mat(p, valorPivote, n).
*/
void HacerUno_Mat(float*p, float valor, int n){
    float *p1; //Copia de la dirección del renglón.
    p1 = p; //Se copia la dirección del renglón.

    //Todos los elementos del renglón se dividen entre el valor pivote.
    for(int i = 0; i < n ; i++, p1++){
        *p1 /= valor;
    }
}
/****************************************************************************************************************************************************/
/*
Esta subrutina modifica una región de memoria (renglón de la matriz identidad) al momento de hacer ceros debajo del pivote de la matriz original
al buscar una matriz inversa. Deberemos aplicar la misma operación que aplicamos en el renglón de la matriz original a todos los demás elementos
del renglón correspondiente en la matriz identidad. p almacena la dirección del "renglón de abajo" que nos auxiliará para modificar el "renglón
de arriba" cuya dirección se encuentra en q; valor almacena el valor que se utilizó para lograr un cero en la matriz original. n es el número
de elementos con los que cuenta el renglón de la matriz identidad.
*/
void HacerCero_Mat(float*p, float *q, float valor, int n){
    float *p1, *q1; //Copia de las direcciones.
    p1 = p ; q1 = q; //Se copian las direcciones.

    /*
    Se aplica la misma operación que se utilizó para lograr un cero en la matriz original a cada elemento del renglón
    correspondiente de la matriz identidad.
    */
    for(int i = 0; i < n ; i++, p1++, q1++){
        *q1 = *q1 - (valor * (*p1) );
    }
}
/****************************************************************************************************************************************************/

/*
Esta función divide entre el número pivote todo un renglón (o parte de éste) de una matriz pero lo hace de
derecha a izquierda. La dirección del renglón se encuentra en p, n es el número de elementos con
los que cuenta el renglón. Se regresa el valor del pivote, es decir, el número por el cuál se dividió
el renglón. La subrutina se llama con la instrucción:
HacerUno_DerIzq(p, n);
*/
float HacerUno_DerIzq(float *p, int n){
    float *p1, valor; //Copia de la dirección y variable que almacenará el valor del pivote.
    p1 = p; //Se copia la dirección.
    valor = *p1; //El valor por el que se dividirá todo el renglón se toma del pivote (inicio del renglón).
    *p = 1.00; //El pivote se hace directamente el 1 (para evitar el resultado: 0.999...)
    p1--; //El puntero se recorre hacia la izquierda

    //Se divide cada componente del renglón entre el valor del pivote hasta que llega al primer elemento del renglón.
    for(int i = n ; i > 1 ; i--, p1--){
        *p1 = *p1 / valor;

    }

    return valor;
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de algún pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operación a todo el renglón en donde el cero se produjo. p es la dirección del "renglón de arriba"
donde se encuentra el pivote; q es la dirección del "renglón de abajo" donde se producirá el cero, n es el número de
elementos con el que cuentan los renglones. Se regresa el valor que pertenecía al elemento que se hizo cero para
usarlo posteriormente en la modificación del vector del sistema de ecuaciones. La función se llama con la sentencia:
HacerCero(p, q, n);
*/
 float HacerCero(float *p, float *q, int n){
    float *p1, *q1, valor; //Copia de las direcciones y variable que almacenará el valor del elemento que se convertirá en cero.
    p1 = p; q1 = q; //Se copian las direcciones.
    valor = *q1; //Se toma el valor del primer elemento del "renglón de abajo" (El que se convertirá en cero).

    //Se aplica la misma operación a todos los elementos del "renglón de abajo."
    for(int i = 0 ; i < n ; i++, p1++, q1++){
        *q1 = *q1 -( valor * (*p1) );
    }

    return valor; //Se regresa el valor que pertenecía al elemento que ahora es cero.
}
/****************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de algún pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operación a todo el renglón en donde el cero se produjo. Este procedimiento, en este caso, se
efectúa de derecha a izquierda. p es la dirección del "renglón de arriba" donde se encuentra el pivote; q es la dirección
del "renglón de abajo" donde se producirá el cero, n es el número de elementos con el que cuentan los renglones. Se regresa
el valor que pertenecía al elemento que se hizo cero para usarlo posteriormente en la modificación del vector del sistema de
ecuaciones. La función se llama con la sentencia:
HacerCero_DerIzq(p, q, n);
*/
float HacerCero_DerIzq(float *p, float *q, int n){
    float *p1, *q1, valor;//Copia de las direcciones y variable que almacenará el valor del elemento que se convertirá en cero.
    p1 = p; q1 = q; //Se copian las direcciones.
    valor = *q1;  //Se toma el valor del primer elemento del "renglón de abajo" (El que se convertirá en cero)

    //Se aplica la misma operación a todos los elementos del "renglón de abajo" barriéndolo de derecha a izquierda.
    for(int i = n ; i >= 1 ; i--, p1--, q1--){
        *q1 = *q1 -( valor * (*p1) );
    }

    return valor; //Se regresa el valor que pertenecía al elemento que ahora es cero.
}
/****************************************************************************************************************************************************/
/*
Esta subrutina se encarga de escalonar una matriz y lograr unos en la diagonal principal; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector,
n es la dimensión del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz(&A[0][0], v, n).
*/
void ReducirMatriz(float *p, float *v, int n){
    /*
    valor es la variable que almacenará el número con el cuál se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la dirección en donde se harán los 1's; q1 es la dirección en donde se harán
    los 0's, v1 es la dirección del vector; pivoteAuxMat y auxVect son apuntadores auxiliares que recorrerán la matriz y el
    vector respectivamente en busca del pivote más grande (pivoteo parcial).
    */
    float *p1, *q1, *v1, valor, *pivoteAuxMat, *auxVect;
    int i, j, k; //Contadores

    //Se copia la dirección de la matriz y del vector.
    p1 = p; //Primer pivote.
    v1 = v; //Primer componente del vector afectada.
    /*
    Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y englones se verán afectadas. Por eso
    todo el procedimiento general se repetirá n veces. p1 dará saltos de n+1 porque los pivotes están debajo del anterior y un espacio
    más a la derecha (diagonal). v1, al ser un vector, dará saltos de 1 en 1 porque en cada iteración se modificará una sola componente a la vez:
    primero la primera, después la segunda y así sucesivamente.
    */
    for(i = 0 ; i < n; i++, p1 += n+1, v1++){

        //PIVOTEO PARCIAL
        pivoteAuxMat = p1 + n; //Se comenzará a buscar un pivote más grande desde justo debajo de donde está el pivote en turno.
        auxVect = v1 + 1;//De igual manera, el vector irá siguiendo el movimiento por columnas que el apuntador de la matriz haga.
        /*
        Con este ciclo se recorrerá toda la columna en cuestión y todo el vector a la vez en busca de un pivote más grande.
        El ciclo se repetirá n -(i+1) porque cada vez habrá una componente menos debajo del pivote por explorar.
        */
        for(k = 0 ; k < n - (i + 1) ; k++, pivoteAuxMat += n, auxVect++){
            /*
            Si se encuentra un pivote más grande en la matriz entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se envía la dirección p1 -i y
            pivoteAuxMat -i porque debemos enviar la dirección de donde comienza el renglón.
            */
            if(*pivoteAuxMat > *p1){
                Intercambiar(p1 - i, pivoteAuxMat - i, n); //Intercambia renglón en la matriz.
                Intercambiar(v1, auxVect, 1); //Intercambia componente en el vector
                ImprimeMatriz(p, n, n);
                cout << endl << endl;
                ImprimeVector(v, n);
                cout << endl << endl << endl;
            }
        }
        //SE HACEN LOS UNOS

        /*
        Se hace uno todo el renglón del pivote, el valor del pivote se guarda en la variable valor.
        se envía el tamaño de n-i porque cada vez habrá una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Después, se usa el valor para dividir la componente del vector
        en cuestión.
        */
        valor = HacerUno(p1, n-i);
        *v1 /= valor;
        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        // SE HACEN LOS CEROS

        q1 = p1 + n; //El primer cero que se hará en la columna en turno se encuentra debajo del pivote.

        /*
        Con este ciclo se harán ceros todas las componentes que se encuentren debajo del pivote. Se
        repetirá n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteración del
        procedimiento habrá un cero menos por hacer en las columnas. q1 da ssaltos de n en n porque
        recorrerá toda la columna en turno y hará ceros esos espacios, auxVect dará saltos de v1 + j + 1
        porque siempre se encontrará una componente después del espacio que está en turno (a la altura del
        pivote de la matriz).
        Primero se hace cero la componente debajo del pivote en cuestión, se modifica todo ese renglón
        y el valor que se encontraba al inicio del renglón modificado (el que se hizo cero) se guarda en la variable valor
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
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros a la derecha; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector, n es la dimensión
del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosAbajoDer(float *p, float *v, int n){
     /*
    valor es la variable que almacenará el número con el cuál se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la dirección en donde se harán los 1's; q1 es la dirección en donde se harán
    los 0's, v1 es la dirección del vector; auxMat y auxVect son apuntadores auxiliares que recorrerán la matriz y el
    vector respectivamente en busca del pivote más grande (pivoteo parcial).
    */
    float *p1, *q1, *v1,*auxMat, *auxVect, valor;
    int i, j, k; //Contadores


    //El apuntador de la matriz A se inicializa en la "cabeza" de la última columna de la matriz.
    p1 = p + (n-1);
    //Como el apuntador de la matriz se mantiene en el primer renglón, entonces el apuntador del vector apunta hacia su primer componente.
    v1 = v;

    /*
    Como el ciclo recorrerá todas las columnas de la matriz haciendo unos y ceros donde corresponda, entonces el ciclo en general se
    ejecutará n veces, el apuntador p1 (matriz) se irá escalonando hacia atrás, por eso dará saltos de n-1; al hace esto, bajará
    renglón a renglón, por lo que el apuntador del vector (v1) irá siguiéndolo y se moverá de 1 en 1 por sus componentes hasta llegar
    a la última que corresponde con el último renglón de la matriz.
    */
    for(i = 0 ; i < n; i++, p1 += n-1, v1++){

        //PIVOTAJE PARCIAL

        auxMat = p1+n; //Se comenzará a buscar un pivote más grande desde justo debajo de donde está el pivote en turno.
        auxVect = v1 + 1; //De igual manera, el vector irá siguiendo el movimiento por columnas que el apuntador de la matriz haga.

        /*
        Con este ciclo se recorrerá toda la columna en cuestión y todo el vector a la vez en busca de un pivote más grande.
        El ciclo se repetirá n -(i+1) veces porque cada vez habrá una componente menos debajo del pivote por explorar.
        */
        for(j = 0; j < n-(i+1) ; j++, auxMat += n, auxVect ++){
            /*
            Si se encuentra un pivote más grande en la matriz, entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se envía la dirección p1 - n-i-1 y
            pivoteAuxMat - n-i-1 porque debemos enviar la dirección de donde comienza el renglón.
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
        Se hace uno todo el renglón del pivote, el valor del pivote se guarda en la variable valor.
        se envía el tamaño de n-i porque cada vez habrá una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Después, se usa el valor para dividir la componente del vector
        en cuestión. En este caso, se utiliza la función HacerUno_DerIzq porque precisamente la división se hará
        de derecha a izquierda hasta llegar al primer elemento del renglón que se está modificando.
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
        Con este ciclo se harán ceros todas las componentes que se encuentren debajo del pivote. Se
        repetirá n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteración del
        procedimiento habrá un cero menos por hacer en las columnas. q1 da saltos de n en n porque
        recorrerá toda la columna en turno y hará ceros esos espacios, auxVect dará saltos de v1 + k + 1
        porque siempre se encontrará una componente después del espacio que está en turno (a la altura del
        pivote de la matriz).
        Primero se hace cero la componente debajo del pivote en cuestión, se modifica todo ese renglón
        y el valor que se encontraba al inicio del renglón modificado (el que se hizo cero) se guarda en la variable valor
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
p almacena la direccion de la matriz A[n][n], q es la dirección del vector v de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se llama con la siguiente sentencia:
ResolverSEL_CerosAbajoDer(&A[0][0], v, n)
*/
void ResolverSEL_CerosAbajoDer(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenará el valor de las componentes del vector.
    int i, j; //Contadores

    /*
    Primeramente se extrae el valor de la última componente del vector porque es la que conocemos; en la segunda iteración se tomará
    la penúltima componente y así sucesivamente. Posteriormente, el apuntador del vector se sitúa al inicio de éste y el puntero de
    la matriz se sitúa en la columna en turno: En la primera iteración p se acomodará al inicio de la primer fila; en la segunda
    iteración, se acomodará en la siguiente columna y así sucesivamente.
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
p almacena la direccion de la matriz A[n][n]; q es la dirección del vector de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se invoca con la siguiente llamada:
ResolverSEL(&A[0][0], v, n)
*/
void ResolverSEL(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenará el valor de las componentes del vector.
    int i, j; //Contadores.

    /*
    Primeramente se extrae el valor de la última componente del vector porque es la que conocemos; en la segunda iteración se tomará
    la penúltima componente y así sucesivamente. Posteriormente, el apuntador del vector se sitúa al inicio de éste y el puntero de
    la matriz se sitúa en la columna en turno: En la primera iteración p se acomodará al inicio de la última fila; en la segunda
    iteración, se acomodará en la columna de su izquierda y así sucesivamente.
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
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros arriba y a la derecha; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector, n es la dimensión
del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaDer(float *p, float *v, int n){
    /*
    valor es la variable que almacenará el número con el cuál se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la dirección en donde se harán los 1's; q1 es la dirección en donde se harán
    los 0's, v1 es la dirección del vector; pivoteAuxMat y pivoteAuxVect son apuntadores auxiliares que recorrerán la matriz y el
    vector respectivamente en busca del pivote más grande (pivoteo parcial).
    */
    float *p1, *q1, *v1, *pivoteAuxMat, *pivoteAuxVect, valor;
    int i, j, k;

    /*
    Por la posición en donde haremos los ceros, este algoritmo comenzará desde el último elemento de la matriz y se irá recorriendo
    hacia atrás; entonces, p1 apuntará al último elemento de la matriz y v1 apuntará al último elemento del vector.
    */
    v1 = v + n-1;
    p1 = p + (n*n) - 1;


    /*
    Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y renglones se verán afectadas. Por eso
    todo el procedimiento general se repetirá n veces. p1 dará saltos de n+1 hacia trás porque los pivotes están debajo del anterior y un espacio
    más a la izquierda (diagonal). v1, al ser un vector, dará saltos de 1 en 1 hacia atrás porque en cada iteración se modificará una sola
    componente a la vez: primero la primera, después la segunda y así sucesivamente.
    */
    for(i = 0 ; i < n ; i++, p1 -= n+1, v1--){

        //PIVOTEO PARCIAL

        /*
        La posición de donde se comenzarán a buscar pivotes más grandes comenzarán justo arriba del pivote "original" en turno.
        De manera similar, el pivote auxiliar en el vector comenzará justo arriba del pivote original en turno.
        */
        pivoteAuxMat = p1 - n;
        pivoteAuxVect = v1 - 1;

        /*
        Con este ciclo se recorrerá toda la columna en cuestión hacia arriba y todo el vector a la vez en busca de un pivote más grande.
        El ciclo se repetirá n -(i+1) porque cada vez habrá una componente menos arriba del pivote por explorar.
        */
        for(j = 0 ; j < n - (i+1) ; j++, pivoteAuxMat -= n, pivoteAuxVect--){

            /*
            Si se encuentra un pivote más grande en la matriz, entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se envía la dirección p1 - n-i-1 y
            pivoteAuxMat - n-i-1 porque debemos enviar la dirección de donde comienza el renglón.
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
        Se hace uno todo el renglón del pivote de derecha a izquierda, por eso se utiliza la función
        HacerUno_DerIzq. El valor del pivote se guarda en la variable valor;
        se envía el tamaño de n-i porque cada vez habrá una componente menos para dividir (la que va
        quedando a la derecha del pivote). Después, se usa el valor para dividir la componente del vector
        en cuestión.
        */
        valor = HacerUno_DerIzq(p1, n-i);
        *v1 /= valor;

        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        //HACER CEROS
        q1 = p1 - n; //El primer cero que se hará se encuentra justo arriba del pivote de la columna en turno.

        /*
        Con este ciclo se harán ceros todas las componentes que se encuentren arriba del pivote. Se
        repetirá n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteración del
        procedimiento habrá un cero menos por hacer en las columnas. q1 da ssaltos de n en n hacia atrás porque
        recorrerá hacia arriba toda la columna en turno y hará ceros esos espacios, pivoteAuxVect dará saltos de v1 - (k + 1)
        porque siempre se encontrará una componente antes del espacio que está en turno (a la altura del
        pivote de la matriz). Primero se hace cero la componente arriba del pivote en cuestión, se modifica todo ese renglón
        y el valor que se encontraba al inicio del renglón modificado (el que se hizo cero) se guarda en la variable valor
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
Esta subrutina se encarga de escalonar una matriz de manera triangular superior con los ceros arriba y a la izquierda; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector, n es la dimensión
del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz_CerosArribaIzq(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaIzq(float *p, float *v, int n){

    /*
    valor es la variable que almacenará el número con el cuál se hacen los unos y ceros en la matriz para posteriormente
    usarlo para modificar el vector. p1 es la dirección en donde se harán los 1's; q1 es la dirección en donde se harán
    los 0's, v1 es la dirección del vector; auxMat y auxVect son apuntadores auxiliares que recorrerán la matriz y el
    vector respectivamente en busca del pivote más grande (pivoteo parcial).
    */
    float *p1, *q1, *v1,*auxMat, *auxVect, valor;
    int i, j, k; //Contadores

    /*
    Por la posición en donde haremos los ceros, este algoritmo comenzará desde el inicio del último renglón y se irá recorriendo
    hacia adelante; entonces, p1 apuntará al primer elemento del último renglón de la matriz y v1 apuntará al último elemento del vector.
    */
    p1 = p +  n*(n-1);
    v1 = v + (n-1);

    /*
    Para reducir la matriz se necesita hacer pivotes en todos las columnas, entonces, todas las columnas y renglones se verán afectadas. Por eso
    todo el procedimiento general se repetirá n veces. p1 dará saltos de n-1 hacia trás porque los pivotes están arriba del anterior y un espacio
    más a la derecha (diagonal). v1, al ser un vector, dará saltos de 1 en 1 hacia atrás porque en cada iteración se modificará una sola
    componente a la vez: primero la última, después la penúltima y así sucesivamente.
    */
    for(i = 0 ; i < n ; i++, p1 -= (n-1), v1-- ){

        //PIVOTEO PARCIAL

         /*
        La posición de donde se comenzarán a buscar pivotes más grandes comenzarán justo arriba del pivote "original" en turno.
        De manera similar, el pivote auxiliar en el vector comenzará justo arriba del pivote original en turno.
        */
        auxMat = p1 - n;
        auxVect = v1-1;

        /*
        Con este ciclo se recorrerá toda la columna en cuestión hacia arriba y todo el vector a la vez en busca de un pivote más grande.
        El ciclo se repetirá n -(i+1) porque cada vez habrá una componente menos arriba del pivote por explorar.
        */
        for(j = 0; j < n - (i+1) ; j++, auxMat -= n, auxVect--){
            /*
            Si se encuentra un pivote más grande en la matriz, entonces se intercambian esos dos renglones y las
            corresponientes componentes del vector. Para los cambios en las matrices se envía la dirección p1 - i y
            auxMat - i porque debemos enviar la dirección de donde comienza el renglón.
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
        Se hace uno todo el renglón del pivote de izquierda a derecha, por eso se utiliza la función
        HacerUno normal. El valor del pivote se guarda en la variable valor;
        se envía el tamaño de n-i porque cada vez habrá una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Después, se usa el valor para dividir la componente del vector
        en cuestión.
        */
        valor = HacerUno(p1, n-i);
        *v1 /= valor;
        ImprimeMatriz(p, n, n);
        cout << endl << endl;
        ImprimeVector(v, n);
        cout << endl << endl << endl;

        //HACER CEROS

        q1 = p1 - n; //El primer cero que se hará se encuentra justo arriba del pivote de la columna en turno.

        /*
        Con este ciclo se harán ceros todas las componentes que se encuentren arriba del pivote. Se
        repetirá n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteración del
        procedimiento habrá un cero menos por hacer en las columnas. q1 da ssaltos de n en n hacia atrás porque
        recorrerá hacia arriba toda la columna en turno y hará ceros esos espacios, pivoteAuxVect dará saltos de v1 - (k + 1)
        porque siempre se encontrará una componente antes del espacio que está en turno (a la altura del
        pivote de la matriz). Primero se hace cero la componente arriba del pivote en cuestión, se modifica todo ese renglón
        y el valor que se encontraba al inicio del renglón modificado (el que se hizo cero) se guarda en la variable valor
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
p almacena la direccion de la matriz A[n][n]; q es la dirección del vector de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se invoca con la siguiente llamada:
ResolverSEL_CerosArribaIzq(&A[0][0], v, n)
*/
void ResolverSEL_CerosArribaIzq(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenará el valor de las componentes del vector.
    int i, j; //Contadores.

    /*
    Primeramente se extrae el valor de la primer componente del vector porque es la que conocemos; en la segunda iteración se tomará
    la segunda componente y así sucesivamente. Posteriormente, el apuntador del vector se sitúa al final de éste y el puntero de
    la matriz se sitúa al final de la columna en turno: En la primera iteración p se acomodará al final de la última columna; en la segunda
    iteración, se acomodará al final de la columna de su izquierda y así sucesivamente.
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
p almacena la direccion de la matriz A[n][n]; q es la dirección del vector de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se invoca con la siguiente llamada:
ResolverSEL_CerosArribaDer(&A[0][0], v, n)
*/
void ResolverSEL__CerosArribaDer(float *p, float *q, int n){
    float *p1, *q1, valor; //Copias de las direcciones y variable que almacenará el valor de las componentes del vector.
    int i, j; //Contadores

    p1 = p; q1 = q; //Se copian las direcciones

    /*
    Primeramente se extrae el valor de la primer componente del vector porque es la que conocemos; en la segunda iteración se tomará
    la segunda componente y así sucesivamente. Posteriormente, el apuntador del vector se sitúa al final de éste y el puntero de
    la matriz se sitúa al final de la columna en turno: En la primera iteración p se acomodará al final de la primer columna; en la segunda
    iteración, se acomodará al final de la columna de su derecha y así sucesivamente.
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
Esta subrutina calcula la inversa de una matriz A[n][n]. p Es la dirección de la matriz A; q es la dirección en donde queremos que el resultado se almacene;
n es el orden de las matrices.
*/
void MatrizInversa(float *p, float *q, int n){
    /*
    p1 y q1 son las copias de las direcciones de las matrices; auxA y auxB son punteros auxiliares que nos ayudarán en el pivoteo parcial;
    la variable valor almacena los valores con los cuales se lograron ceros y unos en la matriz original para posteriormente alterar la matriz
    identidad.
    */
    float *p1, *q1, *auxA, *auxB, valor;
    int i, j, k; //Contadores

    q1 = q; //Se copia la dirección de la matriz en donde se almacenará el resultado.

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
    verán afectadas. Por eso todo el procedimiento general se repetirá n veces. p1 dará saltos de n+1 porque los pivotes están debajo del anterior y un espacio
    más a la derecha (diagonal). v1 de igual manera dará saltos de n en n porque irá "siguiendo" al puntero de la matriz original.
    */
    for(i = 0 ; i < n; i++, p1 += n+1, q1 = q + (n*i) ){

        //PIVOTEO PARCIAL

        //Los pivotes auxiliares se sitúan debajo de los pivotes originales.
        auxA = p1+n; auxB = q1 + n;

        /*
        Con este ciclo se recorrerá toda la columna en cuestión de la matriz A en busca de un pivote más grande; de igual manera el puntero de la matriz identidad
        recorrerá toda la primer columna de esta matriz. El ciclo se repetirá n -(i+1) veces porque cada vez habrá una componente menos debajo del pivote de A por explorar.
        */
        for(j = 0 ; j < n - (i+1) ; j++, auxA += n, auxB += n){

            /*
            Si se encuentra un pivote más grande en la matriz entonces se intercambian esos dos renglones de A y de la matriz identidad.
            Para los cambios en A se envía la dirección p1 -i y pivoteAuxMat -i porque debemos enviar la dirección de donde comienza el renglón.
            En el caso de la matriz identidad simplemente se envía la direeción de q1 y auxB porque estos dos punteros siempre se mantienen en
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
        Se hace uno todo el renglón del pivote, el valor del pivote se guarda en la variable valor.
        se envía el tamaño de n-i porque cada vez habrá una componente menos para dividir (la que va
        quedando a la izquierda del pivote). Después, se usa el valor para dividir toda la columna de la matriz identidad;
        para ello, se utiliza la función HacerUno_Mat.
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
        El puntero auxA  es el que recorrerá la columna en turno de la matirz A; éste apunta hacia el número que se encuentra debajo del pivote; de
        igual manera, el apuntador auxB se sitúa debajo del renglón de la matriz identidad que es congruente con el pivote en cuestión de la matriz A.
        Es como si auxB "siguiera" a auxA.
        */
        auxA = p1 + n; auxB = q1 + n;

        /*
        Con este ciclo se harán ceros todas las componentes que se encuentren debajo del pivote. Se
        repetirá n - (i+1)veces porque el pivote se va escalonando, entonces en cada iteración del
        procedimiento habrá un cero menos por hacer en las columnas. auxA da ssaltos de n en n porque
        recorrerá toda la columna en turno y hará ceros esos espacios, auxB también dará saltos de n en n
        porque siempre irá siguiendo los pasos del puntero auxMat.
        Primero se hace cero la componente debajo del pivote en cuestión, se modifica todo ese renglón
        y el valor que se encontraba al inicio del renglón modificado (el que se hizo cero) se guarda en la variable valor
        para posteriormente modificar todo el renglón correspondiente de la matriz identidad con la función:
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
    Este procedimiento se comenzará a hacer al revés que el anterior; es decir, se comenzará a efectuar desde el final de la matriz.
    p1 se sitúa justo arriba del último pivote que teníamos de la matriz porque este será el primer valor que se hará cero.
    q1 va a apuntar al inicio del último renglón de la matriz identidad.
    */
    p1 = p + (n*n) - (n+1);
    q1 = q + n*(n-1);

    /*
    El procedimiento en general se va a repetir n-1 veces porque arriba del pivote del primer renglón no existe ningún cero.
    p1 dará saltos de n+1 hacia atrás porque el primer cero a generar en la columna que sigue (izquierda) se localiza arriba del
    pivote en el que estamos y justo a la izquierda. q1 dará saltos de n hacia atrás, este último puntero siempre se mantendrá en el
    inicio de los renglones de la matriz inversa.
    */
    for(i = 0 ; i < n-1 ; i++, p1 -= (n+1), q1 -= n){
        /*
        Los punteros que harán el recorrido serán auxA y auxB. auxB comienza arriba de q1 porque justamente el renglón auxB (renglón a modificar)
        será el modificado usando los datos que se encuentren en el renglón de abajo  (q1).
        */
        auxA = p1;
        auxB = q1 - n;

        /*
        Este ciclo es el que controlará la realización de ceros en una columna.
        Se repetirá n - (i+1) veces porque en cada columna siempre habrá un cero menos a generar.
        auxA dará saltos de n en n hacia atrás porque una vez que haga ceros una componente de la columna, proseguirá con la siguiente que se encuentra
        arriba; de igual manera, el apuntador auxB, que es el puntero de la matriz identidad, dará saltos hacia arriba porque irá siguiendo el paso del
        puntero auxA.
        */
        for(j = 0 ; j < n - (i+1); j++, auxB -= n, auxA -= n){

            valor = *auxA;//Se guarda el valor que hay en el lugar donde se generará un cero.
            *auxA = 0; //Se genera el cero
            /*
            Se utiliza el valor guardado para alterar congruentemente el renglón correspondiente en la matriz identidad.
            se envían las direcciones de q1 y auxB; recordemos que estos punteros siempre se mantienen en el inicio de los
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
