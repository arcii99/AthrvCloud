//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SPAMS 100
#define MAX_SPAM_LENGTH 50

int main() {
    char spams[MAX_SPAMS][MAX_SPAM_LENGTH] = {"spam1", "spam2", "spam3"}; // list of spams to check
    char message[MAX_SPAM_LENGTH]; // the message to check
    int spam_index, i, j, match_count;
    printf("Welcome to the Spam Detection System!\n");
    while (1) {
        printf("Enter your message: ");
        fgets(message, MAX_SPAM_LENGTH, stdin); // read user input
        message[strlen(message) - 1] = '\0'; // remove trailing newline character
        match_count = 0;
        for (i = 0; i < MAX_SPAMS; i++) {
            spam_index = i;
            for (j = 0; j < strlen(message); j++) {
                if (spams[spam_index][j] == message[j]) { // compare characters
                    match_count++;
                } else {
                    match_count = 0;
                    break; // reset counter and break out of inner loop
                }
            }
            if (match_count == strlen(message)) { // if all characters match
                printf("The message is spam.\n");
                break; // break out of outer loop
            }
        }
        if (match_count != strlen(message)) { // if no matches found
            printf("The message is not spam.\n");
        }
    }
    return 0;
}