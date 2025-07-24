//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Calculate the minimum of three integers */
#define MIN(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))

int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int i, j, cost, *d, distance;

    /* Allocate memory for the distance matrix */
    d = (int *) malloc((len1 + 1) * (len2 + 1) * sizeof(int));
    if (d == NULL) {
        printf("Out of memory!\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the first row and column */
    for (i = 0; i <= len1; i++)
        d[i * (len2 + 1)] = i;
    for (j = 0; j <= len2; j++)
        d[j] = j;

    /* Calculate the Levenshtein distance */
    for (j = 1; j <= len2; j++) {
        for (i = 1; i <= len1; i++) {
            cost = (s1[i - 1] == s2[j - 1] ? 0 : 1);
            d[i * (len2 + 1) + j] = MIN(d[(i - 1) * (len2 + 1) + j] + 1,
                                         d[i * (len2 + 1) + j - 1] + 1,
                                         d[(i - 1) * (len2 + 1) + j - 1] + cost);
        }
    }

    /* The Levenshtein distance is the value in the bottom right corner of the matrix */
    distance = d[len1 * (len2 + 1) + len2];

    /* Free the memory allocated for the distance matrix */
    free(d);

    return distance;
}

int main()
{
    char *s1 = "kitten";
    char *s2 = "sitting";
    int distance;

    distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between %s and %s is %d.\n", s1, s2, distance);

    return 0;
}