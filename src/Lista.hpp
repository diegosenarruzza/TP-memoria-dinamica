#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    primero = NULL;
    ultimo = NULL;
    tamanio= 0;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; }

template <typename T>
Lista<T>::~Lista() {
    Nodo* next = primero;
    while(next!=NULL) {
        Nodo* actual = next;
        next = next->siguiente;
        delete actual;
    }
    delete next;

}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    //Paso facil, igualo longitudes
    tamanio= l.tamanio;

    //actual apunta a la direccion en memoria de el primero, y va a ir cambiando para ir recorriendo
    Nodo* actual = primero;
    //l_actual, lo uso para ir tomando y copiando los valores
    Nodo* l_actual = l.primero;

    while(l_actual!=NULL) {
        Nodo next;
        //Siguiente de actual apunta a next
        actual->siguiente = &next;
        //Anteior de next apunta a nodo actual
        next.anterior = actual;
        next._valor = l_actual->_valor;

        actual = &next;
        l_actual = l_actual->siguiente;
    }
    primero->anterior = NULL;
    ultimo = actual;
    ultimo->siguiente = NULL;

    //Elimino los 2 punteros que tengo demas
    delete actual;
    delete l_actual;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    //Creo el nodo que va a ir al principio
    Nodo nuevoPrimero;
    nuevoPrimero.anterior = NULL;
    nuevoPrimero._valor = elem;
    nuevoPrimero.siguiente = NULL;

    if(primero==NULL) {
      primero = &nuevoPrimero;
      ultimo = &nuevoPrimero;
    } else { //Si ya hay un elemento, el nuevo va a ser el primero
        primero->anterior = &nuevoPrimero;
        nuevoPrimero.siguiente = primero;
        ultimo = primero;
        primero = &nuevoPrimero;
    }

    //Sumo uno a la longitud
    tamanio++;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Creo el nodo que va a ir al final
    Nodo nuevoUltimo;
    nuevoUltimo.anterior = ultimo;
    nuevoUltimo._valor = elem;
    nuevoUltimo.siguiente = NULL;

    //Al siguiente, del ultimo, le asigno la direccion en memoria del nuevo nodo
    if(primero==NULL){ //Si la lista esta vacia, el unico elemento va a ser primero y ultimo
        primero = &nuevoUltimo;
        ultimo = &nuevoUltimo;
    } else { //Si ya hay un elemento, el nuevo va a ser el ultimo
        ultimo->siguiente = &nuevoUltimo;
        ultimo = &nuevoUltimo;
    }
    //Sumo uno a la longitudtamanio++;
    tamanio = tamanio+1;
}

template <typename T>
int Lista<T>::longitud() const {
    int largo = tamanio;
    return largo;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    T iesimo;
    Nat j=0;
    Nodo* i_nodo = primero;
    //Busco el iesimo nodo
    while(j<i){
        i_nodo = i_nodo->siguiente;
        j++;
    }
    //Devuelvo el valor ubicado en la direccion de memoria del iesimo nodo
    iesimo = i_nodo -> _valor;
    delete i_nodo;
    return iesimo;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nat j=0;
    Nodo* i_nodo = primero;
    //Busco el iesimo nodo
    while(j<i){
        i_nodo = i_nodo->siguiente;
        j++;
    }
    //Si existe un siguiente, le asigno el anterior del iesimo
    if(i_nodo->siguiente!=NULL) {
        i_nodo->siguiente->anterior = i_nodo->anterior;
    }
    //Si existe un anterior, le asigno el siguiente del iesimo
    if(i_nodo->anterior!=NULL) {
        i_nodo->anterior->siguiente = i_nodo->siguiente;
    }

    //Ahora tengo el iesimo con punteros repetidos, tengo que eliminarlo
    delete i_nodo;

    //Achico la longitudtamanio--;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    T iesimo;
    Nat j=0;
    Nodo* i_nodo = primero;
    while(j<i){
        i_nodo = i_nodo->siguiente;
        j++;
    }

    iesimo = i_nodo->_valor;
    delete i_nodo;
    return iesimo;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
    for (int i = 0; i <tamanio ; i++) {
        std::cout << this->iesimo(i) << "\n" ;
    }


}
