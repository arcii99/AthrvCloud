//FormAI DATASET v1.0 Category: Physics simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define gravity constant
#define GRAVITY 9.81

// Define ball structure
typedef struct ball {
    float x;
    float y;
    float vx;
    float vy;
    float ax;
    float ay;
    float radius;
} Ball;

// Function to generate random float value within a range
float rand_float(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize screen size
    float screen_width = 100;
    float screen_height = 50;

    // Initialize ball
    Ball ball;
    ball.x = rand_float(0, screen_width);
    ball.y = rand_float(0, screen_height);
    ball.vx = rand_float(-10, 10);
    ball.vy = rand_float(-10, 10);
    ball.ax = 0;
    ball.ay = GRAVITY;
    ball.radius = rand_float(1, 5);

    // Main loop
    while (1) {
        // Clear screen
        system("clear");

        // Update ball position and velocity
        ball.vx += ball.ax;
        ball.vy += ball.ay;
        ball.x += ball.vx;
        ball.y += ball.vy;

        // Check collision with walls
        if (ball.x <= ball.radius || ball.x >= screen_width - ball.radius) {
            ball.vx = -ball.vx;
        }
        if (ball.y <= ball.radius || ball.y >= screen_height - ball.radius) {
            ball.vy = -ball.vy;
        }

        // Draw ball on screen
        int i, j;
        for (i = 0; i < screen_height; i++) {
            for (j = 0; j < screen_width; j++) {
                if ((j - ball.x) * (j - ball.x) + (i - ball.y) * (i - ball.y) <= ball.radius * ball.radius) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Sleep for a short time
        usleep(1000000 / 30);
    }
    
    return 0;
}