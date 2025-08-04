#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//ESTRUCTURA Y CREACION DE GRAFOS

// Nodo para la lista de vecinos
typedef struct Nodo {
    int destino;              // A qué nodo está conectado
    struct Nodo* siguiente;  // El siguiente vecino
} Nodo;

// Lista de vecinos de un vértice
typedef struct Lista {
    Nodo* cabeza;             // Apunta al primer vecino
} Lista;

// Estructura del grafo completo
typedef struct Grafo {
    int numVertices;          // Cuántos nodos tiene el grafo
    Lista* array;             // Lista de vecinos por cada vértice
} Grafo;

//CREAR UN GRAFO

Grafo* crearGrafo(int V) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->numVertices = V;

    grafo->array = (Lista*) malloc(V * sizeof(Lista));

    for (int i = 0; i < V; i++) {
        grafo->array[i].cabeza = NULL; // Inicializa las listas vacías
    }

    return grafo;
}

//AGREGA UNA ARISTA

void agregarArista(Grafo* grafo, int origen, int destino) {
    // Crear nuevo nodo para destino
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->destino = destino;
    nuevo->siguiente = grafo->array[origen].cabeza;
    grafo->array[origen].cabeza = nuevo;

    // Como el grafo es NO dirigido, también agregar de destino a origen
    Nodo* nuevo2 = (Nodo*) malloc(sizeof(Nodo));
    nuevo2->destino = origen;
    nuevo2->siguiente = grafo->array[destino].cabeza;
    grafo->array[destino].cabeza = nuevo2;
}

//IMPRIME EL GRAFO

void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        Nodo* temp = grafo->array[i].cabeza;
        printf("Nodo %d:", i);
        while (temp != NULL) {
            printf(" -> %d", temp->destino);
            temp = temp->siguiente;
        }
        printf("\n");
    }
}

//DFS PROFUNDIDAD
void dfsDesde(Grafo* grafo, int nodo, bool visitado[]) {
    visitado[nodo] = true;
    printf("%d ", nodo);

    Nodo* temp = grafo->array[nodo].cabeza;
    while (temp != NULL) {
        int vecino = temp->destino;
        if (!visitado[vecino]) {
            dfsDesde(grafo, vecino, visitado);
        }
        temp = temp->siguiente;
    }
}

void dfs(Grafo* grafo, int inicio) {
    bool visitado[grafo->numVertices];
    for (int i = 0; i < grafo->numVertices; i++)
        visitado[i] = false;

    dfsDesde(grafo, inicio, visitado);
}

//BFS ANCHURA
void bfs(Grafo* grafo, int inicio) {
    bool visitado[grafo->numVertices];
    for (int i = 0; i < grafo->numVertices; i++)
        visitado[i] = false;

    int cola[100];
    int frente = 0, fin = 0;

    cola[fin++] = inicio;
    visitado[inicio] = true;

    while (frente < fin) {
        int actual = cola[frente++];
        printf("%d ", actual);

        Nodo* temp = grafo->array[actual].cabeza;
        while (temp != NULL) {
            int vecino = temp->destino;
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola[fin++] = vecino;
            }
            temp = temp->siguiente;
        }
    }
}

//MAIN
int main() {
    Grafo* miGrafo = crearGrafo(5);

    agregarArista(miGrafo, 0, 1);
    agregarArista(miGrafo, 0, 4);
    agregarArista(miGrafo, 1, 2);
    agregarArista(miGrafo, 1, 3);
    agregarArista(miGrafo, 1, 4);
    agregarArista(miGrafo, 2, 3);
    agregarArista(miGrafo, 3, 4);

    printf("Grafo (lista de conexiones):\n");
    imprimirGrafo(miGrafo);

    printf("\nDFS desde nodo 0:\n");
    dfs(miGrafo, 0);

    printf("\n\nBFS desde nodo 0:\n");
    bfs(miGrafo, 0);

    return 0;
}