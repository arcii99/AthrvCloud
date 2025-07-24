//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function prototypes
int min(int a, int b, int c);
int levenshtein_distance(char s[], char t[]);

int main() {
    char s[MAX_LEN], t[MAX_LEN];

    printf("Enter the first string: ");
    fgets(s, MAX_LEN, stdin);

    printf("Enter the second string: ");
    fgets(t, MAX_LEN, stdin);

    // Remove newline character at the end
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    int distance = levenshtein_distance(s, t);
    printf("Levenshtein distance between %s and %s is %d\n", s, t, distance);

    return 0;
}

// Return the minimum of three numbers
int min(int a, int b, int c) {
    int m = a;

    if (b < m)
        m = b;
    if (c < m)
        m = c;

    return m;
}

// Calculate the Levenshtein distance between s and t
int levenshtein_distance(char s[], char t[]) {
    int m = strlen(s);
    int n = strlen(t);

    if (m == 0)
        return n;

    if (n == 0)
        return m;

    // Create a 2D array to store the distances
    int d[m+1][n+1];

    // Initialize the first row and column
    for (int i = 0; i <= m; i++)
        d[i][0] = i;

    for (int j = 0; j <= n; j++)
        d[0][j] = j;

    // Fill in the rest of the array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1])
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = min(d[i-1][j], d[i][j-1], d[i-1][j-1]) + 1;
        }
    }

    return d[m][n];
}