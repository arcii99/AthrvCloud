//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b ? a : b) < c ? (a < b ? a : b) : c;
}

int levenshtein_distance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1), len2 = strlen(s2);
    int *row = calloc(len2 + 1, sizeof(int));
    int prev, tmp;

    for (size_t i = 1; i <= len2; i++) row[i] = i;
    for (size_t i = 1; i <= len1; i++) {
        prev = i;
        for (size_t j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1])
                tmp = row[j - 1];
            else
                tmp = min(row[j - 1], prev, row[j]) + 1;
            row[j - 1] = prev;
            prev = tmp;
        }
        row[len2] = prev;
    }
    int res = row[len2];
    free(row);
    return res;
}

int main() {
    char s1[] = "energetic";
    char s2[] = "creative";

    int res = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between %s and %s is: %d\n", s1, s2, res);

    return 0;
}