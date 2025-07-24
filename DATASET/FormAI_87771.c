//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, k, l, cycleCount = 0;
    int times[3][3], cycles[3][3];
    
    // Seed random number generator
    srand(time(NULL));
    
    // Set initial times for each traffic light
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            times[i][j] = rand() % 11 + 10; // Random time between 10 and 20 seconds
            cycles[i][j] = 0; // Start with zero cycles
        }
    }
    
    // Loop until 20 cycles have been completed
    while(cycleCount < 20){
        // Cycle through each traffic light
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                // If this is the first cycle, print the initial times
                if(cycles[i][j] == 0){
                    printf("Traffic light %d (Direction %d) : Time = %d seconds\n", i+1, j+1, times[i][j]);
                }
                
                // Decrement the time for this traffic light
                times[i][j]--;
                
                // If the time is up, reset the time and increment the cycle count
                if(times[i][j] == 0){
                    times[i][j] = rand() % 11 + 10; // Random time between 10 and 20 seconds
                    cycles[i][j]++; // Increment the cycle count for this traffic light
                    cycleCount++; // Increment the overall cycle count
                    printf("Traffic light %d (Direction %d) : Cycle %d completed\n", i+1, j+1, cycles[i][j]);
                }
            }
        }
    }
    
    printf("All cycles completed\n");
    
    return 0;
}