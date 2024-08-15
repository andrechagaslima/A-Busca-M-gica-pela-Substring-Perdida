#include "bmhs.h"
#define MaxChar 256

bool BMHS(char *texto, int tam_texto, char *padrao, int tam_padrao){

     int i, j, k;
     int d[MaxChar];

     for(j = 0; j < MaxChar; j++){
          d[j] = (tam_padrao + 1);
     }
                                   
     for(j = 0; j < tam_padrao; j++){            
          d[(int)padrao[j]] = (tam_padrao - j);   // Pré-Processamento do padrão
     }
         
     i = tam_padrao;

     while(i <= tam_texto){
          
          k = i - 1;
          j = tam_padrao - 1;
          while((j >= 0) && (texto[k] == padrao[j])){
               k--;
               j--;
          }
          if(j < 0){
               return true; // Padrão encontrado
          } 
          if(i == tam_texto){ 
               i++; 
          } else {
               i = i + d[(int)texto[i]]; // Faz o deslocamento adequado
          }
     }

     return false;  // Padrão não encontrado
}
