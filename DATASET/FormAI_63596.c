//FormAI DATASET v1.0 Category: Spam Detection System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define SPAM_THRESHOLD 0.5

int main() {
    char message[MAX_LENGTH];
    int num_words = 0, num_spam = 0;
    float spam_ratio = 0.0;

    printf("Enter a message:\n");
    fgets(message, MAX_LENGTH, stdin);  // get user input

    // split message into words and check for spam keywords
    char *word = strtok(message, " ");
    while (word != NULL) {
        num_words++;  // count number of words in message

        // check for spam keywords
        if (strstr(word, "buy") != NULL || strstr(word, "sale") != NULL ||
            strstr(word, "discount") != NULL || strstr(word, "free") != NULL) {
            num_spam++;
        }

        word = strtok(NULL, " ");  // move to next word
    }

    // calculate spam ratio
    if (num_words > 0) {
        spam_ratio = (float)num_spam / num_words;
    }

    // determine if message is spam or not
    if (spam_ratio >= SPAM_THRESHOLD) {
        printf("This is spam!\n");
    } else {
        printf("This is not spam.\n");
    }

    return 0;
}