//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int main(int argc, char **argv) {
    char *input_file_name;
    if (argc == 2) {
        input_file_name = argv[1];
    } else {
        input_file_name = "input.txt";
    }

    FILE *input_file = fopen(input_file_name, "r");
    if (!input_file) {
        fprintf(stderr, "Unable to open input file %s\n", input_file_name);
        exit(EXIT_FAILURE);
    }

    char *words[MAX_WORDS];
    int counts[MAX_WORDS] = {0};
    int num_words = 0;

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), input_file)) {
        char *word = strtok(line, " \t\r\n");
        while (word) {
            int i;
            for (i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }
            int duplicate = 0;
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, words[j]) == 0) {
                    duplicate = 1;
                    counts[j]++;
                    break;
                }
            }
            if (!duplicate) {
                words[num_words] = strdup(word);
                counts[num_words] = 1;
                num_words++;
            }

            if (num_words >= MAX_WORDS) {
                fprintf(stderr, "Too many words in input file\n");
                exit(EXIT_FAILURE);
            }

            word = strtok(NULL, " \t\r\n");
        }
    }

    fclose(input_file);

    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
        free(words[i]);
    }

    return 0;
}