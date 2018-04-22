#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
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
    delete actual;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    longitud = l.longitud;

    //Solo quiero crear una lista nueva con los valores de l

    Nodo* actual = primero;
    Nodo* l_actual = l.primero;

    //Necesito tomar los valores que haya en los punteros y crear nuevos punteros con esos valores
    while(l_actual!=NULL) {
        actual->valor = l_actual->_valor;



    }

}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    //Creo el nodo que va a ir al principio
    Nodo* nuevoPrimero;
    nuevoPrimero->anterior = NULL;
    nuevoPrimero->_valor = elem;
    nuevoPrimero->siguiente = &primero;

    //Al anterior, del primero, le asigno la direccion en memoria del nuevo nodo
    primero->anterior = &nuevoPrimero;

    //Elimino el puntero nuevoPrimero
    delete nuevoPrimero;

    //Sumo uno a la longitud
    longitud++;

}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Creo el nodo que va a ir al final
    Nodo* nuevoUltimo;
    nuevoUltimo->anterior = &ultimo;
    nuevoUltimo->_valor = elem;
    nuevoUltimo->siguiente = NULL;

    //Al siguiente, del ultimo, le asigno la direccion en memoria del nuevo nodo
    ultimo->siguiente = &nuevoUltimo;

    //Elimino el puntero nuevoUltimo
    delete nuevoUltimo;

    //Sumo uno a la longitud
    longitud++;
}

template <typename T>
int Lista<T>::longitud() const {
    return  longitud;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nat j=0;
    Nodo* i_nodo = primero;
    //Busco el iesimo nodo
    while(j<i){
        i_nodo = i_nodo->siguiente;
        j++;
    }
    //Devuelvo el valor ubicado en la direccion de memoria del iesimo nodo
    return i_nodo->_valor;
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

    //Achico la longitud
    longitud--;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    T iesimo;
    Nat j=0;
    Nodo* nodovalor = primero;
    while(j<i){
        iesimo = nodovalor->_valor;
        nodovalor = nodovalor->siguiente;
        j++;
    }
    return iesimo;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
	// Completar
}
