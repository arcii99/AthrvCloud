//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int minimum(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Initializing the cost matrix
    int cost[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                cost[i][j] = j;
            }
            else if(j == 0) {
                cost[i][j] = i;
            }
            else {
                cost[i][j] = 0;
            }
        }
    }

    // Filling out the cost matrix
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                cost[i][j] = cost[i - 1][j - 1];
            }
            else {
                cost[i][j] = 1 + minimum(cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1]);
            }
        }
    }

    return cost[len1][len2];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter string 1: ");
    fgets(s1, MAX_LEN, stdin);
    printf("Enter string 2: ");
    fgets(s2, MAX_LEN, stdin);

    // Removing newline characters from the input strings
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}