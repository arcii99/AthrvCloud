//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else {
                int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
                dist[i][j] = min(dist[i-1][j] + 1, dist[i][j-1] + 1, dist[i-1][j-1] + cost);
            }
        }
    }

    return dist[len1][len2];
}

int main() {
    char s1[] = "intelligent";
    char s2[] = "inteligent";
    int distance = levenshtein(s1, s2);
    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}