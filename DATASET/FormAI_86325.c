//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int main() {
    char input_str[100];
    int input_len, i, j, word_count = 0;
    int word_lengths[MAX_WORDS];
    char words[MAX_WORDS][MAX_WORD_LEN];
    fgets(input_str, sizeof(input_str), stdin);
    input_len = strlen(input_str);
    memset(word_lengths, 0, sizeof(word_lengths));
    for (i = 0; i < input_len; i++) {
        char ch = input_str[i];
        if (ch == ' ' || ch == '\n') {
            word_count++;
        } else if (word_lengths[word_count] < MAX_WORD_LEN - 1) {
            words[word_count][word_lengths[word_count]++] = ch;
        }
    }
    printf("Number of words: %d\n", word_count);
    for (i = 0; i < word_count; i++) {
        printf("Word %d: ", i);
        for (j = 0; j < word_lengths[i]; j++) {
            printf("%c", words[i][j]);
        }
        printf("\n");
    }
    return 0;
}