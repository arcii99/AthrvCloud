//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char* str1, char* str2, int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    
    return matrix[len1][len2];
}

int main() {
    char romeo[] = "But, soft! what light through yonder window breaks?";
    char juliet[] = "It is the east, and Juliet is the sun.";
    
    int len1 = strlen(romeo);
    int len2 = strlen(juliet);
    
    printf("Romeo: \"%s\"\n", romeo);
    printf("Juliet: \"%s\"\n", juliet);
    printf("Levenshtein Distance: %d\n", levenshteinDistance(romeo, juliet, len1, len2));
    
    return 0;
}