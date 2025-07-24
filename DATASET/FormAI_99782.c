//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Define solar system constants
#define G 6.6743e-11 // gravitational constant
#define AU 1.496e11 // astronomical unit

// Define celestial body structure
typedef struct {
    char *name; // name of the celestial body
    double mass; // mass in kg
    double radius; // radius in m
    double pos[3]; // position in m
    double vel[3]; // velocity in m/s
} CelestialBody;

// Calculate force between two objects
void calculate_force(CelestialBody *body1, CelestialBody *body2, double force[3]){
    double distance = sqrt(pow(body1->pos[0]-body2->pos[0], 2) + pow(body1->pos[1]-body2->pos[1], 2) + pow(body1->pos[2]-body2->pos[2], 2));
    double magnitude = G * body1->mass * body2->mass / pow(distance, 2);
    force[0] = magnitude * (body2->pos[0] - body1->pos[0]) / distance;
    force[1] = magnitude * (body2->pos[1] - body1->pos[1]) / distance;
    force[2] = magnitude * (body2->pos[2] - body1->pos[2]) / distance;
}

// Update position and velocity of celestial body
void update_position(CelestialBody *body, double force[3], double time_step){
    double acceleration[3];
    acceleration[0] = force[0] / body->mass;
    acceleration[1] = force[1] / body->mass;
    acceleration[2] = force[2] / body->mass;
    body->pos[0] += body->vel[0] * time_step + 0.5 * acceleration[0] * pow(time_step, 2);
    body->pos[1] += body->vel[1] * time_step + 0.5 * acceleration[1] * pow(time_step, 2);
    body->pos[2] += body->vel[2] * time_step + 0.5 * acceleration[2] * pow(time_step, 2);
    body->vel[0] += acceleration[0] * time_step;
    body->vel[1] += acceleration[1] * time_step;
    body->vel[2] += acceleration[2] * time_step;
}

int main(){
    // Seed random number generator
    srand(time(NULL));
    
    // Define celestial bodies in the solar system
    CelestialBody sun = {"Sun", 1.989e30, 696340000, {0, 0, 0}, {0, 0, 0}};
    CelestialBody earth = {"Earth", 5.972e24, 6371000, {AU, 0, 0}, {0, sqrt(G*sun.mass/AU), 0}};
    CelestialBody moon = {"Moon", 7.342e22, 1737100, {AU+384400000, 0, 0}, {0, sqrt(G*(sun.mass+earth.mass)/(AU+384400000)), 0}};
    CelestialBody jupiter = {"Jupiter", 1.898e27, 69911000, {5.2*AU, 0, 0}, {0, sqrt(G*sun.mass/(5.2*AU)), 0}};
    
    // Define simulation parameters
    double time_step = 3600;
    int num_steps = 87600;
    
    // Initialize force and acceleration arrays
    double force_s_e[3], force_s_m[3], force_s_j[3];
    double force_e_s[3], force_e_m[3], force_e_j[3];
    double force_m_s[3], force_m_e[3], force_m_j[3];
    double force_j_s[3], force_j_e[3], force_j_m[3];
    
    // Run simulation
    for (int i = 0; i < num_steps; i++){
        // Calculate forces
        calculate_force(&sun, &earth, force_s_e);
        calculate_force(&sun, &moon, force_s_m);
        calculate_force(&sun, &jupiter, force_s_j);
        calculate_force(&earth, &sun, force_e_s);
        calculate_force(&earth, &moon, force_e_m);
        calculate_force(&earth, &jupiter, force_e_j);
        calculate_force(&moon, &sun, force_m_s);
        calculate_force(&moon, &earth, force_m_e);
        calculate_force(&moon, &jupiter, force_m_j);
        calculate_force(&jupiter, &sun, force_j_s);
        calculate_force(&jupiter, &earth, force_j_e);
        calculate_force(&jupiter, &moon, force_j_m);
        
        // Update positions and velocities
        update_position(&sun, force_s_e, time_step);
        update_position(&sun, force_s_m, time_step);
        update_position(&sun, force_s_j, time_step);
        update_position(&earth, force_e_s, time_step);
        update_position(&earth, force_e_m, time_step);
        update_position(&earth, force_e_j, time_step);
        update_position(&moon, force_m_s, time_step);
        update_position(&moon, force_m_e, time_step);
        update_position(&moon, force_m_j, time_step);
        update_position(&jupiter, force_j_s, time_step);
        update_position(&jupiter, force_j_e, time_step);
        update_position(&jupiter, force_j_m, time_step);
        
        // Print positions of celestial bodies every 10 years
        if (i % (8760*10) == 0){
            printf("Year %d\n", i/8760);
            printf("Sun: x=%f, y=%f, z=%f\n", sun.pos[0], sun.pos[1], sun.pos[2]);
            printf("Earth: x=%f, y=%f, z=%f\n", earth.pos[0], earth.pos[1], earth.pos[2]);
            printf("Moon: x=%f, y=%f, z=%f\n", moon.pos[0], moon.pos[1], moon.pos[2]);
            printf("Jupiter: x=%f, y=%f, z=%f\n\n", jupiter.pos[0], jupiter.pos[1], jupiter.pos[2]);
        }
    }
    
    return 0;
}