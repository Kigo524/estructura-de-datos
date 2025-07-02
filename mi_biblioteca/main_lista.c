#include <stdio.h>
#include "lista.h"

int main() {
    Nodo* lista = NULL;

    insertarInicio(&lista, 10);
    insertarFinal(&lista, 20);
    insertarFinal(&lista, 30);
    insertarEnPosicion(&lista, 15, 1);
    imprimirLista(lista);

    eliminarEnPosicion(&lista, 2);
    imprimirLista(lista);

    eliminarInicio(&lista);
    imprimirLista(lista);

    eliminarFinal(&lista);
    imprimirLista(lista);

    return 0;
}