//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Calculates the minimum of three numbers
int min(int a, int b, int c) {
    int smallest = a < b ? a : b;
    return smallest < c ? smallest : c;
}

// Calculates the Levenshtein Distance between two strings
int levenshteinDistance(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Table to store the distance values
    int table[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                table[i][j] = j;
            }
            else if (j == 0) {
                table[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            }
            else {
                table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]);
            }
        }
    }

    return table[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // Removing the newline character
    str2[strcspn(str2, "\n")] = 0; // Removing the newline character

    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return 0;
}