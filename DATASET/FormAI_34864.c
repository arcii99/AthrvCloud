//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variables for simulation
    float g = 9.8; // Gravitational acceleration
    float mass = 1.0; // Object mass
    float x = 0.0; // Initial position
    float y = 0.0;
    float vx = 5.0; // Initial velocity
    float vy = -10.0;
    float dt = 0.01; // Time step size
    float t = 0.0; // Initial time
    float k = 0.5; // Air resistance coefficient
    float v = 0.0; // Magnitude of velocity

    // Variables for plotting
    int width = 80; // Terminal width
    int height = 24; // Terminal height
    char screen[height][width];
    int x_center = width / 2;
    int y_center = height / 2;

    // Initialize screen with spaces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            screen[i][j] = ' ';
        }
    }

    // Simulation loop
    while (y >= 0.0) {
        // Calculate air resistance
        v = sqrt(vx * vx + vy * vy);
        float fx = -k * v * vx;
        float fy = -mass * g - k * v * vy;

        // Update position and velocity
        x += vx * dt;
        y += vy * dt;
        vx += fx / mass * dt;
        vy += fy / mass * dt;

        // Update time
        t += dt;

        // Plot object on screen
        int x_pixel = (int) (x * width / 50 + x_center);
        int y_pixel = (int) (-y * height / 30 + y_center);
        if (x_pixel >= 0 && x_pixel < width && y_pixel >= 0 && y_pixel < height) {
            screen[y_pixel][x_pixel] = 'o';
        }

        // Print screen to terminal
        system("clear");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%c", screen[i][j]);
            }
            printf("\n");
        }

        // Wait for some time
        for (int i = 0; i < 10000000; i++);

    }

    return 0;
}