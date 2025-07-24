//FormAI DATASET v1.0 Category: Spam Detection System ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // max number of spam words
#define MAX_WORD_LENGTH 20 // max length for each spam word
#define MAX_INPUT_LENGTH 500 // max length for input string

/* Function to check if a given string contains a spam word */
int contains_spam_word(char input[], char spam_list[][MAX_WORD_LENGTH], int num_spam_words) {
    char *token;
    char copy[MAX_INPUT_LENGTH];

    // make a copy of the input string to modify
    strcpy(copy, input);

    // convert all characters in the input string to lowercase
    for (int i = 0; i < strlen(copy); i++) {
        copy[i] = tolower(copy[i]);
    }

    // loop through each spam word and check if it is in the input string
    for (int i = 0; i < num_spam_words; i++) {
        token = strtok(copy, " "); // get the next word from the input string

        // loop through each word in the input string
        while (token != NULL) {
            if (strcmp(token, spam_list[i]) == 0) { // if the word matches a spam word
                return 1;
            }
            token = strtok(NULL, " "); // get the next word from the input string
        }

        // reset the copy of the input string for the next spam word check
        strcpy(copy, input);
    }

    return 0; // no spam words found in the input string
}

int main() {
    char spam_list[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {"buy", "enlarge", "money", "sex", "viagra"}; // array of spam words
    char input[MAX_INPUT_LENGTH]; // user input string

    printf("Enter a message: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // get user input

    if (contains_spam_word(input, spam_list, MAX_SPAM_WORDS)) {
        printf("This message contains spam.\n"); // if spam words found, print message
    } else {
        printf("This message is spam-free.\n"); // if no spam words found, print message
    }

    return 0;
}