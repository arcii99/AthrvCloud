//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levenshteinDistance(char *str1, char *str2, int m, int n) {
    int dp[m+1][n+1];
    
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    return dp[m][n];
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    int distance = levenshteinDistance(str1, str2, m, n);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    
    return 0;
}