//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int minValue = a;
    if (b < minValue) {
        minValue = b;
    }
    if (c < minValue) {
        minValue = c;
    }
    return minValue;
}

int levenshtein(char* s1, char* s2) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int dist[s1Len+1][s2Len+1];
    for (int i = 0; i <= s1Len; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= s2Len; j++) {
        dist[0][j] = j;
    }
    for (int i = 1; i <= s1Len; i++) {
        for (int j = 1; j <= s2Len; j++) {
            if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1;
            }
        }
    }
    return dist[s1Len][s2Len];
}

int main() {
    char* s1 = "kitten";
    char* s2 = "sitting";
    printf("Levenshtein Distance between %s and %s: %d\n", s1, s2, levenshtein(s1, s2));
    return 0;
}