//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter your password: ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Check for intrusion attempts
        if (strcmp(input, "password123") == 0) {
            printf("Access granted.\n");
            break;
        } else {
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Maximum attempts exceeded. Intrusion detected.\n");
        // Add code here to notify system administrator
        // or initiate security protocols
    }

    return 0;
}