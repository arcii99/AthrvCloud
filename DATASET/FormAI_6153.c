//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include<stdio.h>
#include<string.h>
#define min(x,y,z) (x < y)?((x < z)? x : z):((y < z)? y : z) // macro to find the minimum of three integers 

int levenshtein_distance(char* original, char* modified){
    int n = strlen(original);
    int m = strlen(modified);
    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){

            if(i==0) dp[i][j] = j;

            else if(j==0) dp[i][j] = i;

            else if(original[i-1] == modified[j-1]) dp[i][j] = dp[i-1][j-1];

            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    char original[100], modified[100];
    printf("Enter two strings to find their Levenshtein distance: \n");
    scanf("%s %s", original, modified);

    int distance = levenshtein_distance(original, modified);

    printf("The Levenshtein Distance between '%s' and '%s' is: %d", original, modified, distance);
    
    return 0;
}