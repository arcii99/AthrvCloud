//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for drone control

const int TAKEOFF_ALTITUDE = 5;
const int MAX_ALTITUDE = 50;
const int MAX_SPEED = 20;
const int MAX_TURNING_ANGLE = 40;

// Define struct for drone control commands

typedef struct {
    int altitude;
    int speed;
    int heading;
} DroneCommand;

// Define function to parse command string into DroneCommand struct

DroneCommand parseCommand(char* commandString) {
    DroneCommand command;
    char* token = strtok(commandString, " ");
    while (token != NULL) {
        if (strncmp(token, "altitude=", strlen("altitude=")) == 0) {
            command.altitude = atoi(token + strlen("altitude="));
        } else if (strncmp(token, "speed=", strlen("speed=")) == 0) {
            command.speed = atoi(token + strlen("speed="));
        } else if (strncmp(token, "heading=", strlen("heading=")) == 0) {
            command.heading = atoi(token + strlen("heading="));
        }
        token = strtok(NULL, " ");
    }
    return command;
}

// Define function to validate DroneCommand struct

int validateCommand(DroneCommand command) {
    if (command.altitude < TAKEOFF_ALTITUDE || command.altitude > MAX_ALTITUDE) {
        return 0;
    }
    if (command.speed < 0 || command.speed > MAX_SPEED) {
        return 0;
    }
    if (command.heading < -MAX_TURNING_ANGLE || command.heading > MAX_TURNING_ANGLE) {
        return 0;
    }
    return 1;
}

// Define main function

int main() {
    printf("Welcome to the C Drone Remote Control!\n");
    printf("Please enter the control commands in the format altitude=<altitude> speed=<speed> heading=<heading> (separated by spaces)\n");
    printf("Enter 'exit' to quit.\n\n");

    // Invoke main control loop

    char input[100];
    while (strncmp(input, "exit", strlen("exit")) != 0) {

        // Read command from user

        printf("> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strncmp(input, "exit", strlen("exit")) == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Parse and validate command

        DroneCommand command = parseCommand(input);
        int isValid = validateCommand(command);

        // Execute command or report error

        if (isValid) {
            printf("Command accepted: altitude=%d speed=%d heading=%d\n", command.altitude, command.speed, command.heading);
            // TODO: Implement drone control code here
        } else {
            printf("Invalid command format. Please enter the commands in the format altitude=<altitude> speed=<speed> heading=<heading>\n\n");
        }
    }
    return 0;
}