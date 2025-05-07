#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

void inserirInicio(No** inicio, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;

    if (*inicio == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *inicio = novo;
    } else {
        No* ultimo = (*inicio)->ant;
        novo->prox = *inicio;
        novo->ant = ultimo;
        ultimo->prox = novo;
        (*inicio)->ant = novo;
        *inicio = novo;
    }
}

void inserirFim(No** inicio, int valor) {
    if (*inicio == NULL) {
        inserirInicio(inicio, valor);
    } else {
        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        No* ultimo = (*inicio)->ant;
        novo->prox = *inicio;
        novo->ant = ultimo;
        ultimo->prox = novo;
        (*inicio)->ant = novo;
    }
}

void imprimir(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No* atual = inicio;
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != inicio);
    printf("\n");
}

void remover(No** inicio, int valor) {
    if (*inicio == NULL) return;
    No* atual = *inicio;
    do {
        if (atual->valor == valor) {
            if (atual->prox == atual) {
                free(atual);
                *inicio = NULL;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
                if (atual == *inicio)
                    *inicio = atual->prox;
                free(atual);
            }
            return;
        }
        atual = atual->prox;
    } while (atual != *inicio);
}

int main() {
    No* lista = NULL;

    inserirFim(&lista, 10);
    inserirFim(&lista, 20);
    inserirInicio(&lista, 5);
    imprimir(lista); // Deve imprimir: 5 10 20

    remover(&lista, 10);
    imprimir(lista); // Deve imprimir: 5 20

    return 0;
}