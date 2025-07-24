//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: curious
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int arr[] = {a, b, c};
    int m = a;
    for(int i=1; i<3; i++){
        if(arr[i]<m)
            m = arr[i];
    }
    return m;
}

int levenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    
    int dp[m+1][n+1];
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min( dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int main() {
    char s1[50], s2[50];
    printf("Enter the first string:");
    scanf("%s", s1);
    printf("Enter the second string:");
    scanf("%s", s2);
    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein distance between %s and %s is %d\n", s1, s2, distance);
    return 0;
}