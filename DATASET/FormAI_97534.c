//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int levenshtein_distance(char *s, char *t) {
    int rows = strlen(s) + 1;
    int cols = strlen(t) + 1;
    int distance_matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0) {
                distance_matrix[i][j] = j;
            } else if (j == 0) {
                distance_matrix[i][j] = i;
            } else {
                int cost = s[i - 1] == t[j - 1] ? 0 : 1;
                distance_matrix[i][j] = min(
                    distance_matrix[i - 1][j] + 1, // Deletion
                    distance_matrix[i][j - 1] + 1, // Insertion
                    distance_matrix[i - 1][j - 1] + cost // Substitution
                );
            }
        }
    }

    return distance_matrix[rows - 1][cols - 1];
}

int main() {
    char *s = "levenshtein";
    char *t = "mechanism";

    int distance = levenshtein_distance(s, t);

    printf("The Levenshtein distance between %s and %s is %d", s, t, distance);

    return 0;
}