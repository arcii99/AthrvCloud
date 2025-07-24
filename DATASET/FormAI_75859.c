//FormAI DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 200

int main() {
    char message[MAX_MESSAGE_LENGTH];

    printf("*** Welcome to the Happy Spam Detection System! ***\n\n");

    while (1) {
        printf("Enter a message (type 'quit' to exit): ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);

        if (strcmp(message, "quit\n") == 0) {
            printf("\nGoodbye! Thanks for using the Happy Spam Detection System.\n");
            return 0;
        }

        int spam_count = 0;
        int message_len = strlen(message);

        for (int i = 0; i < message_len - 3; i++) {
            if ((message[i] == 's' || message[i] == 'S') && message[i+1] == 'p' && message[i+2] == 'a' && message[i+3] == 'm') {
                spam_count++;
                i += 3;
            }
        }

        if (spam_count == 0) {
            printf("This message is not spam! It brings joy to the world :)\n");
        } else {
            printf("Sorry, this message is spam! It brings nothing but sadness :(\n");
        }
    }

    return 0;
}