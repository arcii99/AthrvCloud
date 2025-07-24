//FormAI DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    while(1) {
        printf("Enter a string to check for spelling errors: ");
        fgets(text, 100, stdin); // get user input
        if (strcmp(text, "exit\n") == 0) { // if user enters "exit", exit program
            printf("Goodbye!\n");
            break;
        }
        int length = strlen(text); // get length of user input
        int index = 0; // position in string
        int word_start = 0; // start position of word being checked
        int word_end = 0; // end position of word being checked
        int has_error = 0; // flag for spelling error
        while (index < length) { // loop through input string
            if (isspace(text[index]) || ispunct(text[index])) { // if current character is space or punctuation
                if (word_start != word_end) { // if word has letters
                    char word[100]; // create a new string for the word
                    strncpy(word, &text[word_start], word_end - word_start); // copy word into new string
                    word[word_end - word_start] = '\0'; // add null terminator
                    printf("Checking spelling for '%s'...\n", word);
                    // here goes our spell checking function... or does it?
                    int is_correct = 1; // assume word is correct
                    int word_length = strlen(word); // get length of word
                    for (int i = 0; i < word_length; i++) {
                        if (!isalpha(word[i])) { // ignore non-letter characters
                            continue;
                        }
                        if (tolower(word[i]) != 'c') { // if word does not contain the letter 'c'
                            is_correct = 0; // flag as error
                            break; // no need to check further
                        }
                    }
                    if (!is_correct) { // if there is an error
                        printf("Spelling error found in '%s'\n", word);
                        has_error = 1; // flag overall error
                    } else {
                        printf("No spelling errors found in '%s'\n", word);
                    }
                }
                word_start = index + 1; // set start position of next word
            } else {
                word_end = index + 1; // set end position of current word
            }
            index++; // move to next character
        }
        if (!has_error) { // if no errors were found
            printf("No spelling errors found!\n");
        }
    }
    return 0;
}