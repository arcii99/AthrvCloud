//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y, z) (x < y ? (x < z ? x : z) : (y < z ? y : z))

int calculateLevenshteinDistance(char *string1, char *string2);

int main() {
    char string1[100], string2[100];
    printf("Enter first string: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter second string: ");
    fgets(string2, sizeof(string2), stdin);

    string1[strcspn(string1, "\n")] = 0; // remove newline character
    string2[strcspn(string2, "\n")] = 0; // remove newline character

    int distance = calculateLevenshteinDistance(string1, string2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", string1, string2, distance);

    return 0;
}

int calculateLevenshteinDistance(char *string1, char *string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    int matrix[length1+1][length2+1];

    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (string1[i-1] == string2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + MIN(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }

    return matrix[length1][length2];
}