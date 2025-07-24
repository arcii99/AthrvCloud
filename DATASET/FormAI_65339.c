//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include<stdio.h>
#include<string.h>

// function to calculate minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    } else if (y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

// function to calculate Levenshtein Distance
int levenshteinDistance(char *s1, char *s2, int m, int n) {
    int dist[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dist[i][j] = j;
            }
            else if (j == 0) {
                dist[i][j] = i;
            }
            else if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = 1 + min(dist[i][j-1], dist[i-1][j], dist[i-1][j-1]);
            }
        }
    }

    return dist[m][n];
}

int main() {
    char s1[100], s2[100];
    
    // input the strings to calculate Levenshtein distance
    printf("Enter the first string: ");
    fgets(s1, 100, stdin);
    printf("Enter the second string: ");
    fgets(s2, 100, stdin);

    // remove newline character from the strings
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    int m = strlen(s1);
    int n = strlen(s2);

    int distance = levenshteinDistance(s1, s2, m, n);
    
    printf("Levenshtein distance between %s and %s is %d.\n", s1, s2, distance);

    return 0;
}