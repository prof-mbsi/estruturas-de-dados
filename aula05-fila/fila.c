#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Tamanho máximo da fila

// Estrutura da fila
typedef struct {
    int dados[MAX];
    int frente, tras;
} Fila;

// Inicializa a fila
void inicializa(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

// Verifica se a fila está vazia
int isEmpty(Fila *f) {
    return f->frente > f->tras;
}

// Verifica se a fila está cheia
int isFull(Fila *f) {
    return f->tras == MAX - 1;
}

// Enqueue (inserção)
void enqueue(Fila *f, int valor) {
    if (isFull(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->dados[++f->tras] = valor;
    printf("Inserido: %d\n", valor);
}

// Dequeue (remoção)
int dequeue(Fila *f) {
    if (isEmpty(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->dados[f->frente++];
}

// Mostra a fila
void exibirFila(Fila *f) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializa(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    exibirFila(&f);

    printf("Removido: %d\n", dequeue(&f));
    exibirFila(&f);

    return 0;
}