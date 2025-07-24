//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

int main(void) {
    char input_string[10000], word[MAX_WORD_LEN];
    int word_count = 0;
    int char_count = 0;
    int word_freq[MAX_WORD_LEN] = {0};
    int max_freq = 0;

    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    for (int i = 0; i < strlen(input_string); i++) {
        if (isalpha(input_string[i]) || input_string[i] == '-') {
            word[char_count] = tolower(input_string[i]);
            char_count++;
        } else if (isspace(input_string[i]) || ispunct(input_string[i])) {
            if (char_count > 0) {
                word[char_count] = '\0';
                word_count++;
                word_freq[strlen(word)]++;
                if (word_freq[strlen(word)] > max_freq) {
                    max_freq = word_freq[strlen(word)];
                }
                char_count = 0;
            }
        }
    }

    printf("\nWord Frequency Count\n");

    for (int i = 1; i < MAX_WORD_LEN; i++) {
        if (word_freq[i] > 0) {
            printf("%d letter words: %d\n", i, word_freq[i]);
        }
    }

    printf("\nMax word frequency: %d\n", max_freq);

    return 0;
}