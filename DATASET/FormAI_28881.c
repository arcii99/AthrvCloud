//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// This function checks if the given command is an intrusion attempt.
bool is_injection_attempt(char* input) {
    char* forbidden_commands[] = { "rm", "ls", "cd", "cat", "echo", "mkdir", "mv", "cp", "wget", "curl" };
    int num_forbidden_commands = sizeof(forbidden_commands) / sizeof(forbidden_commands[0]);
    for (int i = 0; i < num_forbidden_commands; i++) {
        if (strstr(input, forbidden_commands[i]) != NULL) {
            return true;
        }
    }
    return false;
}

// This function logs the input and whether or not it is an intrusion attempt.
void process_input(char* input) {
    bool intrusion_attempt = is_injection_attempt(input);
    FILE* fp = fopen("log.txt", "a");
    if (fp == NULL) {
        printf("Error: failed to open log file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s - Intrusion Attempt: %s\n", input, intrusion_attempt ? "YES" : "NO");
    printf("Input processed and logged.\n");
    fclose(fp);
}

int main(void) {
    char input[MAX_INPUT_LENGTH];
    printf("Intrusion Detection System\n");
    printf("Enter commands:\n");
    while (true) {
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (strlen(input) > 1 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0'; // Remove trailing newline from input
        }
        process_input(input);
    }
    return 0;
}