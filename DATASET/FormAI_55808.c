//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2, matrix[MAX_LEN][MAX_LEN], i, j;
    
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }
    
    printf("The Levenshtein Distance between %s and %s is: %d", str1, str2, matrix[len1][len2]);
    
    return 0;
}

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}