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
    if(fila->frente==fila->atras-1){
        return; //devuelve 1 si la fila y atras van contiguas
    }
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
void dequeue(Fila *fila, int valor){
    if(estaVacia(fila)){
        printf("La fila esta vacia\n");
    } else {
        printf("Elemento %d eliminado\n", fila->arreglo[fila->frente]);
        fila->frente++; //sube la posicion del frente segun se va pasando el valor
    }
}

void verTope(Fila *fila){
    if(estaVacia(fila))
}

int main() {
    Fila f;

    initialize(&f);


    return 0;
}