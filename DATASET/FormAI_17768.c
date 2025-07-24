//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

int min(int a,int b,int c){
    return a<b?(a<c?a:c):(b<c?b:c);
}

int levenshtein_distance(char *s,char *t){
    int n=strlen(s);
    int m=strlen(t);
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=i+j;
            }
            else if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            }
        }
    }
    return dp[n][m];
}

int main(){
    char s[]="Hello";
    char t[]="World";
    int dist=levenshtein_distance(s,t);//Calculating Levenshtein Distance
    printf("The Levenshtein Distance between %s and %s is: %d\n",s,t,dist);//Printing the Distance
    return 0;
}