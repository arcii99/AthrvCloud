//FormAI DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <string.h>

int checkForSpam(char *message) {
    int count = 0;
    char *spamWords[10] = {"buy", "sale", "limited time offer", "discount", "earn money fast",
                           "click here", "subscribe now", "money back guarantee", "amazing",
                           "free gift"};

    for (int i = 0; i < 10; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            count++;
        }
    }

    if (count >= 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, 100, stdin);

    if (checkForSpam(message) == 1) {
        printf("This message contains spam!");
    } else {
        printf("This message is not spam.");
    }

    return 0;
}