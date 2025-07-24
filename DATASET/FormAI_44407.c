//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 50

int dp[MAX_LEN][MAX_LEN];

int min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int levenshteinDistance(char *a, char *b){
    int m = strlen(a), n = strlen(b);
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else{
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[m][n];
}

int main(){
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter first string: ");
    fgets(s1, MAX_LEN, stdin);
    printf("Enter second string: ");
    fgets(s2, MAX_LEN, stdin);

    int result = levenshteinDistance(s1, s2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", s1, s2, result);
    return 0;
}