//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int levenshtein_distance(char *s1, char *s2) {
    int i, j, m, n, distance;
    int t[100][100];

    m = strlen(s1);
    n = strlen(s2);

    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0) t[i][j] = j;
            else if(j == 0) t[i][j] = i;
            else if(s1[i-1] == s2[j-1]) t[i][j] = t[i-1][j-1];
            else t[i][j] = 1 + min(t[i][j-1], t[i-1][j], t[i-1][j-1]);
        }
    }

    distance = t[m][n];

    return distance;
}

int main() {
    char s1[100], s2[100];
    int distance;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    distance = levenshtein_distance(s1, s2);

    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}