//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 100
#define WORDLENGTH 30

int main()
{
    char input[MAXLENGTH];
    char word[WORDLENGTH];
    int i, j, k;
    int word_len, input_len, num_errors, num_typos;
    int paranoid, quit;
    FILE *dictionary;

    char *filename = "dictionary.txt";

    dictionary = fopen(filename, "r");
    if (!dictionary) {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(input, MAXLENGTH, stdin)) {

        input[strcspn(input, "\n")] = '\0';
        input_len = strlen(input);

        num_errors = 0;
        num_typos = 0;
        paranoid = 0;
        quit = 0;

        for (i = 0; i < input_len; i++) {
            if (isalpha(input[i]) || input[i] == '-') {
                paranoid = 1;
                if (strlen(word) < WORDLENGTH - 1)
                    word[strlen(word)] = input[i];
            } else {
                if (paranoid) {
                    word_len = strlen(word);

                    for (j = 0; !quit && j < word_len; j++) {
                        for (k = 0; k < word_len; k++) {
                            if (k == j)
                                continue;
                            memcpy(word + word_len, "\0", 1);
                            strncpy(word + k, word + j, 1);
                            memmove(word + j, word + j + 1, word_len - j);
                            rewind(dictionary);
                            while (fgets(input, MAXLENGTH, dictionary)) {
                                input[strcspn(input, "\n")] = '\0';
                                if (!strcmp(word, input)) {
                                    printf("%s ", word);
                                    num_typos++;
                                }
                            }
                            if (num_typos > 0) {
                                num_errors++;
                                if (num_errors >= 2) {
                                    printf("<<too many mistakes>>");
                                    quit = 1;
                                    break;
                                }
                            }
                        }
                    }
                    memset(word, 0, sizeof(word));
                }
                quit = 0;
                paranoid = 0;
            }
            if (input[i] == '-') {
                putchar('-');
            } else {
                putchar(input[i]);
            }
        }
        putchar('\n');

    }

    fclose(dictionary);

    return 0;
}