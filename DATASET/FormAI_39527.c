//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DRONES 10
#define MAX_COMMAND_LEN 20

typedef struct {
    int id;
    char commands[MAX_COMMAND_LEN];
} Drone;

Drone drone_array[NUM_DRONES];

void initialize_drones() {
    for (int i = 0; i < NUM_DRONES; i++) {
        drone_array[i].id = i + 1;
        strcpy(drone_array[i].commands, "standby");
    }
}

void print_drone_status() {
    printf("Drone Status:\n");
    for (int i = 0; i < NUM_DRONES; i++) {
        printf("Drone ID: %d | Current Command: %s\n", drone_array[i].id, drone_array[i].commands);
    }
}

void execute_command(int id, char* command) {
    printf("Executing command '%s' for drone ID %d...\n", command, id);
    for (int i = 0; i < NUM_DRONES; i++) {
        if (drone_array[i].id == id) {
            strcpy(drone_array[i].commands, command);
            printf("Command executed! New drone status:\n");
            print_drone_status();
            return;
        }
    }
    printf("ERROR: Drone ID not found.\n");
}

int main() {
    initialize_drones();
    printf("Welcome to the post-apocalyptic drone control system.\n");
    printf("Initializing %d drones...\n", NUM_DRONES);
    print_drone_status();
    
    while (1) {
        int id;
        char command[MAX_COMMAND_LEN];
        printf("\nEnter drone ID: ");
        scanf("%d", &id);
        printf("Enter command (standby, patrol, gather, attack): ");
        scanf("%s", command);
        execute_command(id, command);
    }
    
    return 0;
}