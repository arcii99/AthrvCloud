//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int lev_distance(char *s1, char *s2, int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else {
                int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
            }
        }
    }
    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance = lev_distance(str1, str2, len1, len2);
    printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}