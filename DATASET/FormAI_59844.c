//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <string.h>

// Define a function to check the presence of spam words
int checkSpam(char *string) {
    char *spamWords[] = {"buy", "cheap", "win", "prize", "limited", "offer"};

    int i, j, found;
    int numOfSpamWords = sizeof(spamWords) / sizeof(char *);

    for (i = 0; i < numOfSpamWords; i++) {
        found = 0;
        char *word = spamWords[i];
        for (j = 0; j < strlen(string); j++) {
            if (word[found] == string[j]) {
                found++;
            } else {
                found = 0;
            }

            if (found == strlen(word)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char message[200];
    printf("Enter your message: ");
    gets(message); // Read the message from the user

    // Check if the message contains any spam words
    if (checkSpam(message)) {
        printf("Your message contains spam words.\n");
    } else {
        printf("Your message is safe to send.\n");
    }

    return 0;
}