//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    int min = (a < b) ? a : b;
    return (min < c) ? min : c;
}

int distance(char * s1, char * s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dpTable[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dpTable[i][j] = j;
            } else if (j == 0) {
                dpTable[i][j] = i;
            } else {
                int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                dpTable[i][j] = min(dpTable[i - 1][j] + 1,
                                     dpTable[i][j - 1] + 1,
                                     dpTable[i - 1][j - 1] + cost);
            }
        }
    }
    return dpTable[len1][len2];
}

int main(int argc, char ** argv) {
    char * s1;
    char * s2;
    if (argc == 3) {
        s1 = argv[1];
        s2 = argv[2];
    } else {
        printf("Usage: %s string1 string2\n", argv[0]);
        return 0;
    }
    int result = distance(s1, s2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, result);
    return 0;
}