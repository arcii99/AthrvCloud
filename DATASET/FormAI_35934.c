//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the possible commands
#define UP "up"
#define DOWN "down"
#define LEFT "left"
#define RIGHT "right"
#define STOP "stop"
#define LAND "land"

// Define the maximum length of a command
#define MAX_COMMAND_LENGTH 5

// Define the maximum number of commands in a sequence
#define MAX_COMMANDS 10

// Define the battery level at which the drone needs to return home
#define BATTERY_THRESHOLD 20

// Define the maximum altitude the drone can reach
#define MAX_ALTITUDE 100

// Define the maximum distance the drone can travel
#define MAX_DISTANCE 100

// Define the initial battery level
int batteryLevel = 100;

// Define the current altitude
int altitude = 0;

// Define the current position
int posX = 0;
int posY = 0;

// Define the function to check if two strings are equal
bool streq(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

// Define the function to process a single command
void processCommand(char *command) {
    if (streq(command, UP)) {
        if (altitude < MAX_ALTITUDE) {
            altitude++;
        }
    } else if (streq(command, DOWN)) {
        if (altitude > 0) {
            altitude--;
        }
    } else if (streq(command, LEFT)) {
        if (posX > -MAX_DISTANCE) {
            posX--;
        }
    } else if (streq(command, RIGHT)) {
        if (posX < MAX_DISTANCE) {
            posX++;
        }
    } else if (streq(command, STOP)) {
        // Do nothing
    } else if (streq(command, LAND)) {
        altitude = 0;
    } else {
        printf("Invalid command: %s\n", command);
    }
}

// Define the main function
int main() {
    // Define the command buffer
    char command[MAX_COMMAND_LENGTH + 1];

    // Define the sequence of commands
    char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH + 1];
    int numCommands = 0;

    printf("Drone ready. Battery level: %d%%\n", batteryLevel);

    // Run forever
    while (true) {
        // Read a new command
        printf("> ");
        if (!fgets(command, MAX_COMMAND_LENGTH + 1, stdin)) {
            break;
        }

        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        // Add the command to the sequence
        if (numCommands < MAX_COMMANDS && strlen(command) > 0) {
            strcpy(commands[numCommands], command);
            numCommands++;
        }

        // Process the commands in the sequence
        for (int i = 0; i < numCommands; i++) {
            processCommand(commands[i]);
        }

        // Check the battery level
        if (batteryLevel < BATTERY_THRESHOLD) {
            printf("Low battery! Returning home...\n");
            altitude = 0;
            posX = 0;
            posY = 0;
        }

        // Print the status of the drone
        printf("Altitude: %d\nPosition: (%d, %d)\n", altitude, posX, posY);
        printf("Battery level: %d%%\n", batteryLevel);

        // Decrease the battery level
        batteryLevel--;

        // Pause for one second
        sleep(1);
    }

    return 0;
}