//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define G 6.67408e-11 // Gravitational constant
#define WIDTH 80 // Width of screen
#define HEIGHT 24 // Height of screen
#define MAX_PLANETS 10 // Maximum number of planets
#define MAX_RADIUS 10 // Maximum radius of planets
#define MAX_MASS 10000 // Maximum mass of planets
#define MAX_INIT_VELOCITY 100 // Maximum initial velocity of planets
#define MAX_FORCE 100 // Maximum force applied to planets

// Define struct for planets
typedef struct {
    double x; // Horizontal position
    double y; // Vertical position
    double vx; // Horizontal velocity
    double vy; // Vertical velocity
    double mass; // Mass
    double radius; // Radius
} planet;

int main() {
    // Seed random number generator
    srand(time(0));

    // Initialize array of planets
    planet planets[MAX_PLANETS];

    // Initialize planets
    int num_planets = rand() % MAX_PLANETS + 1;
    for (int i = 0; i < num_planets; i++) {
        planets[i].x = rand() % WIDTH;
        planets[i].y = rand() % HEIGHT;
        planets[i].vx = (rand() % MAX_INIT_VELOCITY) * pow(-1, rand() % 2);
        planets[i].vy = (rand() % MAX_INIT_VELOCITY) * pow(-1, rand() % 2);
        planets[i].mass = rand() % MAX_MASS + 1;
        planets[i].radius = rand() % MAX_RADIUS + 1;
    }

    // Run simulation
    while (1) {
        // Clear screen
        system("clear");

        // Update positions of planets
        for (int i = 0; i < num_planets; i++) {
            double fx = 0;
            double fy = 0;

            // Calculate force on planet from other planets
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    double dx = planets[j].x - planets[i].x;
                    double dy = planets[j].y - planets[i].y;
                    double distance = sqrt(dx*dx + dy*dy);
                    double f = G * planets[i].mass * planets[j].mass / (distance * distance);

                    fx += f * dx / distance;
                    fy += f * dy / distance;
                }
            }

            // Calculate acceleration of planet
            double ax = fx / planets[i].mass;
            double ay = fy / planets[i].mass;

            // Update velocity of planet
            planets[i].vx += ax;
            planets[i].vy += ay;

            // Update position of planet
            planets[i].x += planets[i].vx;
            planets[i].y += planets[i].vy;

            // Bounce planet off edges of screen
            if (planets[i].x < 0 || planets[i].x > WIDTH) {
                planets[i].vx *= -1;
            }
            if (planets[i].y < 0 || planets[i].y > HEIGHT) {
                planets[i].vy *= -1;
            }
        }

        // Print planets to screen
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                char symbol = ' ';

                for (int i = 0; i < num_planets; i++) {
                    double dx = x - planets[i].x;
                    double dy = y - planets[i].y;
                    double distance = sqrt(dx*dx + dy*dy);

                    if (distance <= planets[i].radius) {
                        symbol = '#';
                        break;
                    }
                }

                printf("%c", symbol);
            }

            printf("\n");
        }

        // Delay for animation
        usleep(10000);
    }

    return 0;
}