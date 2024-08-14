#include "bmhs.h"
#define MaxChar 256

bool BMHS(char *text, int n, char *pattern, int m){

     int i, j, k;
     int d[MaxChar];

     for(j = 0; j < MaxChar; j++){
          d[j] = (m + 1);
     }

     for(j = 1; j < m; j++){
          d[(int)pattern[j]] = (m - j);
     }
         
     i = m;

     while(i <= n){

          k = i - 1;
          j = m - 1;
          while((text[k] == pattern[j]) && (j >= 0)){
               k--;
               j--;
          }
          if(j < 0){
               return true;
          }
          i = i + d[(int)text[i]];
     }

     return false;
}
