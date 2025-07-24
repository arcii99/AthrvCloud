//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    if(a<b && a<c) return a;
    if(b<a && b<c) return b;
    return c;
}

int levenshteinDistance(char s1[], char s2[], int m, int n) {
    int dp[m+1][n+1];
    
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);
    printf("Levenshtein Distance between %s and %s is: %d\n", s1, s2, levenshteinDistance(s1, s2, m, n));
    return 0;
}