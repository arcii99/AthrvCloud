//FormAI DATASET v1.0 Category: Physics simulation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main()
{
    float g = 9.81; // gravity
    float dt = 0.1; // time step
    float t = 0;    // start time
    float v = 0;    // initial velocity
    float x = 0;    // initial position
    
    while(x >= 0)   // simulate until the object hits the ground (x = 0)
    {
        float a = -g;   // acceleration
        v += a * dt;     // update velocity
        x += v * dt;     // update position
        t += dt;         // update time
        printf("t = %f, x = %f, v = %f\n", t, x, v); // output time, position, and velocity
    }
    
    printf("Object landed at t = %f\n", t); // output the time at which the object landed
    
    return 0;
}