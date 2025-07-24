//FormAI DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100
#define DICT_SIZE 20

char dictionary[DICT_SIZE][MAX_STR_LEN] = {"hello", "world", "computer", "language", "programming", "algorithm", "variable", "function", "array", "iteration", "condition", "pointer", "memory", "structure", "file", "stream", "error", "debugging", "testing", "documentation"};

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void printSuggestions(char *word) {
    printf("\nDid you mean:\n");
    for (int i = 0; i < DICT_SIZE; i++) {
        int dist = levenshteinDistance(word, dictionary[i]);
        if (dist <= 3) {
            printf("- %s\n", dictionary[i]);
        }
    }
    printf("\n");
}

int levenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
        }
    }

    return matrix[len1][len2];
}

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    char input[MAX_STR_LEN];
    printf("Enter a word to spellcheck: ");
    fgets(input, MAX_STR_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    printf("Checking spelling of '%s'...\n", input);

    toLowercase(input);

    int found = 0;
    for (int i = 0; i < DICT_SIZE; i++) {
        if (strcmp(input, dictionary[i]) == 0) {
            printf("'%s' is spelled correctly.\n", input);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sorry, '%s' was not found in the dictionary.\n", input);
        printSuggestions(input);
    }

    return 0;
}