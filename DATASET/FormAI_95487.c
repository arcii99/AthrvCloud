//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define G_CONSTANT 6.67408e-11 // Gravitational Constant

// Structure to store all the properties of a planet
struct Planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

// Function to calculate the force exerted on a planet by another planet
void calculateForce(struct Planet *p1, struct Planet *p2, double *force_x, double *force_y, double *force_z) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force_magnitude = G_CONSTANT * p1->mass * p2->mass / (distance * distance);
    *force_x = force_magnitude * dx / distance;
    *force_y = force_magnitude * dy / distance;
    *force_z = force_magnitude * dz / distance;
}

// Function to update the velocity and position of a planet based on the force exerted on it
void updatePosition(struct Planet *p, double force_x, double force_y, double force_z, double dt) {
    double ax = force_x / p->mass;
    double ay = force_y / p->mass;
    double az = force_z / p->mass;
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->vz += az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// Function to print the properties of all the planets in the simulation
void printStatus(struct Planet *planets, int n) {
    printf("Planet\tMass (kg)\tX (m)\t\tY (m)\t\tZ (m)\t\tVx (m/s)\tVy (m/s)\tVz (m/s)\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t\t%.2e\t\t%.2e\n",
               planets[i].name, planets[i].mass, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }
}

int main() {
    // Set up the properties of the planets in the simulation
    struct Planet planets[3] = {{"Sun", 1.98e30, 0, 0, 0, 0, 0, 0},
                                 {"Earth", 5.98e24, 1.5e11, 0, 0, 0, 3e4, 0},
                                 {"Moon", 7.34e22, 1.5e11 + 3.84e8, 0, 0, 0, 3e4 + 1.02e3, 0}};
    int n = 3;
    double dt = 3600; // Time step for simulation
    
    // Simulation loop
    for (int i = 0; i < 100000; i++) {
        // Calculate the forces exerted on each planet by all the other planets
        double forces[n][3];
        for (int j = 0; j < n; j++) {
            double force_x = 0, force_y = 0, force_z = 0;
            for (int k = 0; k < n; k++) {
                if (j != k) {
                    double f_x, f_y, f_z;
                    calculateForce(&planets[j], &planets[k], &f_x, &f_y, &f_z);
                    force_x += f_x;
                    force_y += f_y;
                    force_z += f_z;
                }
            }
            forces[j][0] = force_x;
            forces[j][1] = force_y;
            forces[j][2] = force_z;
        }
        
        // Update the positions and velocities of each planet based on the forces exerted on them
        for (int j = 0; j < n; j++) {
            updatePosition(&planets[j], forces[j][0], forces[j][1], forces[j][2], dt);
        }
        
        // Print the status of the simulation every 1000 steps
        if (i % 1000 == 0) {
            printf("Step %d:\n", i);
            printStatus(planets, n);
        }
    }
}