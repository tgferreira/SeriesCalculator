/*
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

#include <stdio.h>
#include <math.h>
#include "main.h"
#include "alternada.h"

/*
 * Funcao para calcular Series Alternadas
 */

void alternada(){
    int a = 10;
    float precisao;
    float diferenca;
    int parametro_N = 0;  // Recebe o retorno da funcao erro_Alternada
    int parametro_A = 0;  // Inserido pelo usuario
    int parametro_B = 0;  // Inserido pelo usuario
    int troca = 0;        // Variavel para inversao dos valores, caso necessario
    float resultado = 0;  // Recebe o retorno da funcao soma_Alternada

    // Entrada de dados
    printf("Calculo de SERIE ALTERNADA:\n");
    printf("Esta serie é do tipo -1 ^ (n+1) / n!\n");
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
    if(convergencia_Alternada() == CONVERGENTE){
        // Calcula a serie de acordo com os niveis de erro estabelecidos pelas constantes ERROR_LEVEL_MIN e ERROR_LEVEL_MAX (main.h)
        for (a = ERROR_LEVEL_MIN; a <= ERROR_LEVEL_MAX; a++){
            precisao = ((float)1 / pow(10, a));

            // Encontra o N atraves do calculo do erro
            parametro_N = erro_Alternada(precisao);

            // Calcula a soma da serie e mostra na tela
            resultado = soma_Alternada(parametro_N);
            printf("| O resultado da soma dos %d primeiros termos e: %f |\n", parametro_N, resultado);

            // Calcula a diferenca numerica do erro e mostra na tela
            diferenca = diff_Alternada(parametro_N, resultado);
            printf("| A diferenca numerica do erro é menor que: %f |\n", diferenca);
            printf("-------------------------------------------------------------------\n");
        }
    }

    // Calcula o valor da Integral Numerica
    integral_Alternada(parametro_A, parametro_B);
    printf("-------------------------------------------------------------------\n");
    system("pause");
}

// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)
int convergencia_Alternada(){
    int n = 1;
    float termo1 = 0;
    float termo2 = 0;
    termo1 = pow(-1,(n+1)) / fatorial(n);
    termo2 = pow(-1,(n+2)) / fatorial(n+1);
    // Teste para saber se o termo Bn+1 é menor que Bn
    // Obs: Como o termo do denominador é n! e sabemos tambem que com n -> infinito, o limite sera 0
    // entao nao é necessario testar esta condicao. (Teste da Serie Alternada, pagina 657 do livro)
    if (termo2 < termo1){
        printf("| Serie Convergente                                               |\n");
        printf("-------------------------------------------------------------------\n");
        return CONVERGENTE;
    } else {
        printf("| Serie Divergente                                                |\n");
        printf("-------------------------------------------------------------------\n");
        return DIVERGENTE;
    }
}

// Calcula o erro da serie Alternada
// Retorna o N para o calculo da soma
int erro_Alternada(float precisao){
    int n = 1;
    float termoN = 0;
    for (n = 1; n <= 100000; n++){
        termoN = pow(-1,(n+1)) / fatorial(n);
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
double soma_Alternada(int variavel_N){
    int n = 1;
    float resultado = 0;
    for (n = 1; n <= variavel_N; n++){
        resultado += (pow(-1,(n+1)) / fatorial(n));
    }
    return resultado;
}

// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia
float diff_Alternada(int variavel_N, float valor_Referencia){
    return MODULO(valor_Referencia - soma_Alternada(variavel_N + 1));
}

// Calcula a integral numerica entre dois valores para a integral da serie alternada
// Nao ha retorno. Imprime na tela o valor da integral
void integral_Alternada(int variavel_A, int variavel_B){
//    float valor = 0;

//    valor = integral(2, variavel_A, variavel_B, 0.0, 0.0);
//    printf("| O valor da Integral Numerica entre %d e %d é: %f |\n", variavel_A, variavel_B, valor);
    printf("| O valor da Integral Numerica desta serie nao pode ser calculada de maneira generica, |\n");
    printf("| por conta do fatorial no denominador. porem o codigo foi implementado da mesma forma,|\n");
    printf("| caso se queira modificar a funcao e realizar o calculo basta descomentar as linhas   |\n");
    printf("| na funcao integral_Alternada().                                                      |\n");
}

double f_Alternada(double x){
    double funcao;
    funcao = ( pow( -1, ( x - 1 ) ) / fatorial( x ) );
    return funcao;
}
