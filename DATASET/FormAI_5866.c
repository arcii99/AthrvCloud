//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    int min=a<b?a:b;
    min=min<c?min:c;
    return min;
}

int levenshtein_distance(char* s1, char* s2, int m, int n){
    int dist[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0){
                dist[i][j]=j;
            }else if(j==0){
                dist[i][j]=i;
            }else if(s1[i-1]==s2[j-1]){
                dist[i][j]=dist[i-1][j-1];
            }else{
                dist[i][j]=1+min(dist[i][j-1],//insert
                            dist[i-1][j],//delete
                            dist[i-1][j-1]);//substitute
            }
        }
    }
    return dist[m][n];
}

int main(){
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s",s1);
    printf("Enter second string: ");
    scanf("%s",s2);
    int m=strlen(s1);
    int n=strlen(s2);
    int distance=levenshtein_distance(s1,s2,m,n);
    printf("The Levenshtein Distance between %s and %s is %d\n",s1,s2,distance);

    return 0;
}