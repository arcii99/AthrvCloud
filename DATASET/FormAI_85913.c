//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#define MAX_MSG_LENGTH 100

int main() {
    char inputMsg[MAX_MSG_LENGTH], spamWords[10][10] = {"viagra", "free", "win", "prize", "lottery", "enlargement", "discount", "offer", "money", "cash"};
    int i, j, msgLength, numSpamWords = 0;

    printf("Enter the message to be checked for spam:\n");
    fgets(inputMsg, sizeof(inputMsg), stdin);

    // Remove newline character from input
    if ((msgLength = strlen(inputMsg)) > 0 && inputMsg[msgLength-1] == '\n') {
        inputMsg[msgLength-1] = '\0';
        msgLength--;
    }

    // Convert message to lowercase for easier comparison
    for (i = 0; i < msgLength; i++) {
        inputMsg[i] = tolower(inputMsg[i]);
    }

    // Scan message for spam words
    for (i = 0; i < numSpamWords; i++) {
        if (strstr(inputMsg, spamWords[i]) != NULL) {
            printf("This message contains spam.\n");
            return 0;
        }
    }

    printf("This message is not spam.\n");
    return 0;
}