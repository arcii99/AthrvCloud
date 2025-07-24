//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int x = a < b ? a : b;
    return x < c ? x : c;
}

int edit_distance(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int DP[n1 + 1][n2 + 1];

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0) {
                DP[i][j] = j;
            } else if (j == 0) {
                DP[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1];
            } else {
                DP[i][j] = 1 + min(DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]);
            }
        }
    }

    return DP[n1][n2];
}

int main() {
    char str1[] = "Levenshtein";
    char str2[] = "Distance";
    int result = edit_distance(str1, str2);

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, result);
    return 0;
}