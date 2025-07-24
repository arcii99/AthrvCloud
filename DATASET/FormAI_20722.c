//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include<stdio.h>
#include<string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

int levenshtein_distance(char* str1, char* str2){
    int m = strlen(str1);
    int n = strlen(str2);
    int matrix[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                matrix[i][j] = i+j;
            else if(str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + MIN(MIN(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);
        }
    }
    return matrix[m][n];
}

int main(){
    char str1[100], str2[100];
    int distance;
    printf("Enter first string: ");
    scanf("%s",str1);
    printf("Enter second string: ");
    scanf("%s",str2);
    distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance between %s and %s is %d",str1,str2,distance);
    return 0;
}