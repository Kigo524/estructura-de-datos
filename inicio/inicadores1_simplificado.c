#include <stdio.h>

#define MAX 5

//se crea la estructura
typedef struct{
    int arreglo[MAX]; //datos de la pila
    int tope;  //posicion actual del tope. Si es -1, la pila esta vacia
} Pila; //nombre de la estructura

//inicializar la pila
void inicializar(Pila *p){
    p->tope = -1; /*p es un puntero a una pila para modificar la pila original, y queremos que tope comience en -1*/
}//es -1 para que comience vacia

//funcion para saber si esta vacia
//devuelve 1 si la pila esta vacia y 0 si hay elementos
int estaVacia(Pila *p){
    return p->tope == -1;
}

//funcion para saber si esta llena
//devuelve 1 si ya hay MAX elementos en la pila (esta llena)
int estaLlena(Pila *p){
    return p -> tope == MAX -1;
}

//funcion push
void push(Pila *p, int valor){
    if(estaLlena(p)){//si verifica que esta llena la pila, manda el mensaje
        printf("La pila esta llena. \n");
    } else {
        p->tope++; //al tope en p lo aumenta un valor y...
        p->arreglo[p->tope] = valor; //al arrelgo en p, de la variable tope en p, se le da el dato a la variable valor
        printf("Elemento %d agregado \n", valor);
    }
}

//funcion pop
void pop(Pila *p){
    if(estaVacia(p)){
        printf("La pila esta vacia.\n");
    } else {
        printf("Elemento % d eliminado.\n", p->arreglo[p->tope]);
        p->tope--; //baja el tope, y "elimina" el ultimo valor
    }
}

//top o yo le pongo verTope
void verTope(Pila *p){
    if(estaVacia(p)){
        printf("La pila esta vacia\n");
    } else {
        printf("Elemento en el tope: %d\n", p->arreglo[p->tope]);
    }
}

int main(){
    Pila miPila;
    inicializar(&miPila); //se pasa la direccion porque la funcion espera un puntero

    push(&miPila, 10);
    push(&miPila, 20);
    verTope(&miPila); //seria 20
    pop(&miPila); //elimina el 20
    verTope(&miPila); //seria 10

    return 0;
}