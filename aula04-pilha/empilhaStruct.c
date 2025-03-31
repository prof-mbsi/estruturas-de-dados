#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // Tamanho máximo da pilha

// Definição da struct Produto
typedef struct {
    int codigo;
    char descricao[50];
} Produto;

// Definição da Pilha
typedef struct {
    int topo;
    Produto elementos[MAX];
} Pilha;

// Inicializa a pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está cheia
int isFull(Pilha *p) {
    return (p->topo == MAX - 1);
}

// Verifica se a pilha está vazia
int isEmpty(Pilha *p) {
    return (p->topo == -1);
}

// Empilha um produto
void push(Pilha *p, Produto prod) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->elementos[++p->topo] = prod;
    printf("Produto %d - %s empilhado com sucesso!\n", prod.codigo, prod.descricao);
}

// Desempilha um produto
Produto pop(Pilha *p) {
    Produto vazio = {-1, ""};  // Produto vazio para retornar em caso de erro
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return vazio;
    }
    return p->elementos[p->topo--];
}

// Exibe os produtos na pilha
void exibirPilha(Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("\nProdutos na pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("Código: %d, Descrição: %s\n", p->elementos[i].codigo, p->elementos[i].descricao);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializa(&p);
    Produto prod;
    int opcao;

    do {
        printf("\n1 - Empilhar Produto\n2 - Desempilhar Produto\n3 - Exibir Pilha\n4 - Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                if (isFull(&p)) {
                    printf("Erro: Pilha cheia!\n");
                } else {
                    printf("Digite o código do produto: ");
                    scanf("%d", &prod.codigo);
                    getchar();
                    printf("Digite a descrição do produto: ");
                    fgets(prod.descricao, 50, stdin);
                    prod.descricao[strcspn(prod.descricao, "\n")] = '\0'; // Remover '\n'
                    push(&p, prod);
                }
                break;

            case 2:
                if (!isEmpty(&p)) {
                    Produto removido = pop(&p);
                    printf("Produto desempilhado: Código %d - %s\n", removido.codigo, removido.descricao);
                }
                break;

            case 3:
                exibirPilha(&p);
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
