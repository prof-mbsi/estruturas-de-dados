#include <stdio.h>

// Função iterativa para calcular o fatorial
unsigned long fatorialIterativo(int n) {
    unsigned long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função recursiva para calcular o fatorial
unsigned long fatorialRecursivo(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * fatorialRecursivo(n - 1);
}

int main() {
    int numero;

    // Entrada do usuário
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("\nFatorial não definido para números negativos.\n");
    } else {
        // Chamando as funções e exibindo os resultados
        printf("Fatorial de %d (Iterativo): %lu\n", numero, fatorialIterativo(numero));
        printf("Fatorial de %d (Recursivo): %lu\n", numero, fatorialRecursivo(numero));
    }

    return 0;
}