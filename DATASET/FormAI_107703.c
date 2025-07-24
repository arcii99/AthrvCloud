//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Universal Gravitational Constant

typedef struct {
    double x_pos, y_pos, z_pos;
    double mass;
    double x_speed, y_speed, z_speed;
} planet; // Defining the planet struct

int main() {
    // Creating an array of planets
    planet solar_system[4] = {
        {0.0, 0.0, 0.0, 1.989e30, 0.0, 0.0, 0.0}, // Sun
        {149.6e9, 0.0, 0.0, 5.97e24, 0.0, 29800.0, 0.0}, // Earth
        {0.0, 57.9e9, 0.0, 3.30e23, -47362.0, 0.0, 0.0}, // Mercury
        {0.0, 227.9e9, 0.0, 6.39e23, -35020.0, 0.0, 0.0} // Mars
    };
    
    // Creating a 2D array to store acceleration values
    double acceleration[4][3] = {0};
    
    // Defining time variables
    double t = 0.0, dt = 86400.0; // dt is one day in seconds
    
    // Starting the simulation loop
    while (t < 31557600.0) { // Total simulation time is one Earth year
        
        // Clearing the array of acceleration values
        for (int i=0; i<4; i++) {
            for (int j=0; j<3; j++) {
                acceleration[i][j] = 0.0;
            }
        }
        
        // Calculating gravitational forces and updating acceleration values
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (i != j) {
                    double r = sqrt(pow(solar_system[j].x_pos - solar_system[i].x_pos, 2.0)
                                    + pow(solar_system[j].y_pos - solar_system[i].y_pos, 2.0)
                                    + pow(solar_system[j].z_pos - solar_system[i].z_pos, 2.0));
                    double f = G * solar_system[i].mass * solar_system[j].mass / pow(r, 2.0);
                    acceleration[i][0] += f * (solar_system[j].x_pos - solar_system[i].x_pos) / r;
                    acceleration[i][1] += f * (solar_system[j].y_pos - solar_system[i].y_pos) / r;
                    acceleration[i][2] += f * (solar_system[j].z_pos - solar_system[i].z_pos) / r;
                }
            }
        }
        
        // Updating position and velocity values using acceleration values
        for (int i=0; i<4; i++) {
            solar_system[i].x_pos += solar_system[i].x_speed * dt + 0.5 * acceleration[i][0] * pow(dt, 2.0);
            solar_system[i].y_pos += solar_system[i].y_speed * dt + 0.5 * acceleration[i][1] * pow(dt, 2.0);
            solar_system[i].z_pos += solar_system[i].z_speed * dt + 0.5 * acceleration[i][2] * pow(dt, 2.0);
            
            solar_system[i].x_speed += acceleration[i][0] * dt;
            solar_system[i].y_speed += acceleration[i][1] * dt;
            solar_system[i].z_speed += acceleration[i][2] * dt;
        }
        
        // Printing the positions of the planets
        printf("Time: %lf days\n", t/86400.0);
        printf("Sun: (%lf, %lf, %lf)\n", solar_system[0].x_pos, solar_system[0].y_pos, solar_system[0].z_pos);
        printf("Earth: (%lf, %lf, %lf)\n", solar_system[1].x_pos, solar_system[1].y_pos, solar_system[1].z_pos);
        printf("Mercury: (%lf, %lf, %lf)\n", solar_system[2].x_pos, solar_system[2].y_pos, solar_system[2].z_pos);
        printf("Mars: (%lf, %lf, %lf)\n", solar_system[3].x_pos, solar_system[3].y_pos, solar_system[3].z_pos);
        
        // Updating time
        t += dt;
    }

    return 0;
}