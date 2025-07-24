//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int n = 7; // the size of the pattern
    char pattern[n][n];
    int i, j;

    // initializing the pattern with spaces
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pattern[i][j] = ' ';
        }
    }

    // printing the top hat of Sherlock Holmes
    pattern[0][3] = '/';
    pattern[0][4] = '\\';
    for (i = 1; i < 4; i++) {
        pattern[i][2 + i] = '/';
        pattern[i][4 - i] = '\\';
    }

    // printing the face of Sherlock Holmes
    pattern[4][2] = pattern[4][4] = '_';
    pattern[5][2] = '(';
    pattern[5][4] = ')';
    pattern[6][1] = pattern[6][5] = '|';

    // printing the pipe
    pattern[0][0] = '|';
    pattern[0][n - 1] = '|';
    for (i = 1; i < n; i++) {
        pattern[i][0] = '|';
        pattern[i][n - 1] = '|';
    }

    // printing the pattern
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            putchar(pattern[i][j]);
        }
        putchar('\n');
    }

    return 0;
}