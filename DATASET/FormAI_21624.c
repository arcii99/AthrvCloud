//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

int levenshteinDistance(char* s1, char* s2){
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = i+j;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main(){
    char str1[] = "chatbot";
    char str2[] = "chabot";

    int distance = levenshteinDistance(str1, str2);

    printf("The Levenshtein Distance between %s and %s is %d", str1, str2, distance);

    return 0;
}