//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *s1, char *s2, int m, int n) {
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char s1[] = "kenneth";
    char s2[] = "thompson";

    int m = strlen(s1);
    int n = strlen(s2);
    
    int distance = levenshtein_distance(s1, s2, m, n);

    printf("Ken Thompson\n");
    printf("Levenshtein Distance Calculator\n\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}