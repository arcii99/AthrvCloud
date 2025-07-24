//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char *str1, int len1, char *str2, int len2) {
    int distance[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(distance[i - 1][j - 1], distance[i][j - 1], distance[i - 1][j]);
            }
        }
    }

    return distance[len1][len2];
}

int main() {
    char str1[] = "Hello";
    char str2[] = "Halo";
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Levenshtein Distance: %d\n", levenshteinDistance(str1, len1, str2, len2));

    return 0;
}