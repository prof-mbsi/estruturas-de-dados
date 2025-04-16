#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

void inicializar(Lista *l) {
    l->tamanho = 0;
}

void inserir(Lista *l, int valor) {
    if (l->tamanho < MAX) {
        l->dados[l->tamanho] = valor;
        l->tamanho++;
        printf("Valor inserido com sucesso!\n");
    } else {
        printf("Lista cheia! Nao e possivel inserir.\n");
    }
}

void remover(Lista *l, int valor) {
    int i, pos = -1;
    for (i = 0; i < l->tamanho; i++) {
        if (l->dados[i] == valor) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Valor nao encontrado na lista.\n");
        return;
    }
    for (i = pos; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--;
    printf("Valor removido com sucesso!\n");
}

int buscar(Lista *l, int valor) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->dados[i] == valor) return i;
    }
    return -1;
}

void exibir(Lista *l) {
    if (l->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Elementos da lista: ");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista l;
    int opcao, valor, pos;

    inicializar(&l);

    do {
        printf("\n--- MENU LISTA SEQUENCIAL ---\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Exibir lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                inserir(&l, valor);
                break;
            case 2:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                remover(&l, valor);
                break;
            case 3:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                pos = buscar(&l, valor);
                if (pos != -1)
                    printf("Valor encontrado na posicao %d.\n", pos);
                else
                    printf("Valor nao encontrado.\n");
                break;
            case 4:
                exibir(&l);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
