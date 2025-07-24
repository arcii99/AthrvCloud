//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void projectile_motion(double angle, double velocity);

int main()
{
    double angle, velocity;

    printf("Enter the initial angle (0-90 degrees): ");
    scanf("%lf", &angle);

    printf("Enter the initial velocity (meters per second): ");
    scanf("%lf", &velocity);

    projectile_motion(angle, velocity);

    return 0;
}

void projectile_motion(double angle, double velocity)
{
    double time, range, height;
    int i;

    time = (2 * velocity * sin(angle * PI / 180)) / 9.81;
    range = (pow(velocity, 2) * sin(2 * angle * PI / 180)) / 9.81;
    height = pow((velocity * sin(angle * PI / 180)), 2) / (2 * 9.81);

    printf("Time of flight: %.2lf seconds\n", time);
    printf("Range: %.2lf meters\n", range);
    printf("Maximum height: %.2lf meters\n", height);

    printf("\nTrajectory of the projectile:\n");
    printf("========================================\n");

    for (i = 0; i <= 10; i++) {
        double t = (i * time) / 10;
        double x = (velocity * cos(angle * PI / 180) * t);
        double y = (velocity * sin(angle * PI / 180) * t) - (0.5 * 9.81 * pow(t, 2));

        printf("Time: %.2lf seconds, ", t);
        printf("Distance: %.2lf meters, ", x);
        printf("Height: %.2lf meters\n", y);
    }
}