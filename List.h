#ifndef LIST_H
#define LIST_H

#include <stdexcept> // Para std::out_of_range

template <typename T>
class List {
public:
    virtual ~List() = default; // Destructor virtual para garantizar la limpieza adecuada

    // Inserta el elemento e en la posición pos.
    // Lanza std::out_of_range si la posición es inválida.
    virtual void insert(int pos, T e) = 0;

    // Inserta el elemento e al final de la lista.
    virtual void append(T e) = 0;

    // Inserta el elemento e al principio de la lista.
    virtual void prepend(T e) = 0;

    // Elimina y devuelve el elemento en la posición pos.
    // Lanza std::out_of_range si la posición es inválida.
    virtual T remove(int pos) = 0;

    // Devuelve el elemento en la posición pos.
    // Lanza std::out_of_range si la posición es inválida.
    virtual T get(int pos) = 0;

    // Devuelve la posición de la primera ocurrencia del elemento e,
    // o -1 si no se encuentra.
    virtual int search(T e) = 0;

    // Indica si la lista está vacía.
    virtual bool empty() = 0;

    // Devuelve el número de elementos en la lista.
    virtual int size() = 0;
};

#endif // LIST_H
