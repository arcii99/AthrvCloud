//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    else if (y <= x && y <= z) return y;
    return z;
}

int levenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int distance[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) distance[i][j] = j;
            else if (j == 0) distance[i][j] = i;
            else if (str1[i - 1] == str2[j - 1]) distance[i][j] = distance[i - 1][j - 1];
            else distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
        }
    }

    return distance[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    printf("Levenshtein Distance: %d\n", levenshteinDistance(str1, str2));
    return 0;
}