/*
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

#include <stdio.h>
#include <math.h>
#include "main.h"
#include "harmonica_alternada.h"

/*
 * Funcao para calcular Series Harmonicas Alternadas de 3 tipos?
 */
/*void harmonica_Alternada(){
    int parametro_N = 0;
    int parametro_P = 0;
    int parametro_C = 0;
    float resultado = 0;

    // Entrada de dados
    printf("Calculo de serie harmonica alternada:\n");
    printf("Esta serie é do tipo ( ( - 1 ) ^ ( n + 1 ) ) * ( ( ( n ^ p - 1 ) / ( n ^ p ) + c )\n");
    printf("Entre com o valor inicial para n: ");
    scanf("%d", &parametro_N);
    printf("Entre com o parametro p: ");
    scanf("%d", &parametro_P);
    printf("Entre com o parametro c: ");
    scanf("%d", &parametro_C);
    
    // Verificacao de convergencia
    if(verifica_Convergencia_Harmonica_Alternada(parametro_N, parametro_P, parametro_C) == CONVERGENTE){
        // Para erro de 0,1
        parametro_N = calcula_ErroHA(parametro_N, parametro_P, parametro_C, ERROR_LEVEL1);
        resultado = soma_Serie_Harmonica_Alternada(parametro_N, parametro_P, parametro_C);
        printf("O resultado da soma de %d iteracoes: %f\n", parametro_N, resultado);
        // Para erro de 0,01
        parametro_N = calcula_ErroHA(parametro_N, parametro_P, parametro_C, ERROR_LEVEL2);
        resultado = soma_Serie_Harmonica_Alternada(parametro_N, parametro_P, parametro_C);
        printf("O resultado da soma de %d iteracoes: %f\n", parametro_N, resultado);
        // Para erro de 0,001
        parametro_N = calcula_ErroHA(parametro_N, parametro_P, parametro_C, ERROR_LEVEL3);
        resultado = soma_Serie_Harmonica_Alternada(parametro_N, parametro_P, parametro_C);
        printf("O resultado da soma de %d iteracoes: %f\n", parametro_N, resultado);
        parametro_N = calcula_ErroHA(parametro_N, parametro_P, parametro_C, ERROR_LEVELT);
        resultado = soma_Serie_Harmonica_Alternada(parametro_N, parametro_P, parametro_C);
        printf("O resultado da soma de %d iteracoes: %f\n", parametro_N, resultado);
    }
}

double soma_Serie_Harmonica_Alternada(int variavel_N, int variavel_P, int variavel_C){
    int n = 0;
    float valor;
    double resultado = 0;
    for( n = variavel_N; n <= 1000000; n++){
        valor  = pow( -1, ( n + 1 ) ) * ( pow( n, ( variavel_P - 1 ) ) / ( pow( n, variavel_P ) + variavel_C ) );
        resultado = resultado + valor;    
    }
    return resultado;
}

int calcula_ErroHA(int variavel_N, int variavel_P, int variavel_C, float erro){
    int n = 0;
    float valor;
    for( n = variavel_N; n <= 1000000; n++){
        valor = ( pow( ( n + 1 ), ( variavel_P - 1 ) ) ) / ( pow( ( n + 1 ), variavel_P ) + variavel_C );
        if ( valor < erro ) {
            printf("Para um erro de %.3f, N deve valer %d.\n", erro, n);    
            return n;
        }
    }
}

int verifica_Convergencia_Harmonica_Alternada(int variavel_N, int variavel_P, int variavel_C){
    /* Criterio de Verificacao
     * Se A(n+1) <= A(n),
     * Se Lim A(n) quando n->Infinito = 0 e
     * Se A(n) >= 0 então é Convergente
     * Obs: no caso da serie proposta n^p
     */
/*    
    //int TermoA = pow(-1, ( n + 1 )); // Termo de alternancia
    float Termo1 = ( pow( variavel_N, ( variavel_P - 1 ) ) ) / ( pow( variavel_N, variavel_P ) + variavel_C ); 
    float Termo2 = ( pow( ( variavel_N + 1 ), ( variavel_P - 1 ) ) ) / ( pow( ( variavel_N + 1 ), variavel_P ) + variavel_C );
    
    if ( Termo1 >= 0 ){
        if (Termo2 <= Termo1){
            printf("\nSerie convergente\n");
            return CONVERGENTE;
        } else {
            printf("\nSerie divergente\n");
            return DIVERGENTE;
        }
    }
}

//    for(n = 1;n <= 1000; n++){
//        e = (1/((variavel_P-1)*pow(n,(variavel_P-1))));
//        if (e < erro){ // Error Level 
//            printf("Para um erro de %.3f, N deve valer %d.\n", erro, n);
//            return n;
//        }
//    }
*/