//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: active
#include <stdio.h>
#include <string.h>

// Define the maximum length of the strings to compare
#define MAX_LENGTH 100

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char *string1, char *string2) {
    int string1Length = strlen(string1);
    int string2Length = strlen(string2);
    int matrix[MAX_LENGTH + 1][MAX_LENGTH + 1];

    // Initialize the matrix with the initial values
    for (int i = 0; i <= string1Length; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= string2Length; j++) {
        matrix[0][j] = j;
    }

    // Calculate the minimum distance using the dynamic programming approach
    for (int j = 1; j <= string2Length; j++) {
        for (int i = 1; i <= string1Length; i++) {
            int substitutionCost = 0;
            if (string1[i - 1] != string2[j - 1]) {
                substitutionCost = 1;
            }
            matrix[i][j] = min(matrix[i - 1][j] + 1, 
                               matrix[i][j - 1] + 1, 
                               matrix[i - 1][j - 1] + substitutionCost);
        }
    }

    // Returns the distance
    return matrix[string1Length][string2Length];
}

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    // Read the two strings from the user
    char string1[MAX_LENGTH], string2[MAX_LENGTH];
    printf("Enter the first string: ");
    fgets(string1, MAX_LENGTH, stdin);
    printf("Enter the second string: ");
    fgets(string2, MAX_LENGTH, stdin);

    // Remove the new line character from the input strings
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;

    // Calculate and print the Levenshtein Distance
    int distance = levenshteinDistance(string1, string2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", string1, string2, distance);

    return 0;
}