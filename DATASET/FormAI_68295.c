//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Function to check if the input contains special characters
int contains_special_char(char* input) {
    int i;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        // Only allow alphabetical and space characters
        if (!(input[i] >= 'a' && input[i] <= 'z') &&
            !(input[i] >= 'A' && input[i] <= 'Z') &&
            !(input[i] == ' ')) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the input is an integer
int is_int(char* input) {
    int i;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        // Only allow numerical characters
        if (!(input[i] >= '0' && input[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main(void) {
    char buffer[MAX_BUFFER];
    int attempts = 0;

    printf("Welcome to the Intrusion Detection System! To proceed, please enter the password:\n");

    while (attempts < 3) {
        printf("> ");
        fgets(buffer, MAX_BUFFER, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline

        if (contains_special_char(buffer)) {
            printf("Error: Invalid characters detected. Please try again.\n");
        } else if (!is_int(buffer)) {
            printf("Error: Password must be a number. Please try again.\n");
        } else {
            int password = atoi(buffer);
            if (password == 1234) {
                printf("Access granted. Welcome, Lord!\n");
                break;
            } else {
                printf("Error: Incorrect password. Please try again.\n");
                attempts++;
            }
        }
    }

    if (attempts == 3) {
        printf("Intrusion detected. Guards, seize this fool!\n");
    }

    return 0;
}