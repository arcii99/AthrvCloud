//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three values
int minimum(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(char* str1, char* str2, int m, int n) {
    // Create a 2D array to store the distance between each character
    int distance[m + 1][n + 1];

    // Fill in the base case values
    for (int i = 0; i <= m; i++)
        distance[i][0] = i;
    for (int j = 0; j <= n; j++)
        distance[0][j] = j;

    // Calculate the distance between each pair of characters
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                distance[i][j] = distance[i - 1][j - 1];
            else
                distance[i][j] = 1 + minimum(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
        }
    }

    // Return the final distance value
    return distance[m][n];
}

// Driver function to test the Levenshtein Distance Calculator
int main() {
    char* str1 = "Hello, world!";
    char* str2 = "Helo, world!";
    int m = strlen(str1);
    int n = strlen(str2);

    int distance = levenshtein_distance(str1, str2, m, n);

    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}