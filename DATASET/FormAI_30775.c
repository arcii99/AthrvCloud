//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double angle, velocity, time, x, y;
    double g = 9.81; // acceleration due to gravity in m/s^2
    printf("Enter the launch angle in degrees: ");
    scanf("%lf", &angle);
    angle = angle * PI / 180; // convert to radians
    printf("Enter the launch velocity in m/s: ");
    scanf("%lf", &velocity);
    printf("Enter the time interval in seconds: ");
    scanf("%lf", &time);
    x = 0;
    y = 0;
    while (y >= 0) {
        x = x + (velocity * cos(angle) * time);
        y = y + (velocity * sin(angle) * time) - (0.5 * g * time * time);
        if (y < 0) {
            y = 0;
        }
        printf("At time %.2f s, projectile is at distance %.2f m and height %.2f m\n", time, x, y);
        time = time + 0.1; // increase time by 0.1 s
    }
    return 0;
}