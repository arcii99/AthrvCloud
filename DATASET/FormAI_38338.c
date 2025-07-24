//FormAI DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <string.h>

// Function to determine if a message contains spam
int isSpam(char* message) {
    // List of keywords commonly used in spam messages
    char* spamWords[] = {"money", "free", "win", "prize", "lottery", "cash", "discount", "sale", "offer", "credit"};

    int numSpamWords = sizeof(spamWords) / sizeof(char*);
    int i;

    // Check if message contains any of the spam keywords
    for(i = 0; i < numSpamWords; i++) {
        if(strstr(message, spamWords[i])) {
            return 1; // Return positive if spam keyword found
        }
    }

    return 0; // Return negative if no spam keyword found
}

int main() {
    char message[1000];

    // Loop to repeatedly prompt user for input and check if message contains spam
    while(1) {
        printf("Enter message:\n");
        scanf("%[^\n]", message);
        getchar(); // Clear input buffer

        if(isSpam(message)) {
            printf("Message contains spam!\n");
        } else {
            printf("Message is clean.\n");
        }
    }

    return 0;
}