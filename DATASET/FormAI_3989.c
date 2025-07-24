//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

int levenshteinDistance(char *s1, char *s2, int m, int n, int **dp) {
    if (m == 0)
        return n;

    if (n == 0)
        return m;

    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];

    if (s1[m - 1] == s2[n - 1])
        dp[m - 1][n - 1] = levenshteinDistance(s1, s2, m - 1, n - 1, dp);
    else
        dp[m - 1][n - 1] = 1 + min(
            levenshteinDistance(s1, s2, m - 1, n - 1, dp),
            levenshteinDistance(s1, s2, m - 1, n, dp),
            levenshteinDistance(s1, s2, m, n - 1, dp)
        );

    return dp[m - 1][n - 1];
}

int main() {
    char s1[100], s2[100];
    int m, n;
    int **dp;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    m = strlen(s1);
    n = strlen(s2);

    dp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        dp[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    int distance = levenshteinDistance(s1, s2, m, n, dp);
    printf("The Levenshtein distance between %s and %s is %d\n", s1, s2, distance);

    for (int i = 0; i < m; i++)
        free(dp[i]);

    free(dp);

    return 0;
}