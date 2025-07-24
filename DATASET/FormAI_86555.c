//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OF_PLANETS 5
#define G_CONST 6.67430e-11

typedef struct {
    char name[20];
    double mass; //in kg
    double x_pos; //in m
    double y_pos; //in m
    double x_vel; //in m/s
    double y_vel; //in m/s
} planet;

int main(void) {
    planet planets[NUM_OF_PLANETS];
    double time_step = 3600.0; //in s
    double sim_time = 365 * 24 * 3600.0; //in s
    int i, j;
    
    //initialize planets
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.989e30;
    planets[0].x_pos = 0.0;
    planets[0].y_pos = 0.0;
    planets[0].x_vel = 0.0;
    planets[0].y_vel = 0.0;
    
    strcpy(planets[1].name, "Mercury");
    planets[1].mass = 3.285e23;
    planets[1].x_pos = 57.9e9;
    planets[1].y_pos = 0.0;
    planets[1].x_vel = 0.0;
    planets[1].y_vel = 47.4e3;

    strcpy(planets[2].name, "Venus");
    planets[2].mass = 4.867e24;
    planets[2].x_pos = 108.2e9;
    planets[2].y_pos = 0.0;
    planets[2].x_vel = 0.0;
    planets[2].y_vel = 35.0e3;

    strcpy(planets[3].name, "Earth");
    planets[3].mass = 5.972e24;
    planets[3].x_pos = 149.6e9;
    planets[3].y_pos = 0.0;
    planets[3].x_vel = 0.0;
    planets[3].y_vel = 29.8e3;

    strcpy(planets[4].name, "Mars");
    planets[4].mass = 6.39e23;
    planets[4].x_pos = 227.9e9;
    planets[4].y_pos = 0.0;
    planets[4].x_vel = 0.0;
    planets[4].y_vel = 24.1e3;
    
    //simulation loop
    for (double t = 0; t < sim_time; t += time_step) {
        //calculate net force on each planet
        for (i = 0; i < NUM_OF_PLANETS; i++) {
            double net_x_force = 0.0;
            double net_y_force = 0.0;
            for (j = 0; j < NUM_OF_PLANETS; j++) {
                if (i == j) {
                    continue;
                }
                double dx = planets[j].x_pos - planets[i].x_pos;
                double dy = planets[j].y_pos - planets[i].y_pos;
                double r = sqrt(dx*dx + dy*dy);
                double force = G_CONST * planets[i].mass * planets[j].mass / (r*r);
                net_x_force += force * dx / r;
                net_y_force += force * dy / r;
            }
            //update velocities using net forces
            double accel_x = net_x_force / planets[i].mass;
            double accel_y = net_y_force / planets[i].mass;
            planets[i].x_vel += accel_x * time_step;
            planets[i].y_vel += accel_y * time_step;
        }
        //update positions using velocities
        for (i = 0; i < NUM_OF_PLANETS; i++) {
            planets[i].x_pos += planets[i].x_vel * time_step;
            planets[i].y_pos += planets[i].y_vel * time_step;
        }
    }
    
    //print final positions of planets
    printf("Final positions of planets:\n");
    for (i = 0; i < NUM_OF_PLANETS; i++) {
        printf("%s: (%.2e, %.2e)\n", planets[i].name, planets[i].x_pos, planets[i].y_pos);
    }
    
    return 0;
}