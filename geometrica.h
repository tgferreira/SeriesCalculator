/*
 * Projeto de conclusão de curso - TCC
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

/* 
 * File:   geometrica.h
 * Author: domingos
 *
 * Created on 25 de Setembro de 2018, 11:16
 */

#ifndef GEOMETRICA_H
#define GEOMETRICA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* GEOMETRICA_H */


void geometrica();

// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)
int convergencia_Geometrica(float variavel_r);

// Calcula o erro da serie Geometrica
// Retorna o N para o calculo da soma
int erro_Geometrica(float variavel_a, float variavel_r, float precisao);

// Funcao que realiza a soma dos N termos da Serie
// Retorna a soma
double soma_Geometrica(float variavel_a, float variavel_r, int variavel_N);

// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia
float diff_Geometrica(float variavel_a, float variavel_r, int variavel_N, float valor_Referencia);

// Calcula a integral numerica entre dois valores para a integral da serie harmonica
// Nao ha retorno. Imprime na tela o valor da integral
void integral_Geometrica(int variavel_A, int variavel_B, float variavel_a, float variavel_r);

double f_Geometrica(double x, float a, float r);