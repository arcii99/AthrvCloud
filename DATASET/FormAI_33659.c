//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int min(int a, int b, int c) {
    int m = a;
    if (m > b) { m = b;}
    if (m > c) { m = c;}
    return m;
}

int levenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int d[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (str1[i-1] == str2[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                d[i][j] = min(d[i-1][j], d[i][j-1], d[i-1][j-1]) + 1;
            }
        }
    }

    return d[m][n];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0;

    int distance = levenshteinDistance(str1, str2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}