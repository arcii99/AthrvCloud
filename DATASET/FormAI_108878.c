//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int levenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[len1 + 1][len2 + 1];

    for(int i = 0; i <= len1; i++) dp[i][0] = i;
    for(int i = 0; i <= len2; i++) dp[0][i] = i;

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1], 1 + dp[i - 1][j]);
        }
    }

    return dp[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, levenshteinDistance(s1, s2));
    return 0;
}