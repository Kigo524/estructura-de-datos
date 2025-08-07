#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo del árbol AVL
typedef struct Nodo {    
    int dato;    
    int altura;  // Altura del nodo
    struct Nodo* izquierdo; // Subárbol izquierdo   
    struct Nodo* derecho;   // Subárbol derecho
} Nodo;

// Función para obtener la altura de un nodo
int altura(Nodo* nodo) {    
    if (nodo == NULL) return 0;   
    return nodo->altura;
}

// Función para calcular el máximo entre dos valores
int max(int a, int b) {    
    return (a > b) ? a : b;
}

// Función para obtener el factor de balance de un nodo
int obtenerBalance(Nodo* nodo) {    
    if (nodo == NULL) return 0;    
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}

// Rotación simple a la derecha
Nodo* rotarDerecha(Nodo* y) {   
    Nodo* x = y->izquierdo;   
    Nodo* T2 = x->derecho;

    // Realiza la rotación    
    x->derecho = y;    
    y->izquierdo = T2;

    // Actualiza alturas    
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;    
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;

    return x; // Nueva raíz del subárbol
}

// Rotación simple a la izquierda
Nodo* rotarIzquierda(Nodo* x) {    
    Nodo* y = x->derecho;    
    Nodo* T2 = y->izquierdo;

    // Realiza la rotación    
    y->izquierdo = x;    
    x->derecho = T2;

    // Actualiza alturas    
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;    
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;

    return y; // Nueva raíz del subárbol
}

// Inserta un valor y rebalancea el árbol
Nodo* insertar(Nodo* nodo, int dato) {    
    // Caso base: se crea un nuevo nodo    
    if (nodo == NULL) {        
        Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));        
        nuevo->dato = dato;        
        nuevo->izquierdo = nuevo->derecho = NULL;        
        nuevo->altura = 1;        
        return nuevo;    
    }

    // Insertar recursivamente según el valor    
    if (dato < nodo->dato)        
        nodo->izquierdo = insertar(nodo->izquierdo, dato);    
    else if (dato > nodo->dato)        
        nodo->derecho = insertar(nodo->derecho, dato);    
    else  
        return nodo; // No se permiten duplicados
    
    // Actualizar la altura del nodo actual    
    nodo->altura = 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));

    // Obtener el balance    
    int balance = obtenerBalance(nodo);

    // Rebalanceo según los 4 casos
    // Caso Izquierda-Izquierda    
    if (balance > 1 && dato < nodo->izquierdo->dato)        
        return rotarDerecha(nodo);
    
    // Caso Derecha-Derecha    
    if (balance < -1 && dato > nodo->derecho->dato)      
        return rotarIzquierda(nodo);
    
    // Caso Izquierda-Derecha    
    if (balance > 1 && dato > nodo->izquierdo->dato) {        
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);       
        return rotarDerecha(nodo);    
    }
    
    // Caso Derecha-Izquierda    
    if (balance < -1 && dato < nodo->derecho->dato) {        
        nodo->derecho = rotarDerecha(nodo->derecho);        
        return rotarIzquierda(nodo);    
    }

    return nodo; // Nodo ya balanceado
}

// Encuentra el nodo con el valor más bajo (mínimo) en un subárbol
Nodo* minimoValorNodo(Nodo* nodo) {    
    Nodo* actual = nodo;    
    while (actual->izquierdo != NULL)        
        actual = actual->izquierdo;    
    return actual;
}

// Elimina un nodo del árbol AVL y rebalancea
Nodo* eliminar(Nodo* raiz, int dato) {    
    if (raiz == NULL)        
        return raiz;

    // Buscar el nodo a eliminar    
    if (dato < raiz->dato)        
        raiz->izquierdo = eliminar(raiz->izquierdo, dato);    
    else if (dato > raiz->dato)        
        raiz->derecho = eliminar(raiz->derecho, dato);    
    else {        
        // Nodo encontrado: un hijo o ninguno        
        if ((raiz->izquierdo == NULL) || (raiz->derecho == NULL)) {            
            Nodo* temp;            
            if (raiz->izquierdo != NULL)                
                temp = raiz->izquierdo;            
            else                
                temp = raiz->derecho;

            if (temp == NULL) { // Sin hijos                
                temp = raiz;                
                raiz = NULL;            
            } else {  // Un hijo                
                *raiz = *temp;            
            }            
            free(temp);        
        } else {  
            // Nodo con dos hijos: buscar el menor del subárbol derecho           
            Nodo* temp = minimoValorNodo(raiz->derecho);            
            raiz->dato = temp->dato;            
            raiz->derecho = eliminar(raiz->derecho, temp->dato);        
        }    
    }

    if (raiz == NULL)        
        return raiz;

    // Actualizar la altura del nodo actual    
    raiz->altura = 1 + max(altura(raiz->izquierdo), altura(raiz->derecho));

    // Obtener el factor de balance    
    int balance = obtenerBalance(raiz);

    // Rebalancear si es necesario    
    if (balance > 1 && obtenerBalance(raiz->izquierdo) >= 0)        
        return rotarDerecha(raiz);
    
    if (balance > 1 && obtenerBalance(raiz->izquierdo) < 0) {        
        raiz->izquierdo = rotarIzquierda(raiz->izquierdo);        
        return rotarDerecha(raiz);    
    }
    
    if (balance < -1 && obtenerBalance(raiz->derecho) <= 0)        
        return rotarIzquierda(raiz);
    
    if (balance < -1 && obtenerBalance(raiz->derecho) > 0) {        
        raiz->derecho = rotarDerecha(raiz->derecho);        
        return rotarIzquierda(raiz);    
    }

    return raiz;
}

// Recorrido inOrden para imprimir valores ordenados
void inOrden(Nodo* raiz) {    
    if (raiz != NULL) {        
        inOrden(raiz->izquierdo);        
        printf("%d ", raiz->dato);        
        inOrden(raiz->derecho);    
    }
}

// Liberar toda la memoria del árbol (postorden)
void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);
        free(raiz);
    }
}

// Función principal para probar el árbol AVL
int main() {    
    Nodo* raiz = NULL;

    // Inserción de valores    
    raiz = insertar(raiz, 30);    
    raiz = insertar(raiz, 20);    
    raiz = insertar(raiz, 40);    
    raiz = insertar(raiz, 10);    
    raiz = insertar(raiz, 25);    
    raiz = insertar(raiz, 35);    
    raiz = insertar(raiz, 50);

    printf("Árbol AVL en orden: ");    
    inOrden(raiz);    
    printf("\n");

    // Eliminar un nodo    
    raiz = eliminar(raiz, 40);    
    printf("Después de eliminar 40: ");    
    inOrden(raiz);    
    printf("\n");
    
    // Liberar la memoria del árbol
    liberarArbol(raiz);
    return 0;
}