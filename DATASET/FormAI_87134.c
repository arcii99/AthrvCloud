//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Initialize spam words array
char *spamWords[] = {"click", "win", "money"};

// Function to check if a message contains spam words
int is_spam(char *message) {
    for (int i = 0; i < sizeof(spamWords)/sizeof(spamWords[0]); i++) {
        // Check if the spam word is present in the message
        if (strstr(message, spamWords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[100];
    printf("Enter a message: ");
    fgets(message, 100, stdin);

    if (is_spam(message)) {
        printf("This message contains spam words.\n");
    } else {
        printf("This message is clean.\n");
    }

    return 0;
}