//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: realistic
#include <stdio.h>
#include <math.h>

#define GRAV_CONSTANT 6.67408e-11 // gravitational constant in m^3/(kg*s^2)
#define TIME_STEP 3600 // time step for simulation in seconds
#define TOTAL_TIME 31536000 // total time for simulation in seconds (1 year)
#define NUM_OF_PLANETS 8 // number of planets in the solar system

struct planet {
    char name[20];
    double mass; // in kg
    double radius; // in meters
    double pos[3]; // x, y, and z coordinates in m
    double vel[3]; // x, y, and z velocities in m/s
    double acc[3]; // x, y, and z accelerations in m/s^2
};

struct planet solar_system[NUM_OF_PLANETS] = {
    {"Mercury", 0.330e24, 2440e3, {-46001209093, -10893664367, 3113082277}, {-14160, -38870, -10750}},
    {"Venus", 4.87e24, 6052e3, {-45572476216, 35906412655, 1458029834}, {-36930, -25490, 7270}},
    {"Earth", 5.97e24, 6371e3, {114222638679, 15895252040, -1243326859}, {3450, 29657, -305}},
    {"Mars", 0.642e24, 3390e3, {35367301186, 22791340022, -6812085789}, {-22340, 22729, 5140}},
    {"Jupiter", 1898e24, 69911e3, {611798107490, -418869840725, -129752380007}, {8530, 12370, -2710}},
    {"Saturn", 568e24, 58232e3, {1436662751026, -544162953172, -219381244325}, {4540, 9340, -1580}},
    {"Uranus", 86.8e24, 25362e3, {2742621570659, 1723843635176, -29316708754}, {-3210, 5260, 70}},
    {"Neptune", 102e24, 24622e3, {4358754282685, -1077581232476, -78003466548}, {1300, 5310, -1510}}
};

void update_velocity(struct planet *p1, struct planet *p2) {
    double r_vector[3];
    double distance;
    double force_magnitude;
    double force_vector[3];
    
    // calculate distance between p1 and p2
    for (int i = 0; i < 3; i++) {
        r_vector[i] = p2->pos[i] - p1->pos[i];
    }
    distance = sqrt(pow(r_vector[0], 2) + pow(r_vector[1], 2) + pow(r_vector[2], 2));
    
    // calculate force between p1 and p2
    force_magnitude = GRAV_CONSTANT * p1->mass * p2->mass / pow(distance, 2);
    for (int i = 0; i < 3; i++) {
        force_vector[i] = force_magnitude * r_vector[i] / distance;
    }
    
    // update p1's velocity based on force
    for (int i = 0; i < 3; i++) {
        p1->vel[i] += force_vector[i] / p1->mass * TIME_STEP;
    }
}

void update_position(struct planet *p) {
    for (int i = 0; i < 3; i++) {
        p->pos[i] += p->vel[i] * TIME_STEP;
    }
}

int main() {
    for (int i = 0; i < TOTAL_TIME / TIME_STEP; i++) {
        // update each planet's acceleration based on gravitational forces from all other planets
        for (int j = 0; j < NUM_OF_PLANETS; j++) {
            solar_system[j].acc[0] = 0;
            solar_system[j].acc[1] = 0;
            solar_system[j].acc[2] = 0;
            for (int k = 0; k < NUM_OF_PLANETS; k++) {
                if (j != k) {
                    update_velocity(&solar_system[j], &solar_system[k]);
                }
            }
        }
        // update each planet's position and velocity based on acceleration
        for (int j = 0; j < NUM_OF_PLANETS; j++) {
            update_position(&solar_system[j]);
        }
    }
    // print out final positions of each planet
    for (int i = 0; i < NUM_OF_PLANETS; i++) {
        printf("%s: (%.0f, %.0f, %.0f)\n", solar_system[i].name, solar_system[i].pos[0], solar_system[i].pos[1], solar_system[i].pos[2]);
    }
    return 0;
}