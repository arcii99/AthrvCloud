//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int levenshteinDistance(char *s1, char *s2);

int main() {
  char str1[MAX_LEN];
  char str2[MAX_LEN];
  int distance;

  printf("Welcome to the Levenshtein Distance Calculator!\n");
  printf("Please enter the first string: ");
  fgets(str1, sizeof(str1), stdin);
  str1[strcspn(str1, "\n")] = '\0';

  printf("Please enter the second string: ");
  fgets(str2, sizeof(str2), stdin);
  str2[strcspn(str2, "\n")] = '\0';

  distance = levenshteinDistance(str1, str2);

  printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

  return 0;
}

int levenshteinDistance(char *s1, char *s2) {
  int s1_len = strlen(s1);
  int s2_len = strlen(s2);
  int i, j, substitution_cost;
  int distance_table[s1_len + 1][s2_len + 1];

  for (i = 0; i <= s1_len; i++) {
    distance_table[i][0] = i;
  }

  for (j = 0; j <= s2_len; j++) {
    distance_table[0][j] = j;
  }

  for (j = 1; j <= s2_len; j++) {
    for (i = 1; i <= s1_len; i++) {
      if (s1[i - 1] == s2[j - 1]) {
        substitution_cost = 0;
      }
      else {
        substitution_cost = 1;
      }

      distance_table[i][j] = findMinimum(distance_table[i - 1][j] + 1, distance_table[i][j - 1] + 1, distance_table[i - 1][j - 1] + substitution_cost);
    }
  }

  return distance_table[s1_len][s2_len];
}

int findMinimum(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  }
  else if (b <= a && b <= c) {
    return b;
  }
  else {
    return c;
  }
}