//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshteinDistance(char word1[], char word2[]) {

    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
  
    int distance[word1Length + 1][word2Length + 1];

    for (int i = 0; i <= word1Length; i++) {
        for (int j = 0; j <= word2Length; j++) {
            distance[i][j] = 0;
        }
    }

    for (int i = 0; i <= word1Length; i++) {
        distance[i][0] = i;
    }

    for (int j = 0; j <= word2Length; j++) {
        distance[0][j] = j;
    }

    int cost;

    for (int i = 1; i <= word1Length; i++) {
        for (int j = 1; j <= word2Length; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            distance[i][j] = minimum(distance[i - 1][j] + 1,
                                      distance[i][j - 1] + 1,
                                      distance[i - 1][j - 1] + cost);
        }
    }

    return distance[word1Length][word2Length];
}

int main() {
    char word1[] = "kitten";
    char word2[] = "sitting";
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", word1, word2, levenshteinDistance(word1, word2));
    return 0;
}