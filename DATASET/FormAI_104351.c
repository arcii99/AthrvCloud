//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_COMMAND_LENGTH 50

struct Drone {
    int id;
    int battery_level;
    int altitude;
    char current_command[MAX_COMMAND_LENGTH];
};

struct Drones {
    int num_drones;
    struct Drone drones[MAX_DRONES];

    int current_drone_index;
};

void init_drones(struct Drones *drones) {
    drones->num_drones = 0;
    drones->current_drone_index = -1;
}

int add_drone(struct Drones *drones, int battery_level, int altitude) {
    if (drones->num_drones < MAX_DRONES) {
        drones->drones[drones->num_drones].id = drones->num_drones;
        drones->drones[drones->num_drones].battery_level = battery_level;
        drones->drones[drones->num_drones].altitude = altitude;
        return drones->num_drones++;
    } else {
        return -1;
    }
}

void select_drone(struct Drones *drones, int id) {
    for (int i = 0; i < drones->num_drones; i++) {
        if (drones->drones[i].id == id) {
            drones->current_drone_index = i;
            break;
        }
    }
}

void print_drone_status(struct Drones *drones) {
    printf("Current drone ID: %d\n", drones->drones[drones->current_drone_index].id);
    printf("Battery Level: %d\n", drones->drones[drones->current_drone_index].battery_level);
    printf("Altitude: %d\n", drones->drones[drones->current_drone_index].altitude);
    printf("Current Command: %s\n", drones->drones[drones->current_drone_index].current_command);
}

void issue_command(struct Drones *drones, char *command) {
    if (drones->current_drone_index >= 0) {
        // Check if command is valid
        if (strncmp(command, "takeoff", strlen("takeoff")) == 0) {
            drones->drones[drones->current_drone_index].altitude += 10;
            snprintf(drones->drones[drones->current_drone_index].current_command, MAX_COMMAND_LENGTH, "%s", command);
        } else if (strncmp(command, "land", strlen("land")) == 0) {
            drones->drones[drones->current_drone_index].altitude = 0;
            snprintf(drones->drones[drones->current_drone_index].current_command, MAX_COMMAND_LENGTH, "%s", command);
        } else if (strncmp(command, "move", strlen("move")) == 0) {
            int x, y, z;
            sscanf(command, "%*s %d %d %d", &x, &y, &z);
            printf("Moving drone %d from (%d, %d, %d) to (%d, %d, %d)\n", drones->drones[drones->current_drone_index].id, 0, 0, drones->drones[drones->current_drone_index].altitude, x, y, z);
            snprintf(drones->drones[drones->current_drone_index].current_command, MAX_COMMAND_LENGTH, "%s", command);
        } else {
            printf("Invalid command\n");
        }
    } else {
        printf("No drone selected\n");
    }
}

int main() {
    struct Drones drones;
    init_drones(&drones);

    int drone_id_1 = add_drone(&drones, 100, 0);
    int drone_id_2 = add_drone(&drones, 50, 50);

    select_drone(&drones, drone_id_1);
    issue_command(&drones, "takeoff");
    print_drone_status(&drones);
    issue_command(&drones, "move 10 20 30");
    print_drone_status(&drones);
    issue_command(&drones, "land");
    print_drone_status(&drones);

    select_drone(&drones, drone_id_2);
    issue_command(&drones, "takeoff");
    print_drone_status(&drones);
    issue_command(&drones, "move 5 5 10");
    print_drone_status(&drones);
    issue_command(&drones, "land");
    print_drone_status(&drones);

    return 0;
}