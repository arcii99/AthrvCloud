//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
        
    int redSec = rand() % 10 + 10; // Random number between 10 and 19
    int yelSec = rand() % 3 + 2; // Random number between 2 and 4
    int grnSec = rand() % 10 + 15; // Random number between 15 and 24

    int currSec = 0;
    int currLight = 0; // 0 for red, 1 for yellow, 2 for green

    printf("Starting traffic light controller...\n\n");      
    
    while (1) {
        currSec++;
        
        if (currLight == 0) { // Red light
            printf("The light is red for %d seconds\n", redSec);
            if (currSec >= redSec) {
                currSec = 0;
                currLight = 1; // Switch to yellow
            }
        } else if (currLight == 1) { // Yellow light
            printf("The light is yellow for %d seconds\n", yelSec);
            if (currSec >= yelSec) {
                currSec = 0;
                currLight = 2; // Switch to green
            }
        } else { // Green light
            printf("The light is green for %d seconds\n", grnSec);
            if (currSec >= grnSec) {
                currSec = 0;
                currLight = 0; // Switch to red
            }
        }
    }
    
    return 0;
}