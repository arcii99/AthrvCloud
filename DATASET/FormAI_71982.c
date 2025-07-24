//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshteinDistance(char *str1, char *str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int matrix[n + 1][m + 1];
    for (int i = 0; i <= n; i++) matrix[i][0] = i;
    for (int j = 0; j <= m; j++) matrix[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = str1[i - 1] == str2[j - 1] ? 0 : 1;
            matrix[i][j] = minimum(matrix[i - 1][j] + 1,
                                    matrix[i][j - 1] + 1,
                                    matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[n][m];
}

int main() {
    char str1[] = "hello world";
    char str2[] = "helo werld";
    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}