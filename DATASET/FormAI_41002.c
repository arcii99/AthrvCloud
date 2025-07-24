//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        }
        else {
            return c;
        }
    }
    else {
        if (b < c) {
            return b;
        }
        else {
            return c;
        }
    }
}

int levenshteinDistance(char *s1, char *s2, int len1, int len2) {
    int distance[len1 + 1][len2 + 1];
    int i, j;

    for (i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int cost = 0;
            if (s1[i - 1] != s2[j - 1]) {
                cost = 1;
            }
            distance[i][j] = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + cost);
        }
    }

    return distance[len1][len2];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter first string: ");
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\r\n")] = 0;

    printf("Enter second string: ");
    fgets(s2, MAX_LEN, stdin);
    s2[strcspn(s2, "\r\n")] = 0;

    printf("Levenshtein Distance between %s and %s is %d", s1, s2, levenshteinDistance(s1, s2, strlen(s1), strlen(s2)));

    return 0;
}