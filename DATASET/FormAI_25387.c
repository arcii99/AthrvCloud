//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to calculate Levenshtein Distance between two strings
int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1 + 1][len2 + 1];

    // Fill matrix with values
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0)
                matrix[i][j] = j;
            else if(j == 0)
                matrix[i][j] = i;
            else if(tolower(str1[i - 1]) == tolower(str2[j - 1]))
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = 1 + (matrix[i - 1][j] < matrix[i][j - 1] ? matrix[i - 1][j] : matrix[i][j - 1]);
        }
    }

    // Display matrix
    printf("-------CYP3R L3V3NSHTE1N D1STANC3 CALCULATOR-------\n");
    printf("Initialized Matrix: \n");
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return matrix[len1][len2];
}

int main() {
    // Inputs
    char str1[50], str2[50];

    printf("Enter first string: ");
    fgets(str1, 50, stdin);
    printf("Enter second string: ");
    fgets(str2, 50, stdin);

    // Remove newline character from input
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int dist = levenshteinDistance(str1, str2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, dist);

    return 0;
}