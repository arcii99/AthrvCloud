//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshteinDistance(char* s, char* t){
    int n = strlen(s);
    int m = strlen(t);

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    return dp[n][m];
}

int main(){
    char s[100], t[100];
    printf("Enter two strings: ");
    scanf("%s %s", s, t);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", s, t, levenshteinDistance(s, t));
    return 0;
}