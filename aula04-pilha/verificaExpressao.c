#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Tamanho máximo da pilha

// Estrutura da pilha
typedef struct {
    int topo;
    char elementos[MAX];
} Pilha;

// Função para inicializar a pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha *p) {
    return (p->topo == -1);
}

// Função para verificar se a pilha está cheia
int isFull(Pilha *p) {
    return (p->topo == MAX - 1);
}

// Função para empilhar um caractere
void push(Pilha *p, char valor) {
    if (p->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->elementos[++p->topo] = valor;
}

// Função para desempilhar um caractere
char pop(Pilha *p) {
    if (isEmpty(p)) {
        return '\0';
    }
    return p->elementos[p->topo--];
}

// Função para verificar se a expressão está balanceada
int verificaExpressao(char expressao[]) {
    Pilha p;
    inicializa(&p);

    for (int i = 0; i < strlen(expressao); i++) {
        char c = expressao[i];

        if (c == '(' || c == '[') {
            push(&p, c);
        } else if (c == ')' || c == ']') {
            char topo = pop(&p);

            if ((c == ')' && topo != '(') || (c == ']' && topo != '[')) {
                return 0;  // Expressão incorreta
            }
        }
    }

    return estavazia(&p);  // Se a pilha está vazia, a expressão está correta
}

int main() {
    char expressao[MAX];

    printf("Digite uma expressão matemática: ");
    fgets(expressao, MAX, stdin);

    if (verificaExpressao(expressao)) {
        printf("Expressão válida!\n");
    } else {
        printf("Erro: Expressão inválida!\n");
    }

    return 0;
}
