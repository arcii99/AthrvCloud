//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levDist(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dist[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dist[i][j] = j;
            else if (j == 0) dist[i][j] = i;
            else if (s1[i - 1] == s2[j - 1]) dist[i][j] = dist[i - 1][j - 1];
            else dist[i][j] = 1 + min(dist[i][j - 1], dist[i - 1][j], dist[i - 1][j - 1]);
        }
    }
    return dist[m][n];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, levDist(s1, s2));
    return 0;
}