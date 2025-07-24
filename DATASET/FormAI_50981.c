//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int levenshtein_distance(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int **dp = (int **) malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *) malloc(sizeof(int) * (m + 1));
        memset(dp[i], 0, sizeof(int) * (m + 1));
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }

    int res = dp[n][m];

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }

    free(dp);

    return res;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between %s and %s is %d.\n", str1, str2, distance);

    return 0;
}