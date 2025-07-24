//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int levenshtein_distance(char* s1, char* s2, int n, int m) {
    int distance[n + 1][m + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                distance[i][j] = j;
            } else if(j == 0) {
                distance[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
            }
        }
    }

    return distance[n][m];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    int n, m;

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    n = strlen(s1);
    m = strlen(s2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s1, s2, levenshtein_distance(s1, s2, n, m));

    return 0;
}