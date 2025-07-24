//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MIN2(a,b) ((a)<(b)?(a):(b))
#define MIN3(a,b,c) ((a)<(b)?MIN2(a,c):MIN2(b,c))

int levenshtein(char *s1, char *s2);

int main() {
    char str1[100], str2[100];
    printf("Enter string 1: ");
    fgets(str1, 100, stdin);
    printf("Enter string 2: ");
    fgets(str2, 100, stdin);
    str1[strcspn(str1, "\n")] = 0; //removes newline character
    str2[strcspn(str2, "\n")] = 0;
    int num = levenshtein(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, num);
    return 0;
}

int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];
    int i, j, substitutionCost;
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else {
                substitutionCost = s1[i - 1] == s2[j - 1] ? 0 : 1;
                matrix[i][j] = MIN3(matrix[i-1][j] + 1,  //deletion
                                  matrix[i][j-1] + 1,   //insertion
                                  matrix[i-1][j-1] + substitutionCost); //substitution
            }
        }
    }
    return matrix[len1][len2];
}