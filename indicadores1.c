#include <stdio.h>
#include <stdbool.h>

//Tamaño máximo de la pila
#define MAX 100

//La estructura que describe la pila
typedef struct {
    int arreglo[MAX];  
    int tope;        
} Pila;


//Función para inicializar una pila
void initialize(Pila *pila) {
    pila->tope = -1;  
}

//comenzamos con verificar que la pila esta vacia. Devuelve valor booleano
bool isEmpty(Pila *pila){
    if(pila -> tope == -1){
        return true;
    } else {
        return false;
    }
}

//isfull verifica que este llena la pila de modo que tope este en MAX. devuelve bool
bool isFull (Pila *pila){
    if(pila->tope == MAX -1){
        return true;
    } else {
        return false;
    }
}

//push (pila, valor) agrega un valor en pila


int main() {
    Pila pila;

    initialize(&pila);

    return 0;
}