//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure definition for a planet
typedef struct {
    char name[20];
    float mass; // In Earth Masses
    float distance; // In AU (Astronomical Units)
    float speed; // In km/s
} Planet;

// Function to simulate the movement of planets
void simulate_planets(Planet *planets, int num_planets, float time_step) {
    int i, j;
    float dx, dy, dist, force, accel, ax, ay, new_x, new_y, new_vx, new_vy;
    for (i = 0; i < num_planets; i++) {
        ax = ay = 0.0;
        for (j = 0; j < num_planets; j++) {
            if (i == j) continue;
            // Calculate distance between planets
            dx = planets[j].distance - planets[i].distance;
            dy = 0.0;
            // Calculate force of gravity between planets
            dist = sqrt(dx*dx + dy*dy);
            force = (planets[i].mass * planets[j].mass) / (dist*dist);
            // Calculate acceleration on planet i
            accel = force / planets[i].mass;
            ax += accel * (dx / dist);
            ay += 0.0; // No acceleration in y-direction for this simulation
        }
        // Calculate new position and velocity for planet i
        new_x = planets[i].distance + planets[i].speed*time_step + 0.5*ax*time_step*time_step;
        new_y = 0.0; // No movement in y-direction for this simulation
        new_vx = planets[i].speed + ax*time_step;
        new_vy = 0.0; // No velocity change in y-direction for this simulation
        // Update planet position and velocity
        planets[i].distance = new_x;
        planets[i].speed = new_vx;
    }
}

// Function to print the current position of planets
void print_planets(Planet *planets, int num_planets) {
    int i;
    printf("Current Position of Planets:\n");
    for (i = 0; i < num_planets; i++) {
        printf("%-10s Distance: %.2f AU\n", planets[i].name, planets[i].distance);
    }
    printf("\n");
}

int main() {
    // Define the solar system planets
    Planet planets[] = {
        {"Sun", 333000.0, 0.0, 0.0},
        {"Mercury", 0.055, 0.39, 47.87},
        {"Venus", 0.815, 0.72, 35.02},
        {"Earth", 1.0, 1.0, 29.78},
        {"Mars", 0.107, 1.52, 24.08},
        {"Jupiter", 318.0, 5.20, 13.07},
        {"Saturn", 95.0, 9.58, 9.69},
        {"Uranus", 14.0, 19.18, 6.81},
        {"Neptune", 17.0, 30.07, 5.43},
        {"Pluto", 0.0022, 39.48, 4.67}
    };
    int num_planets = sizeof(planets) / sizeof(Planet);
    float time_step = 1.0; // Number of Earth Days in a simulated day
    int num_days = 365 * 20; // Number of simulated days to run
    int i;
    
    printf("Medieval Solar System Simulation\n\n");
    // Print initial positions of planets
    print_planets(planets, num_planets);
    // Run simulation
    for (i = 0; i < num_days; i++) {
        simulate_planets(planets, num_planets, time_step);
        printf("Day %d\n", i+1);
        print_planets(planets, num_planets);
    }
    return 0;
}