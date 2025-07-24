//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
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

int calculateLevenshteinDistance(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    int matrix[s_len + 1][t_len + 1];
    for (int i = 0; i <= s_len; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= t_len; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= t_len; j++) {
            int cost;
            if (s[i-1] == t[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            int insert = matrix[i][j-1] + 1;
            int delete = matrix[i-1][j] + 1;
            int substitute = matrix[i-1][j-1] + cost;
            matrix[i][j] = min(insert, delete, substitute);
        }
    }

    return matrix[s_len][t_len];
}

int main() {
    char s[] = "grateful";
    char t[] = "code";

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", s, t, calculateLevenshteinDistance(s, t));

    return 0;
}