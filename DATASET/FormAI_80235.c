//FormAI DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define G 9.81      // gravitational constant

int main() {
    // variables 
    double height, time, velocity, distance;
    int i;

    // user input
    printf("Enter the height of the building in meters: ");
    scanf("%lf", &height);

    // calculating time to hit the ground
    time = sqrt((2 * height) / G);

    // printing time
    printf("\nTime taken to hit the ground: %.2lf seconds\n", time);

    // initial velocity and distance from ground
    velocity = G * time;
    distance = velocity * time;

    // printing initial velocity and distance
    printf("Initial velocity at the time of impact: %.2lf m/s\n", velocity);
    printf("Distance from the base of the building at the time of impact: %.2lf m\n", distance);

    // loop to display distance and velocity at 1 second intervals
    printf("\nDistance from the top of the building at every second:\n");
    for (i = 1; i <= time; i++) {
        distance = velocity * i - 0.5 * G * i * i;
        printf("%d second(s): %.2lf m\n", i, distance);
    }

    printf("\nVelocity at every second:\n");
    for (i = 0; i <= time; i++) {
        velocity = G * i;
        printf("%d second(s): %.2lf m/s\n", i, velocity);
    }

    return 0;
}