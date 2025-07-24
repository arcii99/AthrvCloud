//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshtein_distance(char* a, char* b, int m, int n) {
    int** dp = (int**) malloc((m+1) * sizeof(int*));
    for (int i = 0; i <= m; i++) dp[i] = (int*) malloc((n+1) * sizeof(int));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = a[i-1] == b[j-1] ? 0 : 1;
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost);
        }
    }

    int ans = dp[m][n];

    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);

    return ans;
}

int main() {
    char str1[] = "Mathematics";
    char str2[] = "Mathematical";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("The Levenshtein distance between %s and %s is: %d\n", str1, str2, levenshtein_distance(str1, str2, len1, len2));

    char str3[] = "Hello";
    char str4[] = "World";
    int len3 = strlen(str3);
    int len4 = strlen(str4);
    printf("The Levenshtein distance between %s and %s is: %d\n", str3, str4, levenshtein_distance(str3, str4, len3, len4));

    return 0;
}