//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Seeding the random number generator
    int red = 1, yellow = 2, green = 3; // Assigning values to red, yellow, and green respectively
    int currentLight = red; // Initializing the current light to red
    
    // Infinite loop to simulate continuous traffic flow
    while(1) {
        printf("Current light: ");
        // Switch statement to print the current light
        switch(currentLight) {
            case 1: printf("Red\n");
                    break;
            case 2: printf("Yellow\n");
                    break;
            case 3: printf("Green\n");
                    break;
        }
        
        // Generating a random number to decide how long to keep the current light
        int randomNum = rand() % 6 + 1; // A random number between 1 and 6 inclusive
        printf("Keeping this light for %d seconds\n", randomNum);
        usleep(randomNum * 1000000); // usleep() implements a delay in microseconds
        
        // Switching to the next light
        switch(currentLight) {
            case 1: currentLight = green;
                    break;
            case 2: currentLight = green;
                    break;
            case 3: currentLight = red;
                    break;
        }
    }
    return 0;
}