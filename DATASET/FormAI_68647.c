//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 1000

struct Word {
    char str[MAX_WORD_LEN + 1];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    struct Word words[MAX_WORD_COUNT];
    int word_count = 0;

    char c;
    char word[MAX_WORD_LEN + 1] = {'\0'};
    int word_len = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            if (word_len < MAX_WORD_LEN) {
                word[word_len++] = tolower(c);
            }
        } else {
            if (word_len > 0) {
                // Check if the word is already in the list
                int i;
                for (i = 0; i < word_count; i++) {
                    if (strcmp(words[i].str, word) == 0) {
                        words[i].count++;
                        break;
                    }
                }

                if (i == word_count) {
                    strcpy(words[word_count].str, word);
                    words[word_count].count = 1;
                    word_count++;
                }

                // Reset the word buffer
                memset(word, '\0', sizeof(word));
                word_len = 0;
            }
        }
    }

    // Print the word frequencies
    printf("Word frequencies in %s:\n", filename);
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].str, words[i].count);
    }

    fclose(file);

    return 0;
}