//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_LOG_SIZE 100

int main() {

    char input[MAX_INPUT_SIZE];
    char log[MAX_LOG_SIZE][MAX_INPUT_SIZE];
    int log_cnt = 0;

    printf("Welcome to the Intrusion Detection System\n");
    printf("Please enter commands:\n");

    while(1) {

        // Get user input
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Check for command
        if (strncmp(input, "login", 5) == 0) {
            printf("Logging in...\n");
            strcpy(log[log_cnt++], input);
        } else if (strncmp(input, "logout", 6) == 0) {
            printf("Logging out...\n");
            strcpy(log[log_cnt++], input);
        } else if (strncmp(input, "view log", 8) == 0) {
            printf("Viewing log...\n");
            for (int i = 0; i < log_cnt; i++) {
                printf("%s", log[i]);
            }
        } else if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}