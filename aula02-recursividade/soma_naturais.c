/* Exercício 1: Somar os n primeiros números naturais de 
acordo com a entrada do usuário:
*/
#include <stdio.h>
#include <locale.h>

int somaNaturais(int n){
    //Define caso base:
    if(n == 0){
        return 0;
    } else {
        //Chamada recursiva somando próximo n (n-1)
        return n + somaNaturais(n-1);
    }
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    //Cria a variável para interação com o usuário
    int num;
    printf("Digite a quantidade de números naturais para somar: ");
    scanf("%d", &num);
    //Chama a função dentro do printf para exibir o resultado retornado
    printf("Soma dos %d primeiros naturais: %d\n", num, somaNaturais(num));
    return 0;
}