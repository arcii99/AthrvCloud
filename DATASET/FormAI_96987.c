//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    return a<b?(a<c?a:c):(b<c?b:c);
} 

int levenshtein_distance(char s1[], char s2[], int len1, int len2){
    int dp[len1+1][len2+1];
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main(){
    char s1[100], s2[100];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    printf("The Levenshtein distance is %d\n", levenshtein_distance(s1, s2, len1, len2));
    return 0;
}