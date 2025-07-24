//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int getLevenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];
    int i, j;

    for (i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (j = 0; j <= len2; j++)
        dp[0][j] = j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);
    printf("Levenshtein Distance: %d\n", getLevenshteinDistance(str1, str2));
    return 0;
}