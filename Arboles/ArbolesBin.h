#ifndef ARBOLESBIN_H_INCLUDED
#define ARBOLESBIN_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//ptueb

struct nodo{
    nodo *padre, *hder, *hizq, *anterior, *siguiente;
    int valor;
};
/***************************************************************************************************************************************************/

class arbol{
    nodo *donde, *raiz, *principio, *fin;
    int encontrado, como;
    enum encontrado {SI, NO};
    enum como {HDER, HIZQ, RAIZ};

public:
    arbol();
    ~arbol();
    void buscar (int a);
    int agregar(int a);
    void pintar();
    int borrar(int a);
    void borrar1(nodo *p1);
    void intercambiar(nodo *p, nodo *q);

};
//------------------------------------------------------------------------------------------------------------------------------------//

arbol::arbol(){
    donde = raiz = principio = fin = NULL;
    encontrado = NO;
    donde = NULL;
    como = RAIZ;
}
//------------------------------------------------------------------------------------------------------------------------------------//

arbol::~arbol(){
    nodo *p;
    while(principio){
        p = principio;
        principio = p -> siguiente;
        delete p;
    }
    donde = raiz = principio = fin = NULL;
    encontrado = NO;
    donde = NULL;
    como = RAIZ;
    return;
}
//------------------------------------------------------------------------------------------------------------------------------------//

void arbol::buscar(int a){
    nodo *p;
    p = raiz;

    //Si el árbol está vacío, entonces el nodo automáticamente se agregará como raiz
    if(p == NULL){
        encontrado = NO;
        donde = NULL;
        como = RAIZ;

        return;
    }

    while(p){
        if(p->valor == a){
            encontrado = SI;
            if(p == raiz){
                donde = NULL;
                como = RAIZ;
                return;
            }

            donde = p->padre;
            if(donde -> hder == p){
                como = HDER;
            }
            else{
                como = HIZQ;
            }
            return;
        }
        else if(p -> valor > a){
            if(p->hizq == NULL){
                encontrado = NO;
                donde = p;
                como = HIZQ;
                return;
            }
            else{
                donde = p;
                p = p->hizq;
            }
        }
        if(p->valor < a){
            if(p->hder == NULL){
                encontrado = NO;
                donde = p;
                como = HDER;
                return;
            }
            else{
                donde = p;
                p = p->hder;
            }
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------//

int arbol::agregar(int a){
    nodo *p;
    buscar(a);

    if(encontrado == SI) return(0);

    p = new nodo;
    p -> valor = a;
    p->hder = p->hizq = p->anterior = p->padre = p->siguiente = NULL;

    //ARBOL
    if(como == RAIZ){
        raiz = p;
        p->padre = NULL;
    }
    else if(como == HDER){
        donde->hder = p;
        p->padre = donde;
    }
    else{
        donde->hizq = p;
        p->padre = donde;
    }

    //LISTA DOBLE
    if(como == RAIZ){
        p->anterior = p->siguiente = NULL;
        principio = p;
        fin = p;
        return(1);
    }
    if(como == HDER){
        p->anterior = donde;
        p->siguiente = donde->siguiente;
        donde->siguiente = p;
        if(p->siguiente == NULL){
            fin = p;
        }
        else{
            (p->siguiente)->anterior = p;
        }
    }
    else{
        p->siguiente = donde;
        p->anterior = donde->anterior;
        donde -> anterior = p;
        if(p->anterior == NULL){
            principio = p;
        }
        else{
            (p->anterior)->siguiente = p;
        }
    }
    return(1);
}
//------------------------------------------------------------------------------------------------------------------------------------//

void arbol::pintar(){
    std::string padre = "";
    std::string hizq = "";
    std::string hder = "";
    std::string valor = "";
    stringstream ss;
    nodo *p;
    p = principio;


    while(p){
        if(raiz == NULL){
        valor = "Arbol vacío";
        }
        else{
            ss << p->valor;
            valor = ss.str();
        }
        ss.str("");

        if(p->padre == NULL){
            padre = "null";
        }
        else{
            ss << p->padre->valor;
            padre = ss.str();
        }
        ss.str("");

        if(p->hizq == NULL){
            hizq = "null";
        }
        else{
            ss << p->hizq->valor;
            hizq = ss.str();
        }
        ss.str("");

        if(p->hder == NULL){
            hder = "null";
        }
        else{
            ss << p->hder->valor;
            hder = ss.str();
        }
        ss.str("");

        cout << "NODO: " << valor << endl << "PADRE: " << padre << endl
             << "HIJO IZQU: " << hizq << endl << "HIJO DER: " << hder << endl << endl;
        p = p->siguiente;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------

void arbol::intercambiar(nodo *p, nodo *q){
    nodo *r;

    //Caso en el que p está arriba
    if(q->padre == p){
        if(p->hder == q){ //q cuelga como hijo derecho
            //Intercambias los padres
            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            //Intercambias los hijos derechos
            r = p->hder;
            p->hder = q->hder;
            q->hder = r;

            //Intercambias los hijos izquierdos
            r = p->hizq;
            p->hizq = q->hizq;
            q->hizq = r;
            //Arreglas a mano los punteros en conflicto
            q->hder = p;
            p->padre = q;
        }
        else{ //q cuelga como hijo izquierdo
            //Intercambias los padres
            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            //Intercambias los hijos derechos
            r = p->hder;
            p->hder = q->hder;
            q->hder = r;

            //Intercambias los hijos izquierdos
            r = p->hizq;
            p->hizq = q->hizq;
            q->hizq = r;

            q->hizq = p;
            p->padre = q;
        }
    }
    else if(p->padre == q){ //Caso en el que q está arriba
        if(q->hder == p){ //p cuelga como hijo derecho
            //Intercambias los padres
            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            //Intercambias los hijos derechos
            r = p->hder;
            p->hder = q->hder;
            q->hder = r;

            //Intercambias los hijos izquierdos
            r = p->hizq;
            p->hizq = q->hizq;
            q->hizq = r;

            p->hder = q;
            q->padre = p;
        }
        else{ //p cuelga como hijo izquierdo
            //Intercambias los padres
            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            //Intercambias los hijos derechos
            r = p->hder;
            p->hder = q->hder;
            q->hder = r;

            //Intercambias los hijos izquierdos
            r = p->hizq;
            p->hizq = q->hizq;
            q->hizq = r;

            p->hizq = q;
            q->padre = p;
        }
    }
    else{
        //Intercambias los padres
        r = p->padre;
        p->padre = q->padre;
        q->padre = r;

        //Intercambias los hijos derechos
        r = p->hder;
        p->hder = q->hder;
        q->hder = r;

        //Intercambias los hijos izquierdos
        r = p->hizq;
        p->hizq = q->hizq;
        q->hizq = r;
    }

    //SE ARREGLAN LOS VECINOS

    //Se conectan los padres
    if(q->padre == NULL) raiz = q;
    else{
        if(q->padre->hder == p) q->padre->hder = q;
        else q->padre->hizq = q;
    }

    if(p->padre == NULL) raiz = p;
    else{
        if(p->padre->hder == q) p->padre->hder = p;
        else p->padre->hizq = p;
    }

    //Se conectan los hijoz.
    if(q -> hizq != NULL) q->hizq->padre = q;
    if(q->hder != NULL) q->hder->padre = q;

    if(p->hizq != NULL) p->hizq ->padre = p;
    if(p->hder != NULL) p->hder->padre = p;
}

int arbol::borrar(int a){
    nodo *p;
    buscar(a);

    if(encontrado == NO) return(0);

    if(como == RAIZ){
        p = raiz;
    }
    else if(como == HDER){
        p = donde->hder;
    }
    else{
        p = donde->hizq;
    }

    if(p->hder != NULL && p->hizq != NULL){
        intercambiar(p, p->anterior);
    }

    //SE AJUSTAN LAS VARIABLES 'donde' Y 'como' PARA PODER IMPLEMENTAR EL BORRAR1
    donde = p->padre;
    if(p->padre->hizq == p) como = HIZQ;
    else como = HDER;

    borrar1(p);

    return(1);
}

void arbol::borrar1(nodo *p1){
    nodo *p = p1;

    //EL NODO SE DESCONECTA DEL ÁRBOL
    if(p->hder == NULL && p->hizq == NULL){ //CASO DE NODO SIN HIJOS
        //¿Caso de ser raiz?
        if(como == RAIZ){
            raiz = NULL;
        }

        //SE VERIFICA SI CUELGA COMO HIJO IZQUIERDO O DERECHO
        else if(como == HDER){
            donde->hder = NULL;
        }
        else{
            donde->hizq = NULL;
        }
    }
    else if(p->hder != NULL){
        //¿Checamos caso raiz?
        if(como == RAIZ){
            raiz = (p->hder);
            (p->hder)->padre = NULL;
        }
        else if(como == HDER){
            (donde->hder) = (p->hder);
            (p->hder)->padre = donde;
        }
        else{
            (donde->hizq)=p->hder;
            (p->hder)->padre = donde;
        }
    }
    else{
        //¿Checamos caso raiz?
        if(como == RAIZ){
            raiz = (p->hizq);
            (p->hizq)->padre = NULL;
        }
        else if(como == HDER){
            (donde->hder) = p->hizq;
            (p->hizq)->padre = donde;
        }
        else{
            (donde->hizq) = p->hizq;
            (p->hizq)->padre = donde;
        }
    }

    //EL NODO SE DESCONECTA DE LA RAIZ
    if(p == principio){
        if(principio == fin){
            principio = fin = NULL;
        }
        else{
            principio = p->siguiente;
            (p->siguiente)->anterior = NULL;
        }

    }
    else if(p == fin){
        fin = p->anterior;
        (p->anterior)->siguiente = NULL;

    }
    else{
        (p->anterior)->siguiente = p->siguiente;
        (p->siguiente)->anterior = p->anterior;
    }

    //Se borra el nodo
    delete p;
}
#endif // ARBOLESBIN_H_INCLUDED
