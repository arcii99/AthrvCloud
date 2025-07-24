//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: brave
#include <stdio.h>
#include <math.h>
#define G 6.673e-11 // gravitational constant

typedef struct {
    double x_pos;
    double y_pos;
    double z_pos;
    double x_vel;
    double y_vel;
    double z_vel;
    double mass;
} planet;

// function prototypes
void update_acceleration(planet* p, planet* q, double* x_acc, double* y_acc, double* z_acc);
void update_velocity(planet* p, double x_acc, double y_acc, double z_acc, double time_step);
void update_position(planet* p, double time_step);

int main() {
    int num_planets = 2;
    double time_step = 1; // in seconds
    planet planets[num_planets];
    double x_acc, y_acc, z_acc;

    // set up initial conditions for the planets
    planets[0].x_pos = 0;
    planets[0].y_pos = 0;
    planets[0].z_pos = 0;
    planets[0].x_vel = 0;
    planets[0].y_vel = 0;
    planets[0].z_vel = 0;
    planets[0].mass = 5.97e24; // earth mass

    planets[1].x_pos = 384400000;
    planets[1].y_pos = 0;
    planets[1].z_pos = 0;
    planets[1].x_vel = 0;
    planets[1].y_vel = 1000;
    planets[1].z_vel = 0;
    planets[1].mass = 7.35e22; // moon mass

    // run simulation for 1 day (86400 seconds)
    for (int i = 0; i < 86400; i++) {
        // calculate acceleration for each planet
        for (int j = 0; j < num_planets; j++) {
            x_acc = 0;
            y_acc = 0;
            z_acc = 0;
            for (int k = 0; k < num_planets; k++) {
                if (j != k) {
                    update_acceleration(&planets[j], &planets[k], &x_acc, &y_acc, &z_acc);
                }
            }
            update_velocity(&planets[j], x_acc, y_acc, z_acc, time_step);
        }
        // update positions of all planets
        for (int j = 0; j < num_planets; j++) {
            update_position(&planets[j], time_step);
        }
    }
    // print final positions of all planets
    for (int j = 0; j < num_planets; j++) {
        printf("Planet %d: x = %.2f m, y = %.2f m, z = %.2f m\n", j+1, planets[j].x_pos, planets[j].y_pos, planets[j].z_pos);
    }
    return 0;
}

/**
 * Updates the acceleration of planet p due to planet q.
 */
void update_acceleration(planet* p, planet* q, double* x_acc, double* y_acc, double* z_acc) {
    double r = sqrt(pow(q->x_pos - p->x_pos, 2) + pow(q->y_pos - p->y_pos, 2) + pow(q->z_pos - p->z_pos, 2)); // distance between p and q
    double f = G * p->mass * q->mass / pow(r, 2); // force between p and q
    *x_acc += f * (q->x_pos - p->x_pos) / r / p->mass;
    *y_acc += f * (q->y_pos - p->y_pos) / r / p->mass;
    *z_acc += f * (q->z_pos - p->z_pos) / r / p->mass;
}

/**
 * Updates the velocity of planet p based on its acceleration and time step.
 */
void update_velocity(planet* p, double x_acc, double y_acc, double z_acc, double time_step) {
    p->x_vel += x_acc * time_step;
    p->y_vel += y_acc * time_step;
    p->z_vel += z_acc * time_step;
}

/**
 * Updates the position of planet p based on its velocity and time step.
 */
void update_position(planet* p, double time_step) {
    p->x_pos += p->x_vel * time_step;
    p->y_pos += p->y_vel * time_step;
    p->z_pos += p->z_vel * time_step;
}