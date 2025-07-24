//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// Structure for celestial bodies
typedef struct celestial_body {
    char name[20];
    double mass;
    double radius;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;

} CBODY;

int main() {
    
    // Create Celestial Bodies
    CBODY star = {"Sun", 1.989E30, 6.96E8, 0, 0, 0, 0};
    CBODY planet_1 = {"Venus", 4.867E24, 6.052E6, 2.455E10, 1.834E10, 0, 0};
    CBODY planet_2 = {"Earth", 5.972E24, 6.371E6, 0, 1.495E11, -29780, 0};
    CBODY planet_3 = {"Mars", 6.39E23, 3.389E6, -2.067E11, 0, 0, -24007};
    
    // Time Variables
    double current_time = 0;
    double delta_t = 3600;
    
    // Simulation Loop
    while (current_time < 86400) {
        
        // Calculate Distances
        double dist_sun_planet_1 = sqrt(pow((planet_1.pos_x - star.pos_x), 2) + pow((planet_1.pos_y - star.pos_y), 2));
        double dist_sun_planet_2 = sqrt(pow((planet_2.pos_x - star.pos_x), 2) + pow((planet_2.pos_y - star.pos_y), 2));
        double dist_sun_planet_3 = sqrt(pow((planet_3.pos_x - star.pos_x), 2) + pow((planet_3.pos_y - star.pos_y), 2));
        
        double dist_planet_1_planet_2 = sqrt(pow((planet_1.pos_x - planet_2.pos_x), 2) + pow((planet_1.pos_y - planet_2.pos_y), 2));
        double dist_planet_1_planet_3 = sqrt(pow((planet_1.pos_x - planet_3.pos_x), 2) + pow((planet_1.pos_y - planet_3.pos_y), 2));
        double dist_planet_2_planet_3 = sqrt(pow((planet_2.pos_x - planet_3.pos_x), 2) + pow((planet_2.pos_y - planet_3.pos_y), 2));
        
        // Calculate Forces
        double force_sun_planet_1 = (6.674E-11 * star.mass * planet_1.mass) / pow(dist_sun_planet_1, 2);
        double force_sun_planet_2 = (6.674E-11 * star.mass * planet_2.mass) / pow(dist_sun_planet_2, 2);
        double force_sun_planet_3 = (6.674E-11 * star.mass * planet_3.mass) / pow(dist_sun_planet_3, 2);
        
        double force_planet_1_planet_2 = (6.674E-11 * planet_1.mass * planet_2.mass) / pow(dist_planet_1_planet_2, 2);
        double force_planet_1_planet_3 = (6.674E-11 * planet_1.mass * planet_3.mass) / pow(dist_planet_1_planet_3, 2);
        double force_planet_2_planet_3 = (6.674E-11 * planet_2.mass * planet_3.mass) / pow(dist_planet_2_planet_3, 2);
        
        // Calculate Accelerations
        double accel_sun_planet_1 = force_sun_planet_1 / planet_1.mass;
        double accel_sun_planet_2 = force_sun_planet_2 / planet_2.mass;
        double accel_sun_planet_3 = force_sun_planet_3 / planet_3.mass;
        
        double accel_planet_1_planet_2 = force_planet_1_planet_2 / planet_1.mass;
        double accel_planet_1_planet_3 = force_planet_1_planet_3 / planet_1.mass;
        double accel_planet_2_planet_3 = force_planet_2_planet_3 / planet_2.mass;
        
        // Calculate Velocities
        planet_1.vel_x += accel_sun_planet_1 * delta_t;
        planet_1.vel_y += accel_sun_planet_1 * delta_t;
        
        planet_2.vel_x += (accel_sun_planet_2 + accel_planet_1_planet_2) * delta_t;
        planet_2.vel_y += (accel_sun_planet_2 + accel_planet_1_planet_2) * delta_t;
        
        planet_3.vel_x += (accel_sun_planet_3 + accel_planet_1_planet_3 + accel_planet_2_planet_3) * delta_t;
        planet_3.vel_y += (accel_sun_planet_3 + accel_planet_1_planet_3 + accel_planet_2_planet_3) * delta_t;
        
        // Calculate Positions
        planet_1.pos_x += planet_1.vel_x * delta_t;
        planet_1.pos_y += planet_1.vel_y * delta_t;
        
        planet_2.pos_x += planet_2.vel_x * delta_t;
        planet_2.pos_y += planet_2.vel_y * delta_t;
        
        planet_3.pos_x += planet_3.vel_x * delta_t;
        planet_3.pos_y += planet_3.vel_y * delta_t;
        
        // Print Positions
        printf("\n----------------- Time = %lf -----------------\n", current_time);
        printf("%s Position: (%lf, %lf)\n", star.name, star.pos_x, star.pos_y);
        printf("%s Position: (%lf, %lf)\n", planet_1.name, planet_1.pos_x, planet_1.pos_y);
        printf("%s Position: (%lf, %lf)\n", planet_2.name, planet_2.pos_x, planet_2.pos_y);
        printf("%s Position: (%lf, %lf)\n", planet_3.name, planet_3.pos_x, planet_3.pos_y);
        
        current_time += delta_t;
    }
    
    return 0;
}