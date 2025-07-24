//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

int min(int x, int y, int z){
    if(x<=y)
        return (x<=z)?x:z;
    else
        return (y<=z)?y:z;
}

int levenshtein_distance(char string1[], char string2[], int len1, int len2){
    int dp[MAX_SIZE][MAX_SIZE];
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(string1[i-1]==string2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    return dp[len1][len2];
}

int main(){
    char string1[MAX_SIZE], string2[MAX_SIZE];
    printf("Enter String 1: ");
    scanf("%s", string1);
    printf("Enter String 2: ");
    scanf("%s", string2);
    int len1=strlen(string1), len2=strlen(string2);
    int distance=levenshtein_distance(string1, string2, len1, len2);
    printf("Levenshtein Distance = %d\n", distance);
    return 0;
}