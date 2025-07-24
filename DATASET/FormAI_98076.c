//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: statistical
#include <stdio.h>
#include <math.h>
#define G 6.67e-11 // gravitational constant

// function to calculate distance between two objects
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    // initialize objects
    double sun_mass = 1.9891e+30;
    double sun_radius = 696340000;
    double sun_x = 0, sun_y = 0, sun_z = 0;
    double earth_mass = 5.9722e+24;
    double earth_radius = 6371000;
    double earth_distance = 149.6e+9;
    double earth_velocity = 29780;
    double earth_x = earth_distance, earth_y = 0, earth_z = 0;
    double time_step = 86400; // time step is one day in seconds
    double earth_acceleration_x, earth_acceleration_y, earth_acceleration_z;
    double earth_velocity_x = 0, earth_velocity_y = earth_velocity, earth_velocity_z = 0;
    double earth_force_x, earth_force_y, earth_force_z;

    // run simulation for one year
    int days = 365;
    int i, j;
    for (i = 0; i < days; i++) {
        // calculate earth's acceleration due to gravity from sun
        double dist = distance(sun_x, sun_y, sun_z, earth_x, earth_y, earth_z);
        double force = G * sun_mass * earth_mass / dist / dist;
        earth_force_x = force * (sun_x - earth_x) / dist;
        earth_force_y = force * (sun_y - earth_y) / dist;
        earth_force_z = force * (sun_z - earth_z) / dist;
        earth_acceleration_x = earth_force_x / earth_mass;
        earth_acceleration_y = earth_force_y / earth_mass;
        earth_acceleration_z = earth_force_z / earth_mass;

        // update earth's position and velocity
        earth_x += earth_velocity_x * time_step + 0.5 * earth_acceleration_x * time_step * time_step;
        earth_y += earth_velocity_y * time_step + 0.5 * earth_acceleration_y * time_step * time_step;
        earth_z += earth_velocity_z * time_step + 0.5 * earth_acceleration_z * time_step * time_step;
        earth_velocity_x += earth_acceleration_x * time_step;
        earth_velocity_y += earth_acceleration_y * time_step;
        earth_velocity_z += earth_acceleration_z * time_step;

        // print earth's position and velocity
        printf("Day %d: Earth Position: (%.2f, %.2f, %.2f) m, Earth Velocity: (%.2f, %.2f, %.2f) m/s\n", 
            i+1, earth_x, earth_y, earth_z, earth_velocity_x, earth_velocity_y, earth_velocity_z);
    }

    return 0;
}