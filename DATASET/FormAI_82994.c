//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

int calculate_levenshtein_distance(char *s, char *t, int len_s, int len_t) {
    int matrix[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= len_s; i++) {
        for (int j = 0; j <= len_t; j++) {
            if (i == 0) matrix[i][j] = j;
            else if (j == 0) matrix[i][j] = i;
            else if (s[i-1] == t[j-1]) matrix[i][j] = matrix[i-1][j-1];
            else matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
        }
    }

    return matrix[len_s][len_t];
}

int main() {
    char s[MAX_LEN];
    char t[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    int len_s = strlen(s);
    int len_t = strlen(t);

    int distance = calculate_levenshtein_distance(s, t, len_s, len_t);

    printf("Levenshtein Distance = %d\n", distance);

    return 0;
}