//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    return min_val;
}

int levenshteinDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int distance[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            }
            else if (j == 0) {
                distance[i][j] = i;
            }
            else if (word1[i - 1] == word2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else {
                distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
            }
        }
    }

    return distance[len1][len2];
}

int main() {
    char word1[100], word2[100];
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);
    printf("Levenshtein Distance: %d\n", levenshteinDistance(word1, word2));
    return 0;
}