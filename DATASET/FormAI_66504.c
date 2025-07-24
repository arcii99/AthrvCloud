//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c)
        return a;
    else if(b < a && b < c)
        return b;
    else
        return c;
}

int levenshteinDistance(char a[], char b[]) {
    int m = strlen(a), n = strlen(b);
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    char str1[] = "Happy";
    char str2[] = "Joyful";
    int dist = levenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, dist);
    return 0;
}