//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z)
{
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    else return z;
}

int LevenshteinDistance(char* X, char* Y, int m, int n)
{
    int cost = 0;
    int dp[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                cost = (X[i-1] != Y[j-1]);
                dp[i][j] = min(dp[i-1][j] + 1,         
                               dp[i][j-1] + 1,          
                               dp[i-1][j-1] + cost);     
            }
        }
    }
    return dp[m][n];
}

int main()
{
    char X[] = "chatbot";
    char Y[] = "chabot";
    
    int m = strlen(X);
    int n = strlen(Y);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d", X, Y, LevenshteinDistance(X, Y, m, n));
    
    return 0;
}