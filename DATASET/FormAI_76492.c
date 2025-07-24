//FormAI DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdio.h>
#include <math.h>

int main() {
    float time = 0;
    float deltaTime = 0.01;
    float velocity = 0;
    float acceleration = 0;
    float position = 0;

    float mass = 0.5;
    float force = 10; // Assume a constant force of 10 N
    
    while (time <= 5) {
        acceleration = force / mass; // Calculate acceleration
        velocity += acceleration * deltaTime; // Update velocity
        position += velocity * deltaTime; // Update position

        printf("Time: %f s, Position: %f m\n", time, position);

        time += deltaTime; // Increment time
    }

    return 0;
}