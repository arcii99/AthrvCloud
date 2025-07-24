//FormAI DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 10     // Maximum distance that the robot can move in one step
#define MOVE_DELAY 1000     // Delay between each movement in milliseconds
#define MIN_BATTERY 20      // Minimum battery percentage required to move
#define BATTERY_DRAIN 10    // Battery percentage drained with each movement
#define ACTION_DURATION 500 // Duration of each movement in milliseconds

// Function to simulate moving the robot forward
void move_forward(int distance, int *battery) {
    if (*battery >= MIN_BATTERY) {
        printf("Moving forward %d steps...\n", distance);
        *battery -= distance * BATTERY_DRAIN;
        printf("Battery remaining: %d%%\n", *battery);
        usleep(distance * ACTION_DURATION * 1000);
    } else {
        printf("Not enough battery to move. Please recharge.\n");
    }
}

// Function to simulate turning the robot left
void turn_left(int *battery) {
    if (*battery >= MIN_BATTERY) {
        printf("Turning left...\n");
        *battery -= BATTERY_DRAIN;
        printf("Battery remaining: %d%%\n", *battery);
        usleep(ACTION_DURATION * 1000);
    } else {
        printf("Not enough battery to turn. Please recharge.\n");
    }
}

// Function to simulate turning the robot right
void turn_right(int *battery) {
    if (*battery >= MIN_BATTERY) {
        printf("Turning right...\n");
        *battery -= BATTERY_DRAIN;
        printf("Battery remaining: %d%%\n", *battery);
        usleep(ACTION_DURATION * 1000);
    } else {
        printf("Not enough battery to turn. Please recharge.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int battery = 100;  // Starting battery percentage
    int total_distance = 0;

    // Move the robot around randomly until battery runs out
    while (battery > 0) {
        int distance = rand() % MAX_DISTANCE + 1;
        int direction = rand() % 3; // 0 = forward, 1 = left, 2 = right

        switch (direction) {
            case 0:
                move_forward(distance, &battery);
                total_distance += distance;
                break;
            case 1:
                turn_left(&battery);
                break;
            case 2:
                turn_right(&battery);
                break;
        }

        printf("\n");

        if (total_distance >= MAX_DISTANCE * 10) {
            printf("Reached maximum distance limit. Ending program.\n");
            break;
        }

        // Delay between each movement
        usleep(MOVE_DELAY * 1000);
    }

    printf("Battery drained. Total distance travelled: %d steps.\n", total_distance);

    return 0;
}