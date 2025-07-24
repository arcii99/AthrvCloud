//FormAI DATASET v1.0 Category: Physics simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY -9.8 // acceleration due to gravity
#define AIR_RESISTANCE 0.01 // coefficient of air resistance
#define MASS 0.1 // mass of the object
#define TIME_INTERVAL 0.1 // time interval for simulation
#define INITIAL_VELOCITY 40 // initial velocity of object
#define INITIAL_HEIGHT 50 // initial height of object

int main()
{
    double velocity = INITIAL_VELOCITY;
    double height = INITIAL_HEIGHT;
    double time = 0;
    double acceleration;
    double net_force;
    double air_resistance;
    int i = 0;
    
    printf("Simulation starting...\n");
    
    while (height > 0)
    {
        i++;
        net_force = MASS * GRAVITY; // calculate net force
        
        air_resistance = AIR_RESISTANCE * velocity * velocity; // calculate air resistance
        
        net_force -= air_resistance; // adjust net force for air resistance
        
        acceleration = net_force / MASS; // calculate acceleration
        
        velocity += acceleration * TIME_INTERVAL; // calculate new velocity
        
        height += velocity * TIME_INTERVAL; // calculate new height
        
        printf("%d: Time: %.2f seconds, Height: %.2f meters\n", i, time, height);
        
        time += TIME_INTERVAL; // increment time
    }
    
    printf("Simulation complete.\n");
    
    return 0;
}