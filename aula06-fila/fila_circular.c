#include <stdio.h>
#include <stdlib.h>

#define TAM 5  // Tamanho da fila

/*
Adiciona um contador à struct para se certificar que a fila não está cheia já que, 
como a fila é circular, se o índice TAM-1 estiver ocupado, ela não estará 
necessariamente cheia
*/
typedef struct {
    int dados[TAM];
    int frente;
    int tras;
    int contador;
} FilaCircular;

// Inicializa a fila
void inicializar(FilaCircular *f) {
    f->frente = 0;
    f->tras = 0;
    f->contador = 0;
}

// Verifica se a fila está cheia
int isFull(FilaCircular *f) {
    return f->contador == TAM;
}

// Verifica se a fila está vazia
int isEmpty(FilaCircular *f) {
    return f->contador == 0;
}

// Enfileira (enqueue)
void enqueue(FilaCircular *f, int valor) {
    if (isFull(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->dados[f->tras] = valor;
    //utiliza o % para voltar ao início a cada vez que atingir o índice TAM-1
    f->tras = (f->tras + 1) % TAM;
    f->contador++;
    printf("Valor %d enfileirado.\n", valor);
}

// Desenfileira (dequeue)
void dequeue(FilaCircular *f) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return;
    }
    int valor = f->dados[f->frente];
    //utiliza o % para voltar ao início a cada vez que atingir o índice TAM-1
    f->frente = (f->frente + 1) % TAM;
    f->contador--;
    printf("Valor %d desenfileirado.\n", valor);
}

// Exibe os elementos da fila
void exibir(FilaCircular *f) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0, j = f->frente; i < f->contador; i++) {
        printf("%d ", f->dados[j]);
        //utiliza o % para exibir na ordem do mais antigo para o mais novo e voltar aos índices anteriores
        j = (j + 1) % TAM;
    }
    printf("\n");
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    enqueue(&fila, 40);
    enqueue(&fila, 50);

    exibir(&fila);

    dequeue(&fila);
    dequeue(&fila);

    exibir(&fila);

    enqueue(&fila, 60);
    enqueue(&fila, 70);

    exibir(&fila);

    return 0;
}