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
    //Paso facil, igualo longitudes
    longitud = l.longitud;

    //actual apunta a la direccion en memoria de el primero, y va a ir cambiando para ir recorriendo
    Nodo* actual = &primero;
    //l_actual, lo uso para ir tomando y copiando los valores
    Nodo* l_actual = &l.primero;

    while(l_actual!=NULL) {
        Nodo* next;
        //Siguiente de actual apunta a next
        actual->siguiente = &next;
        //Anteior de next apunta a nodo actual
        next->anterior = &actual;
        next->_valor = l_actual->_valor;

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
    for (int i = 0; i <longitud ; i++) {
        cout << this->iesimo(i) << "\n" ;
    }


}
