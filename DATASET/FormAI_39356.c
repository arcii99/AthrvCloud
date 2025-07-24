//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

int levenshteinDistance(char* s, char* t) {
    int m = strlen(s) + 1;
    int n = strlen(t) + 1;

    int dp[m][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j < n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    char* s = (char*) malloc(MAX_LEN * sizeof(char));
    char* t = (char*) malloc(MAX_LEN * sizeof(char));

    printf("Enter a string: ");
    scanf("%s", s);

    printf("Enter another string: ");
    scanf("%s", t);

    int distance = levenshteinDistance(s, t);

    printf("Levenshtein Distance between '%s' and '%s' is %d\n", s, t, distance);

    free(s);
    free(t);

    return 0;
}