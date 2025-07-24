//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshtein_distance(char *s1, char *s2, int m, int n) {
    int **dp = (int **) malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *) malloc(sizeof(int) * (n + 1));
        memset(dp[i], 0, sizeof(int) * (n + 1));
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
            }
        }
    }
    int dist = dp[m][n];
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    return dist;
}

int main() {
    char *s1 = "invasive";
    char *s2 = "example";
    int m = strlen(s1);
    int n = strlen(s2);
    int dist = levenshtein_distance(s1, s2, m, n);
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, dist);
    return 0;
}