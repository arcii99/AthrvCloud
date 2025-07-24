//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 1000

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

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    static int memo[MAX_LIMIT][MAX_LIMIT];
    memset(memo, -1, sizeof(memo));

    if (len1 == 0) {
        return len2;
    }
    if (len2 == 0) {
        return len1;
    }

    if (memo[len1][len2] != -1) {
        return memo[len1][len2];
    }

    int cost;
    if (s1[len1 - 1] == s2[len2 - 1]) {
        cost = 0;
    } else {
        cost = 1;
    }

    int del = levenshtein_distance(s1, s2 + 1) + 1;
    int ins = levenshtein_distance(s1 + 1, s2) + 1;
    int sub = levenshtein_distance(s1 + 1, s2 + 1) + cost;

    int result = minimum(del, ins, sub);

    memo[len1][len2] = result;

    return result;
}

int main() {
    char string1[MAX_LIMIT], string2[MAX_LIMIT];

    printf("Levenshtein Distance Calculator\n");

    printf("Enter first string: ");
    fgets(string1, MAX_LIMIT, stdin);

    printf("Enter second string: ");
    fgets(string2, MAX_LIMIT, stdin);

    //remove the newline character from fgets
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;

    int result = levenshtein_distance(string1, string2);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", string1, string2, result);

    return 0;
}