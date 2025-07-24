//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>
#define GRAVITY 9.81

struct Ball {
    double radius;
    double mass;
    double position[2]; // x, y
    double velocity[2]; // vx, vy
    double acceleration[2]; // ax, ay
};

void simulate(struct Ball *ball, double time_step, double duration) {
    double time = 0;
    while (time < duration) {
        // Update acceleration using gravity
        ball->acceleration[0] = 0;
        ball->acceleration[1] = -GRAVITY;

        // Update velocity and position using Verlet integration
        ball->velocity[0] += ball->acceleration[0] * time_step / 2;
        ball->position[0] += ball->velocity[0] * time_step + 
                             ball->acceleration[0] * pow(time_step, 2) / 2;
        ball->velocity[0] += ball->acceleration[0] * time_step / 2;

        ball->velocity[1] += ball->acceleration[1] * time_step / 2;
        ball->position[1] += ball->velocity[1] * time_step + 
                             ball->acceleration[1] * pow(time_step, 2) / 2;
        ball->velocity[1] += ball->acceleration[1] * time_step / 2;

        // Print ball position after each time step
        printf("Ball position: (%f, %f)\n", ball->position[0], ball->position[1]);
        
        time += time_step;
    }
}

int main() {
    struct Ball ball1 = { 0.1, 0.5, {0, 0}, {2, 5}, {0, 0} };
    simulate(&ball1, 0.01, 5);
    return 0;
}