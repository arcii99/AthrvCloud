//FormAI DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1
#define NUM_ROOMS 5

int main() {
    srand(time(NULL)); // seed for random number generator

    int room[NUM_ROOMS]; // array to store the state of each room's light

    // Initialize all rooms to be off
    for (int i = 0; i < NUM_ROOMS; i++) {
        room[i] = LIGHT_OFF;
    }

    // Print initial state of the rooms
    printf("Initial light state of the rooms: ");
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("%d ", room[i]);
    }
    printf("\n");

    // Control the lights
    for (int i = 0; i < 10; i++) { // perform 10 iterations
        // Choose a random room to toggle light
        int roomNum = rand() % NUM_ROOMS;

        // Toggle light of the randomly chosen room
        if (room[roomNum] == LIGHT_OFF) {
            room[roomNum] = LIGHT_ON;
        } else {
            room[roomNum] = LIGHT_OFF;
        }

        // Print the new state of the rooms
        printf("Iteration %d light state of the rooms: ", i+1);
        for (int j = 0; j < NUM_ROOMS; j++) {
            printf("%d ", room[j]);
        }
        printf("\n");
    }

    // Turn off all lights
    for (int i = 0; i < NUM_ROOMS; i++) {
        room[i] = LIGHT_OFF;
    }

    // Print final state of the rooms
    printf("Final light state of the rooms: ");
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("%d ", room[i]);
    }
    printf("\n");

    return 0;
}