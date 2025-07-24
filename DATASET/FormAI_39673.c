//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  int minimum = a;
  if (b < minimum) {
    minimum = b;
  }
  if (c < minimum) {
    minimum = c;
  }
  return minimum;
}

int levenshtein_distance(char* str1, char* str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int matrix[len1 + 1][len2 + 1];

  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      int substitution_cost = str1[i - 1] == str2[j - 1] ? 0 : 1;
      matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + substitution_cost);
    }
  }

  return matrix[len1][len2];
}

int main() {
  char* str1 = "kitten";
  char* str2 = "sitting";

  printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, levenshtein_distance(str1, str2));

  return 0;
}