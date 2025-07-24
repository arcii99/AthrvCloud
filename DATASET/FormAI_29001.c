//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

// function to calculate Levenshtein distance
int calculateLevenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // create 2D matrix to store distance values
    int distanceMatrix[MAX_LEN + 1][MAX_LEN + 1];

    // initialize first row and column with incremental values
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        distanceMatrix[0][j] = j;
    }

    // calculate minimum distance using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // if characters match, get value from diagonal
            if (str1[i - 1] == str2[j - 1]) {
                distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1];
            } else {
                // otherwise, get minimum value from adjacent cells and add 1
                int minValue = distanceMatrix[i - 1][j];
                if (distanceMatrix[i][j - 1] < minValue) {
                    minValue = distanceMatrix[i][j - 1];
                }
                if (distanceMatrix[i - 1][j - 1] < minValue) {
                    minValue = distanceMatrix[i - 1][j - 1];
                }
                distanceMatrix[i][j] = minValue + 1;
            }
        }
    }

    // return minimum distance value
    return distanceMatrix[len1][len2];
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = calculateLevenshteinDistance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);

    return 0;
}