//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[m+1][n+1];
    int i, j;
    
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            
            else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            
            else dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    return dp[m][n];
}

int main() {
    char s1[50], s2[50];
    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);
    
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between %s and %s is %d.\n", s1, s2, distance);
    
    return 0;
}