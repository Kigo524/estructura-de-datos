/*Selecciona un numero aleatorio entre 1 y 20
ese numero, es la cantidad de valores random que va a agregar a la pila
despues crear un ciclo para vaciar la pila*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    int i, tamano, cont=0;
    int datos[cont];

    srand(time(0));
    tamano = 1 + (rand() % 20); //de 1 a 20

    do{
        if(cont<tamano){
            datos[cont] = (rand() % 20);
            cont++;
        }
    }while(cont<tamano);

    for(i=0; i<tamano; i++){
        printf("%d", datos[i]);
    }
    
    

}