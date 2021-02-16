/*
    Nombre: AlgebraLineal.h
    Autor: Pedro Andr�s Hern�ndez Amador.
    Fecha: enero del 2019

    Descripci�n: Archivo de cabecera que contiene los prototipos de las funciones
                 que realizan operaciones con vectores y matrices.
*/

#ifndef ALGEBRALINEAL_H_INCLUDED
#define ALGEBRALINEAL_H_INCLUDED

/*
    Esta subrutina calcula la suma de 2 vectores.
    La direcci�n de los vectores que se suman est�n
    en p1 y q1; el resultado en r1. El tama�o de los
    vectores es n.
    La funci�n se llama con la instrucci�n:
    SumaVectores(p, q, r, n)
*/
void SumaVector(int *p1, int *q1, int *r1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la resta de 2 vectores.
    La direcci�n de los vectores que se suman est�n
    en p1 y q1; el resultado en r1. El tama�o de los
    vectores es n.
    La funci�n se llama con la instrucci�n:
    SumaVectores(p, q, r, n)
*/
void RestaVector(int *p1, int *q1, int *r1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula el producto punto entre 2 vectores.
    La direcci�n de los vectores est�n en p1 y q1; n es el
    tama�o de los vectores. El valor regresado es el resultado
    de esta operaci�n.
    La funci�n se llama con la instrucci�n:
    ProductoPunto(p, q, n)
*/
float ProductoPunto(float *p1, float *q1, float n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la longitud de un vector.
    La direcci�n del vector est� en p1, n es el
    tama�o del vector. El valor regresado es el resultado
    de esta operaci�n.
    La funci�n se llama con la instrucci�n:
    NormaVector(p, n)
*/
float NormaVector(float *p1, float n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula el �ngulo entre 2 vectores.
    La direcci�n de los vectores est�n en p1 y q1; n es el
    tama�o de los vectores. El valor regresado es el resultado
    de esta operaci�n.
    La funci�n se llama con la instrucci�n:
    AnguloVectores(p, q, n)
*/
float AnguloVectores(float *p1, float *q1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina imprime un vector con n�meros reales como componentes. La direcci�n de �ste
    est� en p1 y n es su tama�o. La funci�n se llama con la instrucci�n:
    ImprimeVector(p, n)
*/
void ImprimeVector(float *p1, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina imprime una matriz. La direcci�n del primer
    elemento de la matriz est� en p1; m es el n�mero de renglones
    y n es el n�mero de columnas.
    La funci�n se llama con la instrucci�n:
    ImprimeMatriz(p, m, n)
*/
void ImprimeMatriz(float *p1, int m, int n);
/***************************************************************************************************************************************************************************/

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
void SumaMatrices(float *p1, float *q1, float *r1, int m, int n);
/***************************************************************************************************************************************************************************/

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
void RestaMatrices(float *p1, float *q1, float *r1, float m, float n);
/***************************************************************************************************************************************************************************/

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
void ProductoMatrizVector(float *p1, float *q1, float *r1, int m, int n);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n].
    La direcci�n del prmier elemento de A se guarda en p1; esc es el n�mero escalar por
    el cu�l se multiplicar� la matriz; m y n son el n�mero de columnas y
    renglones respectivamente de las matrices A y B.
    La funci�n se llama con la siguiente instrucci�n:
    ProductoMatrizEscalar(&A[0][0], esc, m, n)
*/
void ProductoMatrizEscalar(float *p1, float esc, int m, int n);
/***************************************************************************************************************************************************************************/

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
void ProductoMatrices(float *p1, float *q1, float *r1, int m, int n, int k);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n] y una matriz  B[m][k],
    el resultado se guarda en C[m][k]. La matriz resultante se llena de columna en columna
    y de izquierda a derecha. La direcci�n del primer elemento de A se guarda en p1, la direcci�n
    del primer elemento de B se guarda en q1 y la direcci�n del primer elemento de C se guarda en r1.
    m es el n�mero de renglones de las matrices A y C, n es el n�mero de columnas de A y k es el n�mero
    de columnas de las matrices B y C. La funci�n se llama con la siguiente instrucci�n:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatCol_IzqDer(float *p1, float *q1, float *r1, int m, int n, int k);
/***************************************************************************************************************************************************************************/

/*
    Esta subrutina calcula la multiplicaci�n de una matriz A[m][n] y una matriz  B[m][k], el resultado se guarda en C[m][k].
    La matriz resultante se llena rengl�n por rengl�n comenzando desde el final hacia el primer elemento. (Se llena al rev�s
    que la multiplicaci�n convencional). La direcci�n del primer elemento de A se guarda en p1, la direcci�n del primer elemento
    de B se guarda en q1 y la direcci�n del primer elemento de C se guarda en r1. m es el n�mero de renglones de las matrices A
    y C, n es el n�mero de columnas de A y k es el n�mero de columnas de las matrices B y C. La funci�n se llama con la siguiente
    instrucci�n:
    ProductoMatrizVector(&A[0][0], &B[0][0], &C[0][0], m, n, k)
*/
void ProdMatRen_Abajo_y_DerIzq(float *p1, float *q1, float *r1, int m, int n, int k);


/********************SISTEMAS DE ECUACIONES LINEALES********************/

/*
Esta funci�n intercambia dos regiones de memoria. En la resoluci�n de sistemas de ecuaciones, esta subrutina nos
ayudar� intercambiando renglones de matrices. La direcci�n del primer rengl�n se encuentra en p, la direcci�n del
segundo rengl�n se encuentra en q, n es el n�mero de elementos con los que cuentan los renglones. La funci�n se llama
con la siguiente instrucci�n:
Intercambiar(p, q, n);
*/
void Intercambiar(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta funci�n divide entre el n�mero pivote todo un rengl�n (o parte de �ste) de una matriz.
La direcci�n del rengl�n se encuentra en p, n es el n�mero de elementos con
los que cuenta el rengl�n. Se regresa el valor del pivote. La subrutina se llama con la instrucci�n:
HacerUno(p, n);
*/
float HacerUno(float *p, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina divide entre un pivote todas las componentes de un rengl�n de una matriz. Se usar� para modificar la matriz
identidad al momento de calcular una matriz inversa. p es la direcci�n del rengl�n de la matriz identidad, valor es el valor
del pivote, n es el n�mero de elementos con los que cuenta el rengl�n. La funci�n se llama con la siguiente instrucci�n:
HacerUno_Mat(p, valorPivote, n).
*/
void HacerUno_Mat(float*p, float valor, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina modifica una regi�n de memoria (rengl�n de la matriz identidad) al momento de hacer ceros debajo del pivote de la matriz original
al buscar una matriz inversa. Deberemos aplicar la misma operaci�n que aplicamos en el rengl�n de la matriz original a todos los dem�s elementos
del rengl�n correspondiente en la matriz identidad. p almacena la direcci�n del "rengl�n de abajo" que nos auxiliar� para modificar el "rengl�n
de arriba" cuya direcci�n se encuentra en q; valor almacena el valor que se utiliz� para lograr un cero en la matriz original. n es el n�mero
de elementos con los que cuenta el rengl�n de la matriz identidad.
*/
void HacerCero_Mat(float*p, float *q, float valor, int n);
/***************************************************************************************************************************************************************************/

/*
Esta funci�n divide entre el n�mero pivote todo un rengl�n (o parte de �ste) de una matriz pero lo hace de
derecha a izquierda. La direcci�n del rengl�n se encuentra en p, n es el n�mero de elementos con
los que cuenta el rengl�n. Se regresa el valor del pivote, es decir, el n�mero por el cu�l se dividi�
el rengl�n. La subrutina se llama con la instrucci�n:
HacerUno_DerIzq(p, n);
*/
float HacerUno_DerIzq(float *p, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de alg�n pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operaci�n a todo el rengl�n en donde el cero se produjo. p es la direcci�n del "rengl�n de arriba"
donde se encuentra el pivote; q es la direcci�n del "rengl�n de abajo" donde se producir� el cero, n es el n�mero de
elementos con el que cuentan los renglones. Se regresa el valor que pertenec�a al elemento que se hizo cero para
usarlo posteriormente en la modificaci�n del vector del sistema de ecuaciones. La funci�n se llama con la sentencia:
HacerCero(p, q, n);
*/
 float HacerCero(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de hacer cero un elemento debajo de alg�n pivote en alguna matriz. Al hacer esto se debe
aplicar la misma operaci�n a todo el rengl�n en donde el cero se produjo. Este procedimiento, en este caso, se
efect�a de derecha a izquierda. p es la direcci�n del "rengl�n de arriba" donde se encuentra el pivote; q es la direcci�n
del "rengl�n de abajo" donde se producir� el cero, n es el n�mero de elementos con el que cuentan los renglones. Se regresa
el valor que pertenec�a al elemento que se hizo cero para usarlo posteriormente en la modificaci�n del vector del sistema de
ecuaciones. La funci�n se llama con la sentencia:
HacerCero_DerIzq(p, q, n);
*/
float HacerCero_DerIzq(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz y lograr unos en la diagonal principal; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector,
n es la dimensi�n del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz(&A[0][0], v, n).
*/
void ReducirMatriz(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros a la derecha; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector, n es la dimensi�n
del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosAbajoDer(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros abajo y a la derecha.
p almacena la direccion de la matriz A[n][n], q es la direcci�n del vector v de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se llama con la siguiente sentencia:
ResolverSEL_CerosAbajoDer(&A[0][0], v, n)
*/
void ResolverSEL_CerosAbajoDer(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros abajo y a la izquierda (forma normal).
p almacena la direccion de la matriz A[n][n]; q es la direcci�n del vector de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se invoca con la siguiente llamada:
ResolverSEL(&A[0][0], v, n)
*/
void ResolverSEL(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular inferior con los ceros arriba y a la derecha; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector, n es la dimensi�n
del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz_CerosAbajoDer(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaDer(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina se encarga de escalonar una matriz de manera triangular superior con los ceros arriba y a la izquierda; a su vez, tambi�n modifica
el vector del sistema de ecuaciones. p es la direcci�n de la matriz A que se reducir�, v es la direcci�n del vector, n es la dimensi�n
del sistema de ecuaciones. La funci�n se invoca con la siguiente sentencia:
ReducirMatriz_CerosArribaIzq(&A[0][0], v, n).
*/
void ReducirMatriz_CerosArribaIzq(float *p, float *v, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros arriba y a la izquierda.
p almacena la direccion de la matriz A[n][n]; q es la direcci�n del vector de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se invoca con la siguiente llamada:
ResolverSEL_CerosArribaIzq(&A[0][0], v, n)
*/
void ResolverSEL_CerosArribaIzq(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina resuelve un sistema de ecuaciones lineales de n x n que previamente se ha reducido con ceros arriba y a la derecha.
p almacena la direccion de la matriz A[n][n]; q es la direcci�n del vector de magnitud n; la variable n es el tama�o de la matriz y el vector.
La funci�n se invoca con la siguiente llamada:
ResolverSEL_CerosArribaDer(&A[0][0], v, n)
*/
void ResolverSEL__CerosArribaDer(float *p, float *q, int n);
/***************************************************************************************************************************************************************************/

/*
Esta subrutina calcula la inversa de una matriz A[n][n]. p Es la direcci�n de la matriz A; q es la direcci�n en donde queremos que el resultado se almacene;
n es el orden de las matrices.
*/
void MatrizInversa(float *p, float *q, int n);

#endif // ALGEBRALINEAL_H_INCLUDED
