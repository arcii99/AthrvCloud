//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2
#define AIR_DENSITY 1.204 // kg/m^3
#define BALL_RADIUS 0.11 // meters
#define BALL_MASS 0.43 // kg

double getDragForce(double speed) {
    return 0.5 * AIR_DENSITY * M_PI * pow(BALL_RADIUS, 2) * pow(speed, 2);
}

double getNetForce(double speed) {
    double dragForce = getDragForce(speed);
    double gravityForce = BALL_MASS * GRAVITY;
    return gravityForce - dragForce;
}

void updateVelocity(double *vel, double *pos, double dt) {
    double netForce = getNetForce(*vel);
    double acceleration = netForce / BALL_MASS;
    *vel += acceleration * dt;
    *pos += (*vel) * dt;
    if (*pos < 0) {
        *pos = 0;
        *vel = -*vel * 0.8; // coefficient of restitution = 0.8
    }
}

void simulate(double *vel, double *pos, double dt, double totalTime) {
    if (totalTime <= 0) {
        return;
    }
    updateVelocity(vel, pos, dt);
    printf("Time: %f s, Height: %f m, Velocity: %f m/s\n", totalTime, *pos, *vel);
    simulate(vel, pos, dt, totalTime - dt);
}

int main() {
    double initialVelocity = 20.0; // m/s
    double initialHeight = 10.0; // m
    double deltaTime = 0.01; // s

    double vel = initialVelocity;
    double pos = initialHeight;

    simulate(&vel, &pos, deltaTime, 10.0); // simulate for 10 seconds
    return 0;
}