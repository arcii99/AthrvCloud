//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_ROOMS 5
#define MAX_LIGHT_LEVEL 10

// Function to update light level in a particular room
void updateLightLevel(int roomNum, int lightLevel) {
    printf("Light level in room %d updated to %d\n", roomNum, lightLevel);
}

int main() {

    // Set up random seed
    srand(time(0));

    // Initialize light levels in each room to a random value between 0 and MAX_LIGHT_LEVEL
    int lightLevels[NUM_ROOMS];
    for(int i=0; i<NUM_ROOMS; i++) {
        lightLevels[i] = rand() % (MAX_LIGHT_LEVEL+1);
        printf("Light level in room %d initialized to %d\n", i+1, lightLevels[i]);
    }

    // Main control loop
    while(true) {

        // Check for user input
        char input[10];
        printf("\nEnter a room number (1-5) to change light level (0 to quit): ");
        fgets(input, 10, stdin);
        int roomNum = atoi(input);

        // Exit if user enters 0
        if(roomNum == 0) {
            printf("Exiting program...\n");
            break;
        }

        // Handle invalid input
        if(roomNum < 1 || roomNum > NUM_ROOMS) {
            printf("Invalid room number. Please enter a number between 1 and 5.\n");
            continue;
        }

        // Check for user request to increase or decrease light level
        printf("Enter '+' to increase, '-' to decrease: ");
        fgets(input, 10, stdin);
        char operation = input[0];

        // Handle invalid input
        if(operation != '+' && operation != '-') {
            printf("Invalid input. Please enter '+' or '-'.\n");
            continue;
        }

        // Determine new light level
        int newLightLevel;
        if(operation == '+') {
            newLightLevel = lightLevels[roomNum-1] + 1;
        } else {
            newLightLevel = lightLevels[roomNum-1] - 1;
        }

        // Handle light level going out of bounds
        if(newLightLevel < 0) {
            newLightLevel = 0;
        }
        if(newLightLevel > MAX_LIGHT_LEVEL) {
            newLightLevel = MAX_LIGHT_LEVEL;
        }

        // Update light level in specified room
        updateLightLevel(roomNum, newLightLevel);
        lightLevels[roomNum-1] = newLightLevel;
    }

    return 0;
}