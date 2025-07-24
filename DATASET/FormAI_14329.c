//FormAI DATASET v1.0 Category: Spam Detection System ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to check for spam keywords in message
int is_spam(char *message) {
    char keywords[][20] = {"win", "free", "money", "lottery", "prize", "cash", "offer"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strstr(message, keywords[i]) != NULL) {
            return 1; // Message contains a spam keyword
        }
    }

    return 0; // Message does not contain any spam keywords
}

int main() {
    char message[100];

    printf("Welcome to the Spam Detection System!\n");
    printf("Enter your message:\n");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message)) {
        printf("This message has been identified as spam. Please do not send spam messages.\n");
    } else {
        printf("This message is not spam. Thank you for using our service!\n");
    }

    return 0;
}