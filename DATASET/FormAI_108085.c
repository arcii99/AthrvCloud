//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int distances[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        distances[i][0] = i;

    for (int j = 0; j <= len2; j++)
        distances[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            distances[i][j] = min(distances[i - 1][j] + 1, 
                                   distances[i][j - 1] + 1,
                                   distances[i - 1][j - 1] + cost);
        }
    }

    return distances[len1][len2];
}

int main() {
    const char *s1 = "kitten";
    const char *s2 = "sitting";
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}