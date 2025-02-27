#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim){
    int aux, pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2]) /3;
    while(inicio < fim){
        while(inicio < fim && v[inicio] <= pivo)
            inicio++;
        while(inicio < fim && v[fim] > pivo)
            fim--;
        aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio;
}

void quickSort(int *v, int inicio, int fim){
    int pos;
    if(inicio < fim){
        pos = particiona(v, inicio, fim);
        quickSort(v, inicio, pos-1);
        quickSort(v, pos, fim);
    }
}

int main(){

    int vetor[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};

    for(int i=0; i<15; i++){
        printf("\n%d", vetor[i]);
    }

    printf("\n");
    quickSort(vetor, 0, 14);

    for(int i=0; i<15; i++){
        printf("\n%d", vetor[i]);
    }

    return 0;

}
