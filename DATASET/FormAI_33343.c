//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levenshteinDistance(char *s, char *t) {
    int n = strlen(s), m = strlen(t);
    int cost[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) cost[i][j] = j;
            else if (j == 0) cost[i][j] = i;
            else if (s[i - 1] == t[j - 1]) cost[i][j] = cost[i - 1][j - 1];
            else cost[i][j] = 1 + min(cost[i - 1][j - 1], cost[i][j - 1], cost[i - 1][j]);
        }
    }
    return cost[n][m];
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    printf("Levenshtein distance between %s and %s is %d \n", s1, s2, levenshteinDistance(s1, s2));
    char *s3 = "rosettacode";
    char *s4 = "raisethysword";
    printf("Levenshtein distance between %s and %s is %d \n", s3, s4, levenshteinDistance(s3, s4));
    return 0;
}