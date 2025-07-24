//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store the command information.
typedef struct command {
    char* instruction;   // the instruction string
    int distance;        // the distance to move
} command_t;

// Function to send the command to the drone via medieval messenger.
void sendCommand(command_t command) {
    printf("Sending a messenger with the following instructions: %s for a distance of %d leagues.\n", 
           command.instruction, command.distance);
}

int main() {
    // Array of commands to execute.
    command_t commands[3];

    // Fill in the command array.
    commands[0].instruction = "Take flight!";
    commands[0].distance = 10;

    commands[1].instruction = "Survey the land!";
    commands[1].distance = 20;

    commands[2].instruction = "Return to base!";
    commands[2].distance = 15;

    // Loop through the commands and send them.
    for (int i = 0; i < 3; i++) {
        sendCommand(commands[i]);
    }

    return 0;
}