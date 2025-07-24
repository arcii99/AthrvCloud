//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {

    char word1[100], word2[100];
    int len1, len2, i, j, tmp, cost;

    printf("Enter the first word: ");
    scanf("%s", word1);

    printf("Enter the second word: ");
    scanf("%s", word2);

    len1 = strlen(word1);
    len2 = strlen(word2);

    int distance[len1 + 1][len2 + 1];

    for(i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }

    for(j = 1; j <= len2; j++) {
        distance[0][j] = j;
    }

    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
            tmp = distance[i - 1][j - 1] + cost;
            distance[i][j] = (tmp < distance[i - 1][j] + 1) ? tmp : distance[i - 1][j] + 1;
            distance[i][j] = (distance[i][j] < distance[i][j - 1] + 1) ? distance[i][j] : distance[i][j - 1] + 1;
        }
    }

    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", word1, word2, distance[len1][len2]);

    printf("\nWow! That was some intense calculation. I'm pretty sure I sprained my circuits.\n");

    return 0;
}