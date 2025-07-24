//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
  int min = a;
  if (b < min)
    min = b;
  if (c < min)
    min = c;
  return min;
}

int levenshtein_distance(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int matrix[len1+1][len2+1];

  for (int i = 0; i <= len1; i++)
    matrix[i][0] = i;
  for (int j = 0; j <= len2; j++)
    matrix[0][j] = j;

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

      matrix[i][j] = minimum(matrix[i-1][j] + 1,        // deletion
                              matrix[i][j-1] + 1,        // insertion
                              matrix[i-1][j-1] + cost);  // substitution
    }
  }

  return matrix[len1][len2];
}

int main() {
  char word1[20] = "castle";
  char word2[20] = "dragon";

  printf("Levenshtein Distance between %s and %s: %d\n", word1, word2, levenshtein_distance(word1, word2));

  return 0;
}