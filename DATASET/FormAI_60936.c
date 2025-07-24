//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void) {
    char message[MAX_LENGTH];
    int i, j, k;

    printf("Enter your message: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character from message

    // Convert message to all uppercase
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <='z') {
            message[i] = message[i] - 32;
        }
    }

    // Encrypt message
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + ((message[i] - 'A' + 13) % 26);
        }
    }

    // Print encrypted message in retro style
    printf("+");
    for (k = 0; k < strlen(message) + 2; k++) {
        printf("-");
    }
    printf("+\n");

    printf("| ");
    for (k = 0; k < strlen(message); k++) {
        printf("%c ", message[k]);
    }
    printf("|\n");

    printf("+");
    for (k = 0; k < strlen(message) + 2; k++) {
        printf("-");
    }
    printf("+\n");

    return 0;
}