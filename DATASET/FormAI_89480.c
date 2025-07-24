//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include<stdio.h>
#include<string.h>
#define MAX 10000

int minimum(int a,int b,int c);

int main(){

    char word1[MAX],word2[MAX];
    int n,m;

    printf("Levenshtein Distance Calculator\n");
    printf("Enter the first word: ");
    scanf("%s",word1);
    printf("Enter the second word: ");
    scanf("%s",word2);

    n=strlen(word1);
    m=strlen(word2);

    int arr[n+1][m+1];
    int i,j,cost;

    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0) arr[i][j]=j;
            else if(j==0) arr[i][j]=i;
            else if(word1[i-1]==word2[j-1]) arr[i][j]=arr[i-1][j-1];
            else{
                cost=1;
                arr[i][j]=minimum(arr[i][j-1]+1,arr[i-1][j]+1,arr[i-1][j-1]+cost);
            }
        }
    }
    printf("The Levenshtein Distance is: %d\n",arr[n][m]);
    return 0;
}

int minimum(int a,int b,int c){
    int min=a;
    if(b<min) min=b;
    if(c<min) min=c;
    return min;
}