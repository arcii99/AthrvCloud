//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    int timeCount = 0; // Counter to keep track of time
    int greenTimer = 0; // Timer for green light
    int yellowTimer = 0; // Timer for yellow light
    int redTimer = 0; // Timer for red light
    int currentLight = 1; // 1 for green, 2 for yellow, 3 for red

    while (timeCount < 100) { // Loop for 100 seconds
        printf("Time: %d seconds\n", timeCount);

        if (currentLight == 1) { // Green light
            printf("Green Light\n");
            greenTimer++; // Increment green timer
            if (greenTimer >= 10) { // Green light for 10 seconds
                currentLight = 2; // Switch to yellow light
                greenTimer = 0; // Reset green timer
            }
        } 
        else if (currentLight == 2) { // Yellow light
            printf("Yellow Light\n");
            yellowTimer++; // Increment yellow timer
            if (yellowTimer >= 3) { // Yellow light for 3 seconds
                currentLight = 3; // Switch to red light
                yellowTimer = 0; // Reset yellow timer
            }
        } 
        else if (currentLight == 3) { // Red light
            printf("Red Light\n");
            redTimer++; // Increment red timer
            if (redTimer >= 10) { // Red light for 10 seconds
                currentLight = 1; // Switch to green light
                redTimer = 0; // Reset red timer
            }
        }

        printf("--------------------\n");
        timeCount++; // Increment counter
        int delay = rand() % 5; // Random delay between 0 and 4 seconds
        printf("Delay: %d seconds\n", delay);
        printf("--------------------\n");
        sleep(delay); // Delay for random amount of time
    }

    return 0; // End program
}