//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // Maximum number of spam words to check for

char *spam_words[MAX_SPAM_WORDS] = {"investment", "lottery", "free", "money", "win", "cash", "loan", "viagra", "sex", "discount"}; // List of spam words

// Function to check if a word is a spam word
int is_spam_word(char *word) {
    int i;

    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to check if a message is spam or not
int is_spam_message(char *message) {
    char *word, *message_copy;
    int spam_count = 0;

    // Make a copy of the message so that the original message is not changed
    message_copy = strdup(message);

    // Tokenize the message by space delimiter
    word = strtok(message_copy, " ");

    // Check each word for spam
    while (word != NULL) {
        if (is_spam_word(word)) {
            spam_count++;
        }
        word = strtok(NULL, " ");
    }

    // Free the memory allocated for the message copy
    free(message_copy);

    // If more than 2 words are spam words, consider the message as spam
    if (spam_count >= 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove the newline character from the end of the message

    if (is_spam_message(message)) {
        printf("The message is spam!\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}