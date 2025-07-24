//FormAI DATASET v1.0 Category: Physics simulation ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main() {
    // Constants
    const float GRAVITY = 9.8; // m/s^2
    const float TIME_STEP = 0.1; // seconds
    const float AIR_RESISTANCE_COEFFICIENT = 0.1;
    const float MASS = 1.0; // kg

    // Initial position and velocity
    float x = 0.0; // meters
    float y = 0.0; // meters
    float vx = 10.0; // meters/second
    float vy = 20.0; // meters/second

    // Calculate the initial angle and velocity magnitude
    float angle = atan2(vy, vx);
    float velocity = sqrt(vx * vx + vy * vy);

    printf("Projectile launched at %.2f m/s and %.2f degrees\n", velocity, angle * 180.0 / M_PI);

    // Simulation loop
    for (float t = 0; y >= 0.0; t += TIME_STEP) {
        // Calculate the forces
        float air_resistance_force = -0.5 * AIR_RESISTANCE_COEFFICIENT * MASS * velocity * velocity;
        float y_force = -MASS * GRAVITY;
        float x_force = air_resistance_force * cos(angle);

        // Calculate the acceleration
        float ax = x_force / MASS;
        float ay = y_force / MASS;

        // Update the position and velocity
        x += vx * TIME_STEP + 0.5 * ax * TIME_STEP * TIME_STEP;
        y += vy * TIME_STEP + 0.5 * ay * TIME_STEP * TIME_STEP;
        vx += ax * TIME_STEP;
        vy += ay * TIME_STEP;

        // Calculate the new angle and velocity magnitude
        angle = atan2(vy, vx);
        velocity = sqrt(vx * vx + vy * vy);

        // Print the current state
        printf("t=%.2fs x=%.2fm y=%.2fm vx=%.2fm/s vy=%.2fm/s v=%.2fm/s angle=%.2fdeg\n", t, x, y, vx, vy, velocity, angle * 180.0 / M_PI);
    }

    printf("Projectile landed at %.2f meters\n", x);

    return 0;
}