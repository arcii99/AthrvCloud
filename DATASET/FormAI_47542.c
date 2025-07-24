//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8

// Initial position (x,y) and velocity (vx,vy) of each planet
const double positions[NUM_PLANETS][4] = {
    {0.0, 0.0, 0.0, 0.0},   // Sun
    {-4.503402056000000E+09, -4.563413488491183E+10, 4.171432929643317E+03, -3.056548048205782E+02}, // Mercury
    {-1.056002176000000E+11, -2.823008736436604E+10, 9.711487998164462E+02, -3.484756604875570E+03}, // Venus
    {-1.472980399570279E+11, 9.201053568000000E+10, -2.983596296030064E+03, -4.793347155022052E+03}, // Earth
    {-2.117035671817277E+11, -2.125632006707760E+11, 2.020038133547127E+03, -1.877145864718400E+03}, // Mars
    {1.284123361566216E+09, 7.008965328871741E+11, -5.397972772716986E+03, 1.175053590197138E+02}, // Jupiter
    {6.319132516979116E+11, -1.956568972425527E+12, 5.554136917178206E+03, 1.391741430770227E+03}, // Saturn
    {-2.503648831246578E+12, 1.574349938580327E+12, -1.013887106031218E+03, -1.221181906805562E+03} // Uranus
};

const double G = 6.67430e-11; // gravitational constant

void update_positions(double positions[NUM_PLANETS][4], double dt) {
    // Update the positions of the planets based on their current velocities and acceleration due to gravity
    
    double acceleration[NUM_PLANETS][2] = {}; // array to store acceleration for each planet
    
    // calculate acceleration for each planet based on gravitational forces
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) { // do not calculate the planet's force on itself
                double dx = positions[j][0] - positions[i][0];
                double dy = positions[j][1] - positions[i][1];
                double distance = sqrt(dx*dx + dy*dy);
                double force = G / (distance * distance);
                acceleration[i][0] += force * dx / distance;
                acceleration[i][1] += force * dy / distance;
            }
        }
    }
    
    // update planet positions based on current velocities and acceleration
    for (int i = 0; i < NUM_PLANETS; i++) {
        positions[i][0] += positions[i][2] * dt;
        positions[i][1] += positions[i][3] * dt;
        positions[i][2] += acceleration[i][0] * dt;
        positions[i][3] += acceleration[i][1] * dt;
    }
}

void print_positions(double positions[NUM_PLANETS][4]) {
    // print the current positions of each planet
    
    printf("\nCurrent positions of planets (km):\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (%.2f, %.2f)\n", i, positions[i][0], positions[i][1]);
    }
}

int main() {
    double time = 0.0;
    double dt = 86400.0; // increment time by one day (in seconds) each iteration
    
    printf("Simulation of the Solar System\n");
    printf("Press Ctrl-C to stop simulation.\n");
    
    while (1) {
        // update planet positions and print current positions
        update_positions(positions, dt);
        print_positions(positions);
        
        // increment time
        time += dt;
    }
    
    return 0;
}