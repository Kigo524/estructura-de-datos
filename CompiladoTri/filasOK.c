#include <stdio.h>

#define MAXIMO 5  // Capacidad máxima de la fila

// Estructura para representar una fila circular
typedef struct {
    int datos[MAXIMO];  // Arreglo para almacenar elementos
    int frente;         // Índice del primer elemento
    int final;          // Índice del último elemento
} FilaCircular;

// Inicializa una fila vacía
void inicializarFila(FilaCircular *f) {
    f->frente = -1;
    f->final = -1;
}

// Verifica si la fila está vacía
int estaVacia(FilaCircular *f) {
    return f->frente == -1;
}

// Verifica si la fila está llena
int estaLlena(FilaCircular *f) {
    return (f->final + 1) % MAXIMO == f->frente;
}

// Agrega un elemento a la fila
void encolar(FilaCircular *f, int valor) {
    if (estaLlena(f)) {
        printf("Fila llena. No se puede agregar %d\n", valor);
    } else {
        if (estaVacia(f)) {
            f->frente = 0;
        }
        f->final = (f->final + 1) % MAXIMO;
        f->datos[f->final] = valor;
        printf("Elemento agregado: %d\n", valor);
    }
}

// Elimina un elemento del frente
void desencolar(FilaCircular *f) {
    if (estaVacia(f)) {
        printf("Fila vacía. No se puede eliminar\n");
    } else {
        printf("Elemento removido: %d\n", f->datos[f->frente]);

        if (f->frente == f->final) {
            f->frente = f->final = -1;
        } else {
            f->frente = (f->frente + 1) % MAXIMO;
        }
    }
}

// Muestra el elemento frente sin eliminarlo
int verFrente(FilaCircular *f) {
    if (estaVacia(f)) {
        printf("Fila vacía. No hay elementos\n");
        return -1;
    }
    return f->datos[f->frente];
}

// Imprime todos los elementos de la fila
void imprimirFila(FilaCircular *f) {
    printf("\n--- Estado actual de la fila ---\n");
    if (estaVacia(f)) {
        printf("[Vacía]\n");
    } else {
        int i = f->frente;
        while (1) {
            if (i == f->frente)
                printf("[%d] <- frente\n", f->datos[i]);
            else
                printf("[%d]\n", f->datos[i]);

            if (i == f->final) break;
            i = (i + 1) % MAXIMO;
        }
    }
    printf("-------------------------------\n\n");
}

int main() {
    FilaCircular fila;
    inicializarFila(&fila);

    encolar(&fila, 10);
    encolar(&fila, 20);
    encolar(&fila, 30);
    encolar(&fila, 40);
    imprimirFila(&fila);

    desencolar(&fila);  // Remueve 10
    desencolar(&fila);  // Remueve 20  
    imprimirFila(&fila);

    encolar(&fila, 50);
    encolar(&fila, 60);
    encolar(&fila, 70);

    encolar(&fila, 80); // No se puede agregar (fila llena)
    imprimirFila(&fila);

    printf("Elemento al frente: %d\n", verFrente(&fila));

    return 0;
}