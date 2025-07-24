//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

#define MAX_DRONES 10
#define MAX_COMMANDS 100

typedef struct {
    // drone data
    float x;
    float y;
    float z;
    float rotation;

    // drone status
    bool is_flying;
    bool is_connected;
} Drone;

typedef struct {
    // command data
    int drone_id;
    char command[20];
    float target_x;
    float target_y;
    float target_z;

    // command status
    bool is_complete;
} Command;

int main() {
    Drone drones[MAX_DRONES];
    Command commands[MAX_COMMANDS];

    // initialize drones
    for (int i = 0; i < MAX_DRONES; i++) {
        drones[i].is_connected = false;
        drones[i].is_flying = false;
    }

    // initialize commands
    for (int i = 0; i < MAX_COMMANDS; i++) {
        commands[i].is_complete = false;
    }

    // connect drones
    for (int i = 0; i < MAX_DRONES; i++) {
        drones[i].is_connected = true;
        printf("Drone %d connected\n", i+1);
    }

    // generate commands
    commands[0].drone_id = 1;
    strcpy(commands[0].command, "takeoff");
    commands[0].target_x = 10;
    commands[0].target_y = 20;
    commands[0].target_z = 5;

    commands[1].drone_id = 2;
    strcpy(commands[1].command, "move");
    commands[1].target_x = -5;
    commands[1].target_y = 10;
    commands[1].target_z = 2;

    // execute commands
    for (int i = 0; i < MAX_COMMANDS; i++) {
        Command current_command = commands[i];
        Drone current_drone = drones[current_command.drone_id - 1];

        // check if command is for a valid drone
        if (!current_drone.is_connected) {
            printf("Command skipped for drone %d - drone is not connected.\n", current_command.drone_id);
            continue;
        }

        // execute command
        if (strcmp(current_command.command, "takeoff") == 0) {
            current_drone.is_flying = true;
            printf("Drone %d has taken off.\n", current_command.drone_id);
        } else if (strcmp(current_command.command, "move") == 0) {
            // simulate drone movement
            current_drone.x += current_command.target_x;
            current_drone.y += current_command.target_y;
            current_drone.z += current_command.target_z;
            printf("Drone %d has moved to (%.2f, %.2f, %.2f).\n", current_command.drone_id, current_drone.x, current_drone.y, current_drone.z);
        } else {
            printf("Invalid command for drone %d.\n", current_command.drone_id);
            continue;
        }

        // mark command as complete
        commands[i].is_complete = true;
    }

    // print status
    printf("\n===== DRONE STATUS =====\n");
    for (int i = 0; i < MAX_DRONES; i++) {
        Drone current_drone = drones[i];
        printf("Drone %d - x: %.2f, y: %.2f, z: %.2f, rotation: %.2f, status: %s and %s\n", i+1, current_drone.x, current_drone.y, current_drone.z, current_drone.rotation, (current_drone.is_flying ? "flying" : "not flying"), (current_drone.is_connected ? "connected" : "not connected"));
    }
    printf("\n===== COMMAND STATUS =====\n");
    for (int i = 0; i < MAX_COMMANDS; i++) {
        Command current_command = commands[i];
        printf("Command %d - for drone %d, %s to (%.2f, %.2f, %.2f), status: %s\n", i+1, current_command.drone_id, current_command.command, current_command.target_x, current_command.target_y, current_command.target_z, (current_command.is_complete ? "complete" : "incomplete"));
    }

    return 0;
}