#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define BITS_PER_WORD (sizeof(unsigned long) * CHAR_BIT)  // Define o número de bits por palavra

// Preprocessamento da máscara para cada caractere do alfabeto
void preprocessShiftAnd(char *pattern, int m, unsigned long *M) {
    for (int i = 0; i < 256; i++) {
        M[i] = 0;
    }
    for (int j = 0; j < m; j++) {
        M[(unsigned char)pattern[j]] |= (1UL << j);  
    }
}

// Função para buscar o padrão no texto usando o algoritmo Shift-And
bool shiftAndSearch(char *text, int n, char *pattern, int m) {
    if (m > BITS_PER_WORD) {
        printf("Padrão muito longo para a implementação com uma única palavra. Considere dividir o padrão.\n");
        return false;
    }

    unsigned long *M = (unsigned long *)malloc(256 * sizeof(unsigned long));
    if (M == NULL) {
        fprintf(stderr, "Erro ao alocar memória para M.\n");
        return false;
    }

    preprocessShiftAnd(pattern, m, M);

    unsigned long *R = (unsigned long *)malloc(sizeof(unsigned long));
    if (R == NULL) {
        fprintf(stderr, "Erro ao alocar memória para R.\n");
        free(M); 
        return false;
    }
    *R = 0;

    for (int i = 0; i < n; i++) {
        // Desloca o registro R para a direita e aplica a máscara do caractere atual do texto
        *R = (*R << 1) | 1UL;
        *R &= M[(unsigned char)text[i]];

        // Verifica se o bit mais à esquerda está ativado, o que indica que o padrão foi encontrado
        if (*R & (1UL << (m - 1))) {
            free(M);
            free(R);

            return true;  // Padrão encontrado
        }
    }

    free(M);
    free(R);

    return false;  // Padrão não encontrado
}