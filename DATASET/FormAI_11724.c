//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DRONES 100
#define MAX_COMMANDS 200

// struct representing a drone
typedef struct drone {
    int id;
    float x;
    float y;
    float z;
} drone;

// struct representing a command
typedef struct command {
    int drone_id;
    char action[20];
    float value;
} command;

// function to generate random float number between min and max
float random_float(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

// function to simulate drone movement
void move_drone(drone* d, float x, float y, float z) {
    d->x += x;
    d->y += y;
    d->z += z;
}

// function to execute a single command on a drone
void execute_command(drone* d, command c) {
    if (c.action == "move_x") {
        move_drone(d, c.value, 0, 0);
    } else if (c.action == "move_y") {
        move_drone(d, 0, c.value, 0);
    } else if (c.action == "move_z") {
        move_drone(d, 0, 0, c.value);
    } else {
        printf("Unknown command %s for drone %d\n", c.action, c.drone_id);
    }
}

// function to execute a list of commands on multiple drones
void execute_commands(drone drones[], command cmds[], int num_drones, int num_cmds) {
    for (int i = 0; i < num_cmds; i++) {
        for (int j = 0; j < num_drones; j++) {
            if (cmds[i].drone_id == drones[j].id) {
                execute_command(&drones[j], cmds[i]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int num_drones = 5;
    int num_cmds = 10;
    drone drones[MAX_DRONES];
    command cmds[MAX_COMMANDS];
    
    // initialize drones
    for (int i = 0; i < num_drones; i++) {
        drones[i].id = i+1;
        drones[i].x = random_float(-100, 100);
        drones[i].y = random_float(-100, 100);
        drones[i].z = random_float(0, 50);
        printf("Drone %d initialized at (%.2f, %.2f, %.2f)\n", drones[i].id, drones[i].x, drones[i].y, drones[i].z);
    }

    // initialize commands
    for (int i = 0; i < num_cmds; i++) {
        cmds[i].drone_id = rand() % num_drones + 1;
        cmds[i].value = random_float(10, 20);
        int action = rand() % 3;
        if (action == 0) {
            sprintf(cmds[i].action, "move_x");
        } else if (action == 1) {
            sprintf(cmds[i].action, "move_y");
        } else {
            sprintf(cmds[i].action, "move_z");
        }
        printf("Command %d for drone %d: %s %.2f\n", i+1, cmds[i].drone_id, cmds[i].action, cmds[i].value);
    }

    // execute commands on drones
    execute_commands(drones, cmds, num_drones, num_cmds);

    // print final states of drones
    for (int i = 0; i < num_drones; i++) {
        printf("Drone %d final position: (%.2f, %.2f, %.2f)\n", drones[i].id, drones[i].x, drones[i].y, drones[i].z);
    }

    return 0;
}