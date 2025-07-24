//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
  char *str1 = "The moon shone like a silver clamshell";
  char *str2 = "A shoal of fish swam in the sky";

  int len_str1 = strlen(str1);
  int len_str2 = strlen(str2);

  int dist[len_str1 + 1][len_str2 + 1];

  for (int i = 0; i <= len_str1; i++) {
    for (int j = 0; j <= len_str2; j++) {
      if (i == 0) {
        dist[i][j] = j;
      }
      else if (j == 0) {
        dist[i][j] = i;
      }
      else {
        dist[i][j] = -1;
      }
    }
  }

  for (int i = 1; i <= len_str1; i++) {
    for (int j = 1; j <= len_str2; j++) {
      int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
      dist[i][j] = fmin(fmin(dist[i][j-1] + 1, dist[i-1][j] + 1), dist[i-1][j-1] + cost);
      if (i > 1 && j > 1 && str1[i-1] == str2[j-2] && str1[i-2] == str2[j-1]) {
        dist[i][j] = fmin(dist[i][j], dist[i-2][j-2] + cost);
      }
    }
  }

  printf("The Levenshtein distance between\n\n'%s'\n\nand\n\n'%s'\n\nis %d\n", str1, str2, dist[len_str1][len_str2]);

  return 0;
}