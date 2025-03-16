/* Exercício 2: Contar quantos dígitos há em um número informado
pelo usuário:
*/
#include <stdio.h>
#include <locale.h>

int contaDigitos(int n){
    //Define caso base:
    if(n == 0){
        return 0;
    } else {
        //Chamada recursiva somando 1 e passando n/10 como parâmetro a cada
        //chamada onde n não seja 0, temos um dígito a mais no número
        return 1 + contaDigitos(n/10);
    }
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    //Cria a variável para interação com o usuário
    int num;
    printf("Digite um inteiro para contagem de dígitos: ");
    scanf("%d", &num);
    //Verifica se o usuário informou 0 para evitar divisão dentro da função, 
    //pois retornaria 1
    if(num == 0){
        printf("O número tem 1 dígito.\n");
    } else{
        //Chama a função dentro do printf para exibir o resultado retornado
        printf("O número %d tem %d dígitos.\n", num, contaDigitos(num));
    }
    return 0;
}