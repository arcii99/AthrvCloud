//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int min(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  } else if (b <= c) {
    return b;
  } else {
    return c;
  }
}

int levenshteinDistance(char s[], char t[]) {
  int n = strlen(s);
  int m = strlen(t);
  int dp[MAX_LEN][MAX_LEN];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
      }
    }
  }

  return dp[n][m];
}

int main() {
  char s[MAX_LEN];
  char t[MAX_LEN];
  
  printf("Welcome to the Levenshtein Distance Calculator!\n");
  
  do {
    printf("\nPlease enter the first string: ");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = 0;
    
    printf("Please enter the second string: ");
    fgets(t, MAX_LEN, stdin);
    t[strcspn(t, "\n")] = 0;

    int distance = levenshteinDistance(s, t);
  
    printf("\nThe Levenshtein distance between '%s' and '%s' is: %d\n", s, t, distance);
  
    printf("\nWould you like to calculate another Levenshtein distance? (Y/N) ");
  } while (getchar() == 'Y' || getchar() == 'y');
  
  return 0;
}