#include <stdio.h>

#define N 3

char vertices[N] = {'A', 'B', 'C'};
int matriz[N][N] = {
    {0, 10, 8},
    {10, 0, 12},
    {8, 12, 0}
};

int visitado[N];

void mostrarCaminho(int caminho[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", vertices[caminho[i]]);
        if (i != tamanho - 1)
            printf(" -> ");
    }
    printf("\n");
}

void caminhar(int atual, int caminho[], int tamanho) {
    caminho[tamanho++] = atual;
    visitado[atual] = 1;

    if (tamanho == N) {
        mostrarCaminho(caminho, tamanho);
    } else {
        for (int i = 0; i < N; i++) {
            if (matriz[atual][i] != 0 && !visitado[i]) {
                caminhar(i, caminho, tamanho);
            }
        }
    }

    visitado[atual] = 0;
}

int main() {
    int caminho[N];

    printf("Todos os caminhos possíveis:\n");
    for (int i = 0; i < N; i++) {
        caminhar(i, caminho, 0);
    }

    return 0;
}