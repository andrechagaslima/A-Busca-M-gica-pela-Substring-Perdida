#ifndef LEITURA_H
#define LEITURA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {  //Struct para receber o início e o final de cada query
    int start;
    int end;    
} Query;

void verificacaoArquivoEntrada(char *argv[], char* inputFile, char* estrategia);

ssize_t read_line(FILE *file, char **line, size_t *len);

void imprimirSaidas(FILE *arquivoSaida, bool *resultado, int qte_restultados,
double tempoUsuario, double tempoNoSistema);

void testaAberturaArquivo(FILE* arquivo, char* arquivoAberto);

void leituraArquivo(FILE *file, char **text, char **pattern, Query **queries, int *num_queries);

void processQuery(Query *query, char *text, char *process_text);

#endif