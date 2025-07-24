//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the possible drone commands
typedef enum {
    TAKE_OFF,
    LAND,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    TURN_LEFT,
    TURN_RIGHT,
    HOVER,
    EMERGENCY_STOP
} DroneCommand;

// Struct to hold the drone status
typedef struct {
    int battery_level;
    int altitude;
    int x_coord;
    int y_coord;
    int z_coord;
    int is_flying;
} DroneStatus;

// Function to execute a command on the drone
void execute_command(DroneCommand command, DroneStatus * status) {
    switch (command) {
        case TAKE_OFF:
            if (!status->is_flying) {
                printf("Taking off...\n");
                status->is_flying = 1;
                status->altitude = 10;
            } else {
                printf("Drone is already flying!\n");
            }
            break;
        case LAND:
            if (status->is_flying) {
                printf("Landing...\n");
                status->is_flying = 0;
                status->altitude = 0;
            } else {
                printf("Drone is already landed!\n");
            }
            break;
        case MOVE_FORWARD:
            if (status->is_flying) {
                printf("Moving forward...\n");
                status->x_coord += 1;
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case MOVE_BACKWARD:
            if (status->is_flying) {
                printf("Moving backward...\n");
                status->x_coord -= 1;
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case MOVE_LEFT:
            if (status->is_flying) {
                printf("Moving left...\n");
                status->y_coord += 1;
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case MOVE_RIGHT:
            if (status->is_flying) {
                printf("Moving right...\n");
                status->y_coord -= 1;
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case MOVE_UP:
            if (status->is_flying) {
                printf("Moving up...\n");
                status->z_coord += 1;
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case MOVE_DOWN:
            if (status->is_flying) {
                printf("Moving down...\n");
                status->z_coord -= 1;
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case TURN_LEFT:
            if (status->is_flying) {
                printf("Turning left...\n");
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case TURN_RIGHT:
            if (status->is_flying) {
                printf("Turning right...\n");
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case HOVER:
            if (status->is_flying) {
                printf("Hovering...\n");
            } else {
                printf("Drone is not flying!\n");
            }
            break;
        case EMERGENCY_STOP:
            printf("Emergency stop!\n");
            status->is_flying = 0;
            break;
        default:
            printf("Invalid command!\n");
            break;
    }
}

int main() {
    DroneStatus drone_status = {100, 0, 0, 0, 0, 0};

    printf("Welcome to the Drone Remote Control Program!\n");

    while (1) {
        // Display the available commands
        printf("Available commands: TAKE_OFF, LAND, MOVE_FORWARD, MOVE_BACKWARD, MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN, TURN_LEFT, TURN_RIGHT, HOVER, EMERGENCY_STOP\n");

        char input[20];
        printf("> ");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n"); // Remove \n from the input

        // Parse the command
        DroneCommand command = -1;
        if (strcmp(input, "TAKE_OFF") == 0) {
            command = TAKE_OFF;
        } else if (strcmp(input, "LAND") == 0) {
            command = LAND;
        } else if (strcmp(input, "MOVE_FORWARD") == 0) {
            command = MOVE_FORWARD;
        } else if (strcmp(input, "MOVE_BACKWARD") == 0) {
            command = MOVE_BACKWARD;
        } else if (strcmp(input, "MOVE_LEFT") == 0) {
            command = MOVE_LEFT;
        } else if (strcmp(input, "MOVE_RIGHT") == 0) {
            command = MOVE_RIGHT;
        } else if (strcmp(input, "MOVE_UP") == 0) {
            command = MOVE_UP;
        } else if (strcmp(input, "MOVE_DOWN") == 0) {
            command = MOVE_DOWN;
        } else if (strcmp(input, "TURN_LEFT") == 0) {
            command = TURN_LEFT;
        } else if (strcmp(input, "TURN_RIGHT") == 0) {
            command = TURN_RIGHT;
        } else if (strcmp(input, "HOVER") == 0) {
            command = HOVER;
        } else if (strcmp(input, "EMERGENCY_STOP") == 0) {
            command = EMERGENCY_STOP;
        } else {
            printf("Invalid command!\n");
            continue;
        }

        execute_command(command, &drone_status);

        // Print the drone status
        printf("Battery level: %d\n", drone_status.battery_level);
        printf("Altitude: %d\n", drone_status.altitude);
        printf("X coordinate: %d\n", drone_status.x_coord);
        printf("Y coordinate: %d\n", drone_status.y_coord);
        printf("Z coordinate: %d\n", drone_status.z_coord);
        printf("Flying: %d\n", drone_status.is_flying);
    }

    return 0;
}