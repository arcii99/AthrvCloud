//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    }
    else if (y < x && y < z) {
        return y;
    }
    else {
        return z;
    }
}

int levenshtein(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1] + cost);
        }
    }

    return dist[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int dist = levenshtein(s1, s2);
    printf("Levenshtein Distance: %d", dist);
    return 0;
}