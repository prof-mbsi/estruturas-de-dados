#include <stdio.h>
#include <locale.h>

// Função iterativa para calcular Fibonacci
unsigned long fibonacciIterativo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long anterior = 0, atual = 1, proximo;
    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

// Função recursiva para calcular Fibonacci
unsigned long fibonacciRecursivo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int main() {
    int numero;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Entrada do usuário
    printf("\nDigite um número inteiro positivo para calcular Fibonacci: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("\nNúmero inválido! Insira um valor maior ou igual a 0.\n");
    } else {
        // Chamando as funções e exibindo os resultados
        printf("Fibonacci de %d (Iterativo): %lu\n", numero, fibonacciIterativo(numero));
        printf("Fibonacci de %d (Recursivo): %lu\n", numero, fibonacciRecursivo(numero));
    }

    return 0;
}