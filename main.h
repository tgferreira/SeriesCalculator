
#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */

typedef int boolean;
#define TRUE 1
#define FALSE 0

// Nivel de erro inicial para as series
#define ERROR_LEVEL_MIN 1
#define ERROR_LEVEL_MAX 3

// Padrao de resposta para criterio de convergencia
#define CONVERGENTE 1
#define DIVERGENTE 0

// Macro para o modulo de um valor
#define MODULO(x) ((x)>=0?(x):-(x))


int fatorial(int variavel_N);
// Funcao comum a varias series
// Retorna o valor de um numero N fatorial

double f(double x);

// Define quantos intervalos serao utilizados na funcao integral()
#define INTERVALOS 100

float integral(int tipo, float variavel_A, float variavel_B, float variavel_C, float variavel_D);
