//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int levenshteinDistance(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } 
            else if(j == 0) {
                dp[i][j] = i;
            }
            else if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    char word1[100], word2[100];
    printf("Enter the first word: ");
    scanf("%s", &word1);
    printf("Enter the second word: ");
    scanf("%s", &word2);

    int distance = levenshteinDistance(word1,word2);
    printf("The Levenshtein distance between %s and %s is: %d", word1, word2, distance);

    return 0;
}