//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c) return a;
    else if (b < a && b < c) return b;
    else return c;
}

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int d[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            int substitution_cost = s1[i-1] == s2[j-1] ? 0 : 1;
            int deletion_cost = d[i-1][j] + 1;
            int insertion_cost = d[i][j-1] + 1;
            int substitution_insertion_cost = d[i-1][j-1] + substitution_cost;
            d[i][j] = minimum(deletion_cost, insertion_cost, substitution_insertion_cost);
        }
    }

    return d[len1][len2];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between %s and %s is %d", s1, s2, distance);
    return 0;
}