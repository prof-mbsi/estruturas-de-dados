#include <stdio.h>

//define o tamanho do vetor e facilita a criação dos loops
#define SIZE 10

int main(){

    int i, aux, flag;
    int vetor[SIZE];

    //preenche o vetor
    for(i=0; i<SIZE; i++){
        printf("Item %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    //define flag verdadeiro para executar o while pelo menos 1 vez
    flag = 1;

    while(flag){
        //define o flag falso para caso não haja um swap até o final do loop
        flag = 0;

        //itera analisando a necessidade de fazer o swap
        for(i=0; i<=SIZE-2; i++){
            //caso anterior seja maior que posterior, swap e seta a flag para verdadeiro
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                flag = 1;
            }
        }

    }

    //mostra o vetor ordenado
    for(i=0; i<SIZE; i++){
        printf("\nElemento %d : %d", i+1, vetor[i]);
    }

    return 0;

}