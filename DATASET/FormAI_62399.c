//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include<stdio.h>
#include<string.h>

int Matrix(char str1[], char str2[], int m, int n){
    int d[m+1][n+1];
    int i, j, cost;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0)
                d[i][j]=j;
            else if(j==0)
                d[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                d[i][j]=d[i-1][j-1];
            else{
                cost=1+Matrix(str1, str2, i-1, j-1);
                if(cost>d[i-1][j]+1)
                    cost=d[i-1][j]+1;
                if(cost>d[i][j-1]+1)
                    cost=d[i][j-1]+1;
                d[i][j]=cost;
            }
        }
    }
    return d[m][n];
}

int main(){
    char str1[1000], str2[1000];
    printf("What is the first string? ");
    scanf("%s", str1);
    printf("What is the second string? ");
    scanf("%s", str2);
    int m=strlen(str1);
    int n=strlen(str2);
    printf("The levenshtein distance for %s and %s is %d", str1, str2, Matrix(str1, str2, m, n));
    return 0;
}