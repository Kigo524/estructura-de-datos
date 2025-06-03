#include <stdio.h>
#include <stdbool.h>

//Tamaño máximo de la fila
#define MAX 100

//La estructura que describe la fila
typedef struct {
    int arreglo[MAX];  
    int frente;        
    int atras;        
} Fila;


//Función para inicializar una fila
void initialize(Fila *fila) {
    fila->frente = -1;  
    fila->atras = 0;  
}

int estaVacia(Fila *fila) {
    return fila->frente == fila->atras - 1; //devuelve 1 si la fila y atras van contiguas
}

int estaLlena(Fila *fila){
    return fila->atras==MAX; //develve 1 si se llaga al maximo de elementos
}

//esto es un push para agregar elementos
void enqueue(Fila *fila, int valor){
    if(estaLlena(fila)){
        printf("La fila esta llena \n");
    } else {
        fila->arreglo[fila->atras]=valor;
        fila->atras++;
        printf("Elemento %d agregado \n", valor);
    }
}

//esto es un pop
void dequeue(Fila *fila){
    if(estaVacia(fila)){
        printf("La fila esta vacia\n");
    } else {
        printf("Elemento %d eliminado\n", fila->arreglo[fila->frente + 1]);
        fila->frente++; //sube la posicion del frente segun se va pasando el valor
    }
}

void peek(Fila *fila){
    if(estaVacia(fila)){
        printf("La fila esta vacia\n");
    } else {
        printf("Elemnto en el tope: %d\n", fila->arreglo[fila->frente + 1]);
    }
}

//-------------------------------------------------------------------------
//esto es solo para poder ver los cambios
void imprimirFila(Fila *fila){
    if (estaVacia(fila)){
        printf("Fila vacia\n");
    } else {
        printf("Fila: ");
        for (int i = fila->frente + 1; i < fila->atras; i++){
            printf("%d ", fila->arreglo[i]);
        }
        printf("\n");
    }
}
//-------------------------------------------------------------------------

int main() {
    Fila f;

    initialize(&f);

    estaVacia(&f);

    enqueue(&f, 10);
    imprimirFila(&f);

    enqueue(&f, 20);
    imprimirFila(&f);

    enqueue(&f, 30);
    imprimirFila(&f);

    peek(&f); //saldria 10
    dequeue(&f);
    imprimirFila(&f);

    peek(&f); //saldria 20

    return 0;
}