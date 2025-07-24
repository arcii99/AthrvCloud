//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int** dist = malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
        dist[i][0] = i;
    }
    for (int j = 1; j <= len2; j++) {
        dist[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1] + cost);
        }
    }
    int result = dist[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);
    return result;
}

int main() {
    char* str1 = "kitten";
    char* str2 = "sitting";
    int dist = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, dist);
    return 0;
}