//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *s1, char *s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int i, j, cost;
  int **d = malloc((len1 + 1) * sizeof(int *));
  for (i = 0; i <= len1; i++) {
    d[i] = malloc((len2 + 1) * sizeof(int));
    d[i][0] = i;
  }
  for (j = 0; j <= len2; j++) {
    d[0][j] = j;
  }
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      cost = s1[i-1] == s2[j-1] ? 0 : 1;
      d[i][j] = d[i-1][j-1] + cost < d[i][j-1] + 1
    ? d[i-1][j-1] + cost < d[i-1][j] + 1
    ? d[i-1][j-1] + cost : d[i-1][j] + 1 : d[i][j-1] + 1;
    }
  }
  int distance = d[len1][len2];
  for (i = 0; i <= len1; i++) {
    free(d[i]);
  }
  free(d);
  return distance;
}

int main() {
  char str1[100], str2[100];
  printf("Enter the first string:\n");
  gets(str1);
  printf("Enter the second string:\n");
  gets(str2);
  int distance = levenshtein_distance(str1, str2);
  printf("The Levenshtein distance between %s and %s is %d\n", str1, str2, distance);
  return 0;
}