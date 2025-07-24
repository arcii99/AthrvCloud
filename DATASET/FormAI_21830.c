//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Define variables
    int greenTime = 20;
    int yellowTime = 3;
    int redTime = 15;
    int counter = 0;
    int previousState = 0; // 0 - red, 1 - yellow, 2 - green

    srand(time(0)); // Initialize random seed
    
    // Loop through traffic light states
    while(1){
        int state;
        
        if(previousState == 0){
            // Transition from red to green
            printf("\nRED\n");
            state = 2;
        }
        else if(previousState == 1){
            // Transition from yellow to red
            printf("\nRED\n");
            state = 0;
        }
        else{
            // Transition from green to yellow
            printf("\nYELLOW\n");
            state = 1;
        }

        previousState = state;

        // Loop through time states for current color
        while(counter < (state == 0 ? redTime : (state == 1 ? yellowTime : greenTime))){
            printf("Time remaining: %d\n", (state == 0 ? redTime - counter : (state == 1 ? yellowTime - counter : greenTime - counter)));
            counter++;
            sleep(1); // wait for 1 second
        }

        counter = 0; // reset timer 
    }
    
    return 0;
}