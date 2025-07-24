//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */
int minimum(int a, int b, int c);
int levenshtein_distance(char *s1, char *s2);

/* main function */
int main(void) {
    char *str1 = "levenshtein";
    char *str2 = "frankenstein";
    int dist;

    printf("Calculating Levenshtein Distance...\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    dist = levenshtein_distance(str1, str2);

    printf("The Levenshtein Distance between the two strings is: %d\n", dist);

    return 0;
}

/* function to find the minimum of three integers */
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

/* implementation of levenshtein distance algorithm */
int levenshtein_distance(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    /* create a 2D array for distance matrix */
    int dist[s1_len + 1][s2_len + 1];

    /* initialization of distance matrix */
    for (int i = 0; i <= s1_len; i++) {
        for (int j = 0; j <= s2_len; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else {
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = minimum(dist[i - 1][j] + 1, /* deletion */
                                      dist[i][j - 1] + 1, /* insertion */
                                      dist[i - 1][j - 1] + 1 /* substitution */
                                     );
            }
        }
    }

    return dist[s1_len][s2_len];
}