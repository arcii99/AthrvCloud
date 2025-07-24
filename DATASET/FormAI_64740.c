//FormAI DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100     // Maximum length of a command
#define MAX_NUM_COMMANDS 10        // Maximum number of commands that can be stored in the history
#define MAX_HISTORY_LENGTH 1000    // Maximum length of the history

// Structure for storing commands in the history
typedef struct {
    int id;
    char command[MAX_COMMAND_LENGTH];
} Command;

int history_id = 0;             // ID counter for the history
int num_commands = 0;           // Number of commands stored in the history
Command history[MAX_NUM_COMMANDS];   // Array for storing the history

// Add a command to the history
void add_command_to_history(char* command) {
    if(num_commands == MAX_NUM_COMMANDS) {  // If the history is full, remove the oldest command
        for(int i = 0; i < MAX_NUM_COMMANDS - 1; i++) {
            history[i] = history[i+1];
        }
        num_commands--;
    }

    Command new_command;
    new_command.id = history_id++;
    strcpy(new_command.command, command);
    history[num_commands++] = new_command;
}

// Display the history
void display_history() {
    printf("Command history:\n");
    for(int i = 0; i < num_commands; i++) {
        printf("%d: %s\n", history[i].id, history[i].command);
    }
}

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char history_cmd[MAX_COMMAND_LENGTH];

    // Loop to accept and execute commands
    while(1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Check if the command is "history" and display the history if it is
        strcpy(history_cmd, "history\n");
        if(strcmp(command, history_cmd) == 0) {
            display_history();
            continue;   // Restart the main loop
        }

        add_command_to_history(command);    // Add the command to the history
        system(command);                   // Execute the command
    }

    return 0;
}