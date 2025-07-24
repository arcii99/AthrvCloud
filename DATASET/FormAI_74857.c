//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

int min(int x,int y,int z){
    if(x<=y && x<=z)
        return x;
    else if(y<=x && y<=z)
        return y;
    else
        return z;
}

int levenshtein_distance(char *a, char *b){
    int n = strlen(a), m = strlen(b);
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    return dp[n][m];
}

int main(){
    char a[1000] = "Good night, good night! parting is such sweet sorrow";
    char b[1000] = "Good night, good night! parting is such a sweet sorrow";
    
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d",a,b,levenshtein_distance(a,b));
    
    return 0;
}