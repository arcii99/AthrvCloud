//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX(a,b) (((a)>(b))?(a):(b))

int calculateLevenshteinDistance(char *string1, char *string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    int distance[length1 + 1][length2 + 1];

    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else {
                distance[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (string1[i - 1] == string2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                int deletion = distance[i - 1][j] + 1;
                int insertion = distance[i][j - 1] + 1;
                int substitution = distance[i - 1][j - 1] + 1;
                distance[i][j] = MAX(MAX(deletion, insertion), substitution);
            }
        }
    }

    return distance[length1][length2];
}

int main() {
    char input1[MAX_INPUT_LENGTH];
    char input2[MAX_INPUT_LENGTH];

    printf("Enter string 1: ");
    fgets(input1, MAX_INPUT_LENGTH, stdin);
    input1[strcspn(input1, "\n")] = 0;

    printf("Enter string 2: ");
    fgets(input2, MAX_INPUT_LENGTH, stdin);
    input2[strcspn(input2, "\n")] = 0;

    int levenshteinDistance = calculateLevenshteinDistance(input1, input2);
    printf("Levenshtein distance between %s and %s is %d\n", input1, input2, levenshteinDistance);

    return 0;
}