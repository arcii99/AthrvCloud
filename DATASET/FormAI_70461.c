//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance[len1 + 1][len2 + 1];
    memset(distance, 0, sizeof(distance));

    for (int i = 1; i <= len1; i++) {
        distance[i][0] = i;
    }

    for (int j = 1; j <= len2; j++) {
        distance[0][j] = j;
    }

    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = min(
                    1 + distance[i - 1][j], // insertion
                    1 + distance[i][j - 1], // deletion
                    1 + distance[i - 1][j - 1] // substitution
                );
            }
        }
    }

    return distance[len1][len2];
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    printf("Enter two strings:\n");
    scanf("%s", str1);
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    printf("\nLevenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}