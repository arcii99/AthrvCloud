//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(const char* word1, const char* word2) {
    size_t word1_len = strlen(word1), word2_len = strlen(word2);
    int* memo = malloc(sizeof(int) * (word1_len + 1) * (word2_len + 1));

    for (int i = 0; i <= word1_len; i++) {
        for (int j = 0; j <= word2_len; j++) {
            if (i == 0) {
                memo[i * (word2_len + 1) + j] = j;
            } else if (j == 0) {
                memo[i * (word2_len + 1) + j] = i;
            } else {
                int deletion = memo[(i - 1) * (word2_len + 1) + j] + 1;
                int insertion = memo[i * (word2_len + 1) + j - 1] + 1;
                int substitution = memo[(i - 1) * (word2_len + 1) + j - 1] + (word1[i - 1] != word2[j - 1] ? 1 : 0);
                memo[i * (word2_len + 1) + j] = deletion < insertion ? (deletion < substitution ? deletion : substitution) : (insertion < substitution ? insertion : substitution);
            }
        }
    }

    int distance = memo[word1_len * (word2_len + 1) + word2_len];
    free(memo);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", word1, word2, distance);
    return distance;
}

int main() {
    levenshtein_distance("surprised", "excited");
    return 0;
}