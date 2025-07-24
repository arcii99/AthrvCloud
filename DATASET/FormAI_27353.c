//FormAI DATASET v1.0 Category: Physics simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8
#define NUM_SAMPLES 100

void simulate_projectile_motion(float vel, float angle, float mass, float air_resistance);

int main() {
    float vel = 30.0;
    float angle = 45.0;
    float mass = 0.05;
    float air_resistance = 0.001;

    simulate_projectile_motion(vel, angle, mass, air_resistance);

    return 0;
}

void simulate_projectile_motion(float vel, float angle, float mass, float air_resistance) {
    float rad = M_PI / 180.0;
    float x_pos, y_pos, x_vel, y_vel, time, delta_t;

    // Initial conditions
    x_pos = 0.0;
    y_pos = 0.0;
    x_vel = vel * cos(angle * rad);
    y_vel = vel * sin(angle * rad);
    delta_t = 0.01;
    time = 0.0;

    for (int i = 0; i <= NUM_SAMPLES; i++) {
        float air_resistance_force = air_resistance * pow(x_vel, 2);
        float x_acc = -air_resistance_force / mass;
        float y_acc = -GRAVITY - (air_resistance_force / mass);

        x_vel += x_acc * delta_t;
        y_vel += y_acc * delta_t;

        x_pos += x_vel * delta_t;
        y_pos += y_vel * delta_t;

        if (y_pos < 0.0) { // Projectile hit the ground
            y_pos = 0.0;
            y_vel = -y_vel * 0.8; // Bounce on the ground with 80% energy retention
        }

        printf("Sample %3d: time = %6.3f, x_pos = %6.3f, y_pos = %6.3f\n", i, time, x_pos, y_pos);
        time += delta_t;
    }
}