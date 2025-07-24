//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {

    char word1[100], word2[100];

    printf("Enter the first word: ");
    scanf("%s", word1);

    printf("Enter the second word: ");
    scanf("%s", word2);

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int dist[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            }
            else if (j == 0) {
                dist[i][j] = i;
            }
            else if (word1[i - 1] == word2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            }
            else {
                int delete = dist[i - 1][j] + 1;
                int insert = dist[i][j - 1] + 1;
                int substitute = dist[i - 1][j - 1] + 1;
                dist[i][j] = (delete < insert ? delete : insert) < substitute ? (delete < insert ? delete : insert) : substitute;
            }
        }
    }

    printf("The Levenshtein Distance between %s and %s is: %d\n", word1, word2, dist[len1][len2]);

    return 0;
}