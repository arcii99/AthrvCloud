//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.81

typedef struct object {
    double mass;
    double position;
    double velocity;
    double acceleration;
} Object;

void update(Object *o, double time_step) {
    o->velocity += o->acceleration * time_step;
    o->position += o->velocity * time_step;
}

int main() {
    Object ball = {0.5, 0, 0, 0};
    double time_step = 0.01;
    double height = 1;
    double time = 0;

    // Throw the ball up with an initial velocity
    ball.velocity = sqrt(2 * GRAVITY * height);

    while (ball.position >= 0) {
        // Calculate the acceleration of the ball
        ball.acceleration = -GRAVITY;

        // Update the position and velocity of the ball
        update(&ball, time_step);

        // Print the time and position of the ball
        printf("Time: %f, Position: %f\n", time, ball.position);

        // Increment the time
        time += time_step;
    }

    return 0;
}