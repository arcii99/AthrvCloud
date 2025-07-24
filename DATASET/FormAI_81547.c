//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int i, j, cost;
    int mat[len1+1][len2+1];

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                mat[i][j] = j;
            }
            else if (j == 0) {
                mat[i][j] = i;
            }
            else {
                cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
                mat[i][j] = minimum(mat[i-1][j] + 1,
                                     mat[i][j-1] + 1,
                                     mat[i-1][j-1] + cost);
            }
        }
    }

    return mat[len1][len2];
}

int minimum(int a, int b, int c) {
    int min = a;

    if (b < min) {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    return min;
}

int main(void) {
    char str1[] = "Hello, how are you doing?";
    char str2[] = "Hey, how are you?";
    int distance = levenshtein(str1, str2);

    printf("The Levenshtein distance between\n");
    printf("%s\n", str1);
    printf("and\n");
    printf("%s\n", str2);
    printf("is:\n");
    printf("%d\n", distance);

    return 0;
}