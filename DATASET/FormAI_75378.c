//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main() {
    char text[10000];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int frequencies[MAX_NUM_WORDS];
    int num_words = 0;

    printf("Hello! This is the Happy Word Frequency Counter!\n");
    printf("Please enter some text (less than 10000 characters):\n");
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, " ");
    while (token != NULL && num_words < MAX_NUM_WORDS) {
        if (strlen(token) > 2 && strlen(token) < MAX_WORD_LENGTH) {
            int i;
            for (i = 0; token[i]; i++) {
                token[i] = tolower(token[i]);
            }
            strcpy(words[num_words], token);
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(words[j], token) == 0) {
                    frequencies[j]++;
                    break;
                }
            }
            if (j == num_words) {
                frequencies[num_words] = 1;
                num_words++;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("\nCool beans! Here are the word frequencies:\n");

    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    printf("\nThanks for playing! Have a wonderful day! :D\n");

    return 0;
}