//FormAI DATASET v1.0 Category: Physics simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define GRAVITY 9.8

typedef struct {
    double xPos;
    double yPos;
    double xVel;
    double yVel;
} Particle;

int main() {
    srand(time(NULL));

    int i, j;
    Particle particles[10];

    // Initialize particles with random positions and velocities
    for (i = 0; i < 10; i++) {
        particles[i].xPos = rand() % SCREEN_WIDTH;
        particles[i].yPos = rand() % SCREEN_HEIGHT;
        particles[i].xVel = rand() % 10 - 5;
        particles[i].yVel = rand() % 10 - 5;
    }

    // Main loop
    while (1) {
        // Clear the screen
        system("clear");

        // Update particle positions and velocities
        for (i = 0; i < 10; i++) {
            particles[i].yVel += GRAVITY;
            particles[i].xPos += particles[i].xVel;
            particles[i].yPos += particles[i].yVel;

            // Handle collisions with walls
            if (particles[i].xPos < 0 || particles[i].xPos >= SCREEN_WIDTH) {
                particles[i].xVel = -particles[i].xVel;
            }
            if (particles[i].yPos < 0 || particles[i].yPos >= SCREEN_HEIGHT) {
                particles[i].yVel = -particles[i].yVel * 0.8;
                particles[i].yPos = SCREEN_HEIGHT - 1;
            }

            // Draw particle
            for (j = 0; j < SCREEN_HEIGHT; j++) {
                if (j == (int) round(particles[i].yPos) && particles[i].xPos >= 0
                        && particles[i].xPos < SCREEN_WIDTH) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Wait
        usleep(50000);
    }

    return 0;
}