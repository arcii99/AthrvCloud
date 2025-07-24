//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // Maximum number of spam words that can be detected
#define MAX_WORD_LEN 20 // Maximum length of a single word

char spam_words[MAX_SPAM_WORDS][MAX_WORD_LEN]; // Array to store the spam words
int spam_count[MAX_SPAM_WORDS]; // Array to store the number of times each spam word is found

void detect_spam(char *message) {
    char *word; // Pointer to the current word being processed
    int i, j, match;

    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        spam_count[i] = 0; // Reset the count array
    }

    word = strtok(message, " "); // Get the first word in the message

    while (word != NULL) { // Loop through all words in the message
        for (i = 0; i < MAX_SPAM_WORDS; i++) {
            match = strcmp(word, spam_words[i]); // Compare the current word to each spam word

            if (match == 0) { // If a match is found, increment the count for that spam word
                spam_count[i]++;
            }
        }

        word = strtok(NULL, " "); // Get the next word in the message
    }

    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (spam_count[i] > 0) { // If a spam word was found, print a warning message
            printf("Warning: Message may contain spam word '%s' (%d occurrences)\n", spam_words[i], spam_count[i]);
        }
    }
}

int main() {
    int i;
    char message[100];

    // Set the spam words to detect
    strcpy(spam_words[0], "buy");
    strcpy(spam_words[1], "cheap");
    strcpy(spam_words[2], "discount");
    strcpy(spam_words[3], "free");
    strcpy(spam_words[4], "money-back");
    strcpy(spam_words[5], "offer");
    strcpy(spam_words[6], "sale");
    strcpy(spam_words[7], "sex");
    strcpy(spam_words[8], "viagra");
    strcpy(spam_words[9], "win");

    // Get the message from the user
    printf("Enter a message to check for spam: ");
    fgets(message, 100, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = 0;

    // Check for spam in the message
    detect_spam(message);

    return 0;
}