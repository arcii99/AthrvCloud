//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // set random seed based on current time
    
    printf("Welcome to the Traffic Light Controller Program\n\n");
    
    int wait_time = (rand() % 10) + 1; // generate random wait time between 1 and 10 seconds
    
    printf("Please wait %d seconds while initializing the system...\n\n", wait_time);
    
    for (int i = 0; i < wait_time; i++) {
        printf("%d second(s) passed...\n", i+1);
        sleep(1); // wait for 1 second
    }
    
    printf("\nThe system has been initialized!\n\n");
    
    while (1) {
        // generate random values for traffic light durations
        int red_time = (rand() % 10) + 1;
        int yellow_time = (rand() % 3) + 1;
        int green_time = (rand() % 10) + 1;
        
        printf("Red Light for %d second(s)\n", red_time);
        sleep(red_time);
        
        printf("Yellow Light for %d second(s)\n", yellow_time);
        sleep(yellow_time);
        
        printf("Green Light for %d second(s)\n", green_time);
        sleep(green_time);
        
        printf("\n");
    }
    
    return 0;
}