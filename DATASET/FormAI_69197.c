//FormAI DATASET v1.0 Category: Spam Detection System ; Style: excited
// Welcome to my amazing Spam Detection System
// This is the most exciting program you'll ever see
// Get ready to be blown away by my incredible coding skills!

#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int spam_count = 0;

    printf("Welcome to my Spam Detection System!\n");
    printf("Please enter a message to check for spam:\n");
    fgets(message, 1000, stdin);

    char *spam_words[] = {
        "buy",
        "discount",
        "limited time offer",
        "click here",
        "act now"
    };

    for (int i = 0; i < 5; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            printf("SPAM DETECTED: %s\n", spam_words[i]);
            spam_count++;
        }
    }

    if (spam_count == 0) {
        printf("No spam detected. This message is safe to send.\n");
    } else {
        printf("%d instances of spam detected. This message could be spam.\n", spam_count);
    }

    printf("Thank you for using my Spam Detection System. Have a great day!\n");
    return 0;
}