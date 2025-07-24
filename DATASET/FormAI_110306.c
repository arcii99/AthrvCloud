//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshteinDistance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int mat[m+1][n+1];

    for (int i = 1; i <= m; i++) {
        mat[i][0] = i;
    }

    for (int j = 1; j <= n; j++) {
        mat[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s[i-1] == t[j-1]) {
                mat[i][j] = mat[i-1][j-1];
            } else {
                mat[i][j] = min(mat[i-1][j], mat[i][j-1], mat[i-1][j-1]) + 1;
            }
        }
    }

    return mat[m][n];
}

int main() {
    char s[] = "levenshtein";
    char t[] = "distance";
    int distance = levenshteinDistance(s, t);
    printf("Levenshtein distance between %s and %s is %d.\n", s, t, distance);
    return 0;
}