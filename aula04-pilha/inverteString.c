#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Tamanho máximo da pilha

// Estrutura da pilha
typedef struct {
    int topo;
    char caracteres[MAX];
} Pilha;

// Função para inicializar a pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

// Função para empilhar um caractere
void push(Pilha *p, char valor) {
    if (p->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->caracteres[++p->topo] = valor;
}

// Função para desempilhar um caractere
char pop(Pilha *p) {
    if (p->topo == -1) {
        return '\0';
    }
    return p->caracteres[p->topo--];
}

int main() {
    Pilha p;
    inicializa(&p);
    char str[MAX];

    // Obtendo a string do usuário
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remover o '\n' do final

    // Empilhando os caracteres
    for (int i = 0; i < strlen(str); i++) {
        push(&p, str[i]);
    }

    // Desempilhando e exibindo a string invertida
    printf("String invertida: ");
    while (p.topo != -1) {
        printf("%c", pop(&p));
    }
    printf("\n");

    return 0;
}
