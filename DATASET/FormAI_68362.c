//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein(const char *a, const char *b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int *matrix = (int*) malloc((alen+1) * (blen+1) * sizeof(int));
    int i, j, k, p, q, t;
    if(matrix == NULL) {
        printf("Error: Out of memory.\n");
        return -1;
    }

    for(i = 0; i <= alen; i++) {
        for(j = 0; j <= blen; j++) {
            if(i == 0) {
                matrix[j] = j;
            } else if(j == 0) {
                matrix[i*(blen+1)] = i;
            } else {
                p = matrix[(i-1)*(blen+1) + j] + 1;
                q = matrix[i*(blen+1) + j-1] + 1;
                t = matrix[(i-1)*(blen+1) + j-1];
                if(a[i-1] != b[j-1]) {
                    t++;
                }
                matrix[i*(blen+1) + j] = min(p, q, t);
            }
        }
    }

    int result = matrix[alen*(blen+1) + blen];

    free(matrix);

    return result;
}

int main() {
    const char *str1 = "hello";
    const char *str2 = "world";

    int distance = levenshtein(str1, str2);

    printf("The Levenshtein distance between %s and %s is %d.\n", str1, str2, distance);

    return 0;
}