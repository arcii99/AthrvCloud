//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int min(int a, int b, int c) {
    /* Returns the minimum value among three integers */
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *str1, char *str2) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dist[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = 1 + min(dist[i][j - 1], dist[i - 1][j], dist[i - 1][j - 1]);
            }
        }
    }
    return dist[len1][len2];
}

int main() {
    char str1[MAX_LEN];
    printf("Enter string 1: ");
    gets(str1);

    char str2[MAX_LEN];
    printf("Enter string 2: ");
    gets(str2);

    printf("Levenshtein Distance: %d", levenshtein_distance(str1, str2));

    return 0;
}