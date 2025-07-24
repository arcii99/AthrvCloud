//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if(a < b && a < c) return a;
    else if(b < c) return b;
    else return c;
}

int levenshteinDistance(char *s, char *t) {
    int m = strlen(s), n = strlen(t);
    int **dp = (int **)malloc((m+1) * sizeof(int *));
    for(int i=0; i<=m; i++)
        dp[i] = (int *)malloc((n+1) * sizeof(int));
    for(int i=1; i<=m; i++)
        dp[i][0] = i;
    for(int j=1; j<=n; j++)
        dp[0][j] = j;
    for(int j=1; j<=n; j++) {
        for(int i=1; i<=m; i++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + minimum(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    int result = dp[m][n];
    for(int i=0; i<=m; i++)
        free(dp[i]);
    free(dp);
    return result;
}

int main() {
    char str1[50], str2[50];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d", str1, str2, distance);

    return 0;
}