/*
 * Projeto de conclusão de curso - TCC
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

/* 
 * File:   alternada.h
 * Author: domingos
 *
 * Created on 11 de Outubro de 2018, 09:52
 */

#ifndef ALTERNADA_H
#define ALTERNADA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* ALTERNADA_H */

/*
 * Projeto de conclusão de curso - TCC
 * Autor: Domingos Savio Faria Paes
 * Universidade Federal de Itajuba - Curso de Sistemas de Informação
 */

void alternada();

int convergencia_Alternada();
// Verifica os criterios de convergencia da serie
// retorna CONVERGENTE(1) ou DIVERGENTE(0)

int erro_Alternada(float precisao);
// Calcula o erro da serie Harmonica
// Retorna o N para o calculo da soma

double soma_Alternada(int variavel_N);
// Funcao que realiza a soma dos N termos da Serie
// Retorna a soma

float diff_Alternada(int variavel_N, float valor_Referencia);
// Funcao que calcula a diferenca numerica entre o termo N e seu subsequente
// Retorna a diferenca entre o termo N+1 e o valor de referencia

void integral_Alternada(int variavel_A, int variavel_B);
// Calcula a integral numerica entre dois valores para a integral da serie harmonica
// Nao ha retorno. Imprime na tela o valor da integral

double f_Alternada(double x);