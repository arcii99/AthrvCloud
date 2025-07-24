//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c) {
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}

int levenshtein_distance(char* s1, char* s2, int m, int n) {
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int m = strlen(str1);
    int n = strlen(str2);
    int distance = levenshtein_distance(str1, str2, m, n);
    printf("Levenshtein Distance between %s and %s is %d", str1, str2, distance);
    return 0;
}