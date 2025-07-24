//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11   // Gravitational constant (m^3 kg^-1 s^-2)
#define TIME_STEP 3600  // Time step in seconds

typedef struct {
    double x, y, z;    // Position in meters
    double vx, vy, vz; // Velocity in meters per second
    double mass;       // Mass of the planet in kg
} Planet;

void simulate(Planet *planets, int num_planets, double sim_time) {
    double force_x[num_planets][num_planets];
    double force_y[num_planets][num_planets];
    double force_z[num_planets][num_planets];
    double distance, magnitude, force;
    int i, j, k;

    for (i = 0; i < num_planets; i++) {
        for (j = i + 1; j < num_planets; j++) {
            // Calculate the distance between the planets
            distance = sqrt(pow(planets[i].x - planets[j].x, 2) +
                            pow(planets[i].y - planets[j].y, 2) +
                            pow(planets[i].z - planets[j].z, 2));

            // Calculate the gravitational force between the planets
            magnitude = G * planets[i].mass * planets[j].mass / pow(distance, 2);
            force = magnitude / planets[i].mass;

            // Calculate the x, y and z components of the force
            force_x[i][j] = force * (planets[j].x - planets[i].x) / distance;
            force_y[i][j] = force * (planets[j].y - planets[i].y) / distance;
            force_z[i][j] = force * (planets[j].z - planets[i].z) / distance;

            force_x[j][i] = -force_x[i][j];
            force_y[j][i] = -force_y[i][j];
            force_z[j][i] = -force_z[i][j];
        }
    }

    for (i = 0; i < num_planets; i++) {
        // Calculate the net force on the planet
        double net_force_x = 0;
        double net_force_y = 0;
        double net_force_z = 0;

        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                net_force_x += force_x[i][j];
                net_force_y += force_y[i][j];
                net_force_z += force_z[i][j];
            }
        }

        // Calculate the acceleration of the planet
        double acceleration_x = net_force_x / planets[i].mass;
        double acceleration_y = net_force_y / planets[i].mass;
        double acceleration_z = net_force_z / planets[i].mass;

        // Update the velocity and position of the planet
        planets[i].vx += acceleration_x * TIME_STEP;
        planets[i].vy += acceleration_y * TIME_STEP;
        planets[i].vz += acceleration_z * TIME_STEP;

        planets[i].x += planets[i].vx * TIME_STEP;
        planets[i].y += planets[i].vy * TIME_STEP;
        planets[i].z += planets[i].vz * TIME_STEP;
    }

    // Output the new position of each planet
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d: (%f, %f, %f)\n", i + 1, planets[i].x, planets[i].y, planets[i].z);
    }

    // Recurse if there is more simulation time remaining
    if (sim_time > TIME_STEP) {
        simulate(planets, num_planets, sim_time - TIME_STEP);
    }
}

int main() {
    Planet planets[2] = {
        {
            .x = 0,
            .y = 0,
            .z = 0,
            .vx = 0,
            .vy = 0,
            .vz = 0,
            .mass = 5.9722e24 // Mass of Earth in kg
        },
        {
            .x = 147e9,
            .y = 0,
            .z = 0,
            .vx = 0,
            .vy = 30300, // Velocity of Earth in m/s around the Sun
            .vz = 0,
            .mass = 1.9891e30 // Mass of Sun in kg
        }
    };

    simulate(planets, 2, 31536000); // Simulate for 1 year (31536000 seconds)

    return 0;
}