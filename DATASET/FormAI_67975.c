//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
    // Initializing variables
    float mass, velocity, distance;
    const float gravity = 9.81;

    // Taking user input
    printf("Enter the mass of the object in kg: ");
    scanf("%f", &mass);

    printf("Enter the velocity of the object in m/s: ");
    scanf("%f", &velocity);

    printf("Enter the distance of the object from the ground in m: ");
    scanf("%f", &distance);

    // Calculating force and work done
    float force = mass * gravity;
    float work_done = force * distance;

    // Calculating final velocity
    float final_velocity = sqrt(pow(velocity, 2) + (2 * work_done / mass));

    // Displaying results
    printf("The force acting on the object is %.2f N.\n", force);
    printf("The work done on the object is %.2f J.\n", work_done);
    printf("The final velocity of the object is %.2f m/s.\n", final_velocity);

    return 0;
}