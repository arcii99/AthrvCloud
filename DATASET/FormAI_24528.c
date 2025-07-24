//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100], str2[100];
  int len1, len2, i, j, distance;

  printf("I am a program that calculates the Levenshtein Distance!\n");
  printf("Enter the first string: ");
  scanf("%s", str1);
  printf("Enter the second string: ");
  scanf("%s", str2);

  len1 = strlen(str1);
  len2 = strlen(str2);

  int matrix[len1+1][len2+1];

  printf("\nCalculating...\n\n");

  for(i = 0; i <= len1; i++)
    matrix[i][0] = i;

  for(j = 0; j <= len2; j++)
    matrix[0][j] = j;

  for(i = 1; i <= len1; i++) {
    for(j = 1; j <= len2; j++) {
      if(str1[i-1] == str2[j-1])
        matrix[i][j] = matrix[i-1][j-1];
      else
        matrix[i][j] = 1 + min(matrix[i-1][j],      // deletion
                              matrix[i][j-1],       // insertion
                              matrix[i-1][j-1]);    // substitution
    }
  }

  distance = matrix[len1][len2];

  printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

  return 0;
}

int min(int a, int b, int c) {
  int temp = a < b ? a : b;
  return temp < c ? temp : c; 
}