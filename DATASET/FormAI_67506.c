//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include<stdio.h>
#include<string.h>

// function that returns minimum of three numbers
int minimum(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    if(c <= a && c <= b) return c;
}

// function that calculates the Levenshtein distance
int levenshteinDistance(char *s1, char *s2, int len1, int len2){
    int dp[len1+1][len2+1];
    int i,j;
    for(i=0;i<=len1;i++){
        for(j=0;j<=len2;j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    return dp[len1][len2];
}

// main function
int main(){
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshteinDistance(s1, s2, len1, len2));
    return 0;
}