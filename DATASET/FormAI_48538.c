//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11  // gravitational constant
#define NUM_PLANETS 3  // number of planets in the simulation

// structure to hold information about a planet
typedef struct planet_t{
    char name[20];
    double mass;
    double position[3];
    double velocity[3];
} planet;

// function to calculate the force between two planets
void calculate_force(double planet1_pos[], double planet2_pos[], double planet1_mass, double planet2_mass, double force[]){
    double dist, dist_squared;
    double unit_vec[3];
    
    // calculate distance between two planets
    dist_squared = pow((planet2_pos[0] - planet1_pos[0]), 2) + pow((planet2_pos[1] - planet1_pos[1]), 2) + pow((planet2_pos[2] - planet1_pos[2]), 2);
    dist = sqrt(dist_squared);
    
    // calculate unit vector in the direction of the other planet
    unit_vec[0] = (planet2_pos[0] - planet1_pos[0]) / dist;
    unit_vec[1] = (planet2_pos[1] - planet1_pos[1]) / dist;
    unit_vec[2] = (planet2_pos[2] - planet1_pos[2]) / dist;
    
    // calculate force between two planets
    double magnitude = G * (planet1_mass * planet2_mass) / dist_squared;
    force[0] = magnitude * unit_vec[0];
    force[1] = magnitude * unit_vec[1];
    force[2] = magnitude * unit_vec[2];
}

// function to update velocity and position of a planet based on the force acting on it
void update_planet(planet *p, double force[], double time_step){
    double acceleration[3];
    acceleration[0] = force[0] / p->mass;
    acceleration[1] = force[1] / p->mass;
    acceleration[2] = force[2] / p->mass;
    
    p->velocity[0] += acceleration[0] * time_step;
    p->velocity[1] += acceleration[1] * time_step;
    p->velocity[2] += acceleration[2] * time_step;
    
    p->position[0] += p->velocity[0] * time_step;
    p->position[1] += p->velocity[1] * time_step;
    p->position[2] += p->velocity[2] * time_step;
}

int main(){
    // initialize the planets
    planet planets[NUM_PLANETS];
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.976e24;
    planets[0].position[0] = 0;
    planets[0].position[1] = 0;
    planets[0].position[2] = 0;
    planets[0].velocity[0] = 0;
    planets[0].velocity[1] = 0;
    planets[0].velocity[2] = 0;

    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.421e23;
    planets[1].position[0] = 227.9e9;
    planets[1].position[1] = 0;
    planets[1].position[2] = 0;
    planets[1].velocity[0] = 0;
    planets[1].velocity[1] = 24.077e3;
    planets[1].velocity[2] = 0;

    strcpy(planets[2].name, "Jupiter");
    planets[2].mass = 1.898e27;
    planets[2].position[0] = 778.3e9;
    planets[2].position[1] = 0;
    planets[2].position[2] = 0;
    planets[2].velocity[0] = 0;
    planets[2].velocity[1] = 13.07e3;
    planets[2].velocity[2] = 0;

    // run the simulation
    double time_step = 86400;  // one day
    double force[3];
    int i, j, k;
    for (k = 0; k < 365; k++){
        for (i = 0; i < NUM_PLANETS; i++){
            for (j = 0; j < NUM_PLANETS; j++){
                if (i == j) continue;
                calculate_force(planets[i].position, planets[j].position, planets[i].mass, planets[j].mass, force);
                update_planet(&planets[i], force, time_step);
            }
        }
        printf("Day %d:\n", k+1);
        for (i = 0; i < NUM_PLANETS; i++){
            printf("%s: x=%.0fkm y=%.0fkm z=%.0fkm\n", planets[i].name, planets[i].position[0]/1000, planets[i].position[1]/1000, planets[i].position[2]/1000);
        }
    }
    return 0;
}