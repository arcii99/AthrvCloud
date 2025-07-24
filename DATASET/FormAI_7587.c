//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include<stdio.h>  
#include<string.h>   
#define MAX_LEN 100  

int min(int a, int b, int c) {
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}

int levenshtein_distance(char *str1, char *str2) {  
    int cost;
    int len1 = strlen(str1);  
    int len2 = strlen(str2);
    int mat[MAX_LEN][MAX_LEN];
    
    memset(mat,0,sizeof(mat));

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                mat[i][j] = j;
            }
            else if (j == 0) {
                mat[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                mat[i][j] = mat[i - 1][j - 1];
            }
            else {
                cost = 1;
                mat[i][j] = min(mat[i - 1][j] + 1, mat[i][j - 1] + 1, mat[i - 1][j - 1] + cost);
            }
        }
    }

    return mat[len1][len2];
}

void main() {  
    char str1[MAX_LEN];  
    char str2[MAX_LEN];
    printf("Enter first string: ");  
    scanf("%s", str1);  
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Levenshtein Distance is: %d",levenshtein_distance(str1, str2));
}