/*
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

#include <stdio.h>
#include <math.h>
#include "main.h"
#include "harmonica.h"

/*
 * Funcao para calcular Series Harmonicas
 */
void harmonica(){
    int a = 10;
    float precisao;
    float diferenca;
    int parametro_N = 0;  // Recebe o retorno da funcao erro_Harmonica
    int parametro_P = 0;  // Inserido pelo usuario
    int parametro_A = 0;  // Inserido pelo usuario
    int parametro_B = 0;  // Inserido pelo usuario
    int troca = 0;        // Variavel para inversao dos valores, caso necessario
    float resultado = 0;  // Recebe o retorno da funcao soma_Harmonica

    // Entrada de dados
    printf("Calculo de SERIE HARMONICA:\n");
    printf("Esta serie é do tipo ( 1 / ( n ^ P ) )\n");
    printf("Entre com o parametro P: ");
    scanf("%d", &parametro_P);
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
    if(convergencia_Harmonica(parametro_P) == CONVERGENTE){

        // Calcula a serie de acordo com os niveis de erro estabelecidos pelas constantes ERROR_LEVEL_MIN e ERROR_LEVEL_MAX (main.h)
        for (a = ERROR_LEVEL_MIN; a <= ERROR_LEVEL_MAX; a++){
            precisao = ((float)1 / pow(10, a));

            // Encontra o N atraves do calculo do erro
            parametro_N = erro_Harmonica(parametro_P, precisao);

            // Calcula a soma da serie e mostra na tela
            resultado = soma_Harmonica(parametro_N, parametro_P);
            printf("| O resultado da soma dos %d primeiros termos e: %f |\n", parametro_N, resultado);

            // Calcula a diferenca numerica do erro e mostra na tela
            diferenca = diff_Harmonica(parametro_N, parametro_P, resultado);
            printf("| A diferenca numerica do erro é menor que: %f |\n", diferenca);
            printf("-------------------------------------------------------------------\n");
        }
    }

    // Calcula o valor da Integral Numerica
    integral_Harmonica(parametro_A, parametro_B, parametro_P);
    printf("-------------------------------------------------------------------\n");
    system("pause");
}

// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)
int convergencia_Harmonica(int variavel_P){
    /* Criterio de Verificacao
     * Se P > 1 é Convergente ( Pagina 647 e 648 do livro )
     * Se P <= 1 é Divergente
     */
    if (variavel_P > 1){
        printf("| Serie Convergente                                               |\n");
        printf("-------------------------------------------------------------------\n");
        return CONVERGENTE;
    } else if (variavel_P <= 1){
        printf("| Serie Divergente                                                |\n");
        printf("-------------------------------------------------------------------\n");
        return DIVERGENTE;
    }
}

// Calcula o erro da serie Harmonica
// Retorna o N para o calculo da soma
int erro_Harmonica(int variavel_P, float precisao){
    int n = 0;
    // Traducao da formula (1/(p-1)*erro)^(1/(p-1))
    n = ceil(pow(((float)1/((float)(variavel_P-1)*precisao)), ((float)1/(float)(variavel_P-1))));
    printf("| Para um erro de %.3f, N deve valer %d. |\n", precisao, n);
    return n;
}

// Funcao que realiza a soma dos N termos da Serie
// Retorna a soma
double soma_Harmonica(int variavel_N, int variavel_P){
    int a = 0;
    float resultado = 0;

    for(a = 1;a <= variavel_N; a++){
        resultado = resultado + ((float)1 / pow( a, variavel_P ));
    }
    return resultado;
}

// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia
float diff_Harmonica(int variavel_N, int variavel_P, float valor_Referencia){
    return MODULO(valor_Referencia - soma_Harmonica(variavel_N + 1, variavel_P));
}

// Calcula a integral numerica entre dois valores para a integral da serie harmonica
// Nao ha retorno. Imprime na tela o valor da integral
void integral_Harmonica(int variavel_A, int variavel_B, int variavel_P){
    float valor = 0;

    // Chama a funcao integral para o tipo HARMONICA
    valor = integral(1, variavel_A, variavel_B, variavel_P, 0.0);
    printf("| O valor da Integral Numerica entre %d e %d é: %f |\n", variavel_A, variavel_B, valor);
}

double f_Harmonica(double x, int p){
    double funcao;
    funcao = 1.0 / pow( x, p);
    return funcao;
}
