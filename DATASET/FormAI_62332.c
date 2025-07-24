//FormAI DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100

void processMessage(char* message);

int spam_message_count = 0;
char* spam_messages[MAX_MESSAGES];

int main() {
    char message[256];

    printf("Enter a message: ");
    fgets(message, 256, stdin);

    // Process the message
    processMessage(message);

    // Check if the message is spam
    if (spam_message_count > 0) {
        printf("\n\nWARNING: This message is likely spam!\n");
        printf("Possible spam messages:\n");
        for (int i = 0; i < spam_message_count; i++) {
            printf("- %s\n", spam_messages[i]);
        }
    } else {
        printf("\n\nThis message is not spam.\n");
    }

    return 0;
}

// Processes a message to determine if it is spam
void processMessage(char* message) {
    char delimiters[] = " \n\t.,?!-";
    char* word = strtok(message, delimiters);

    while (word != NULL && spam_message_count < MAX_MESSAGES) {
        // Check if the word is in the list of spam words
        if (strstr(word, "viagra") || strstr(word, "cialis") || strstr(word, "bonus")) {
            spam_messages[spam_message_count] = word;
            spam_message_count++;
        }

        // Get the next word in the message
        word = strtok(NULL, delimiters);
    }
}