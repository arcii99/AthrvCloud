//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int main() {
    char str1[100], str2[100];
    printf("Enter String 1: ");
    scanf("%s", str1);
    printf("Enter String 2: ");
    scanf("%s", str2);
    int len1 = strlen(str1), len2 = strlen(str2);

    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (int i = 0; i <= len2; i++)
        dp[0][i] = i;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        }
    }
    printf("Levenshtein Distance Matrix:\n");
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("Levenshtein Distance between \"%s\" and \"%s\": %d\n", str1, str2, dp[len1][len2]);
    return 0;
}