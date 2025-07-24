//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include<stdio.h>
#include<string.h>
#define MAX_LEN 100
 
int min(int x, int y, int z){
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}
 
int calculateLevenshteinDistance(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[MAX_LEN][MAX_LEN];
 
    //Building the matrix
    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            // Fill in first row and column  
            if(i == 0){
                matrix[i][j] = j;
                continue;
            }
            if(j == 0){
                matrix[i][j] = i;
                continue;
            }
 
            // Check for calculation of Levenshtein Distance 
            if(str1[i-1] == str2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
 
    return matrix[len1][len2];
}
 
int main(){
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter the first string:\n");
    scanf("%s", str1);
    printf("Enter the second string:\n");
    scanf("%s", str2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, calculateLevenshteinDistance(str1, str2));
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    return 0;
}