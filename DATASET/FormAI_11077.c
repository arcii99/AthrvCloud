//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // create a 2D array to store the distance values
    int distance[len1 + 1][len2 + 1];
    // initialize the first column and row with incremental values
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }
    // perform the dynamic programming to compute the distances of substrings
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitution_cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            int deletion_cost = distance[i - 1][j] + 1;
            int insertion_cost = distance[i][j - 1] + 1;
            int substitution_or_noop_cost = distance[i - 1][j - 1] + substitution_cost;
            // pick the minimum cost of the three options: deletion, insertion, and substitution (with or without cost)
            int min_cost = deletion_cost < insertion_cost ? deletion_cost : insertion_cost;
            min_cost = substitution_or_noop_cost < min_cost ? substitution_or_noop_cost : min_cost;
            distance[i][j] = min_cost;
        }
    }
    // return the final distance value for the two input strings
    return distance[len1][len2];
}

int main() {
    char* str1 = "kitten";
    char* str2 = "sitting";
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between %s and %s is %d.\n", str1, str2, distance);
    return 0;
}