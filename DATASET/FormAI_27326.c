//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// Returns the minimum of three values
int min(int x, int y, int z) { 
    return x < y ? (x < z ? x : z) : (y < z ? y : z); 
}

// Calculates and returns the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance[len1 + 1][len2 + 1]; // distance array
    int i, j;

    // initialize first row and column
    for (i = 0; i <= len1; i++)
        distance[i][0] = i;
    for (j = 0; j <= len2; j++)
        distance[0][j] = j;

    // calculate the distance array
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                distance[i][j] = distance[i - 1][j - 1];
            else
                distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
        }
    }

    // return the Levenshtein distance
    return distance[len1][len2];
}

int main() {
    char str1[] = "C programming";
    char str2[] = "Java programming";
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}