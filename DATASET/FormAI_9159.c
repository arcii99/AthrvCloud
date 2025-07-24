//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_COUNT 5
#define MAX_MESSAGE_LENGTH 100

char spamList[MAX_SPAM_COUNT][MAX_MESSAGE_LENGTH] = {"buy now", "limited offer", "make money fast", "amazing deal", "you have won!"};

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int spamCount = 0;

    // Prompt user to enter message
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Check if message contains any spam words
    for (int i = 0; i < MAX_SPAM_COUNT; i++) {
        if (strstr(message, spamList[i]) != NULL) {
            spamCount++;
        }
    }

    // Determine if message is spam or not
    if (spamCount >= 3) {
        printf("This message is SPAM!\n");
    } else {
        printf("This message is NOT spam.\n");
    }

    return 0;
}