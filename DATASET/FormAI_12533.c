//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>

const float G = 9.81; // gravitational field strength
const float DT = 0.1; // time step
const float MASS = 0.1; // mass of object

float compute_acceleration(float force) {
    return force / MASS;
}

float compute_force(float weight) {
    return weight * G;
}

int main() {
    float height = 10.0; // initial height
    float velocity = 0.0; // initial velocity
    float time = 0.0; // initial time
    float force, acceleration;
    float weight = MASS * G;
    
    while(height > 0.0) {
        force = compute_force(weight);
        acceleration = compute_acceleration(force);
        velocity += acceleration * DT;
        height -= velocity * DT;
        time += DT;
        
        printf("Time: %f, Height: %f, Velocity: %f\n", time, height, velocity);
    }
    
    return 0;
}