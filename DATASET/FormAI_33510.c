//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    return ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c));
}

int levenshteinDistance(char* s, int lenS, char* t, int lenT) {
    int distance[lenS + 1][lenT + 1];
    memset(distance, 0, sizeof(distance));

    for (int i = 0; i <= lenS; i++) {
        for (int j = 0; j <= lenT; j++) {
            if (i == 0) {
                distance[i][j] = j;
            }
            else if (j == 0) {
                distance[i][j] = i;
            }
            else if (s[i - 1] == t[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else {
                distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
            }
        }
    }

    return distance[lenS][lenT];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("Levenshtein Distance: %d\n", levenshteinDistance(str1, len1, str2, len2));

    return 0;
}