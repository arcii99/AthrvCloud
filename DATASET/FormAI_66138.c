//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // maximum length of strings

/* Levenshtein Distance Calculator */
int levenshtein_distance(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int distance[n + 1][m + 1];

    // initializing the distance array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else {
                distance[i][j] = 0;
            }
        }
    }

    // calculating the distance
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            distance[i][j] = fmin(
                    fmin(distance[i - 1][j] + 1, distance[i][j - 1] + 1),
                    distance[i - 1][j - 1] + cost
                );
        }
    }

    return distance[n][m];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // removing newline character

    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // removing newline character

    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, levenshtein_distance(str1, str2));

    return 0;
}