//FormAI DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include<stdio.h>
#include<math.h>

#define DELTA_T 0.0001 // Time increment in seconds
#define MASS 1.0 // Mass of the particle in kg
#define CHARGE 1.0 // Charge of the particle in Coulombs
#define B_FIELD 0.5 // Magnetic field of the system in Tesla

int main(){
    double x,y,z,vx,vy,vz,ax,ay,az; // Position, velocity and acceleration variables
    double q_over_m, omega; // Charge to mass ratio and angular frequency of motion
    double Bx, By, Bz; // Components of the magnetic field
    double v_x_bx, v_y_by, v_z_bz; // Components of the cross product between velocity and magnetic field

    // Set initial conditions
    x = 0.0;
    y = 0.0;
    z = 0.0;
    vx = 100.0;
    vy = 0.0;
    vz = 0.0;

    // Calculate charge to mass ratio and magnetic field components
    q_over_m = CHARGE/MASS;
    Bx = 0.0;
    By = 0.0;
    Bz = B_FIELD;

    // Calculate angular frequency of motion
    omega = q_over_m * B_FIELD;

    // Run simulation
    for (int i=0; i<100000; i++){
        // Calculate components of the cross product between velocity and magnetic field
        v_x_bx = vy * Bz - vz * By;
        v_y_by = vz * Bx - vx * Bz;
        v_z_bz = vx * By - vy * Bx;

        // Calculate acceleration
        ax = q_over_m * v_x_bx;
        ay = q_over_m * v_y_by;
        az = q_over_m * v_z_bz;

        // Update position and velocity
        x += vx * DELTA_T + 0.5 * ax * DELTA_T * DELTA_T;
        y += vy * DELTA_T + 0.5 * ay * DELTA_T * DELTA_T;
        z += vz * DELTA_T + 0.5 * az * DELTA_T * DELTA_T;
        vx += ax * DELTA_T;
        vy += ay * DELTA_T;
        vz += az * DELTA_T;

        // Print position
        printf("%f %f %f\n", x, y, z);

        // Calculate expected position
        double expected_z = 0.0;
        double expected_x = 100.0 * cos(omega * i * DELTA_T);
        double expected_y = 100.0 * sin(omega * i * DELTA_T);

        // Check if the actual position matches the expected position
        if (fabs(x - expected_x) > 0.01 || fabs(y - expected_y) > 0.01 || fabs(z - expected_z) > 0.01){
            printf("Unexpected position at time %f: (%f, %f, %f)\n", i*DELTA_T, x, y, z);
            return 1;
        }
    }

    printf("Simulation completed successfully.\n");
    return 0;
}