//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    return c;
}

int levenshtein(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[MAX_LENGTH][MAX_LENGTH];

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0) {
                matrix[i][j] = j;
            } else if(j == 0) {
                matrix[i][j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1]; 
            } else {
                matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]) + 1; 
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int distance = levenshtein(str1, str2);
    printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}