#include <stdio.h>

//função que particiona o vetor
int particiona(int *v, int inicio, int fim){

    //encontra um pivot. Nesse caso, busca um valor mediano
    int aux, pivot = (v[inicio] + v[fim] + v[(inicio + fim)/2]) /3;

    //checa se inicio < fim para continuar executando a função
    while(inicio < fim){
        //move o índice em busca de um valor à esquerda maior que o pivot
        while(inicio < fim && v[inicio] <= pivot)
            inicio++;
        //move o índice em busca de um valor à direita menor que o pivot
        while(inicio < fim && v[fim] > pivot)
            fim--;
        //faz o swap
        aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio;
}

//função que implementa a lógica da solução
void quickSort(int *v, int inicio, int fim){
    int pos;
    //checa se a posição inicial está antes da posição final para continuar executando o código
    if(inicio < fim){
        //chama o método particiona passando o vetor, posição inicial e posição final
        pos = particiona(v, inicio, fim);

        //chama quickSort para o vetor dividido à esquerda
        quickSort(v, inicio, pos-1);

        //chama quickSort para o vetor dividido à direita
        quickSort(v, pos, fim);
    }
}

//função main que executa o programa
int main(){

    //cria estaticamente o vetor de 15 posições
    int vetor[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};

    //mostra o vetor na ordem orignial
    for(int i=0; i<15; i++){
        printf("\n%d", vetor[i]);
    }

    printf("\n");

    //chama a fução quickSort pela primeira vez passando o vetor, posição inicial e posição final
    quickSort(vetor, 0, 14);

    //mostra o vetor ordenado
    for(int i=0; i<15; i++){
        printf("\n%d", vetor[i]);
    }

    return 0;

}
