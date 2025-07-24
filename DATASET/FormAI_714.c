//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743*pow(10,-11) // gravitational constant

struct planet {
    char name[20];
    double mass; // in kg
    double position[3]; // in m
    double velocity[3]; // in m/s
};

void simulate(double time, double dt, int num_planets, struct planet* planets) {
    double force[3], distance, acceleration[3];
    for(int i = 0; i < num_planets; i++) {
        for(int j = 0; j < num_planets; j++) {
            if(i == j) continue;
            distance = sqrt(pow((planets[j].position[0] - planets[i].position[0]), 2) 
                + pow((planets[j].position[1] - planets[i].position[1]), 2)
                + pow((planets[j].position[2] - planets[i].position[2]), 2));
            force[0] = G * (planets[i].mass * planets[j].mass) / pow(distance, 2) * (planets[j].position[0] - planets[i].position[0]) / distance;
            force[1] = G * (planets[i].mass * planets[j].mass) / pow(distance, 2) * (planets[j].position[1] - planets[i].position[1]) / distance;
            force[2] = G * (planets[i].mass * planets[j].mass) / pow(distance, 2) * (planets[j].position[2] - planets[i].position[2]) / distance;
            acceleration[0] = force[0] / planets[i].mass;
            acceleration[1] = force[1] / planets[i].mass;
            acceleration[2] = force[2] / planets[i].mass;
            planets[i].velocity[0] += acceleration[0] * dt;
            planets[i].velocity[1] += acceleration[1] * dt;
            planets[i].velocity[2] += acceleration[2] * dt;
        }
    }
    for(int i = 0; i < num_planets; i++) {
        planets[i].position[0] += planets[i].velocity[0] * dt;
        planets[i].position[1] += planets[i].velocity[1] * dt;
        planets[i].position[2] += planets[i].velocity[2] * dt;
        printf("Position of planet %s at time %f seconds: (%f, %f, %f)\n", planets[i].name, time, 
            planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
}

int main() {
    int num_planets = 2;
    double time = 0, dt = 60; // time and time step in seconds
    struct planet planets[num_planets];
    // Customize your planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97*pow(10, 24);
    planets[0].position[0] = 147.09*pow(10,9);
    planets[0].position[1] = 0;
    planets[0].position[2] = 0;
    planets[0].velocity[0] = 0;
    planets[0].velocity[1] = 30300;
    planets[0].velocity[2] = 0;
 
    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.39*pow(10, 23);
    planets[1].position[0] = 0;
    planets[1].position[1] = 206.62*pow(10, 9);
    planets[1].position[2] = 0;
    planets[1].velocity[0] = 24130;
    planets[1].velocity[1] = 0;
    planets[1].velocity[2] = 0;
 
    // Simulate for 1 day (86400 seconds)
    while(time <= 86400) {
        simulate(time, dt, num_planets, planets);
        time += dt;
    }
    return 0;
}