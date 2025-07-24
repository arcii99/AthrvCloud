//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    Word words[MAX_WORDS];
    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    int i, j, found;

    while (fgets(line, MAX_WORD_LENGTH, stdin)) {
        /* remove any non-alphanumeric characters from the line */
        for (i = 0; i < strlen(line); i++) {
            if (!isalnum(line[i])) {
                line[i] = ' ';
            }
        }

        /* split the line into words */
        char* word = strtok(line, " ");
        while (word != NULL) {
            /* convert the word to lowercase */
            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            /* check if the word is already in the list */
            found = 0;
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            /* add the word to the list if it's not already there */
            if (!found) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }

            /* get the next word */
            word = strtok(NULL, " ");
        }
    }

    /* print the word frequencies */
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}