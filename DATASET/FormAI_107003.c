//FormAI DATASET v1.0 Category: Physics simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define constants
#define GRAVITY 9.81
#define TIME_STEP 0.1
#define MIN_HEIGHT 5.0
#define MAX_HEIGHT 50.0
#define MIN_VELOCITY 10.0
#define MAX_VELOCITY 30.0

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables
    double height = (double)(rand() % (int)(MAX_HEIGHT - MIN_HEIGHT)) + MIN_HEIGHT;
    double velocity = (double)(rand() % (int)(MAX_VELOCITY - MIN_VELOCITY)) + MIN_VELOCITY;
    double angle = (double)(rand() % 90);
    double x = 0.0, y = height, t = 0.0;
    double vx = velocity * cos(angle * M_PI / 180);
    double vy = velocity * sin(angle * M_PI / 180);

    // Loop until projectile hits the ground
    while (y >= 0.0) {
        // Calculate new position and velocity components
        double ax = 0.0, ay = -GRAVITY;
        x += vx * TIME_STEP;
        y += vy * TIME_STEP + 0.5 * ay * pow(TIME_STEP, 2);
        vx += ax * TIME_STEP;
        vy += ay * TIME_STEP;
        t += TIME_STEP;

        // Print current position
        printf("t = %.2f sec, x = %.2f m, y = %.2f m\n", t, x, y);
    }

    // Print final time and distance travelled
    printf("Projectile hit the ground at t = %.2f sec and travelled a distance of %.2f m.\n", t, x);

    return 0;
}