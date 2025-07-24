//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 50
#define MAX_COMMANDS 5

int main() {
    char input[MAX_INPUT];
    char commands[MAX_COMMANDS][MAX_INPUT] = {"up", "down", "left", "right", "stop"};
    int current_direction = -1;

    printf("Welcome to C Drone Remote Control\n");
    printf("Commands Available: up, down, left, right, stop\n");

    while(true) {
        printf("Enter a command: ");
        fgets(input, MAX_INPUT, stdin);
        strtok(input, "\n"); // remove new line character

        // check if input matches a command
        int i;
        for(i = 0; i < MAX_COMMANDS; i++) {
            if(strcmp(input, commands[i]) == 0) {
                break;
            }
        }

        if(i != MAX_COMMANDS) {
            // command found
            if(i != current_direction) {
                // drone is changing direction
                if(current_direction != -1) {
                    printf("Drone stopped.\n");
                }
                printf("Drone is now going %s.\n", commands[i]);
                current_direction = i;
            }
            else if(i == MAX_COMMANDS - 1) {
                // stop command entered
                printf("Drone stopped.\n");
                current_direction = -1;
            }
            else {
                // drone is continuing in same direction
                printf("Drone is already going %s.\n", commands[i]);
            }
        }
        else {
            printf("Invalid command entered. Try again.\n");
        }
    }
    return 0;
}