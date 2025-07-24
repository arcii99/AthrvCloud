//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the minimum of three integers
int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

// Calculates the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist[len1 + 1][len2 + 1];

    // Initialize the first row and column of the distance matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Calculate the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = min(dist[i-1][j] + 1,          // Deletion
                                dist[i][j-1] + 1,            // Insertion
                                dist[i-1][j-1] + 1);         // Substitution
            }
        }
    }

    // Return the distance between the two strings
    return dist[len1][len2];
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("The Levenshtein distance between %s and %s is %d\n", str1, str2, levenshtein_distance(str1, str2));
    return 0;
}