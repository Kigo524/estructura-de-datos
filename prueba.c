#include <stdio.h>
int main(){
int i=0, tam=0, mayor=0, menor=0, pos=0;
float suma=0;
//6 15 7 5 12 8 11 18

printf("Ingrese el numero de calificaciones:");
scanf("%d", &tam);

float calificaciones[tam];

for(i=0; i<tam; i++){
    printf("Ingresa la calificacion %d:", i+1);
    scanf("%f", &calificaciones[i]);
    suma=suma+calificaciones[i];
}

float promedio=suma/tam;
printf("\n\nEl promedio es: %.2f", promedio);

//para imprimir
int aux, flag;
printf("\n\nLas calificaciones son:\n");
for(i=0;i<tam;i++){
    printf("%.1f ", calificaciones[i]);
}

//ahora ordenado ... por burbuja?
printf("\n\n");
do{
    flag=0;
    for(i=0;i<tam;i++){
        if(calificaciones[i]>calificaciones[i+1]){
            flag=1;

            aux=calificaciones[i];
            calificaciones[i]= calificaciones[i+1];
            calificaciones[i+1]=aux;
        }
    }
}while(flag==1);

for(i=0; i<tam; i++){
    printf("%.1f ", calificaciones[i]);
}

//para buscar
int buscar, encontrado=0;
printf("\n\nIngresa la calificacion a buscar:");
scanf("%d", &buscar);

if(calificaciones[i] == buscar){
    printf("La calificacion se encuentra en la posicion: %d\n", i);
    encontrado=1;
} else if(!encontrado){
    printf("No esta esa calificacion");
}

return 0;
}