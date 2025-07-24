//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <math.h>

#define G 6.67E-11 // Gravitational constant
#define AU 149.6E9 // Astronomical unit in meters
#define DAY 86400 // Day in seconds

// Function to calculate the distance between two celestial bodies
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

int main() {
    // Define the celestial bodies in our solar system
    struct celestial_body {
        char name[20];
        double mass, radius, x_pos, y_pos, x_vel, y_vel;
    };
    struct celestial_body sun = {"Sun", 1.989E30, 695700E3, 0, 0, 0, 0};
    struct celestial_body mercury = {"Mercury", 3.3E23, 2.44E6, 0.387*AU, 0, 0, 38.9E3};
    struct celestial_body venus = {"Venus", 4.87E24, 6.05E6, 0.723*AU, 0, 0, 35E3};
    struct celestial_body earth = {"Earth", 5.97E24, 6.37E6, AU, 0, 0, 29.8E3};
    struct celestial_body moon = {"Moon", 7.34E22, 1.74E6, AU + 384400E3, 0, 0, 30.3E3};
    struct celestial_body mars = {"Mars", 6.39E23, 3.39E6, 1.524*AU, 0, 0, 24.1E3};
    struct celestial_body jupiter = {"Jupiter", 1.898E27, 69.9E6, 5.203*AU, 0, 0, 13.1E3};
    struct celestial_body saturn = {"Saturn", 5.68E26, 58.2E6, 9.539*AU, 0, 0, 9.64E3};
    struct celestial_body uranus = {"Uranus", 8.68E25, 25.4E6, 19.18*AU, 0, 0, 6.8E3};
    struct celestial_body neptune = {"Neptune", 1.02E26, 24.6E6, 30.07*AU, 0, 0, 5.43E3};
    struct celestial_body pluto = {"Pluto", 1.31E22, 1.19E6, 39.48*AU, 0, 0, 4.74E3};
    
    struct celestial_body solar_system[10] = {sun, mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune};
    int bodies = sizeof(solar_system)/sizeof(solar_system[0]);
    
    int time = 0;
    double x_force[bodies], y_force[bodies], acceleration[bodies], x_accel[bodies], y_accel[bodies];
    double x_distance[bodies][bodies], y_distance[bodies][bodies], dist[bodies][bodies];
    
    // Begin simulation
    while (time <= 365*50) {
        printf("Day %d:\n", time);
        
        // Calculate forces between each celestial body
        for (int i = 0; i < bodies; i++) {
            x_force[i] = 0;
            y_force[i] = 0;
            for (int j = 0; j < bodies; j++) {
                if (i != j) {
                    x_distance[i][j] = solar_system[j].x_pos - solar_system[i].x_pos;
                    y_distance[i][j] = solar_system[j].y_pos - solar_system[i].y_pos;
                    dist[i][j] = distance(solar_system[i].x_pos, solar_system[i].y_pos, solar_system[j].x_pos, solar_system[j].y_pos);
                    x_force[i] += G * solar_system[i].mass * solar_system[j].mass * x_distance[i][j] / pow(dist[i][j], 3);
                    y_force[i] += G * solar_system[i].mass * solar_system[j].mass * y_distance[i][j] / pow(dist[i][j], 3);
                }
            }
        }
        
        // Calculate acceleration of each celestial body
        for (int i = 0; i < bodies; i++) {
            x_accel[i] = x_force[i] / solar_system[i].mass;
            y_accel[i] = y_force[i] / solar_system[i].mass;
        }
        
        // Update velocity and position of each celestial body
        for (int i = 0; i < bodies; i++) {
            solar_system[i].x_vel += x_accel[i] * DAY;
            solar_system[i].y_vel += y_accel[i] * DAY;
            solar_system[i].x_pos += solar_system[i].x_vel * DAY;
            solar_system[i].y_pos += solar_system[i].y_vel * DAY;
        }
        
        // Print positions of each celestial body
        for (int i = 0; i < bodies; i++) {
            printf("%s: (%e, %e)\n", solar_system[i].name, solar_system[i].x_pos, solar_system[i].y_pos);
        }
        
        time++;
        printf("\n");
    }
    
    return 0;
}