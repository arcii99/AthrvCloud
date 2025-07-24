//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

/* Function to check if a message contains spam */
int contains_spam(char *message, int len) {

    char *spam_words[] = {"buy", "discount", "limited time offer", "make money fast"};

    int num_spam_words = 4; // number of spam words in the array

    /* Loop through the spam words array and check if any appear in the message */
    for (int i = 0; i < num_spam_words; i++) {
        char *spam_word = spam_words[i];

        /* Check if the spam word appears in the message */
        char *result = strstr(message, spam_word);
        if (result != NULL) {
            /* Spam word found */
            return 1;
        }
    }

    /* No spam words found */
    return 0;
}

int main() {
    char message[1000];
    int len;

    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    len = strlen(message);

    /* Check if the message contains spam */
    int is_spam = contains_spam(message, len);

    if (is_spam) {
        printf("This message contains spam!\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}