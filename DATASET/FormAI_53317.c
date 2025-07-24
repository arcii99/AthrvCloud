//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate Minimum of three values
int minimum(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    return min_val;
}

// Calculate the Levenshtein Distance between two strings
int levenshteinDistance(char *s1, char *s2) {
    // Get the Length of the input strings
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);

    // Initialize a 2D array to store the distance values
    int distanceMatrix[s1_length+1][s2_length+1];

    // Initialize first row
    for(int i=0; i<=s2_length; i++) {
        distanceMatrix[0][i] = i;
    }

    // Initialize first column
    for(int j=0; j<=s1_length; j++) {
        distanceMatrix[j][0] = j;
    }

    // Calculate the Levenshtein Distance for each cell
    for(int i=1; i<=s1_length; i++) {
        for(int j=1; j<=s2_length; j++) {
            int substitutionCost = 0;
            if(s1[i-1] != s2[j-1]) {
                substitutionCost = 1;
            }
            distanceMatrix[i][j] = minimum(distanceMatrix[i-1][j] + 1, distanceMatrix[i][j-1] + 1, distanceMatrix[i-1][j-1] + substitutionCost);
        }
    }

    // Return the final distance value
    return distanceMatrix[s1_length][s2_length];
}

// Main function
int main() {
    // Test the Levenshtein Distance Calculator with some sample strings
    char *s1 = "levenshtein";
    char *s2 = "meilenstein";
    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein Distance between %s and %s is: %d\n", s1, s2, distance);

    s1 = "kitten";
    s2 = "sitting";
    distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein Distance between %s and %s is: %d\n", s1, s2, distance);

    return 0;
}