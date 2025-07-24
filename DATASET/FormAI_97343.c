//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
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

int LevenshteinDistance(char* s1, char* s2) {
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    int distance[s1_length + 1][s2_length + 1];

    for (int i = 0; i <= s1_length; ++i) {
        for (int j = 0; j <= s2_length; ++j) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + minimum(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
            }
        }
    }

    return distance[s1_length][s2_length];
}

int main() {
    char* s1 = "chatbot";
    char* s2 = "chabot";

    int distance = LevenshteinDistance(s1, s2);

    printf("%s and %s have a Levenshtein Distance of %d\n", s1, s2, distance);

    return 0;
}