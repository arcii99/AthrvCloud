//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main()
{
    char s1[100], s2[100];
    
    printf("Please enter the first string: ");
    scanf("%s", s1);
    
    printf("Please enter the second string: ");
    scanf("%s", s2);
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int matrix[len1+1][len2+1];
    
    memset(matrix, 0, sizeof(matrix));
    
    for (int i = 1; i <= len1; i++) {
        matrix[i][0] = i;
    }
    
    for (int j = 1; j <= len2; j++) {
        matrix[0][j] = j;
    }
    
    int cost;
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            
            matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
        }
    }
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, matrix[len1][len2]);
    
    return 0;
}