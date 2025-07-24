//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int calculateLevenshteinDistance(char *string1, char *string2, int length1, int length2) {
    int distance[length1 + 1][length2 + 1];

    for(int i = 0; i <= length1; i++) distance[i][0] = i;
    for(int j = 0; j <= length2; j++) distance[0][j] = j;

    for(int i = 1; i <= length1; i++) {
        for(int j = 1; j <= length2; j++) {
            if (string1[i - 1] == string2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
            }
        }
    }

    return distance[length1][length2];
}

int main() {
    char *string1 = "future";
    char *string2 = "proof";

    int length1 = strlen(string1);
    int length2 = strlen(string2);

    int levenshteinDistance = calculateLevenshteinDistance(string1, string2, length1, length2);

    printf("The Levenshtein Distance between %s and %s is %d\n", string1, string2, levenshteinDistance);

    return 0;
}