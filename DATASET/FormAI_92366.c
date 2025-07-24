//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char *s, int len_s, char *t, int len_t) {
    int i, j, cost, **d;
  
    d = (int **)malloc((len_s + 1) * sizeof(int *));
    for (i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }
  
    for (i = 0; i <= len_s; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= len_t; j++) {
        d[0][j] = j;
    }
  
    for (j = 1; j <= len_t; j++) {
        for (i = 1; i <= len_s; i++) {
            if (s[i-1] == t[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);
        }
    }
    int distance = d[len_s][len_t];
    for (i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);
    return distance;
}

int main() {
    char a[20], b[20];
    printf("Enter the first string: ");
    scanf("%s", a);
    printf("Enter the second string: ");
    scanf("%s", b);
    int distance = levenshtein_distance(a, strlen(a), b, strlen(b));
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", a, b, distance);
    return 0;
}