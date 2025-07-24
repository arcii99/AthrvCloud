//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compress(char *s) {
    int n = strlen(s);

    if (n == 0) return;

    int i, j, k;
    char **t = (char **) malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) t[i] = (char *) malloc((n + 1) * sizeof(char));
    int **d = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) d[i] = (int *) malloc(n * sizeof(int));
    int **p = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) p[i] = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        t[i][0] = s[i];
        for (j = 1; j < n; j++) t[i][j] = '\0';
    }

    for (i = 0; i < n; i++) d[i][i] = 1;

    for (k = 2; k <= n; k++) {
        for (i = 0; i <= n - k; i++) {
            j = i + k - 1;
            if (s[i] == s[j] && k == 2) {
                d[i][j] = 2;
                p[i][j] = i;
            }
            else if (s[i] == s[j]) {
                d[i][j] = d[i+1][j-1] + 2;
                p[i][j] = i+1;
            }
            else {
                if (d[i+1][j] > d[i][j-1]) {
                    d[i][j] = d[i+1][j];
                    p[i][j] = i+1;
                }
                else {
                    d[i][j] = d[i][j-1];
                    p[i][j] = i;
                }
            }
        }
    }

    i = 0;
    j = n - 1;

    char *res = (char *) malloc(n * sizeof(char));
    int idx = 0;

    while (i <= j) {
        if (s[i] == s[j] && p[i][j] == i) {
            strncat(res, &s[i], 1);
            i++;
            j--;
        }
        else if (p[i][j] == i+1) i++;
        else j--;
    }

    printf("Compressed string: %s\n", res);

    for (i = 0; i < n; i++) free(t[i]);
    free(t);
    for (i = 0; i < n; i++) free(d[i]);
    free(d);
    for (i = 0; i < n; i++) free(p[i]);
    free(p);
    free(res);
}

int main() {
    char s[] = "Mississippi";
    printf("Original string: %s\n", s);
    compress(s);
    return 0;
}