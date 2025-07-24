//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include<stdio.h>
#include<math.h>
#define TIME_STEP 0.01 // Time step for simulation
#define GRAV_CONST 6.674 * pow(10,-11) // Gravitational constant
#define BOUNCE_FACTOR 0.95 // Factor of energy retained after collision with walls

// Defining a particle structure
typedef struct {
    double mass; // Mass of the particle in kg
    double x_pos; // X position of the particle in m
    double y_pos; // Y position of the particle in m
    double x_vel; // X velocity of the particle in m/s
    double y_vel; // Y velocity of the particle in m/s
    double x_acc; // X acceleration of the particle in m/s^2
    double y_acc; // Y acceleration of the particle in m/s^2
} Particle;

int main() {
    Particle particle1,particle2; // Creating two particles

    // Setting initial values for particle1
    particle1.mass = 10;
    particle1.x_pos = 0;
    particle1.y_pos = 0;
    particle1.x_vel = 0;
    particle1.y_vel = 10;
    particle1.x_acc = 0;
    particle1.y_acc = 0;

    // Setting initial values for particle2
    particle2.mass = 20;
    particle2.x_pos = 50;
    particle2.y_pos = 0;
    particle2.x_vel = 0;
    particle2.y_vel = -10;
    particle2.x_acc = 0;
    particle2.y_acc = 0;

    double distance = sqrt(pow((particle2.x_pos - particle1.x_pos),2) + pow((particle2.y_pos - particle1.y_pos),2)); // Finding initial distance between two particles
    double force_magnitude = GRAV_CONST * (particle1.mass * particle2.mass) / pow(distance,2); // Calculating gravitational force magnitude between the two particles

    particle1.x_acc = force_magnitude / particle1.mass * (particle2.x_pos - particle1.x_pos) / distance; // Calculating x acceleration for particle1
    particle1.y_acc = force_magnitude / particle1.mass * (particle2.y_pos - particle1.y_pos) / distance; // Calculating y acceleration for particle1

    particle2.x_acc = force_magnitude / particle2.mass * (particle1.x_pos - particle2.x_pos) / distance; // Calculating x acceleration for particle2
    particle2.y_acc = force_magnitude / particle2.mass * (particle1.y_pos - particle2.y_pos) / distance; // Calculating y acceleration for particle2

    while(1) {
        // Updating particle positions
        particle1.x_pos += particle1.x_vel * TIME_STEP + 0.5 * particle1.x_acc * pow(TIME_STEP,2);
        particle1.y_pos += particle1.y_vel * TIME_STEP + 0.5 * particle1.y_acc * pow(TIME_STEP,2);

        particle2.x_pos += particle2.x_vel * TIME_STEP + 0.5 * particle2.x_acc * pow(TIME_STEP,2);
        particle2.y_pos += particle2.y_vel * TIME_STEP + 0.5 * particle2.y_acc * pow(TIME_STEP,2);

        distance = sqrt(pow((particle2.x_pos - particle1.x_pos),2) + pow((particle2.y_pos - particle1.y_pos),2)); // Finding distance between two particles
        force_magnitude = GRAV_CONST * (particle1.mass * particle2.mass) / pow(distance,2); // Calculating gravitational force magnitude between the two particles

        // Calculating new accelerations based on the updated positions
        particle1.x_acc = force_magnitude / particle1.mass * (particle2.x_pos - particle1.x_pos) / distance;
        particle1.y_acc = force_magnitude / particle1.mass * (particle2.y_pos - particle1.y_pos) / distance;

        particle2.x_acc = force_magnitude / particle2.mass * (particle1.x_pos - particle2.x_pos) / distance;
        particle2.y_acc = force_magnitude / particle2.mass * (particle1.y_pos - particle2.y_pos) / distance;

        // Updating particle velocities based on the accelerations
        particle1.x_vel += particle1.x_acc * TIME_STEP;
        particle1.y_vel += particle1.y_acc * TIME_STEP;

        particle2.x_vel += particle2.x_acc * TIME_STEP;
        particle2.y_vel += particle2.y_acc * TIME_STEP;

        // Checking for collision with the walls
        if(particle1.x_pos < 0) {
            particle1.x_pos = -particle1.x_pos;
            particle1.x_vel = -BOUNCE_FACTOR * particle1.x_vel;
        }
        if(particle1.x_pos > 100) {
            particle1.x_pos = 200 - particle1.x_pos;
            particle1.x_vel = -BOUNCE_FACTOR * particle1.x_vel;
        }
        if(particle1.y_pos < 0) {
            particle1.y_pos = -particle1.y_pos;
            particle1.y_vel = -BOUNCE_FACTOR * particle1.y_vel;
        }
        if(particle1.y_pos > 100) {
            particle1.y_pos = 200 - particle1.y_pos;
            particle1.y_vel = -BOUNCE_FACTOR * particle1.y_vel;
        }

        if(particle2.x_pos < 0) {
            particle2.x_pos = -particle2.x_pos;
            particle2.x_vel = -BOUNCE_FACTOR * particle2.x_vel;
        }
        if(particle2.x_pos > 100) {
            particle2.x_pos = 200 - particle2.x_pos;
            particle2.x_vel = -BOUNCE_FACTOR * particle2.x_vel;
        }
        if(particle2.y_pos < 0) {
            particle2.y_pos = -particle2.y_pos;
            particle2.y_vel = -BOUNCE_FACTOR * particle2.y_vel;
        }
        if(particle2.y_pos > 100) {
            particle2.y_pos = 200 - particle2.y_pos;
            particle2.y_vel = -BOUNCE_FACTOR * particle2.y_vel;
        }
    }
    return 0;
}