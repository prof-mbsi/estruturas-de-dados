/* Exercício 3: Receber uma palavra e inverter recursivamente
*/
#include <stdio.h>
#include <string.h>
#include <locale.h>

void invertePalavra(char palavra[], int inicio, int fim){
    //Define caso base:
    if(inicio >= fim){
        return;
    } else {
        //Faz o swap da letra na posição início com a letra na posição fim
        char temp = palavra[inicio];
        palavra[inicio] = palavra[fim];
        palavra[fim] = temp;
        //Chamada recursiva passando a palavra com os índices início e fim 
        //se deslocando para o meio da palavra a cada chamada
        invertePalavra(palavra, inicio + 1, fim - 1);
    }
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    //Cria a variável para interação com o usuário
    char palavra[60];
    printf("Digite uma palavra para inverter: ");
    scanf("%s", &palavra);
    //Cria uma variável para receber o tamanho da palavra digitada
    int tamanho = strlen(palavra);
    //Chama a função para inverter enviando a palavra, a posição inicial 0 
    //e a posição final sendo tamanho-1 (já que a posição inicial é 0)
    invertePalavra(palavra, 0, tamanho-1);
    //Exibe a palavra invertida
    printf("Palavra invertida: %s\n", palavra);
    return 0;
}