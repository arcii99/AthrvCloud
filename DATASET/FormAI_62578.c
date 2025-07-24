//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                dist[i][j] = i + j;
            } else {
                dist[i][j] = min(
                    dist[i - 1][j] + 1,
                    dist[i][j - 1] + 1,
                    dist[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)
                );
            }
        }
    }

    return dist[len1][len2];
}

int main() {
    char str1[MAXLEN], str2[MAXLEN];

    printf("Enter first string: ");
    fgets(str1, MAXLEN, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter second string: ");
    fgets(str2, MAXLEN, stdin);
    str2[strcspn(str2, "\n")] = 0;

    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, levenshtein_distance(str1, str2));

    return 0;
}