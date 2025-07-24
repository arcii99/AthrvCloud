//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < c) {
        return b;
    } else {
        return c;
    }
}

int LevenshteinDistance(char word1[], char word2[], int n, int m) {
    int dp[n + 1][m + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    char word1[100], word2[100];
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);
    int n = strlen(word1);
    int m = strlen(word2);
    printf("The Levenshtein Distance is: %d", LevenshteinDistance(word1, word2, n, m));
    return 0;
}