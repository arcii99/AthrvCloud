//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if(b < min) {
        min = b;
    }
    if(c < min) {
        min = c;
    }
    return min;
}

int calculateLevenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int levDist[len1 + 1][len2 + 1];

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                levDist[i][j] = j;
            }
            else if(j == 0) {
                levDist[i][j] = i;
            }
            else if(str1[i - 1] == str2[j - 1]) {
                levDist[i][j] = levDist[i - 1][j - 1];
            }
            else {
                levDist[i][j] = 1 + min(levDist[i][j - 1], levDist[i - 1][j], levDist[i - 1][j - 1]);
            }
        }
    }

    return levDist[len1][len2];
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";

    printf("Levenshtein distance between %s and %s is %d", str1, str2, calculateLevenshteinDistance(str1, str2));
    return 0;
}