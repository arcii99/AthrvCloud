//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    int spam_count = 0;

    const char *spam_keywords[] = {"money", "free", "claim", "click here", "limited time offer"};

    char message[1000];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character at the end of the message
    message[strcspn(message, "\n")] = '\0';

    // Convert the message to lowercase to make it case-insensitive
    for (int i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }

    // Check if the message contains any spam keywords
    for (int i = 0; i < sizeof(spam_keywords) / sizeof(spam_keywords[0]); i++) {
        if (strstr(message, spam_keywords[i])) {
            printf("This message contains the spam keyword '%s'\n", spam_keywords[i]);
            spam_count++;
        }
    }

    if (spam_count == 0) {
        printf("This message is not spam.\n");
    } else {
        printf("This message is spam!\n");
    }

    return 0;
}