//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int x, int y, int z) {
    if (x < y && x < z)
        return x;
    if (y < x && y < z)
        return y;
    return z;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
    int length_s1 = strlen(s1);
    int length_s2 = strlen(s2);
    int matrix[length_s1 + 1][length_s2 + 1];

    // Initialize the first column and row of the matrix
    for (int i = 0; i <= length_s1; i++)
        matrix[i][0] = i;
    for (int j = 0; j <= length_s2; j++)
        matrix[0][j] = j;

    // Calculate the Levenshtein distance
    for (int i = 1; i <= length_s1; i++) {
        for (int j = 1; j <= length_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,
                                matrix[i][j - 1] + 1,
                                matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the result
    return matrix[length_s1][length_s2];
}

int main() {
    char *s1 = "mathematics";
    char *s2 = "ephemeral";
    int result = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, result);
    return 0;
}