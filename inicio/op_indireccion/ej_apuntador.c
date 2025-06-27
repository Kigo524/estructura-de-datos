#include <stdio.h>

int main(){
    int n, m;
    
    printf("ingrese un valor");
    scanf("%d", &n); //ejemplo con 5
    scanf("%d", &m); //ejemplo con 11
    
    printf("Imprime %d\n", n);
    printf("Imprime %d\n", m);
    int *p, *q, *r;
    
    p=&n;
    q=&m;
    
    printf("Imprime %d\n", n);
    printf("Imprime %d\n", m);

    printf("P = %p\n", p);
    printf("q = %d\n", &q);
    printf("m = %d\n", &m);


    *p=13;
    *q=13;

    printf("Imprime %d\n", n);
    printf("Imprime %d\n", m);

    printf("P = %p\n", p);
    printf("q = %d\n", &q);
    printf("m = %d\n", &m);

    n=27;
    *p= (n) + (*q);


    printf("Imprime %d\n", n);
    printf("Imprime %d\n", m);

    printf("P = %p\n", p);
    printf("q = %d\n", &q);
    printf("m = %d\n", &m);

    q=p;

    printf("Despues de q=p\n");
    printf("Imprime %d\n", n);
    printf("Imprime %d\n", m);

    printf("P = %p\n", p);
    printf("q = %d\n", &q);
}