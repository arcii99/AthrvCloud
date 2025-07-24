//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int levenshtein(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int dp_table[MAX_LENGTH][MAX_LENGTH];
    memset(dp_table, 0, sizeof(dp_table));

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dp_table[i][j] = j;
            } else if(j == 0) {
                dp_table[i][j] = i;
            } else if(word1[i-1] == word2[j-1]) {
                dp_table[i][j] = dp_table[i-1][j-1];
            } else {
                int min_cost = dp_table[i-1][j-1];
                if(dp_table[i][j-1] < min_cost) {
                    min_cost = dp_table[i][j-1];
                }
                if(dp_table[i-1][j] < min_cost) {
                    min_cost = dp_table[i-1][j];
                }
                dp_table[i][j] = min_cost + 1;
            }
        }
    }

    return dp_table[len1][len2];
}

int main() {
    char word1[MAX_LENGTH], word2[MAX_LENGTH];
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    int distance = levenshtein(word1, word2);
    printf("The Levenshtein distance between %s and %s is %d.\n", word1, word2, distance);

    return 0;
}