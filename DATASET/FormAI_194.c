//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}

int LevenshteinDistance(char *s1, char *s2){
    int m = strlen(s1);
    int n = strlen(s2);
    int d[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                d[i][j] = j;
            }
            else if(j==0){
                d[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                d[i][j] = d[i-1][j-1];
            }
            else{
                d[i][j] = 1+min(d[i][j-1],d[i-1][j],d[i-1][j-1]);
            }
        }
    }
    return d[m][n];
}

int main(){
    char str1[] = "Hello, World!";
    char str2[] = "Hllo, Wod!";

    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d",str1,str2,LevenshteinDistance(str1,str2));

    return 0;
}