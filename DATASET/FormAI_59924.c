//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

// Calculates Levenshtein Distance
int levenshteinDistance(char *s1, char *s2);

// Main function
int main()
{
    char s1[MAX_LEN], s2[MAX_LEN];

    // Prompt user to input strings
    printf("Enter first string: ");
    fgets(s1, MAX_LEN, stdin);
    printf("Enter second string: ");
    fgets(s2, MAX_LEN, stdin);

    int distance = levenshteinDistance(s1, s2);

    // Present the Levenshtein Distance and challenge the user
    printf("The Levenshtein Distance between %s and %s is %d. Can you beat this score?\n", s1, s2, distance);

    return 0;
}

// Calculates Levenshtein Distance using dynamic programming
int levenshteinDistance(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int distance[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else {
                distance[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                int deletion = distance[i - 1][j] + 1;
                int insertion = distance[i][j - 1] + 1;
                int substitution = distance[i - 1][j - 1] + 1;
                distance[i][j] = (deletion < insertion) ? deletion : insertion;
                distance[i][j] = (substitution < distance[i][j]) ? substitution : distance[i][j];
            }
        }
    }

    return distance[m][n];
}