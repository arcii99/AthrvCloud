//FormAI DATASET v1.0 Category: Physics simulation ; Style: brave
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define GRAVITY 9.81

int main() {
    double angle, velocity, distance, height, time;
    double x, y;
    double initialVelocityX, initialVelocityY, timeInterval;
    int i;

    printf("Enter the angle of projection (in degrees): ");
    scanf("%lf", &angle);

    printf("Enter the velocity of projection (in m/s): ");
    scanf("%lf", &velocity);

    printf("Enter the initial height of the projectile (in meters): ");
    scanf("%lf", &height);

    distance = 0;
    time = 0;
    timeInterval = 0.05; // 50 milliseconds

    // Convert angle from degrees to radians
    angle = angle * PI / 180;

    initialVelocityX = velocity * cos(angle);
    initialVelocityY = velocity * sin(angle);

    printf("\n Projectile Motion:\n");

    for (i = 1; y >= 0; i++) {
        x = initialVelocityX * time;
        y = initialVelocityY * time - 0.5 * GRAVITY * pow(time, 2) + height;

        printf(" Time: %.2f s \t\t Distance: %.2f m \t Height: %.2f m \n", time, x, y);

        time += timeInterval;
        distance = x;
    }

    printf("\n The projectile hit the ground at a distance of %.2f meters. \n", distance);

    return 0;
}