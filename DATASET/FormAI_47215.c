//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int green = 0; // Green light duration counter
    int red = 0; // Red light duration counter
    int yellow = 0; // Yellow light duration counter
    int timeLeft = 0; // Time left on current light
    int cycleCounter = 0; // Counter for number of cycles completed
    time_t t; // Set up random number generator seed
    srand((unsigned) time(&t));
    
    while (cycleCounter < 10) { // Run for 10 cycles
        int light = rand() % 3; // Choose random light
        switch (light) {
            case 0:
                printf("Green light!\n");
                green = 30; // Set green light duration
                timeLeft = green; // Set time left on current light
                while (timeLeft > 0) { // Loop until time is up
                    printf("%d seconds left...\n", timeLeft);
                    timeLeft--;
                    sleep(1); // Wait for one second
                }
                printf("Green light complete!\n\n");
                break;
            case 1:
                printf("Yellow light!\n");
                yellow = 5; // Set yellow light duration
                timeLeft = yellow; // Set time left on current light
                while (timeLeft > 0) { // Loop until time is up
                    printf("%d seconds left...\n", timeLeft);
                    timeLeft--;
                    sleep(1); // Wait for one second
                }
                printf("Yellow light complete!\n\n");
                break;
            case 2:
                printf("Red light!\n");
                red = 20; // Set red light duration
                timeLeft = red; // Set time left on current light
                while (timeLeft > 0) { // Loop until time is up
                    printf("%d seconds left...\n", timeLeft);
                    timeLeft--;
                    sleep(1); // Wait for one second
                }
                printf("Red light complete!\n\n");
                break;
        }
        cycleCounter++; // Increment cycle counter
    }
    
    printf("All cycles complete!"); // End message
    return 0;
}