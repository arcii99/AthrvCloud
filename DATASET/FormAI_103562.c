//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    // define starting coordinates for GPS
    float x=0.0, y=0.0;
    char direction;
    int distance;
    char next;

    // program intro
    printf("Welcome to GPS Navigation Simulation!\n");

    // start navigation loop
    while (1) {
        // get next instruction
        printf("Enter next direction (N/S/E/W): ");
        scanf(" %c", &direction);
        printf("Enter distance (in km): ");
        scanf("%d", &distance);

        // update coordinates based on direction and distance
        switch (direction) {
            case 'N': y += distance; break;
            case 'S': y -= distance; break;
            case 'E': x += distance; break;
            case 'W': x -= distance; break;
            default: printf("Invalid direction!\n"); break;
        }

        // output new coordinates
        printf("New coordinates: (%.2f,%.2f)\n", x, y);

        // ask if user wants to input another instruction
        printf("Do you want to enter another instruction? (Y/N): ");
        scanf(" %c", &next);

        // exit if user doesn't want to input another instruction
        if (next == 'N') {
            printf("Exiting GPS Navigation Simulation...\n");
            exit(0);
        }
    }

    return 0;
}