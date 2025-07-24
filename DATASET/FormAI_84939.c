//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *s1, char *s2)
{
    // Calculate the lenghts of the two strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D array to store the distances
    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and first column of the array
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the distance and store it in the array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                int min = matrix[i-1][j];
                if (matrix[i][j-1] < min) {
                    min = matrix[i][j-1];
                }
                if (matrix[i-1][j-1] < min) {
                    min = matrix[i-1][j-1];
                }
                matrix[i][j] = min + 1;
            }
        }
    }

    // Return the final distance
    return matrix[len1][len2];
}

int main()
{
    char s1[] = "kitten";
    char s2[] = "sitting";

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}