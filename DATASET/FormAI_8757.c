//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int min(int a, int b, int c) {
   int min = a;
   if (b < min) {
      min = b;
   }
   if (c < min) {
      min = c;
   }
   return min;
}
 
int getLevenshteinDistance(char *s, char *t, int len_s, int len_t) {
   int matrix[len_s + 1][len_t + 1];
 
   matrix[0][0] = 0;
 
   for (int i = 1; i <= len_s; i++) {
      matrix[i][0] = i;
   }
 
   for (int j = 1; j <= len_t; j++) {
      matrix[0][j] = j;
   }
 
   int substitutionCost;
 
   for (int i = 1; i <= len_s; i++) {
      for (int j = 1; j <= len_t; j++) {
         substitutionCost = (s[i-1] == t[j-1]) ? 0 : 1;
         matrix[i][j] = min(matrix[i-1][j] + 1,              
                     matrix[i][j-1] + 1,      
                     matrix[i-1][j-1] + substitutionCost);  
      }
   }
 
   return matrix[len_s][len_t];
}
 
int main(int argc, char *argv[]) {
   char *s = "kitten";
   char *t = "sitting";
 
   int distance = getLevenshteinDistance(s, t, strlen(s), strlen(t));
   printf("Levenshtein Distance between %s and %s : %d\n", s, t, distance);
   
   return 0;
}