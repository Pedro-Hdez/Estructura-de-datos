/*
    Nombre: AlgebraLineal.h
    Autor: Pedro Andrés Hernández Amador.
    Fecha: enero del 2019

    Descripción: Archivo de cabecera que contiene los prototipos de las funciones
                 que realizan operaciones con vectores y matrices.
*/

#ifndef ALGEBRALINEAL_H_INCLUDED
#define ALGEBRALINEAL_H_INCLUDED

/*
    Esta subrutina calcula la suma de 2 vectores.
    La dirección de los vectores que se suman están
    en p1 y q1; el resultado en r1. El tamaño de los
    vectores es n.
    La función se llama con la instrucción:
    SumaVectores(p, q, r, n)
*/
void SumaVector(int *p1, int *q1, int *r1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la resta de 2 vectores.
    La dirección de los vectores que se suman están
    en p1 y q1; el resultado en r1. El tamaño de los
    vectores es n.
    La función se llama con la instrucción:
    SumaVectores(p, q, r, n)
*/
void RestaVector(int *p1, int *q1, int *r1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula el producto punto entre 2 vectores.
    La dirección de los vectores están en p1 y q1; n es el
    tamaño de los vectores. El valor regresado es el resultado
    de esta operación.
    La función se llama con la instrucción:
    ProductoPunto(p, q, n)
*/
float ProductoPunto(float *p1, float *q1, float n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la longitud de un vector.
    La dirección del vector está en p1, n es el
    tamaño del vector. El valor regresado es el resultado
    de esta operación.
    La función se llama con la instrucción:
    NormaVector(p, n)
*/
float NormaVector(float *p1, float n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula el ángulo entre 2 vectores.
    La dirección de los vectores están en p1 y q1; n es el
    tamaño de los vectores. El valor regresado es el resultado
    de esta operación.
    La función se llama con la instrucción:
    AnguloVectores(p, q, n)
*/
float AnguloVectores(float *p1, float *q1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina imprime un vector con números reales como componentes. La dirección de éste
    está en p1 y n es su tamaño. La función se llama con la instrucción:
    ImprimeVector(p, n)
*/
void ImprimeVector(float *p1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina imprime una matriz. La dirección del primer
    elemento de la matriz está en p1; m es el número de renglones
    y n es el número de columnas.
    La función se llama con la instrucción:
    ImprimeMatriz(p, m, n)
*/
void ImprimeMatriz(float *p1, int m, int n);
/***************************************************************************************************************************************************************************/

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
void SumaMatrices(float *p1, float *q1, float *r1, int m, int n);
/***************************************************************************************************************************************************************************/

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
void RestaMatrices(float *p1, float *q1, float *r1, float m, float n);
/***************************************************************************************************************************************************************************/

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
void ProductoMatrizVector(float *p1, float *q1, float *r1, int m, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicación de una matriz A[m][n].
    La dirección del prmier elemento de A se guarda en p1; esc es el número escalar por
    el cuál se multiplicará la matriz; m y n son el número de columnas y
    renglones respectivamente de las matrices A y B.
    La función se llama con la siguiente instrucción:
    ProductoMatrizEscalar(&A[0][0], esc, m, n)
*/
void ProductoMatrizEscalar(float *p1, float esc, int m, int n);
/***************************************************************************************************************************************************************************/

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
void ProductoMatrices(float *p1, float *q1, float *r1, int m, int n, int k);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicación de una matriz A[m][n] y una matriz  B[m][k],
    el resultado se guarda en C[m][k]. La matriz resultante se llena de columna en columna
    y de izquierda a derecha. La dirección del primer elemento de A se guarda en p1, la dirección
    del primer elemento de B se guarda en q1 y la dirección del primer elemento de C se guarda en r1.
    m es el número de renglones de las matrices A y C, n es el número de columnas de A y k es el número
    de columnas de las matrices B y C. La función se llama con la siguiente instrucción:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatCol_IzqDer(float *p1, float *q1, float *r1, int m, int n, int k);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicación de una matriz A[m][n] y una matriz  B[m][k], el resultado se guarda en C[m][k].
    La matriz resultante se llena renglón por renglón comenzando desde el final hacia el primer elemento. (Se llena al revés
    que la multiplicación convencional). La dirección del primer elemento de A se guarda en p1, la dirección del primer elemento
    de B se guarda en q1 y la dirección del primer elemento de C se guarda en r1. m es el número de renglones de las matrices A
    y C, n es el número de columnas de A y k es el número de columnas de las matrices B y C. La función se llama con la siguiente
    instrucción:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatRen_Abajo_y_DerIzq(float *p1, float *q1, float *r1, int m, int n, int k);


/********************SISTEMAS DE ECUACIONES LINEALES********************/

/*
Esta función intercambia dos regiones de memoria. En la resolución de sistemas de ecuaciones, esta subrutina nos
ayudará intercambiando renglones de matrices. La dirección del primer renglón se encuentra en p, la dirección del
segundo renglón se encuentra en q, n es el número de elementos con los que cuentan los renglones. La función se llama
con la siguiente instrucción:
Intercambiar(p, q, n);
*/
void Intercambiar(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta función divide entre el número pivote todo un renglón (o parte de éste) de una matriz.
La dirección del renglón se encuentra en p, n es el número de elementos con
los que cuenta el renglón. Se regresa el valor del pivote. La subrutina se llama con la instrucción:
HacerUno(p, n);
*/
float HacerUno(float *p, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina divide entre un pivote todas las componentes de un renglón de una matriz. Se usará para modificar la matriz
identidad al momento de calcular una matriz inversa. p es la dirección del renglón de la matriz identidad, valor es el valor
del pivote, n es el número de elementos con los que cuenta el renglón. La función se llama con la siguiente instrucción:
HacerUno_Mat(p, valorPivote, n).
*/
void HacerUno_Mat(float*p, float valor, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina modifica una región de memoria (renglón de la matriz identidad) al momento de hacer ceros debajo del pivote de la matriz original
al buscar una matriz inversa. Deberemos aplicar la misma operación que aplicamos en el renglón de la matriz original a todos los demás elementos
del renglón correspondiente en la matriz identidad. p almacena la dirección del "renglón de abajo" que nos auxiliará para modificar el "renglón
de arriba" cuya dirección se encuentra en q; valor almacena el valor que se utilizó para lograr un cero en la matriz original. n es el número
de elementos con los que cuenta el renglón de la matriz identidad.
*/
void HacerCero_Mat(float*p, float *q, float valor, int n);
/***************************************************************************************************************************************************************************/

/*
Esta función divide entre el número pivote todo un renglón (o parte de éste) de una matriz pero lo hace de
derecha a izquierda. La dirección del renglón se encuentra en p, n es el número de elementos con
los que cuenta el renglón. Se regresa el valor del pivote, es decir, el número por el cuál se dividió
el renglón. La subrutina se llama con la instrucción:
HacerUno_DerIzq(p, n);
*/
float HacerUno_DerIzq(float *p, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de algún pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operación a todo el renglón en donde el cero se produjo. p es la dirección del "renglón de arriba"
donde se encuentra el pivote; q es la dirección del "renglón de abajo" donde se producirá el cero, n es el número de
elementos con el que cuentan los renglones. Se regresa el valor que pertenecía al elemento que se hizo cero para
usarlo posteriormente en la modificación del vector del sistema de ecuaciones. La función se llama con la sentencia:
HacerCero(p, q, n);
*/
 float HacerCero(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de algún pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operación a todo el renglón en donde el cero se produjo. Este procedimiento, en este caso, se
efectúa de derecha a izquierda. p es la dirección del "renglón de arriba" donde se encuentra el pivote; q es la dirección
del "renglón de abajo" donde se producirá el cero, n es el número de elementos con el que cuentan los renglones. Se regresa
el valor que pertenecía al elemento que se hizo cero para usarlo posteriormente en la modificación del vector del sistema de
ecuaciones. La función se llama con la sentencia:
HacerCero_DerIzq(p, q, n);
*/
float HacerCero_DerIzq(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz y lograr unos en la diagonal principal; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector,
n es la dimensión del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz(&A[0][0], v, n).
*/
void ReducirMatriz(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros a la derecha; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector, n es la dimensión
del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosAbajoDer(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros abajo y a la derecha.
p almacena la direccion de la matriz A[n][n], q es la dirección del vector v de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se llama con la siguiente sentencia:
ResolverSEL_CerosAbajoDer(&A[0][0], v, n)
*/
void ResolverSEL_CerosAbajoDer(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros abajo y a la izquierda (forma normal).
p almacena la direccion de la matriz A[n][n]; q es la dirección del vector de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se invoca con la siguiente llamada:
ResolverSEL(&A[0][0], v, n)
*/
void ResolverSEL(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros arriba y a la derecha; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector, n es la dimensión
del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaDer(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular superior con los ceros arriba y a la izquierda; a su vez, también modifica
el vector del sistema de ecuaciones. p es la dirección de la matriz A que se reducirá, v es la dirección del vector, n es la dimensión
del sistema de ecuaciones. La función se invoca con la siguiente sentencia:
ReducirMatriz_CerosArribaIzq(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaIzq(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros arriba y a la izquierda.
p almacena la direccion de la matriz A[n][n]; q es la dirección del vector de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se invoca con la siguiente llamada:
ResolverSEL_CerosArribaIzq(&A[0][0], v, n)
*/
void ResolverSEL_CerosArribaIzq(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros arriba y a la derecha.
p almacena la direccion de la matriz A[n][n]; q es la dirección del vector de magnitud n; la variable n es el tamaño de la matriz y el vector.
La función se invoca con la siguiente llamada:
ResolverSEL_CerosArribaDer(&A[0][0], v, n)
*/
void ResolverSEL__CerosArribaDer(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina calcula la inversa de una matriz A[n][n]. p Es la dirección de la matriz A; q es la dirección en donde queremos que el resultado se almacene;
n es el orden de las matrices.
*/
void MatrizInversa(float *p, float *q, int n);

#endif // ALGEBRALINEAL_H_INCLUDED
