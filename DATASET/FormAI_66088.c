//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: modular
#include <stdio.h>
#include <math.h>

#define G_CONSTANT 6.67408e-11 // Gravitational constant G

// Structure for planet
typedef struct {
    double mass;  // Mass of planet in kg
    double x_pos; // X-coordinate of planet's position
    double y_pos; // Y-coordinate of planet's position
    double x_vel; // X-component of planet's velocity
    double y_vel; // Y-component of planet's velocity
} Planet;

// Function to calculate distance between two planets
double distance(Planet planet1, Planet planet2) {
    double dx = planet1.x_pos - planet2.x_pos;
    double dy = planet1.y_pos - planet2.y_pos;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate gravitational force between two planets
double force(Planet planet1, Planet planet2) {
    double dist = distance(planet1, planet2);
    return (G_CONSTANT * planet1.mass * planet2.mass) / (dist*dist);
}

// Function to update planets' velocities and positions
void update_planets(Planet *planets, int num_planets, double timestep) {
    int i, j;
    double fx, fy, dist, force_ij, acceleration_i, acceleration_j;
    for (i = 0; i < num_planets; i++) {
        fx = fy = 0;
        for (j = 0; j < num_planets; j++) {
            if (i == j) {
                continue;
            }
            force_ij = force(planets[i], planets[j]);
            dist = distance(planets[i], planets[j]);
            fx += force_ij * (planets[j].x_pos - planets[i].x_pos) / dist;
            fy += force_ij * (planets[j].y_pos - planets[i].y_pos) / dist;
        }
        acceleration_i = fx / planets[i].mass;
        acceleration_j = fy / planets[i].mass;
        planets[i].x_vel += acceleration_i * timestep;
        planets[i].y_vel += acceleration_j * timestep;
        planets[i].x_pos += planets[i].x_vel * timestep;
        planets[i].y_pos += planets[i].y_vel * timestep;
    }
}

// Function to print the positions of all the planets
void print_positions(Planet *planets, int num_planets, double time) {
    int i;
    printf("Time %fs:\n", time);
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.2f, %.2f)\n", i+1, planets[i].x_pos, planets[i].y_pos);
    }
}

int main() {
    int num_planets = 3;
    Planet planets[num_planets];

    // Initialize planets
    planets[0].mass = 5.97e24; // Earth
    planets[0].x_pos = 0;
    planets[0].y_pos = 0;
    planets[0].x_vel = 0;
    planets[0].y_vel = 0;

    planets[1].mass = 7.34e22; // Moon
    planets[1].x_pos = 384400000; // Distance from Earth
    planets[1].y_pos = 0;
    planets[1].x_vel = 0;
    planets[1].y_vel = 1022; // Velocity of Moon relative to Earth

    planets[2].mass = 1.89e27; // Jupiter
    planets[2].x_pos = 780000000; // Distance from Earth
    planets[2].y_pos = 0;
    planets[2].x_vel = 0;
    planets[2].y_vel = 13720; // Velocity of Jupiter relative to Earth

    double timestep = 3600; // 1 hour in seconds
    int num_steps = 24; // Number of steps to simulate in 1 day
    int i;

    // Simulate the system for one day
    for (i = 0; i < num_steps; i++) {
        update_planets(planets, num_planets, timestep);
        print_positions(planets, num_planets, i*timestep);
    }

    return 0;
}