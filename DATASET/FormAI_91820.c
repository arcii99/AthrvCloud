//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

/* Function to calculate the minimum of three integers */
int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

/* Function to calculate Levenshtein Distance between two given strings */
int levenshtein(const char *a, const char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int distance[MAX_LEN][MAX_LEN];

    // Initialize distance[][] array with 0 and 1.
    for (int i = 0; i <= len_a; ++i) {
        for (int j = 0; j <= len_b; ++j) {
            if (i == 0)
                distance[i][j] = j;

            else if (j == 0)
                distance[i][j] = i;

            else if (a[i - 1] == b[j - 1])
                distance[i][j] = distance[i - 1][j - 1];

            else
                distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
        }
    }
    return distance[len_a][len_b];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin); // Read input from standard input stream
    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin); // Read input from standard input stream
    
    // Remove newline character from the input strings
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    printf("The Levenshtein Distance is: %d", levenshtein(str1, str2));
    return 0;
}