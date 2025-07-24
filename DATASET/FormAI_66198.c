//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to display the current state of the traffic light
void displayState(int red, int yellow, int green) {
    printf("Red light: %d\n", red);
    printf("Yellow light: %d\n", yellow);
    printf("Green light: %d\n", green);
}

int main() {
    int red = 10; // time for red light 
    int yellow = 3; // time for yellow light
    int green = 15; // time for green light
    
    int timeLeft = 0;
    bool isGreen = false; // set initial state to red
    
    while (true) {
        if (isGreen) { // if green light is on
            timeLeft = green; // set time left to green light time
            printf("\nGreen light is on\n");
        } else if (timeLeft == 0) { // if red or yellow light is on and it's time to switch
            if (red != 0) { // if there is still time left on the red light
                timeLeft = red; // set time left to red light time
                printf("\nRed light is on\n");
            } else { // if there is no time left on the red light
                timeLeft = yellow; // set time left to yellow light time
                printf("\nYellow light is on\n");
            }
            isGreen = !isGreen; // switch the state
        }
        
        displayState(red, yellow, green);
        printf("Time left: %d\n", timeLeft);
        timeLeft--; // decrement the time left
        sleep(1); // sleep for a second
    }
    
    return 0;
}