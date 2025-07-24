//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) 
{
    int result = a;
    if (b < result) {
        result = b;
    }
    if (c < result) {
        result = c;
    }
    return result;
}

int levenshtein_distance(char *s, char *t)
{
    int n = strlen(s), m = strlen(t);
    int distance[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        distance[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = 0;
            if (s[i - 1] != t[j - 1]) {
                cost = 1;
            }
            distance[i][j] = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + cost);
        }
    }
    return distance[n][m];
}

int main()
{
    char s[100], t[100]; // Assumes max length of both strings is 99.
    printf("Enter two strings separated by a space: ");
    scanf("%s %s", s, t);
    printf("\nThe Levenshtein Distance between '%s' and '%s' is %d.\n", s, t, levenshtein_distance(s, t));
    return 0;
}