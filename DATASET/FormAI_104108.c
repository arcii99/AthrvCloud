//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// function to check if a character is a letter or not
int is_letter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if a character is a symbol or not
int is_symbol(char c) {
    if (!is_letter(c) && c != ' ' && c != '\t' && c != '\n') {
        return 1;
    } else {
        return 0;
    }
}

// function to convert a word to lowercase
void to_lowercase(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += 32;
        }
    }
}

int main() {
    // welcome message
    printf("++++++++++ Welcome to the Cyberpunk Spell Checker ++++++++++\n");

    // input text
    char text[1000];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // check each word in the text
    printf("\nResult:\n");
    char *word = strtok(text, " ,.-\n\t");
    while (word != NULL) {
        char word_copy[50];
        strcpy(word_copy, word);

        // check if the word contains symbols or digits
        int has_symbols_or_digits = 0;
        for (int i = 0; i < strlen(word_copy); i++) {
            if (is_symbol(word_copy[i]) || (word_copy[i] >= '0' && word_copy[i] <= '9')) {
                has_symbols_or_digits = 1;
                break;
            }
        }

        // if the word contains symbols or digits, skip it
        if (has_symbols_or_digits) {
            printf("%s ", word);
            word = strtok(NULL, " ,.-\n\t");
            continue;
        }

        // convert the word to lowercase
        to_lowercase(word_copy);

        // check if the word is spelled correctly
        int is_spelled_correctly = 1;
        char dictionary[][50] = {"cyber", "punk", "spell", "checker", "is", "awesome", "program", "in", "c", "language", "coding", "is", "fun"};

        for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
            if (strcmp(word_copy, dictionary[i]) == 0) {
                is_spelled_correctly = 1;
                break;
            } else {
                is_spelled_correctly = 0;
            }
        }
        
        // print the word with the appropriate message
        if (is_spelled_correctly) {
            printf("%s ", word);
        } else {
            printf("[[WRONG:%s]] ", word);
        }

        // get the next word
        word = strtok(NULL, " ,.-\n\t");
    }
    printf("\n");

    // exit message
    printf("\n++++++++++++++++++++++++  Good bye!  ++++++++++++++++++++++++\n");

    return 0;
}