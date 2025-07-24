//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int LevenshteinDistance(char *s1, char *s2) {
  int s1_length = strlen(s1);
  int s2_length = strlen(s2);

  int matrix[s1_length + 1][s2_length + 1];
  memset(matrix, 0, sizeof(matrix));

  for(int i = 0; i <= s1_length; i++) {
    matrix[i][0] = i;
  }

  for(int j = 0; j <= s2_length; j++) {
    matrix[0][j] = j;
  }

  for(int i = 1; i <= s1_length; i++) {
    for(int j = 1; j <= s2_length; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

      int deletion = matrix[i - 1][j] + 1;
      int insertion = matrix[i][j - 1] + 1;
      int substitution = matrix[i - 1][j - 1] + cost;

      matrix[i][j] = deletion;
      if(insertion < matrix[i][j]) {
        matrix[i][j] = insertion;
      }
      if(substitution < matrix[i][j]) {
        matrix[i][j] = substitution;
      }
    }
  }

  return matrix[s1_length][s2_length];
}

int main() {
  char s1[MAX_LENGTH];
  char s2[MAX_LENGTH];

  printf("Enter the first string: ");
  fgets(s1, MAX_LENGTH, stdin);
  s1[strcspn(s1, "\n")] = 0;

  printf("Enter the second string: ");
  fgets(s2, MAX_LENGTH, stdin);
  s2[strcspn(s2, "\n")] = 0;

  int distance = LevenshteinDistance(s1, s2);
  printf("Levenshtein Distance: %d\n", distance);

  return 0;
}