#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define BITS_PER_WORD (sizeof(unsigned long) * CHAR_BIT)  // Define o número de bits do sistema

void preprocessMasks(char *pattern, int m, unsigned long **M, unsigned long numPatterns) {
    for (int i = 0; i < 256; i++) {
        for (unsigned long j = 0; j < numPatterns; j++) {
            M[i][j] = 0;
        }
    }
    
    for (int j = 0; j < m; j++) {
        M[(unsigned char)pattern[j]][j / BITS_PER_WORD] |= (1UL << (j % BITS_PER_WORD));
    }
}

bool shiftAnd(char *text, int n, char *pattern, int m) {
    if (m > n) {
        printf("Padrão muito longo para a query.\n");
        return false;
    }

    // Calcula o número vetores para armazenar o padrão
    unsigned long numPatterns = (unsigned long)ceil((double)m/BITS_PER_WORD);

    // Matriz de máscaras
    unsigned long **M = (unsigned long **)malloc(256 * sizeof(unsigned long *));
    for (int i = 0; i < 256; i++) {
        M[i] = (unsigned long *)malloc(numPatterns * sizeof(unsigned long));
        if (M[i] == NULL) {
            printf("Erro ao alocar memória para M[%d].\n", i);
            return false;
        }
    }

    preprocessMasks(pattern, m, M, numPatterns);

    // Vetor de casamento R
    unsigned long *R = (unsigned long *)malloc(numPatterns * sizeof(unsigned long));
    if (R == NULL) {
        printf("Erro ao alocar memória para R.\n");
        for (int i = 0; i < 256; i++) {
            free(M[i]);
        }
        free(M);
        return false;
    }

    for (unsigned long i = 0; i < numPatterns; i++) {
        R[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        unsigned long carry = 1UL; //Or com 1 após o shift ou passa o bit pro proximo vetor

        for (unsigned long j = 0; j < numPatterns; j++) {
            unsigned long newR = ((R[j] << 1) | carry) & M[(unsigned char)text[i]][j];
            carry = (R[j] >> (BITS_PER_WORD - 1)) & 1UL; 
            R[j] = newR;

            if (j == numPatterns - 1 && (R[j] & (1UL << ((m - 1) % BITS_PER_WORD)))) {
                for (int k = 0; k < 256; k++) {
                    free(M[k]);
                }
                free(M);
                free(R);
                return true;  // Padrão encontrado
            }
        }
    }

    for (int i = 0; i < 256; i++) {
        free(M[i]);
    }
    free(M);
    free(R);

    return false;  // Padrão não encontrado
}