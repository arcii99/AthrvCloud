//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate minimum of three integers
int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;
    return smallest;
}

// Calculate Levenshtein Distance between two strings
int levenshtein_distance(char * s1, char * s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];

    // Fill the first row and column with corresponding index
    for (int i = 0; i <= len1; i++)
        matrix[i][0] = i;
    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j;

    // Fill in the rest of the matrix
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            matrix[i][j] = min( matrix[i - 1][j] + 1, // deletion
                                matrix[i][j - 1] + 1, // insertion
                                matrix[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]) ); // substitution

    // Return the distance
    return matrix[len1][len2];
}

int main() {
    char word1[100];
    char word2[100];

    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    int distance = levenshtein_distance(word1, word2);
    printf("The Levenshtein Distance between %s and %s is %d.\n", word1, word2, distance);

    return 0;
}