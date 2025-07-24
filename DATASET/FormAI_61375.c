//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int smallest = (a < b) ? a : b;
    smallest = (smallest < c) ? smallest : c;
    return smallest;
}

int levenshtein(char *s1, char *s2, int len1, int len2) {
    if (len1 == 0) {
        return len2;
    }
    if (len2 == 0) {
        return len1;
    }
    int cost;
    if(s1[len1-1] == s2[len2-1]) {
        cost = 0;
    } else {
        cost = 1;
    }
    return min(levenshtein(s1, s2, len1 - 1, len2) + 1,
            levenshtein(s1, s2, len1, len2 - 1) + 1,
            levenshtein(s1, s2, len1 - 1, len2 - 1) + cost);
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance = levenshtein(str1, str2, len1, len2);
    printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}