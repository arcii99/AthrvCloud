//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

float simulateSpring(float mass, float dt, float time, float pos, float vel);

int main(void) {
    float mass, dt, time, pos, vel, result;
    
    printf("Enter mass of system: ");
    scanf("%f", &mass);
    
    printf("Enter time step value (in seconds): ");
    scanf("%f", &dt);
    
    printf("Enter time duration (in seconds): ");
    scanf("%f", &time);
    
    printf("Enter initial position: ");
    scanf("%f", &pos);
    
    printf("Enter initial velocity: ");
    scanf("%f", &vel);
    
    result = simulateSpring(mass, dt, time, pos, vel);
    
    printf("Final position of the mass is %.2f meters.", result);
    
    return 0;
}

float simulateSpring(float mass, float dt, float time, float pos, float vel) {
    float force, acc, newPos, newVel, newTime;
    
    force = -1 * 9.8 * mass;
    
    if (time <= 0) {
        return pos;
    } else {
        acc = force / mass;
        newPos = pos + vel * dt;
        newVel = vel + acc * dt;
        newTime = time - dt;
        
        return simulateSpring(mass, dt, newTime, newPos, newVel);
    }
}