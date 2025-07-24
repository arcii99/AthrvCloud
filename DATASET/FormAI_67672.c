//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char input_buffer[MAX_BUFFER_SIZE];
    const char *restricted_command = "rm -rf /";
    const char *su_command = "su";

    printf("Welcome to the Intrusion Detection System.\n");

    while (true) {
        printf("$ ");

        fgets(input_buffer, MAX_BUFFER_SIZE, stdin);

        if (strstr(input_buffer, restricted_command) != NULL) {
            printf("Warning: Unauthorized access detected. System will be locked down.\n");
            // Code to lock down the system goes here
            exit(EXIT_FAILURE);
        }

        if (strstr(input_buffer, su_command) != NULL) {
            printf("Warning: Elevated privileges detected. Please verify your identity.\n");
            // Code to prompt for user password goes here
        }

        // Code to execute the command entered by the user goes here
    }

    return 0;
}