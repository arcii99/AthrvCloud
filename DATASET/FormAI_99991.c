//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8 // acceleration due to gravity in m/s^2

int main() {
    float velocity, angle, time, x, y;
    float rad;
    float tmax;
    float xOld = 0, yOld = 0; // for plotting the trajectory

    printf("Enter initial velocity (in m/s): ");
    scanf("%f", &velocity);

    printf("Enter angle of projection (in degrees): ");
    scanf("%f", &angle);

    rad = (angle * M_PI) / 180; // convert to radians

    printf("Enter time increment(deltaT): ");
    scanf("%f", &time);

    printf("Enter maximum time (seconds): ");
    scanf("%f", &tmax);

    printf("\n");

    printf("TIME\tX\tY\n");

    for (float t = 0; t <= tmax; t += time) {
        x = velocity * cos(rad) * t;
        y = (velocity * sin(rad) * t) - (0.5 * GRAVITY * pow(t, 2));

        printf("%.2f\t%.2f\t%.2f\n", t, x, y);

        // plot the trajectory
        printf("PLOT %f,%f\n", xOld, yOld);
        printf("PLOT %f,%f\n", x, y);

        xOld = x;
        yOld = y;
    }

    return 0;
}