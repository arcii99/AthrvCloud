//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int count = 0;

    // Prompt the user to enter a message
    printf("Enter the message:\n");
    fgets(message, sizeof(message), stdin);

    // Check for spam keywords
    if (strstr(message, "buy now") != NULL || strstr(message, "discount") != NULL || strstr(message, "limited time offer") != NULL) {
        printf("This message is spam.\n");
        return 0;
    }

    // Count the number of exclamation marks
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '!') {
            count++;
        }
    }

    // Check if there are too many exclamation marks
    if (count > 5) {
        printf("This message is spam.\n");
        return 0;
    }

    // Check if the message is all uppercase
    int isAllUpperCase = 1;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            isAllUpperCase = 0;
            break;
        }
    }

    if (isAllUpperCase) {
        printf("This message is spam.\n");
        return 0;
    }

    // If none of the above conditions are met, the message is not spam
    printf("This message is not spam.\n");
    return 0;
}