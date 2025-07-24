//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define DICTIONARY_SIZE 15
#define WORDS_TO_CHECK_SIZE 10

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH] = {"hello", "world", "happy", "coding", "fun", "awesome", "fantastic", "cheerful", "program", "learning", "language", "spellcheck", "creative", "unique", "exciting"};
    char words_to_check[WORDS_TO_CHECK_SIZE][MAX_WORD_LENGTH] = {"happy", "world", "program", "learing", "cheerful", "fantatsic", "spellchecking", "coding", "creativity", "excitment"};
    char temp_word[MAX_WORD_LENGTH];
    int dictionary_length = DICTIONARY_SIZE;
    int words_to_check_length = WORDS_TO_CHECK_SIZE;
    int errors_found = 0;

    // Start checking for spellings
    for(int i = 0; i < words_to_check_length; i++) {
        strcpy(temp_word, words_to_check[i]);

        // Convert the word to lowercase for comparison
        for(int j = 0; temp_word[j]; j++) {
            temp_word[j] = tolower(temp_word[j]);
        }

        // Compare the converted word with all the words in the dictionary
        for(int j = 0; j < dictionary_length; j++) {
            if(strcmp(temp_word, dictionary[j]) == 0) {
                break;
            } else if(j == dictionary_length-1) {
                // No match found in the dictionary
                printf("ERROR: %s not found in dictionary.\n", words_to_check[i]);
                errors_found++;
            }
        }
    }

    // Display summary
    if(errors_found == 0) {
        printf("No spelling errors found! Great job!\n");
    } else {
        printf("%d spelling error(s) found. Don't worry, just keep learning and improving!\n", errors_found);
    }

    return 0;
}