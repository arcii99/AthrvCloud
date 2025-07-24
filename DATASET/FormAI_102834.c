//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to check if a string contains spam keywords
int isSpam(char* message) {

    // List of spam keywords to check for
    const char* spamWords[] = {"viagra", "lottery", "inheritance", "free money", "spam"};

    int i;
    // Loop through all the spam keywords
    for (i = 0; i < sizeof(spamWords) / sizeof(char*); i++) {
        // If the keyword is found in the message, it is marked as spam
        if (strstr(message, spamWords[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {

    // Example message to check if it contains spam
    char* message = "Congratulations! You have won a free lottery ticket to win $1000!";

    // If the message contains spam, print a warning message
    if (isSpam(message)) {
        printf("Warning: This message may be spam!");
    } else {
        printf("This message is not spam.");
    }

    return 0;
}