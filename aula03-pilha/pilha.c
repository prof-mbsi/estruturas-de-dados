#include <stdio.h>

//Define constante que limita o vetor
#define MAX 5

//Define uma struct para a pilha com um vetor de int e uma variável para controlar o topo
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

//Inicializa uma pilha para que topo não seja NULL e seja possível executar as funções sem erro
void inicializar(Pilha *p) {
    p->topo = -1;
}

//Retorna 1 se a pilha está vazia (topo == -1)
int estaVazia(Pilha *p) {
    return (p->topo == -1);
}

//Retorna 1 se a pilha está cheia (topo == MAX - 1)
int estaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

//Função que empilha um elemento no topo da pilha
void push(Pilha *p, int valor) {
    //Retorna erro se a pilha estiver cheia
    if (estaCheia(p)) {
        printf("Erro: A pilha está cheia!\n");
        return;
    }
    //Incrementa topo e armazena o valor na próxima posição do vetor
    p->topo++;
    p->itens[p->topo] = valor;
}

//Função que desempilha o último elemento
int pop(Pilha *p) {
    //Retorna erro se a pilha estiver vazia
    if (estaVazia(p)) {
        printf("Erro: A pilha está vazia!\n");
        return -1;
    }
    //Retorna a elemento no topo da pilha e decrementa topo para atualizar
    return p->itens[p->topo--];
}

//Função que retorna elemento no topo da pilha
int peek(Pilha p) {
    //Retorna erro se estiver vazia pois, não há elementos
    if (estaVazia(&p)) {
        printf("Erro: A pilha est� vazia!\n");
        return -1;
    }
    //Retorna o elemento na posição topo
    return p.itens[p.topo];
}

//Função que mostra a pilha
void exibir(Pilha p) {
    //Retorna erro se estiver vazia pois, não há elementos
    if (estaVazia(&p)) {
        printf("Erro: A pilha está vazia!\n");
        return;
    }
    //Inicia a saída
    printf("Pilha: ");
    //Itera sobre a pilha mostrando seus elementos
    for (int i = p.topo; i >= 0; i--) {
        printf("\n   ---");
        printf("\n | %d |", p.itens[i]);
    }
    printf("\n   ---");
}

int main() {
    printf("\nAula de Estruturas de Dados Aplicadas: Pilha\n\n");
    //Cria uma variável do tipo Pilha
    Pilha p;
    //Inicializa uma pilha para topo não ser NULL e permitir as interações 
    inicializar(&p);
    //Empilha 10
    push(&p, 10);
    //Empilha 11
    push(&p, 11);
    //Empilha 12
    push(&p, 12);
    //Empilha 13
    push(&p, 13);
    //Exibe a Pilha
    exibir(p);
    //Exibe o elemento no topo
    printf("Topo da pilha: %d\n", peek(p));
    //Remove o elemento do topo
    printf("Removendo: %d\n", pop(&p));
    //Exibe a pilha para checagem
    exibir(p);
    
    return 0;
}

