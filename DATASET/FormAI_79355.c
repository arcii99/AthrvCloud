//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
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

int levenshtein_distance(char *x, char *y) {
    int m = strlen(x);
    int n = strlen(y);

    if (m == 0) {
        return n;
    } else if (n == 0) {
        return m;
    }

    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (x[i-1] == y[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);

    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);

    // Remove newline character from strings
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between %s and %s is %d", str1, str2, distance);

    return 0;
}