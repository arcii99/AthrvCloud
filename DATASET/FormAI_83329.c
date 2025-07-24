//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix[100][100];

int minimum(int a, int b, int c){
  int min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  return min;
}

int levenshtein_distance(char *s1, char *s2, int len1, int len2){

  memset(matrix, 0, sizeof(matrix)); 

  int i,j;

  for (i = 1; i <= len1; i++)
    matrix[i][0] = i;

  for (j = 1; j <= len2; j++)
    matrix[0][j] = j;

  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {

      if (s1[i-1] == s2[j-1])
        matrix[i][j] = matrix[i-1][j-1];
      
      else
        matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+1);
    }
  }
  
  return matrix[len1][len2];
}

int main(){

  char *s1 = "puzzle";
  char *s2 = "muzzle";
  
  int distance = levenshtein_distance(s1, s2, strlen(s1), strlen(s2));

  printf("The Levenshtein Distance between %s and %s is %d \n", s1, s2, distance);

  return 0;
}