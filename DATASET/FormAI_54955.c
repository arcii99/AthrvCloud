//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include<stdio.h>
#include<string.h>
#define MAX_LEN 1000

int min(int a, int b, int c) {
  if(a < b && a < c) {
    return a;
  } else if(b < a && b < c) {
    return b;
  } else {
    return c;
  }
}

int levenshtein_distance(char *str1, char *str2) {
  int m = strlen(str1);
  int n = strlen(str2);
  int matrix[m+1][n+1];
  int i, j;
  
  for(i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }
  
  for(j = 0; j <= n; j++) {
    matrix[0][j] = j;
  }
  
  for(i = 1; i <= m; i++) {
    for(j = 1; j <= n; j++) {
      int cost;
      if(str1[i-1] == str2[j-1]) {
        cost = 0;
      } else {
        cost = 1;
      }
      matrix[i][j] = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + cost);
    }
  }
  
  return matrix[m][n];
}

int main() {
  char str1[MAX_LEN], str2[MAX_LEN];
  
  printf("Enter the first string: ");
  fgets(str1, MAX_LEN, stdin);
  
  printf("Enter the second string: ");
  fgets(str2, MAX_LEN, stdin);
  
  // Removing the newline character from strings
  str1[strcspn(str1, "\n")] = 0;
  str2[strcspn(str2, "\n")] = 0;
  
  int dist = levenshtein_distance(str1, str2);
  printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, dist);
  
  return 0;
}