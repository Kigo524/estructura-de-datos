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


int main() {
    Pila pila;

    initialize(&pila);  

    return 0;
}