#ifndef LEITURA_H
#define LEITURA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int start;
    int end;
} Query;

void verificacaoArquivoEntrada(char *argv[], char* inputFile, char* estrategia);

ssize_t read_line(FILE *file, char **line, size_t *len);

void imprimirSaidas(FILE *arquivoSaida, int *resultado, int qte_restultados,
double tempoUsuario, double tempoNoSistema);

void testaAberturaArquivo(FILE* arquivo, char* arquivoAberto);

void leituraArquivo(FILE *file, char **text, char **pattern, Query **queries, int *num_queries);

#endif