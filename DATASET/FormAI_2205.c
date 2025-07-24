//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: brave
#include <stdio.h>
#include <string.h>

// Helper function to find minimum of three integers
int min(int a, int b, int c) {
    int m = a;
    if (m > b) {
        m = b;
    }
    if (m > c) {
        m = c;
    }
    return m;
}

// Function to calculate Levenshtein Distance between two strings
int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist[len1+1][len2+1];

    // Initialize first row and first column
    for (int i = 0; i <= len1; ++i) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
        dist[0][j] = j;
    }

    // Loop through all characters and calculate the distance
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i-1] == str2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1;
            }
        }
    }

    return dist[len1][len2];
}

int main() {

    // Get input from user
    char str1[100], str2[100];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    // Calculate Levenshtein Distance
    int distance = levenshteinDistance(str1, str2);

    // Print the result
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}