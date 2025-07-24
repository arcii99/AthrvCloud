//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum LIGHT_STATE {RED, YELLOW, GREEN}; // Traffic light states: Red, Yellow, and Green

// Function to wait for the specified number of seconds
void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while(clock() < endwait) {}
}

int main() {
    enum LIGHT_STATE light_state = RED; // Set initial light state to Red
    int cycle_count = 0; // Keep track of the number of light cycles
    
    while(cycle_count < 10) { // Run for 10 cycles
        if(light_state == RED) { // If light is Red
            printf("\nRED Light\n");
            wait(5); // Wait for 5 seconds
            light_state = GREEN; // Change light to Green
        }
        else if(light_state == YELLOW) { // If light is Yellow
            printf("YELLOW Light\n");
            wait(3); // Wait for 3 seconds
            light_state = RED; // Change light to Red
        }
        else { // If light is Green
            printf("GREEN Light\n");
            wait(10); // Wait for 10 seconds
            light_state = YELLOW; // Change light to Yellow
        }
        cycle_count++; // Increment cycle count after each light cycle
    }
    
    printf("\nEnd of traffic light cycle\n");
    return 0;
}