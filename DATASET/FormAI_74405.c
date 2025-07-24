//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11 // gravitational constant
#define MAX_OBJ 10 // maximum number of objects

typedef struct {
    double x; // x coordinate
    double y; // y coordinate
    double vx; // x velocity
    double vy; // y velocity
    double mass; // mass
    double radius; // radius
    double color; // color
} Object;

double random_double(double min, double max) {
    return (max - min) * ((double)rand() / RAND_MAX) + min;
}

int main(void) {
    srand(time(NULL)); // initialize random seed

    Object objects[MAX_OBJ]; // create array of objects
    int n = 0; // number of objects

    // add initial objects
    objects[n++] = (Object){300e3, 300e3, random_double(-1000, 1000), random_double(-1000, 1000), 1e22, 50, 0};
    objects[n++] = (Object){500e3, 800e3, random_double(-1000, 1000), random_double(-1000, 1000), 1e21, 10, 1};
    objects[n++] = (Object){700e3, 200e3, random_double(-1000, 1000), random_double(-1000, 1000), 1e20, 5, 2};
    objects[n++] = (Object){900e3, 600e3, random_double(-1000, 1000), random_double(-1000, 1000), 1e19, 2, 3};

    double dt = 60 * 60 * 24 * 365; // time step of 1 year
    double t = 0; // current time

    printf("Starting simulation...\n");

    while (1) {
        // calculate total force on each object
        for (int i = 0; i < n; i++) {
            double fx = 0;
            double fy = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double dx = objects[j].x - objects[i].x;
                double dy = objects[j].y - objects[i].y;
                double d = sqrt(dx*dx + dy*dy);
                double f = G * objects[i].mass * objects[j].mass / (d*d);
                fx += f * dx / d;
                fy += f * dy / d;
            }
            objects[i].vx += fx / objects[i].mass * dt;
            objects[i].vy += fy / objects[i].mass * dt;
        }

        // update positions of all objects
        for (int i = 0; i < n; i++) {
            objects[i].x += objects[i].vx * dt;
            objects[i].y += objects[i].vy * dt;
        }

        // check for collisions
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double dx = objects[j].x - objects[i].x;
                double dy = objects[j].y - objects[i].y;
                double d = sqrt(dx*dx + dy*dy);
                if (d < objects[i].radius + objects[j].radius) {
                    // collision!
                    double total_mass = objects[i].mass + objects[j].mass;
                    double new_vx = (objects[i].mass * objects[i].vx + objects[j].mass * objects[j].vx) / total_mass;
                    double new_vy = (objects[i].mass * objects[i].vy + objects[j].mass * objects[j].vy) / total_mass;
                    double new_x = (objects[i].x + objects[j].x) / 2;
                    double new_y = (objects[i].y + objects[j].y) / 2;
                    objects[i].mass = total_mass;
                    objects[i].radius += objects[j].radius;
                    objects[i].vx = new_vx;
                    objects[i].vy = new_vy;
                    objects[i].x = new_x;
                    objects[i].y = new_y;
                    // remove object j by moving the last object in the array to its position
                    // and decrementing the number of objects
                    objects[j] = objects[--n];
                    j--;
                }
            }
        }

        // draw objects
        for (int i = 0; i < n; i++) {
            printf("%c ", 'A' + (int)objects[i].color);
            for (int j = 0; j < objects[i].radius * 2; j++) {
                printf("*");
            }
            printf("\n");
        }

        // sleep for a second to slow down the simulation
        // this is only necessary for visualizing the simulation on the console
        // in production code this would be removed
        usleep(1000000);

        t += dt;
    }

    return 0;
}