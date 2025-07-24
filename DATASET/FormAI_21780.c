//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int distance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int mat[len1+1][len2+1];
    for (int i=0; i<=len1; i++)
        mat[i][0] = i;
    for (int j=0; j<=len2; j++)
        mat[0][j] = j;
    for (int i=1; i<=len1; i++) {
        for (int j=1; j<=len2; j++) {
            int del = mat[i-1][j] + 1;
            int ins = mat[i][j-1] + 1;
            int sub = mat[i-1][j-1] + (s1[i-1] != s2[j-1]);
            mat[i][j] = (del < ins ? del : ins) < sub ? (del < ins ? del : ins) : sub;
        }
    }
    return mat[len1][len2];
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    printf("Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, distance(s1, s2));
    s1 = "saturday";
    s2 = "sunday";
    printf("Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, distance(s1, s2));
    return 0;
}