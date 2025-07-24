//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include<stdio.h>
#include<string.h>

#define MAX 10000

int dp[MAX][MAX];

int min(int a, int b, int c) {
    if(a < b && a < c) return a;
    else if(b < a && b < c) return b;
    else return c;
}

int levenshtein(char *a, int m, char *b, int n) {
    int i, j;
    
    for(i=0; i<=n; i++) dp[0][i] = i;
    for(i=0; i<=m; i++) dp[i][0] = i;
    
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
        }
    }
    
    return dp[m][n];
}

int main() {
    char a[MAX], b[MAX];
    int m, n, distance;
    printf("Enter the first string: ");
    scanf("%s", a);
    printf("Enter the second string: ");
    scanf("%s", b);
    
    m = strlen(a);
    n = strlen(b);
    
    distance = levenshtein(a, m, b, n);
    
    printf("Levenshtein distance between %s and %s is %d\n", a, b, distance);
    
    return 0;
}