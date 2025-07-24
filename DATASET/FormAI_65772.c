//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
  if (a < b && a < c) {
    return a;
  } else if (b < a && b < c) {
    return b;
  } else {
    return c;
  }
}

int levenshtein_distance(char* s1, char* s2) {
  int m = strlen(s1) + 1;
  int n = strlen(s2) + 1;

  int dist[m][n];
  memset(dist, 0, sizeof(dist));

  for (int i=0; i < m; i++) {
    dist[i][0] = i;
  }

  for (int j=0; j < n; j++) {
    dist[0][j] = j;
  }

  for (int i=1; i < m; i++) {
    for (int j=1; j < n; j++) {
      if (s1[i-1] == s2[j-1]) {
        dist[i][j] = dist[i-1][j-1];
      } else {
        dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1;
      }
    }
  }

  return dist[m-1][n-1];
}

int main() {
  char str1[MAX_LEN], str2[MAX_LEN];

  // Get input strings from user
  printf("Enter string #1: ");
  fgets(str1, MAX_LEN, stdin);

  printf("Enter string #2: ");
  fgets(str2, MAX_LEN, stdin);

  // Remove newline characters
  str1[strcspn(str1, "\n")] = 0;
  str2[strcspn(str2, "\n")] = 0;

  // Calculate and print Levenshtein distance
  printf("Levenshtein distance: %d\n", levenshtein_distance(str1, str2));

  return 0;
}