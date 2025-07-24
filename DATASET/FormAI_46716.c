//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 40
#define PARTICLES 100
#define GRAVITY 0.1

typedef struct particle_t {
    float x, y, vx, vy, ax, ay;
} particle;

int main() {
    particle particles[PARTICLES];
    char screen[WIDTH * HEIGHT];
    float timestep = 0.1;
    float friction = 0.1;
    int i, j;

    // Initialize particles
    srand(time(NULL));
    for (i = 0; i < PARTICLES; i++) {
        particles[i].x = rand() % WIDTH;
        particles[i].y = rand() % HEIGHT;
        particles[i].vx = rand() % 10;
        particles[i].vy = rand() % 10;
        particles[i].ax = 0;
        particles[i].ay = 0;
    }

    // Simulation loop
    while (1) {
        // Clear screen
        for (i = 0; i < WIDTH * HEIGHT; i++) {
            screen[i] = ' ';
        }

        // Apply gravity and friction to particles
        for (i = 0; i < PARTICLES; i++) {
            particles[i].ax = 0;
            particles[i].ay = GRAVITY;

            particles[i].vx -= particles[i].vx * friction;
            particles[i].vy -= particles[i].vy * friction;

            particles[i].vx += particles[i].ax * timestep;
            particles[i].vy += particles[i].ay * timestep;

            particles[i].x += particles[i].vx * timestep;
            particles[i].y += particles[i].vy * timestep;

            // Check for collisions with walls
            if (particles[i].x < 0) {
                particles[i].x = 0;
                particles[i].vx *= -1;
            }
            if (particles[i].x > WIDTH) {
                particles[i].x = WIDTH;
                particles[i].vx *= -1;
            }
            if (particles[i].y < 0) {
                particles[i].y = 0;
                particles[i].vy *= -1;
            }
            if (particles[i].y > HEIGHT) {
                particles[i].y = HEIGHT;
                particles[i].vy *= -1;
            }

            // Place particle on screen
            screen[(int)particles[i].x + (int)particles[i].y * WIDTH] = '*';
        }

        // Print screen
        printf("\033[2J"); // Clear terminal screen
        for (j = 0; j < HEIGHT; j++) {
            for (i = 0; i < WIDTH; i++) {
                putchar(screen[i + j * WIDTH]);
            }
            putchar('\n');
        }

        // Sleep for a short time
        usleep(50000);
    }
}