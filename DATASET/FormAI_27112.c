//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int d[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                d[i][j] = i + j;
            } else if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
            }
        }
    }

    return d[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}