#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

//Verificar se os arquivos foram passados corretamente.
void verificacaoArquivoEntrada(char *argv[], char* inputFile, char* estrategia){

     //Verificar se a estratégia foi fornecida
     if(estrategia[0] != 'D' && estrategia[0] != 'A' || strlen(estrategia) > 1){
          printf("Selecione uma estratégia valida.\n");
          exit(EXIT_FAILURE);
     }
     // Verificar se o arquivo de entrada foi fornecido
     if (inputFile == NULL) {
          printf("O arquivo de entrada é necessário.\n");
          exit(EXIT_FAILURE);
     }

}

// Função para imprimir dados de tempo de execução e distâncias calculadas em um arquivo de saída.
void imprimirSaidas(FILE *arquivoSaida, long int resultado,
double tempoUsuario, double tempoNoSistema){

     printf("Tempo de Usuário: %.6lf segundos.\n", tempoUsuario);
     printf("Algoritmo ficou %.6lf segundos no sistema.\n", tempoNoSistema);
     fprintf(arquivoSaida, "%ld", resultado);

}

// Função para verificar se um arquivo foi aberto corretamente.
void testaAberturaArquivo(FILE* arquivo, char* arquivoAberto){

     if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo de entrada.\n");
          exit(EXIT_FAILURE);
     }

}
