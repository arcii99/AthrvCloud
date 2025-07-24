//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    return c;
}

int levenshtein_distance(char *word1, char *word2, int len1, int len2) {
    int dp[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    char word1[100];
    char word2[100];
    scanf("%s %s", word1, word2);
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int distance = levenshtein_distance(word1, word2, len1, len2);
    printf("The Levenshtein Distance between %s and %s is %d\n", word1, word2, distance);
    return 0;
}