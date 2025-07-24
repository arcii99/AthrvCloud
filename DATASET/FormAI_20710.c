//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 500
#define NUM_OF_LANES 3

// Function to generate random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to move car forward in a lane
void moveCarForward(int lane[], int index) {
    if (index > 0) {
        lane[index] = lane[index - 1];
    }
}

int main() {

    // Initialize random seed
    srand(time(NULL));

    // Initialize variables
    int carCount = 0;
    int traffic[MAX_TIME][NUM_OF_LANES] = {0};
    
    // Simulate traffic flow for each time interval
    for (int time = 0; time < MAX_TIME; time++) {
        
        // Generate new cars with random gap between them
        if (generateRandomNumber(0, 1)) {
            for (int i = 0; i < NUM_OF_LANES; i++) {
                if (traffic[time][i] == 0 && carCount < MAX_CARS) {
                    traffic[time][i] = ++carCount;
                    if (carCount < MAX_CARS) {
                        time += generateRandomNumber(1, 3);
                    }
                }
            }
        }
        
        // Move existing cars forward in each lane
        for (int i = 0; i < NUM_OF_LANES; i++) {
            for (int j = 0; j < MAX_TIME - 1; j++) {
                moveCarForward(traffic[j + 1], i);
            }
        }
        
        // Print the current traffic flow for each lane
        printf("Time %d:\n", time);
        for (int i = 0; i < NUM_OF_LANES; i++) {
            for (int j = 0; j < MAX_TIME; j++) {
                if (traffic[j][i] == 0) {
                    printf("  | ");
                } else {
                    printf("%2d| ", traffic[j][i]);
                }
            }
            printf("\n");
        }
        printf("\n");
        
    }

    return 0;
}