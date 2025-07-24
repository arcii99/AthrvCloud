//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    else if (y <= x && y <= z) return y;
    else return z;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1+1][len2+1];
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) matrix[i][j] = j;
            else if (j == 0) matrix[i][j] = i;
            else {
                cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
                matrix[i][j] = min(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}