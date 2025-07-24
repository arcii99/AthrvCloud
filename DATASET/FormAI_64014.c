//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of three numbers
int minimum(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int substitution_cost;
            if (s[i-1] == t[j-1]) {
                substitution_cost = 0;
            } else {
                substitution_cost = 1;
            }
            d[i][j] = minimum(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+substitution_cost);
        }
    }
    return d[m][n];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    printf("Levenshtein distance: %d\n", levenshtein_distance(s1, s2));
    return 0;
}