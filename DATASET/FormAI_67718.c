//FormAI DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define constants
#define GRAVITY 9.81
#define MASS 10

int main() {
    
    //initialize variables
    float height, time_elapsed, velocity, acceleration;
    int i;
    
    //set random seed
    srand(time(NULL));
    
    //generate random value for initial height
    height = (float)rand()/RAND_MAX * 100;
    
    //initialize time elapsed and initial velocity to zero
    time_elapsed = 0;
    velocity = 0;
    
    printf("Initial Height: %.2f meters\n", height);
    
    //iterate for 10 seconds
    for(i=0; i<=100; i++) {
        
        //calculate acceleration
        acceleration = -GRAVITY;
        
        //calculate velocity
        velocity += acceleration * 0.1;
        
        //calculate height
        height += velocity * 0.1;
        
        //increase time elapsed
        time_elapsed += 0.1;
        
        //check if height is below ground level
        if(height <= 0) {
            printf("Time elapsed: %.2f seconds, Height: %.2f meters\n", time_elapsed, 0.0);
            printf("Particle has hit the ground\n");
            break;
        }
        else {
            printf("Time elapsed: %.2f seconds, Height: %.2f meters\n", time_elapsed, height);
        }
    }
    
    printf("\n");
    return 0;
}