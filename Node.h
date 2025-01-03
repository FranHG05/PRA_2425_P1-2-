#include <ostream>

template <typename T>
class Node {
    public:
        // El elemento almacenado, de tipo genérico T
        T data;

        // Puntero al siguiente nodo de la secuencia (o nullptr si es el último nodo de la secuencia)
        Node<T>* next;

        // Método constructor. next será nullptr en caso de que no se proporcione
        Node(T data, Node<T>* next = nullptr)
            : data(data), next(next) {}

        // Sobrecarga global del operador << para imprimir una instancia de Node<T> por pantalla
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
            out << node.data;  // Se limita a imprimir el atributo 'data'
            return out;
        }
};

