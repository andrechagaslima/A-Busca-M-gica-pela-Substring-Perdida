#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

//Verificar se os arquivos foram passados corretamente.
void verificacaoArquivoEntrada(char *argv[], char* inputFile, char* estrategia){

     //Verificar se a estratégia foi fornecida
     if(estrategia[0] != 'K' && estrategia[0] != 'B' || strlen(estrategia) > 1){
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
void imprimirSaidas(FILE *arquivoSaida, int *resultado, int qte_restultados,
double tempoUsuario, double tempoNoSistema){

     printf("Tempo de Usuário: %.6lf segundos.\n", tempoUsuario);
     printf("Algoritmo ficou %.6lf segundos no sistema.\n", tempoNoSistema);
     
     for(int i=0; i<qte_restultados; i++){  
          if(resultado[i] == 1){   
               fprintf(arquivoSaida, "Sim\n");
          } else if(resultado[i] == 0){
               fprintf(arquivoSaida, "Não\n");
          } else {
               fprintf(arquivoSaida, "Erro\n");
          }
     }
}

// Função para verificar se um arquivo foi aberto corretamente.
void testaAberturaArquivo(FILE* arquivo, char* arquivoAberto){

     if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo de entrada.\n");
          exit(EXIT_FAILURE);
     }

}

// Função para ler os dados de um arquivo e adicioná-los a um tabuleiro.
void leituraArquivo(FILE* arquivo, long int n){

     

     for (int i = 0; i < n; i++) {
          fscanf(arquivo, "%ld", &tabuleiro[i]);
     }

}