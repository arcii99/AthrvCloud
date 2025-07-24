//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* This program simulates an Intrusion Detection System (IDS) */

/* Function to check if a string contains a specific word */
int string_contains_word(char* str, char* word) {
    char* token = strtok(str, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Welcome to the Intrusion Detection System.\n");
    printf("Enter your username: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    /* Check for user login attempts */
    if (string_contains_word(buffer, "login") || string_contains_word(buffer, "log in") || string_contains_word(buffer, "signin")) {
        printf("User login attempt detected. Please enter your password: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        /* Check for password attempts */
        if (string_contains_word(buffer, "password") || string_contains_word(buffer, "pass") || string_contains_word(buffer, "secret")) {
            printf("Password attempt detected. Access denied.\n");
            exit(1);
        }
    }

    /* Check for system commands */
    if (string_contains_word(buffer, "rm") || string_contains_word(buffer, "shutdown") || string_contains_word(buffer, "halt") || string_contains_word(buffer, "reboot")) {
        printf("System command detected. Access denied.\n");
        exit(1);
    }

    printf("No suspicious activity detected. Have a nice day!\n");

    return 0;
}