//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b && a < c ? a : b < c ? b : c;
}

int levenshtein_distance(char* s1, char* s2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (s1[m - 1] == s2[n - 1])
        return levenshtein_distance(s1, s2, m - 1, n - 1);
    return 1 + min(levenshtein_distance(s1, s2, m, n - 1),
                   levenshtein_distance(s1, s2, m - 1, n),
                   levenshtein_distance(s1, s2, m - 1, n - 1));
}

int main() {
    char s1[100], s2[100];
    int len1, len2, distance;

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    distance = levenshtein_distance(s1, s2, len1, len2);
    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}