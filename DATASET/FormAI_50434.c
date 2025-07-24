//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MAX_ANGLE 360

typedef struct {
    int speed;
    int angle;
} Drone_Commands;

bool validate_speed(int speed) {
    if(speed < 0 || speed > MAX_SPEED) {
        return false;
    }
    return true;
}

bool validate_angle(int angle) {
    if(angle < 0 || angle > MAX_ANGLE) {
        return false;
    }
    return true;
}

void execute_command(Drone_Commands commands) {
    if(validate_speed(commands.speed) && validate_angle(commands.angle)) {
        printf("Executing command: speed=%d, angle=%d\n", commands.speed, commands.angle);
    } else {
        printf("Invalid command: speed=%d, angle=%d\n", commands.speed, commands.angle);
    }
}

int main() {
    Drone_Commands command_list[] = {
        {50, 180},
        {25, 270},
        {100, 90},
        {-10, 360},
        {75, -45},
        {0, 1000}
    };
    int num_commands = sizeof(command_list) / sizeof(command_list[0]);
    
    for(int i = 0; i < num_commands; i++) {
        execute_command(command_list[i]);
    }
    return 0;
}