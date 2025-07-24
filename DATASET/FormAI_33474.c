//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define DICT_SIZE 100

int main() {
    char dictionary[DICT_SIZE][MAX_WORD_LEN];
    int num_words = 0;

    FILE *f_dict = fopen("dictionary.txt", "r");
    if (f_dict == NULL) {
        perror("Error opening dictionary file");
        return 1;
    }

    // load dictionary file into memory
    char word[MAX_WORD_LEN];
    while (fgets(word, MAX_WORD_LEN, f_dict)) {
        // strip newline character from end of word
        word[strcspn(word, "\n")] = 0;
        strncpy(dictionary[num_words], word, MAX_WORD_LEN);
        num_words++;
    }
    fclose(f_dict);

    // get input from user
    char input_text[MAX_WORD_LEN * 100];
    printf("Enter text to check spelling: ");
    fgets(input_text, MAX_WORD_LEN * 100, stdin);

    // tokenize input text and check each word against dictionary
    char *token;
    token = strtok(input_text, " .,!?\n");
    while (token != NULL) {
        char lower_word[MAX_WORD_LEN];
        strcpy(lower_word, token);
        // convert word to lowercase
        for (int i = 0; i < strlen(lower_word); i++) {
            lower_word[i] = tolower(lower_word[i]);
        }

        // check if word is in dictionary
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(lower_word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }

        // if word not found in dictionary, suggest corrections
        if (!found) {
            printf("Misspelled word: %s\n", token);
            printf("Suggestions: ");

            int num_corrections = 0;
            for (int i = 0; i < num_words; i++) {
                if (strlen(dictionary[i]) == strlen(lower_word)) {
                    int num_diff = 0;
                    for (int j = 0; j < strlen(lower_word); j++) {
                        if (lower_word[j] != dictionary[i][j]) {
                            num_diff++;
                        }
                    }
                    if (num_diff == 1) {
                        printf("%s ", dictionary[i]);
                        num_corrections++;
                    }
                }
            }

            if (num_corrections == 0) {
                printf("No suggestions found.");
            }
            printf("\n");
        }
        token = strtok(NULL, " .,!?\n");
    }

    return 0;
}