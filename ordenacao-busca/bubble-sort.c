#include <stdio.h>

#define SIZE 10

int main(){

    int i, aux, flag;
    int vetor[SIZE];

    for(i=0; i<SIZE; i++){
        printf("Item %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    flag = 1;

    while(flag){
        flag = 0;

        for(i=0; i<=SIZE-2; i++){
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                flag = 1;
            }
        }

    }

    for(i=0; i<SIZE; i++){
        printf("\nElemento %d : %d", i+1, vetor[i]);
    }

}