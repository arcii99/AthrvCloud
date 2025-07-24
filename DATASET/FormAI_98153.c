//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>

// Function to check if the command is valid
int validateCommand(char input[]) {
    if (strcmp(input, "takeoff") == 0 || strcmp(input, "land") == 0 || strcmp(input, "up") == 0 || strcmp(input, "down") == 0 || strcmp(input, "left") == 0 || strcmp(input, "right") == 0 || strcmp(input, "forward") == 0 || strcmp(input, "back") == 0 || strcmp(input, "rotate") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to execute the command
void executeCommand(char input[]) {
    printf("Executing command: %s\n", input);
    // code to control drone goes here...
}

int main() {
    char command[10];
    int validCommand;
    
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Commands available: takeoff, land, up, down, left, right, forward, back, rotate\n");
    
    while (1) {
        printf("Enter a command: ");
        fgets(command, 10, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline character
        
        validCommand = validateCommand(command);
        
        if (validCommand) {
            executeCommand(command);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}