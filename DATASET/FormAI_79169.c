//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int min(int x, int y, int z) { 
    return ((x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z)); 
} 
  
int LevenshteinDistance(char *str1, char *str2) 
{ 
    int len1 = strlen(str1), len2 = strlen(str2); 
    int matrix[len1+1][len2+1];

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {

            if(i == 0)
                matrix[i][j] = j;

            else if(j == 0)
                matrix[i][j] = i;

            else if(str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1];

            else
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
        }
    }

    return matrix[len1][len2]; 
} 

int main() 
{ 
    char string1[100], string2[100]; 
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: "); 
    scanf("%s", string1); 
    printf("Please enter the second string: "); 
    scanf("%s", string2); 
    int result = LevenshteinDistance(string1, string2); 
    printf("The Levenshtein Distance between %s and %s is %d.\n", string1, string2, result); 
    return 0; 
}