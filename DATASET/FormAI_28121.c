//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int levenshtein_distance(char* string1, char* string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int i, j, cost;
    int** matrix = (int**)malloc((length1 + 1) * sizeof(int*));
    for (i = 0; i <= length1; i++) {
        matrix[i] = (int*)malloc((length2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }
    for (i = 1; i <= length1; i++) {
        for (j = 1; j <= length2; j++) {
            cost = (tolower(string1[i - 1]) != tolower(string2[j - 1]));
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1,
                                      matrix[i][j - 1] + 1),
                                matrix[i - 1][j - 1] + cost);
        }
    }
    int distance = matrix[length1][length2];
    for (i = 0; i <= length1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char* string1 = "Cyberpunk";
    char* string2 = "Levenshtein";
    int distance = levenshtein_distance(string1, string2);
    printf("The Levenshtein distance between '%s' and '%s' is %d!\n", string1, string2, distance);
    return 0;
}