//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int levDistance(char *s1, char *s2) {
    int n = strlen(s1), m = strlen(s2);
    int dp[n+1][m+1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    
    return dp[n][m];
}

int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    char s1[100];
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0; // remove trailing newline
    
    printf("Please enter the second string: ");
    char s2[100];
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0; // remove trailing newline
    
    int dist = levDistance(s1, s2);
    printf("\nThe Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s1, s2, dist);
    
    printf("\nThank you for using the Levenshtein Distance Calculator!\n");
    
    return 0;
}