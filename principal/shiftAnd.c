#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define BITS_PER_WORD (sizeof(unsigned long) * CHAR_BIT)  // Define o número de bits por palavra

// Preprocessamento da máscara para cada caractere do alfabeto
void preprocessShiftAnd(char *pattern, int m, unsigned long **M, unsigned long numPatterns) {
    // Inicializa as máscaras
    for (int i = 0; i < 256; i++) {
        for (unsigned long j = 0; j < numPatterns; j++) {
            M[i][j] = 0;
        }
    }
    
    // Preenche as máscaras para cada caractere do padrão
    for (int j = 0; j < m; j++) {
        M[(unsigned char)pattern[j]][j / BITS_PER_WORD] |= (1UL << (j % BITS_PER_WORD));
    }
}

// Função para buscar o padrão no texto usando o algoritmo Shift-And
bool shiftAndSearch(char *text, int n, char *pattern, int m) {
    if (m > n) {
        printf("Padrão muito longo para a query.\n");
        return false;
    }

    // Calcula o número necessário de vetores de bits
    unsigned long numPatterns = (unsigned long)ceil((double)m/BITS_PER_WORD);

    // Aloca a matriz de máscaras
    unsigned long **M = (unsigned long **)malloc(256 * sizeof(unsigned long *));
    for (int i = 0; i < 256; i++) {
        M[i] = (unsigned long *)malloc(numPatterns * sizeof(unsigned long));
        if (M[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para M[%d].\n", i);
            return false;
        }
    }

    preprocessShiftAnd(pattern, m, M, numPatterns);

    // Aloca múltiplos vetores de bits R
    unsigned long *R = (unsigned long *)malloc(numPatterns * sizeof(unsigned long));
    if (R == NULL) {
        fprintf(stderr, "Erro ao alocar memória para R.\n");
        for (int i = 0; i < 256; i++) {
            free(M[i]);
        }
        free(M);
        return false;
    }

    // Inicializa todos os vetores R
    for (unsigned long i = 0; i < numPatterns; i++) {
        R[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        unsigned long carry = 1UL;  // Carry para lidar com o overflow entre os vetores de bits

        for (unsigned long j = 0; j < numPatterns; j++) {
            unsigned long newR = ((R[j] << 1) | carry) & M[(unsigned char)text[i]][j];
            carry = (R[j] >> (BITS_PER_WORD - 1)) & 1UL;  // Captura o bit de overflow
            R[j] = newR;

            // Verifica se o bit mais à esquerda do último vetor está ativado
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

    // Libera memória
    for (int i = 0; i < 256; i++) {
        free(M[i]);
    }
    free(M);
    free(R);

    return false;  // Padrão não encontrado
}