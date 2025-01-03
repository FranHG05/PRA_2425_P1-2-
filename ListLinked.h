#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        // Puntero al primer nodo de la secuencia enlazada que almacena los datos de la lista
        Node<T>* first;

        // Número de elementos que contiene la lista
        int n;

    public:
        // Método constructor sin argumentos. Inicializa los dos atributos de instancia
        ListLinked() : first(nullptr), n(0) {}

        // Método destructor. Libera la memoria dinámica reservada por los nodos Node<T>
        ~ListLinked() {
            Node<T>* aux;
            while (first != nullptr) {
                aux = first->next;  // El puntero auxiliar apunta al siguiente nodo
                delete first;       // Libera la memoria del nodo actual
                first = aux;        // Mueve first al siguiente nodo
            }
        }

        // Sobrecarga del operador []. Devuelve el elemento situado en la posición pos
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }
            return current->data;
        }

        // Sobrecarga global del operador << para imprimir una instancia de ListLinked<T>
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " ";
                current = current->next;
            }
            return out;
        }
};

