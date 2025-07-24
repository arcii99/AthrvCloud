//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int i, j, count = 0;

    printf("********************************************************\n");
    printf("**** Welcome to the Spam Detection System ****\n");
    printf("********************************************************\n\n");

    while (1) {
        printf("Enter your message (or type 'exit' to finish): ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);

        if (strcmp(message, "exit\n") == 0) {
            break;
        }

        for (i = 0; i < strlen(message); i++) {
            if (message[i] == 'c') {
                for (j = i; j < strlen(message) && j < i + 3; j++) {
                    if (message[j] != 'c') {
                        break;
                    }
                }
                if (j - i == 3) {
                    count++;
                    printf("Potential spam detected in the following message: %s", message);
                    printf("The letters 'c' appear consecutively more than twice.\n");
                    break;
                }
            }
        }
    }

    if (count == 0) {
        printf("No potential spam detected.\n");
    } else {
        printf("%d potential spam message(s) detected.\n", count);
    }

    printf("\nThank you for using our Spam Detection System.\n");

    return 0;
}