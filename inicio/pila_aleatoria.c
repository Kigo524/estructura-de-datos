/*Selecciona un numero aleatorio entre 1 y 20
ese numero, es la cantidad de valores random que va a agregar a la pila
despues crear un ciclo para vaciar la pila*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    int tamano=0, cont=0, i=0;
    int datos[tamano];

    srand(time(NULL));
    tamano = 1 + rand() % (20); //de 1 a 20

    do{
        srand(time(NULL));
        cont++;
        datos[cont] = 1 + rand() % 20;
    }while(tamano!=datos[cont]);

    for(i=0; i<tamano; i++){
        printf("%d", datos[i]);
    }
    
    

}