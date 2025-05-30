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
void push(Pila *pila, int valor) {
    int flag=0; //agrego una bandera para comuicarlo internamente
    if (pila->tope == MAX - 1) {
        printf("La pila está llena.\n");
    } else {
        pila->tope++;
        pila->arreglo[pila->tope]=valor;
        flag=1; //que marque 1 si realiza la accion de agregar
    }
    printf("Elemento %d agregado a la pila.\n", valor);//se escribe afuera del else
}

int main() {
    Pila pila;

    initialize(&pila);

    return 0;
}