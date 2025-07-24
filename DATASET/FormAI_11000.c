//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char message[100]; // declaring a character array to store the message
    int i, j, count; // declaring variables to iterate and count

    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter a message to check for spam: ");

    fgets(message, sizeof(message), stdin); // getting input from the user

    // checking for spam keywords
    char spamWords[6][20] = {"buy", "discount", "sale", "free", "money", "offer"};

    for (i = 0; i < 6; i++) {
        count = 0;
        for (j = 0; j < strlen(message) - strlen(spamWords[i]); j++) { // checking each substring
            if (strncmp(message+j, spamWords[i], strlen(spamWords[i])) == 0) { // comparing with spam keywords
                count++;
            }
        }
        if (count > 0) {
            printf("SPAM DETECTED - contains the word '%s' %d times!\n", spamWords[i], count);
        }
    }

    // checking for excessive punctuation
    char punctuations[] = "!?.,;:\"\'()[]{}";
    int punctCount = 0;

    for (i = 0; i < strlen(message); i++) {
        if (strchr(punctuations, message[i]) != NULL) { // checking each character for punctuation
            punctCount++;
        }
    }

    if (punctCount > strlen(message) / 10) { // if more than 10% of the message is punctuation
        printf("SPAM DETECTED - contains excessive punctuation!\n");
    }

    printf("Spam detection complete. Thank you!");

    return 0;
}