//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int redTime = 30, yellowTime = 5, greenTime = 40;
    int timeCounter = 0;
    int currentLight = 1;   // 1 - Red, 2 - Yellow, 3 - Green
    int numCycles = 0;
    int maxNumCycles = 10;

    printf("Starting Traffic Light Controller...\n");
    
    while(numCycles < maxNumCycles) {
        printf("Cycle %d...\n", numCycles+1);
        
        // Set the timer to 0
        timeCounter = 0;

        while (timeCounter < greenTime) {
            if (currentLight == 1) {
                printf("Red Light ON\n");
            }
            else if (currentLight == 2) {
                printf("Yellow Light ON\n");
            }
            else if (currentLight == 3) {
                printf("Green Light ON\n");
            }

            timeCounter++;
            printf("Time Remaining: %d seconds\n", greenTime-timeCounter);
            
            // Generate random number to simulate cars passing by
            int numCars = generateRandomNumber(0, 20);
            printf("Number of Cars that Passed: %d\n", numCars);

            // If a car passed by during yellow light, extend the green light
            if (currentLight == 2 && numCars > 0) {
                printf("Extending Green Light by 10 seconds...\n");
                greenTime += 10;
            }

            printf("\n");
        }

        currentLight = 2;   // Set to yellow light
        timeCounter = 0;

        while (timeCounter < yellowTime) {
            printf("Yellow Light ON\n");
            timeCounter++;
            printf("Time Remaining: %d seconds\n", yellowTime-timeCounter);
            printf("\n");
        }

        currentLight = 3;   // Set to green light
        numCycles++;

        printf("\n");
    }

    printf("Traffic Light Controller Terminated!");
    return 0;
}