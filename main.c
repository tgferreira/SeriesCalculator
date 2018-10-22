#include <stdio.h>
#include <stdlib.h>
#include "geometrica.h"
#include "harmonica.h"
#include "telescopica.h"
#include "main.h"

int main(int argc, char** argv) {

    int a = 0;
    int opcao;

    // Interface com o usuario - Montagem do menu
    do{
    system("cls");
    printf("\n<<< Projeto Fundamentos 2 - MAT007 >>>\n");
    printf("   Escolha uma opcao:\n");
    printf("   OK 1 - Serie Harmonica. (Serie-p)\n");
    printf("      2 - Serie Harmonica Alternada.\n");
    printf("   OK 3 - Serie Alternada.\n");
    printf("   OK 4 - Serie Geometrica.\n");
    printf("   OK 5 - Serie Telescopica.\n");
    printf("      6 - Serie de Potencias.\n");
    printf("  ---------------------------\n");
    printf("   9 - Sair.\n");
    scanf("%d", &opcao);
    switch( opcao ) {
        case 1:  // Serie Harmonica
            harmonica();
            break;
        case 2:  // Serie Harmonica Alternada
//            harmonica_Alternada();
            break;
        case 3:  // Serie Alternada
            alternada();
            break;
        case 4:  // Serie Geometrica
            geometrica();
            break;
        case 5:  // Serie Telescopica
            telescopica();
            break;
        case 6:  // Serie de Potencias
//            potencias();
            break;
        case 9:
            exit(0);
    }
    }while(opcao != 9);
    return (EXIT_SUCCESS);
}

// Funcao comum a varias series
// Retorna o valor de um numero N fatorial
int fatorial(int variavel_N){
    int a = 0;
    double resultado = 1;
    for (a = 1; a <= variavel_N; a++){
        resultado = resultado * a;
    }
    return resultado;
}

// Este codigo para o calculo da integral foi retirado da internet e adaptado para este trabalho
float integral(int tipo, float variavel_A, float variavel_B, float variavel_C, float variavel_D){
    int i;
    float h, j, x, y, z, aux=0, integral;
    float vx[ INTERVALOS + 1 ], vy[ INTERVALOS + 1 ];

    h = ( variavel_B - variavel_A ) / INTERVALOS;
    j = 0;

    for (i = 0; i < INTERVALOS + 1; i++){
        vx[i] = variavel_A+j;
        j = j + h;
    }
    // Aplica a funcao de acordo com o tipo da funcao a integrar
    for (i = 0; i < INTERVALOS + 1; i++){
        switch (tipo){
            case 1:
                vy[i] = f_Harmonica(vx[i], variavel_C);
                break;
            case 2:
                vy[i] = f_Alternada(vx[i]);
                break;
            case 3:
                vy[i] = f_Geometrica(vx[i], variavel_C, variavel_D);
                break;
            case 4:
                vy[i] = f_Telescopica(vx[i]);
                break;
            default:
                return -1;
        }
    }
    for (i = 1; i < INTERVALOS; i = i + 2){
        x = aux + vy[i];
        aux = x;
    }
    aux = 0;
    for (i = 2; i < INTERVALOS; i = i + 2){
        y = aux + vy[i];
        aux = y;
    }
    z = vy[0] + vy[ INTERVALOS ];
    integral = (z + 4 * x + 2 * y) * ( h / 3 );
    return integral;
}
