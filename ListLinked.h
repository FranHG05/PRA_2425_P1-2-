#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;  // Puntero al primer nodo de la lista enlazada
    int n;            // Número de elementos en la lista

public:
    // Constructor sin argumentos
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;  // Liberar el nodo actual
            first = aux;   // Avanzar al siguiente nodo
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;  // Avanzar hasta la posición deseada
        }

        return current->data;  // Devolver el dato almacenado en esa posición
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";  // Imprimir el dato de cada nodo
            current = current->next;  // Avanzar al siguiente nodo
        }
        return out;  // Retornar el flujo de salida
    }

    // Implementación de insert (insertar en posición específica)
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* newNode = new Node<T>(e);  // Crear un nuevo nodo con el dato
        if (pos == 0) {  // Insertar al principio
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;  // Avanzar hasta la posición anterior
            }
            newNode->next = current->next;  // Apuntar al siguiente nodo
            current->next = newNode;  // Insertar el nuevo nodo
        }
        n++;  // Aumentar el número de elementos
    }

    // Implementación de append (insertar al final)
    void append(T e) override {
        Node<T>* newNode = new Node<T>(e);  // Crear un nuevo nodo con el dato
        if (first == nullptr) {  // Si la lista está vacía
            first = newNode;
        } else {
            Node<T>* current = first;
            while (current->next != nullptr) {
                current = current->next;  // Buscar el último nodo
            }
            current->next = newNode;  // Insertar el nuevo nodo al final
        }
        n++;  // Aumentar el número de elementos
    }

    // Implementación de prepend (insertar al principio)
    void prepend(T e) override {
        Node<T>* newNode = new Node<T>(e, first);  // Crear un nuevo nodo con el dato
        first = newNode;  // El primer nodo ahora es el nuevo nodo
        n++;  // Aumentar el número de elementos
    }

    // Implementación de remove (eliminar por posición)
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* current = first;
        if (pos == 0) {  // Eliminar el primer nodo
            first = first->next;
            T data = current->data;
            delete current;  // Liberar la memoria del nodo
            n--;
            return data;
        }

        // Buscar el nodo anterior al que queremos eliminar
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        Node<T>* toDelete = current->next;
        current->next = toDelete->next;  // Eliminar el nodo
        T data = toDelete->data;
        delete toDelete;  // Liberar la memoria del nodo
        n--;
        return data;  // Retornar el dato eliminado
    }

    // Implementación de get (obtener el elemento por posición)
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;  // Avanzar hasta la posición deseada
        }
        return current->data;  // Devolver el dato en esa posición
    }

    // Implementación de search (buscar un elemento)
    int search(T e) override {
        Node<T>* current = first;
        for (int i = 0; i < n; ++i) {
            if (current->data == e) {
                return i;  // Retornar la posición del primer nodo que contiene el dato
            }
            current = current->next;  // Avanzar al siguiente nodo
        }
        return -1;  // Si el dato no se encuentra, retornar -1
    }

    // Implementación de empty (verificar si la lista está vacía)
    bool empty() override {
        return n == 0;  // Si el número de elementos es 0, la lista está vacía
    }

    // Implementación de size (obtener el tamaño de la lista)
    int size() override {
        return n;  // Retornar el número de elementos
    }
};



