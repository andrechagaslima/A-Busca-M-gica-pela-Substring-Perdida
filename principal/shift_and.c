#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Preprocessamento da máscara para cada caractere do alfabeto
void preprocessShiftAnd(char *pattern, int m, bool **M) {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = true;  
        }
    }
    for (int j = 0; j < m; j++) {
        M[(unsigned char)pattern[j]][j] = false;  
    }
}

// Função para deslocar o vetor de bits para a direita manualmente
void shiftRight(bool *R, int m) {
    for (int j = m - 1; j > 0; j--) {
        R[j] = R[j - 1];
    }
    R[0] = true; 
}

// Função para buscar o padrão no texto usando o algoritmo Shift-And
void shiftAndSearch(char *text, int n, char *pattern, int m) {
    bool **M = (bool **)malloc(256 * sizeof(bool *));
    for (int i = 0; i < 256; i++) {
        M[i] = (bool *)malloc(m * sizeof(bool));
    }
    preprocessShiftAnd(pattern, m, M);

    bool *R = (bool *)malloc(m * sizeof(bool));
    for (int j = 0; j < m; j++) {
        R[j] = true;
    }

    for (int i = 0; i < n; i++) {
        shiftRight(R, m);
        for (int j = 0; j < m; j++) {
            R[j] = R[j] && M[(unsigned char)text[i]][j];
        }
        if (!R[m - 1]) {
            printf("Casamento na posição: %d\n", i - m + 2);
        }
    }

    // Liberação da memória alocada
    for (int i = 0; i < 256; i++) {
        free(M[i]);
    }
    free(M);
    free(R);
}