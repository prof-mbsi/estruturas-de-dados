#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Tamanho máximo da pilha

// Definição da estrutura da pilha
typedef struct {
    int topo;
    int elementos[MAX];
} Pilha;

// Função para inicializar a pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está cheia
int isFull(Pilha *p) {
    return (p->topo == MAX - 1);
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha *p) {
    return (p->topo == -1);
}

// Função para empilhar um número
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->elementos[p->topo] = valor;
}

// Função para desempilhar um número
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->elementos[p->topo--];
}

int main() {
    Pilha p;
    inicializa(&p);
    int n, valor;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &n);

    // Inserindo os números na pilha
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        push(&p, valor);
    }

    // Desempilhando os números para exibi-los na ordem inversa
    printf("Números na ordem inversa:\n");
    while (!isEmpty(&p)) {
        printf("%d ", pop(&p));
    }
    printf("\n");

    return 0;
}
