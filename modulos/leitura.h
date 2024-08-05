#ifndef LEITURA_H
#define LEITURA_H
#include <stdio.h>

void verificacaoArquivoEntrada(char *argv[], char* inputFile, char* estrategia);

void imprimirSaidas(FILE *arquivoSaida, int *resultado, int qte_restultados,
double tempoUsuario, double tempoNoSistema);

void testaAberturaArquivo(FILE* arquivo, char* arquivoAberto);

#endif