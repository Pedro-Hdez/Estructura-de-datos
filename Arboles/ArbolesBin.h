#ifndef ARBOLESBIN_H_INCLUDED
#define ARBOLESBIN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

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
    int borrar1(int a);

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
    nodo *p;
    p = principio;
    while(p){

        (p->padre == NULL ?   padre = "null" : padre = to_string(p->padre->valor) );
        (p->hizq == NULL ?   hizq = "null" : hizq = to_string(p->hizq->valor) );
        (p->hder == NULL ?   hder = "null" : hder = to_string(p->hder->valor) );

        cout << "NODO: " << p->valor << endl << "PADRE: " << padre << endl
             << "HIJO IZQU: " << hizq << endl << "HIJO DER: " << hder << endl << endl;
        p = p->siguiente;
    }
}

int arbol::borrar1(int a){
    buscar(a);

    if(encontrado == NO) return (0);

    nodo *p;
    if(como == HIZQ) p = donde->hizq;
    else p = donde->hder;

    //CASO DE BORRAR UN NODO SIN HIJOS
    if(p->hizq == NULL && p->hder == NULL){
        //Se desconecta del padre haciendo Null su respectiva rama
        if(como == RAIZ){
            delete p;
            raiz = principio = fin = NULL;
            return(1);
        }
        else{
            if(como == HIZQ) donde->hizq = NULL;
            else donde -> hder = NULL;

            if(p == principio){
                principio = p->siguiente;
                (p->siguiente)->anterior = NULL;
            }
            else if(p == fin){
                fin = p->anterior;
                (p->anterior)->siguiente = NULL;

            }
            else{
                (p->anterior)->siguiente = p->siguiente;
                (p->siguiente)->anterior = p->anterior;
            }
            delete p;
        }
    }
    //CASO DE BORRAR NODOS CON UN SOLO HIJO
    else{
        //EL NODO SE DESCONECTA DEL ARBOL
        if(como == HIZQ){
            if(p->hizq == NULL){
                (p->padre)->hizq = p->hder;
                (p->hder)->padre = p->padre;
            }
            else{
                (p->padre)->hizq = p->hizq;
                (p->hizq)->padre = p->padre;
            }
        }
        else{
            if(p->hizq == NULL){
                (p->padre)->hder = p->hder;
                (p->hder)->padre = p->padre;
            }
            else{
                (p->padre)->hder = p->hizq;
                (p->hizq)->padre = p->padre;
            }

        }
        //SE AJUSTA LA LISTA ORDENADA
        if(p == principio){
            principio = p->siguiente;
            (p->siguiente)->anterior = NULL;
        }
        else if(p == fin){
            fin = p->anterior;
            (p->anterior)->siguiente = NULL;

        }
        else{
            (p->anterior)->siguiente = p->siguiente;
            (p->siguiente)->anterior = p->anterior;
        }
        delete p;
    }
}


#endif // ARBOLESBIN_H_INCLUDED
