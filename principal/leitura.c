#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "leitura.h"

//Verificar se os arquivos foram passados corretamente.
void verificacaoArquivoEntrada(char *argv[], char* inputFile, char* estrategia){

     if(estrategia[0] != 'S' && estrategia[0] != 'B' || strlen(estrategia) > 1){
          printf("Selecione uma estratégia valida.\n");
          exit(EXIT_FAILURE);
     }
   
     if (inputFile == NULL) {
          printf("O arquivo de entrada é necessário.\n");
          exit(EXIT_FAILURE);
     }

}

// Função para imprimir dados de tempo de execução e os resultados.
void imprimirSaidas(FILE *arquivoSaida, bool *resultado, int qte_restultados,
double tempoUsuario, double tempoNoSistema){

     printf("Tempo de Usuário: %.6lf segundos.\n", tempoUsuario);
     printf("Algoritmo ficou %.6lf segundos no sistema.\n", tempoNoSistema);
     
     for(int i=0; i<qte_restultados; i++){  
          if(resultado[i] == true){   
               fprintf(arquivoSaida, "Sim\n");
          } else if(resultado[i] == false){
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

ssize_t read_line(FILE *file, char **line, size_t *len) {
    ssize_t read;
    read = getline(line, len, file);
    if (read == -1) {
        if (feof(file)) {
            return 0; // Fim do arquivo
        } else {
            perror("Erro ao ler a linha do arquivo");
            exit(EXIT_FAILURE);
        }
    }
    // Remover nova linha, se presente
    if ((*line)[read - 1] == '\n') {
        (*line)[read - 1] = '\0';
        read--;
    }
    return read;
}

// Função para ler os dados de um arquivo e adicioná-los a um tabuleiro.
void leituraArquivo(FILE *file, char **text, char **pattern, Query **queries, int *num_queries) {
    size_t len = 0;
    ssize_t read;
    char *line = NULL;

    // Ler a primeira linha do arquivo (Texto Principal)
    read = read_line(file, &line, &len);
    if (read == 0) {
        printf("Erro: arquivo vazio ou fim do arquivo inesperado.\n");
        exit(EXIT_FAILURE);
    }

    *text = (char *)malloc((read + 1) * sizeof(char));
    if (*text == NULL) {
        printf("Erro ao alocar memória para o texto.\n");
        free(line);
        exit(EXIT_FAILURE);
    }
    strncpy(*text, line, read);
    (*text)[read] = '\0';

    // Ler a segunda linha do arquivo (Padrão)
    read = read_line(file, &line, &len);
    if (read == 0) {
        printf("Erro: arquivo vazio ou fim do arquivo inesperado.\n");
        free(*text);
        exit(EXIT_FAILURE);
    }

    *pattern = (char *)malloc((read + 1) * sizeof(char));
    if (*pattern == NULL) {
        printf("Erro ao alocar memória para o padrão.\n");
        free(*text);
        free(line);
        exit(EXIT_FAILURE);
    }
    strncpy(*pattern, line, read);
    (*pattern)[read] = '\0';

    // Ler a terceira linha do arquivo (Número de queries)
    read = read_line(file, &line, &len);
    if (read == 0) {
        printf("Erro: arquivo vazio ou fim do arquivo inesperado.\n");
        free(*text);
        free(*pattern);
        free(line);
        exit(EXIT_FAILURE);
    }
    *num_queries = atoi(line);

    *queries = (Query *)malloc(*num_queries * sizeof(Query));
    if (*queries == NULL) {
        printf("Erro ao alocar memória para as consultas.\n");
        free(*text);
        free(*pattern);
        free(line);
        exit(EXIT_FAILURE);
    }

    // Leitura dos intervalos das queries
    for (int i = 0; i < *num_queries; i++) {
        read = read_line(file, &line, &len);
        if (read == 0) {
            printf("Erro: arquivo vazio ou fim do arquivo inesperado.\n");
            free(*text);
            free(*pattern);
            free(*queries);
            free(line);
            exit(EXIT_FAILURE);
        }
        sscanf(line, "%d %d", &(*queries)[i].start, &(*queries)[i].end);
    }

    free(line);
}

void processQuery(Query *query, char *text, char *process_text){
    int count = 0;
    for(int i = (query->start - 1); i < query->end; i++){
        process_text[count] = text[i];
        count++;
    }
    process_text[count] = '\0';
}