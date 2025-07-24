//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(char *s, char *t) {
  int m = strlen(s) + 1;
  int n = strlen(t) + 1;
  int d[m][n];

  for (int i = 0; i < m; i++) d[i][0] = i;
  for (int j = 0; j < n; j++) d[0][j] = j;

  for (int j = 1; j < n; j++) {
    for (int i = 1; i < m; i++) {
      int cost = s[i-1] == t[j-1] ? 0 : 1;

      d[i][j] = min(
        d[i-1][j] + 1,
        d[i][j-1] + 1,
        d[i-1][j-1] + cost
      );
    }
  }

  return d[m-1][n-1];
}

int main() {
  char *s = "kitten";
  char *t = "sitting";

  printf("Levenshtein distance between %s and %s is %d", s, t, levenshtein_distance(s, t));
  return 0;
}