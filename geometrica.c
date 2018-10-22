/*
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

#include <stdio.h>
#include <math.h>
#include "main.h"
#include "geometrica.h"

/*
 * Funcao para calcular Series Geometricas
 */
void geometrica(){
    int a = 10;
    float precisao;
    float diferenca;
    int parametro_N = 0;  // Recebe o retorno da funcao erro_Geometrica
    float parametro_a = 0.0;  // Inserido pelo usuario
    float parametro_r = 0.0;  // Inserido pelo usuario
    int parametro_A = 0;  // Inserido pelo usuario
    int parametro_B = 0;  // Inserido pelo usuario
    int troca = 0;        // Variavel para inversao dos valores, caso necessario
    float resultado = 0;  // Recebe o retorno da funcao soma_Geometrica

    // Entrada de dados
    printf("Calculo de serie GEOMETRICA:");
    printf("Esta serie é do tipo ( ar ^ (n-1) )\n");
    printf("Entre com o parametro a: ");
    scanf("%f", &parametro_a);
    printf("Entre com o parametro r: ");
    scanf("%f", &parametro_r);
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
    if(convergencia_Geometrica(parametro_r) == CONVERGENTE){

        // Calcula a serie de acordo com os niveis de erro estabelecidos pelas constantes ERROR_LEVEL_MIN e ERROR_LEVEL_MAX (main.h)
        for (a = ERROR_LEVEL_MIN; a <= ERROR_LEVEL_MAX; a++){
            precisao = ((float)1 / pow(10, a));

            // Encontra o N atraves do calculo do erro
            parametro_N = erro_Geometrica(parametro_a, parametro_r, precisao);

            // Calcula a soma da serie e mostra na tela
            resultado = soma_Geometrica((float)parametro_a, (float)parametro_r, parametro_N);
            printf("| O resultado da soma dos %d primeiros termos e: %f |\n", parametro_N, resultado);

            // Calcula a diferenca numerica do erro e mostra na tela
            diferenca = diff_Geometrica(parametro_a, parametro_r, parametro_N, resultado);
            printf("| A diferenca numerica do erro é menor que: %f |\n", diferenca);
            printf("-------------------------------------------------------------------\n");
        }
    }

    // Calcula o valor da Integral Numerica
    integral_Geometrica(parametro_A, parametro_B, parametro_a, parametro_r);
    printf("-------------------------------------------------------------------\n");
    system("pause");
}

// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)
int convergencia_Geometrica(float variavel_r){
    /* Criterio de Verificacao
     * Se -1 < r < 1 é Convergente ( Pagina 638 )
     * porem r = 1 é divergente
     */
    if ((variavel_r == 1.0) || (variavel_r < -1.0) || (variavel_r > 1.0)){
        printf("| Serie Divergente                                                |\n");
        printf("-------------------------------------------------------------------\n");
        return DIVERGENTE;
    }
    printf("| Serie Convergente                                               |\n");
    printf("-------------------------------------------------------------------\n");
    return CONVERGENTE;
}

// Calcula o erro da serie Geometrica
// Retorna o N para o calculo da soma
int erro_Geometrica(float variavel_a, float variavel_r, float precisao){
    int n = 0;
    float termoN = 0;
    for (n = 0; n <= 100000; n++){
        termoN = ( variavel_a * pow( variavel_r, ( n - 1 ) ) );
        if (MODULO(termoN) < precisao){
            n--;
            printf("| Para um erro de %.3f, N deve valer %d. |\n", precisao, n);
            return n;
        }
    }
    return -1;
}

// Funcao que realiza a soma dos N termos da Serie
// Retorna a soma
double soma_Geometrica(float variavel_a, float variavel_r, int variavel_N){
    int n = 0;
    double resultado = 0;

    for(n = 1; n <= variavel_N; n++){
        resultado = resultado + ( variavel_a * pow( variavel_r, ( n - 1 ) ) );
    }
    return resultado;
}

// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia
float diff_Geometrica(float variavel_a, float variavel_r, int variavel_N, float valor_Referencia){
    return MODULO(valor_Referencia - soma_Geometrica(variavel_a, variavel_r, variavel_N + 1));
}

// Calcula a integral numerica entre dois valores para a integral da serie harmonica
// Nao ha retorno. Imprime na tela o valor da integral
void integral_Geometrica(int variavel_A, int variavel_B, float variavel_a, float variavel_r){
    float valor = 0;

    // Chama a funcao integral para o tipo HARMONICA
    valor = integral(3, variavel_A, variavel_B, variavel_a, variavel_r);
    printf("| O valor da Integral Numerica entre %d e %d é: %f |\n", variavel_A, variavel_B, valor);
}

double f_Geometrica(double x, float a, float r){
    double funcao;
    funcao = ( a * pow( r, ( x - 1 ) ) );
    return funcao;
}
