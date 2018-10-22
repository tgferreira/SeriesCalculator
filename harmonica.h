/*
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

/* 
 * File:   harmonica.h
 * Author: domingos
 *
 * Created on 25 de Setembro de 2018, 11:18
 */

#ifndef HARMONICA_H
#define HARMONICA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* HARMONICA_H */

void harmonica();
// Funcao principal da Serie Harmonica

int convergencia_Harmonica(int variavel_P);
// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)

int erro_Harmonica(int variavel_P, float erro);
// Calcula o erro da serie Harmonica
// Retorna o N para o calculo da soma

double soma_Harmonica(int variavel_N, int variavel_P);
// Funcao que realiza a soma dos N termos da Serie
// Retorna a soma

float diff_Harmonica(int variavel_N, int variavel_P, float valor_Referencia);
// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia

void integral_Harmonica(int variavel_A, int variavel_B, int variavel_P);
// Calcula a integral numerica entre dois valores para a integral da serie harmonica
// Nao ha retorno. Imprime na tela o valor da integral

double f_Harmonica(double x, int p);