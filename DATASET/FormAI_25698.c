//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

int levenshtein_distance(char *word1, char *word2) {
    int matrix[strlen(word1) + 1][strlen(word2) + 1];
    int i, j, sub_cost;

    for(i = 0; i <= strlen(word1); i++) {
        for(j = 0; j <= strlen(word2); j++) {
            if(i == 0) {
                matrix[i][j] = j;
            }
            else if(j == 0) {
                matrix[i][j] = i;
            }
            else {
                sub_cost = 0;
                if(word1[i-1] != word2[j-1]) {
                    sub_cost = 1;
                }
                matrix[i][j] = fmin(matrix[i-1][j] + 1, fmin(matrix[i][j-1] + 1, matrix[i-1][j-1] + sub_cost));
            }
        }
    }

    return matrix[strlen(word1)][strlen(word2)];
}

int main() {
    char word1[100], word2[100];
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", word1, word2, levenshtein_distance(word1, word2));

    return 0;
}