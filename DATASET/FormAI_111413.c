//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430E-11 //Gravitational constant
#define DAY 86400 //Number of seconds in a day

struct planet {
    char name[12];
    double mass; //kg
    double x, y, z; //position coordinates in meters
    double vx, vy, vz; //velocity components in meters per second
    double fx, fy, fz; //force components in N
    double ax, ay, az; //acceleration components in m/s^2
};

void update_forces(struct planet planets[], int num_planets) {
    int i, j;
    double distance, force, x_diff, y_diff, z_diff;
    for (i = 0; i < num_planets; i++) {
        planets[i].fx = 0;
        planets[i].fy = 0;
        planets[i].fz = 0;
        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                x_diff = planets[j].x - planets[i].x;
                y_diff = planets[j].y - planets[i].y;
                z_diff = planets[j].z - planets[i].z;
                distance = sqrt(x_diff*x_diff + y_diff*y_diff + z_diff*z_diff);
                force = G * planets[i].mass * planets[j].mass / (distance * distance);
                planets[i].fx += force * x_diff / distance;
                planets[i].fy += force * y_diff / distance;
                planets[i].fz += force * z_diff / distance;
            }
        }
    }
}

void update_velocities_positions(struct planet planets[], int num_planets, double time_step) {
    int i;
    for (i = 0; i < num_planets; i++) {
        //update velocities
        planets[i].vx += planets[i].fx / planets[i].mass * time_step;
        planets[i].vy += planets[i].fy / planets[i].mass * time_step;
        planets[i].vz += planets[i].fz / planets[i].mass * time_step;
        //update positions
        planets[i].x += planets[i].vx * time_step;
        planets[i].y += planets[i].vy * time_step;
        planets[i].z += planets[i].vz * time_step;
    }
}

void print_planet_data(struct planet planets[], int num_planets, int day) {
    int i;
    printf("Day %d:\n", day);
    for (i = 0; i < num_planets; i++) {
        printf("%s - Position: (%.2e, %.2e, %.2e) m; Velocity: (%.2e, %.2e, %.2e) m/s\n",
            planets[i].name, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }
    printf("\n");
}

int main() {
    //define planets
    struct planet sun = {"Sun", 1.989E+30, 0, 0, 0, 0, 0, 0};
    struct planet earth = {"Earth", 5.974E+24, 1.49597871E+11, 0, 0, 0, 29783, 0};
    struct planet moon = {"Moon", 7.348E+22, 1.49597871E+11 + 384400000, 0, 0, 0, 29783 + 1022, 0};
    struct planet mars = {"Mars", 6.39E+23, 2.279E+11, 0, 0, 0, 24130, 0};
    struct planet planets[] = {sun, earth, moon, mars};
    int num_planets = 4;
    
    //run simulation for 365 days
    int num_days = 365;
    int i;
    for (i = 0; i < num_days; i++) {
        update_forces(planets, num_planets);
        update_velocities_positions(planets, num_planets, DAY);
        print_planet_data(planets, num_planets, i+1);
    }

    return 0;
}