//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int levenshtein_distance(char *s1, char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    int matrix[len_s1 + 1][len_s2 + 1];

    for (int i = 0; i <= len_s1; i++) {
        matrix[i][0] = i;
    }

    for (int i = 0; i <= len_s2; i++) {
        matrix[0][i] = i;
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (tolower(s1[i - 1]) != tolower(s2[j - 1]));
            matrix[i][j] = min(matrix[i - 1][j] + 1,
                               matrix[i][j - 1] + 1,
                               matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len_s1][len_s2];
}

int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter two strings to calculate their Levenshtein Distance.\n");

    char s1[100];
    char s2[100];

    printf("String 1: ");
    fgets(s1, 100, stdin);
    printf("String 2: ");
    fgets(s2, 100, stdin);

    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);

    return 0;
}