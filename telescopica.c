/*
 * Autor: Tiago Ferreira
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

#include <stdio.h>
#include <math.h>
#include "main.h"
#include "telescopica.h"


void telescopica(){
    int a = 10;
    float precisao;
    float diferenca;
    int parametro_N = 0;  // Recebe o retorno da funcao erro_Telescopica
    int parametro_A = 0;  // Inserido pelo usuario
    int parametro_B = 0;  // Inserido pelo usuario
    int troca = 0;        // Variavel para inversao dos valores, caso necessario
    float resultado = 0;  // Recebe o retorno da funcao soma_Alternada

    // Entrada de dados
    printf("Calculo de SERIE TELESCOPICA:\n");
    printf("Esta serie e do tipo (1/n)-(1/n+1)\n");
    printf("Entre com os valores para o calculo da Integral Numerica:\n(o menor valor sera assumido como sendo o limite inferior e o maior como limite superior)\n");
    printf("Entre com o parametro A: ");
    scanf("%d", &parametro_A);
    printf("Entre com o parametro B: ");
    scanf("%d", &parametro_B);

    // Verifica e corrige caso os valores de A e B nao estejam no padrao estabelecido
    if (parametro_A > parametro_B){
        troca = parametro_A;
        parametro_A = parametro_B;
        parametro_B = troca;
    }

    printf("-------------------------------------------------------------------\n");

    // Verificacao de convergencia
    if(convergencia_Telescopica() == CONVERGENTE){
        printf("A convergencia se da, pois:\n");
        printf("(1/n)-(1/n+1) = 1 - 1/2\n");
        printf("(1/n+1)-(1/(n+1)+1) = 1/2 - 1/3\n");
        printf("(1/n+2)-(1/(n+2)+1) = 1/3 - 1/4\n");
        printf("Como todos os termos apos o 1 se anulam, quando o N -> infinito, |\na serie converge para 1 ou aproximadamente 1. |\n Portanto a soma da serie sempre converge a 1. |\n");
        printf("-------------------------------------------------------------------\n");

        for (a = ERROR_LEVEL_MIN; a <= ERROR_LEVEL_MAX; a++){
            precisao = ((float)1 / pow(10, a));

            // Encontra o N atraves do calculo do erro
            parametro_N = erro_Telescopica(precisao);

            if(a < ERROR_LEVEL_MIN){
            // Calcula a soma da serie e mostra na tela
            resultado = soma_Telescopica(parametro_A-parametro_B);
            printf("| O resultado da soma dos %d primeiros termos e: %f |\n", parametro_B, resultado);

            // Calcula a diferenca numerica do erro e mostra na tela
            diferenca = diff_Telescopica(parametro_A-parametro_B, parametro_B);
            printf("| A diferenca numerica do erro e menor que: %f |\n", diferenca);
            printf("-------------------------------------------------------------------\n");
            }
        }
    }

    // Calcula o valor da Integral Numerica
    integral_Telescopica(parametro_A, parametro_B,a,0.0);
    printf("-------------------------------------------------------------------\n");
    system("pause");
}

// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)
int convergencia_Telescopica(){
    int n = 1;
    float termo1 = 0;
    float termo2 = 0;
    float termo3 = 0;
    termo1 = (1/n)-(1/n+1); //= 1 - 1/2
    termo2 = (1/n+1)-(1/(n+1)+1); // = 1/2 - 1/3
    termo3 = (1/n+2)-(1/(n+2)+1); // 1/3 - 1/4
    // Como todos os termos após o 1 se anulam quando o N -> infinito, a série converge para 1 ou aproximadamente 1.
    // Portanto a soma da série sempre converge a 1
    return CONVERGENTE;
}

// Calcula o erro da serie Alternada
// Retorna o N para o calculo da soma
int erro_Telescopica(float precisao){
    int n = 1;
    float termoN = 0;
    for (n = 1; n <= 100000; n++){
        termoN = ((float)1 / (float)n);
        if (termoN < precisao){
            n--;
            printf("| Para um erro de %.3f, N deve valer %d. |\n", precisao, n);
            return n;
        }
    }
    return -1;
}

// Funcao que realiza a soma dos N termos da Serie
// Retorna a soma
double soma_Telescopica(int variavel_N){
//    int n = 1;
    float resultado = 0;
//    for (n = 1; n <= variavel_N; n++){
        resultado = ( (float)1 - ( (float)1 / variavel_N + 1 ) );
//    }
    return resultado;
}

// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia
float diff_Telescopica(int variavel_N, float valor_Referencia){
    return soma_Telescopica(variavel_N);
}

// Calcula a integral numerica entre dois valores para a integral da serie Telescopica
// Nao ha retorno. Imprime na tela o valor da integral

void integral_Telescopica(int variavel_A, int variavel_B, float variavel_a, float variavel_r){
    float valor = 0;

    // Chama a funcao integral para o tipo TELESCOPICA
    valor = integral(4, variavel_A, variavel_B, variavel_a, variavel_r);
    printf("| O valor da Integral Numerica entre %d e %d e: %f |\n", variavel_A, variavel_B, valor);
}

double f_Telescopica (double n){
    double funcao;
    funcao = (1.0 / n) - (1.0 / (n + 1.0));
    return funcao;
}
