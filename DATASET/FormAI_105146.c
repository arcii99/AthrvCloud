//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main(void) {
    char text[MAX_NUM_WORDS * MAX_WORD_LENGTH];
    int word_count[MAX_NUM_WORDS] = {0};
    char *token;
    char *delimiter = " ,.!?\n\t\r";
    int num_words = 0;

    printf("Enter a piece of text:\n");
    fgets(text, sizeof(text), stdin);

    token = strtok(text, delimiter);
    while (token) {
        int word_len = strlen(token);
        if (word_len > MAX_WORD_LENGTH) {
            printf("Word '%s' is too long!\n", token);
        } else {
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(token, &text[word_count[i]]) == 0) {
                    word_count[i] += (word_len + 1);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (num_words < MAX_NUM_WORDS) {
                    word_count[num_words++] = word_len + 1;
                    strcpy(&text[word_count[num_words - 1]], token);
                } else {
                    printf("Maximum number of words reached!\n");
                    break;
                }
            }
        }
        token = strtok(NULL, delimiter);
    }

    printf("\nFrequency of words in the text:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s : %d\n", &text[word_count[i]], i + 1);
    }

    return 0;
}