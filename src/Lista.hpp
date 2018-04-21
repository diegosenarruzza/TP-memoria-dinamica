#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    // Completar
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; } 

template <typename T>
Lista<T>::~Lista() {
    // Completar
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    // Completar
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    // Completar
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Completar
}

template <typename T>
int Lista<T>::longitud() const {
    // Completar
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    // Completar
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
	// Completar
}
