//FormAI DATASET v1.0 Category: System administration ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of the command line input
#define MAX_INPUT_LENGTH 100

// Define a struct for storing command configurations
typedef struct {
    char* command_name;
    int (*command_function_ptr)();
} command_config;

// Define function prototypes
int command_help();
int command_time();
int command_exit();

// Define an array of command configurations
command_config command_configs[] = {
    {"help", command_help},
    {"time", command_time},
    {"exit", command_exit}
};

// Define the number of available commands
const int NUM_COMMANDS = sizeof(command_configs) / sizeof(command_config);

int main() {
    char input[MAX_INPUT_LENGTH];

    // Print out the available commands
    printf("Welcome to the system administration program.\n");
    printf("Available commands:\n");

    for (int i = 0; i < NUM_COMMANDS; ++i) {
        printf("- %s\n", command_configs[i].command_name);
    }

    printf("Type 'help' for more information.\n");

    // Enter an infinite loop for accepting and processing user input
    while (1) {
        // Prompt the user for input and read in the input
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Strip newline character from input
        input[strcspn(input, "\n")] = 0;

        // Convert input to lowercase for case-insensitive comparison
        for (int i = 0; input[i]; ++i) {
            input[i] = tolower(input[i]);
        }

        // Search for a matching command configuration
        int command_found = 0;
        for (int i = 0; i < NUM_COMMANDS; ++i) {
            if (strcmp(input, command_configs[i].command_name) == 0) {
                command_configs[i].command_function_ptr();
                command_found = 1;
                break;
            }
        }

        // If no matching command configuration was found, print an error message
        if (!command_found) {
            printf("Unknown command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}

// Define the command functions
int command_help() {
    printf("Available commands:\n");

    for (int i = 0; i < NUM_COMMANDS; ++i) {
        printf("- %s\n", command_configs[i].command_name);
    }

    return 0;
}

int command_time() {
    system("date");
    return 0;
}

int command_exit() {
    printf("Goodbye!\n");
    exit(0);
}