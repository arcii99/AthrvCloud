//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshteinDist(char str1[], char str2[], int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    return matrix[len1][len2];
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist = levenshteinDist(str1, str2, len1, len2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", str1, str2, dist);

    char str3[] = "abcdefg";
    char str4[] = "abcgfeabcd";
    len1 = strlen(str3);
    len2 = strlen(str4);
    dist = levenshteinDist(str3, str4, len1, len2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", str3, str4, dist);

    return 0;
}