//FormAI DATASET v1.0 Category: Browser Plugin ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for plugin data
#define PLUGIN_NAME "ExamplePlugin"
#define PLUGIN_AUTHOR "John Doe"

// define function to display plugin info
void display_plugin_info() {
    printf("Plugin Name: %s\n", PLUGIN_NAME);
    printf("Plugin Author: %s\n", PLUGIN_AUTHOR);
}

// define function to perform plugin action
void perform_plugin_action() {
    printf("Plugin Action Performed!\n");
}

// define function to handle plugin commands
void handle_plugin_command(char* command) {
    if(strcmp(command, "info") == 0) {
        display_plugin_info();
    } else if(strcmp(command, "action") == 0) {
        perform_plugin_action();
    } else {
        printf("Invalid command entered.\n");
    }
}

// define main function
int main() {
    // welcome message
    printf("Welcome to the Example Browser Plugin!\n");

    // get user input
    char command[20];
    printf("Enter a command (info or action): ");
    scanf("%s", command);

    // handle user command
    handle_plugin_command(command);

    return 0;
}