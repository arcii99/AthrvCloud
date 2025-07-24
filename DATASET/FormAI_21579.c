//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of three numbers
int min(int a, int b, int c) {
    int m = a; // initialize m as a
    if (b < m) m = b; // if b is smaller than m, update m as b
    if (c < m) m = c; // if c is smaller than m, update m as c
    return m;
}

int levenshtein_distance(char *s, char *t) {
    int n = strlen(s); // length of s
    int m = strlen(t); // length of t
    int d[n + 1][m + 1]; // declare a matrix d
    int i, j;

    // initialize the first row and column of d
    for (i = 0; i <= n; i++) d[i][0] = i;
    for (j = 0; j <= m; j++) d[0][j] = j;

    // compute the rest of the matrix d
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) d[i][j] = d[i - 1][j - 1];
            else d[i][j] = min(d[i - 1][j] + 1, // deletion
                               d[i][j - 1] + 1, // insertion
                               d[i - 1][j - 1] + 1); // substitution
        }
    }

    return d[n][m]; // return the bottom-right element of the matrix d
}

int main() {
    char s[100], t[100]; // declare two strings s and t
    printf("Enter the first string s: ");
    scanf("%s", s); // get input for s from the user
    printf("Enter the second string t: ");
    scanf("%s", t); // get input for t from the user
    int distance = levenshtein_distance(s, t); // calculate the Levenshtein distance between s and t
    printf("The Levenshtein distance between %s and %s is %d.\n", s, t, distance); // output the result
    return 0; // exit the program with no errors
}