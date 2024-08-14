#include "bmhs.h"
#define MaxChar 256

bool BMHS(char *text, int n, char *pattern, int m){

     int i, j, k;
     int d[MaxChar];

     for(j = 0; j < MaxChar; j++){
          d[j] = (m + 1);
     }

     for(j = 0; j < m; j++){
          d[(int)pattern[j]] = (m - j);
     }
         
     i = m;

     while(i <= n){
          
          k = i - 1;
          j = m - 1;
          while((j >= 0) && (text[k] == pattern[j])){
               k--;
               j--;
          }
          if(j < 0){
               return true;
          } 
          if(i == n){ 
               i++; 
          } else {
               i = i + d[(int)text[i]];
          }
     }

     return false;
}
