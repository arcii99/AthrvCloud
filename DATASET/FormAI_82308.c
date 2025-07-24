//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int leven_distance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int dist[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = 1 + min(dist[i][j - 1], 
                                      dist[i - 1][j], 
                                      dist[i - 1][j - 1]);
            }
        }
    }
    return dist[len1][len2];
}

int main() {
    char s1[] = "Sherlock Holmes";
    char s2[] = "Shelock Holmes";
    int dist = leven_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", 
           s1, s2, dist);
    return 0;
}