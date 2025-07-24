//FormAI DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define MAX_TIME 10.0
#define TIME_STEP 0.1
#define EARTH_RADIUS 6.371e6
#define G 6.67e-11
#define M_EARTH 5.97e24
#define M_SAT 500.0
#define ALTITUDE 200.0e3

int main() {
    double time = 0.0;
    double sat_x, sat_y, sat_z;
    double sat_vx, sat_vy, sat_vz;
    double sat_ax, sat_ay, sat_az;
    double dist, force;

    // Initialize satellite position
    sat_x = 0.0;
    sat_y = EARTH_RADIUS + ALTITUDE;
    sat_z = 0.0;

    // Initialize satellite velocity
    sat_vx = 7000.0;
    sat_vy = 0.0;
    sat_vz = 0.0;

    while (time < MAX_TIME) {
        // Calculate gravitational force on satellite
        dist = sqrt(sat_x * sat_x + sat_y * sat_y + sat_z * sat_z);
        force = G * M_EARTH * M_SAT / (dist * dist);

        // Calculate components of acceleration
        sat_ax = -force * sat_x / (M_SAT * dist);
        sat_ay = -force * sat_y / (M_SAT * dist);
        sat_az = -force * sat_z / (M_SAT * dist);

        // Update velocity
        sat_vx += sat_ax * TIME_STEP;
        sat_vy += sat_ay * TIME_STEP;
        sat_vz += sat_az * TIME_STEP;

        // Update position
        sat_x += sat_vx * TIME_STEP;
        sat_y += sat_vy * TIME_STEP;
        sat_z += sat_vz * TIME_STEP;

        // Print position
        printf("Time: %lf, Altitude: %lf\n", time, sqrt(sat_x * sat_x + sat_y * sat_y + sat_z * sat_z) - EARTH_RADIUS);

        // increment time
        time += TIME_STEP;
    }
    
    return 0;
}