//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>

void simulate(int time, float velocity, float position){
    float acceleration = -9.8; // acceleration due to gravity
    float time_elapsed = 0.01; // small time step for more accurate simulation
    float new_position = position + velocity * time_elapsed; 
    float new_velocity = velocity + acceleration * time_elapsed;
    
    printf("Time: %d seconds, Position: %.2f meters, Velocity: %.2f m/s\n", time, position, velocity);
    
    if(time >= 10){ // simulation ends after 10 seconds
        return;
    }
    else{
        simulate(time+1, new_velocity, new_position);
    }
}

int main(){
    printf("C Physics Simulation: Object Falling Under Gravity\n");
    printf("Initial Conditions: Position = 50 meters, Velocity = 0 m/s\n");
    simulate(0, 0, 50); // simulate from time = 0, initial velocity = 0, initial position = 50
    return 0;
}