//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to calculate the minimum of three numbers
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

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist[MAX_LEN + 1][MAX_LEN + 1];

    // Initializing the distance matrix
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            }
            else if (j == 0) {
                dist[i][j] = i;
            }
            else if (str1[i-1] == str2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            }
            else {
                dist[i][j] = 1 + min(dist[i][j-1], dist[i-1][j], dist[i-1][j-1]);
            }
        }
    }

    // Returning the Levenshtein Distance
    return dist[len1][len2];
}

// Main function to test the implementation
int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    // Getting input from the user
    printf("Enter String 1: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter String 2: ");
    fgets(str2, MAX_LEN, stdin);

    // Removing new line character from input
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Displaying the Levenshtein Distance between the strings
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, levenshteinDistance(str1, str2));
    
    return 0;
}