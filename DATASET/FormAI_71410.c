//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    return c;
}

int levenshteinDistance(char* str1, char* str2, int len1, int len2) {
    int  i, j, cost, **dp;
    dp = malloc(sizeof(int*) * (len1 + 1));
    for(i = 0; i <= len1; i++)
        dp[i] = malloc(sizeof(int) * (len2 + 1));
    for(i = 0; i <= len1; i++)
        dp[i][0] = i;
    for(j = 0; j <= len2; j++)
        dp[0][j] = j;
    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }
    int result = dp[len1][len2];
    for(i = 0; i <= len1; i++)
        free(dp[i]);
    free(dp);
    return result;
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    printf("Levenshtein Distance of '%s' and '%s' is %d", str1, str2, levenshteinDistance(str1, str2, len1, len2 ));
    return 0;
}