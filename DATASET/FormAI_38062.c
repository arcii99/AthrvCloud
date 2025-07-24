//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

double calcPeriod(double l, double g);
double calcAngle(double l, double a, double v, double t);

int main() {
    double length, initialAngle, initialVelocity, time;
    printf("Enter length of pendulum (in meters): ");
    scanf("%lf", &length);
    printf("Enter initial angle (in degrees): ");
    scanf("%lf", &initialAngle);
    printf("Enter initial velocity (in meters/second): ");
    scanf("%lf", &initialVelocity);
    printf("Enter time step (in seconds): ");
    scanf("%lf", &time);

    double gravity = 9.81; // acceleration due to gravity, in meters/second^2
    double period = calcPeriod(length, gravity);
    double angle = initialAngle * PI / 180; // converting to radians
    double velocity = initialVelocity;
    double timeElapsed = 0;

    while (timeElapsed <= 20 * period) {
        angle = calcAngle(length, angle, velocity, time);
        velocity += (-1 * gravity / length) * sin(angle) * time;
        timeElapsed += time;
        printf("%lf %lf\n", timeElapsed, angle * 180 / PI); // converting back to degrees
    }

    return 0;
}

double calcPeriod(double l, double g) {
    return 2 * PI * sqrt(l / g);
}

double calcAngle(double l, double a, double v, double t) {
    if (t == 0) {
        return a;
    } else {
        double acceleration = (-1 * 9.81 / l) * sin(a);
        double newAngle = a + v * t + 0.5 * acceleration * pow(t, 2);
        return calcAngle(l, newAngle, v + acceleration * t, t / 2);
    }
}