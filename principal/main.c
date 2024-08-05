#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>
#include "leitura.h"

int main(int argc, char *argv[]) {
    
     char *algoritmo = NULL;
     char *inputFile = NULL;
     char *outputFile = "saida.txt";
     struct rusage start, end; //Usados para calcular o tempo (getrusage)
     struct timeval inicio, fim; //Usados para calcular o tempo (gettimeofday)
     long int resultado = 0;

     //Recebe o algoritmo e o nome do arquivo de entrada
     algoritmo = argv[1];
     inputFile = argv[2];

     verificacaoArquivoEntrada(argv, inputFile, algoritmo);

     // Abrir o arquivo de entrada
     FILE *arquivo = fopen(inputFile, "r");
     testaAberturaArquivo(arquivo, inputFile);

     // Abrir o arquivo de saída
     FILE *arquivoSaida = fopen(outputFile, "w");
     testaAberturaArquivo(arquivoSaida, outputFile);

     

     getrusage(RUSAGE_SELF, &start);
     gettimeofday(&inicio, NULL);

     //Escolha do Algoritmo
     if(algoritmo[0] == '1') {

     } else if (algoritmo[0] == '2') {

     }

     gettimeofday(&fim, NULL);
     getrusage(RUSAGE_SELF, &end);

     //Cálculos de tempo
     double tempoUsuario = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
     double tempoNoSistema = (end.ru_stime.tv_sec - start.ru_stime.tv_sec) 
          + 1e-6 * (end.ru_stime.tv_usec - start.ru_stime.tv_usec);

     imprimirSaidas(arquivoSaida, resultado, tempoUsuario, tempoNoSistema);
     
     //Finalizações

     fclose(arquivo);
     fclose(arquivoSaida);

     return 0;

}