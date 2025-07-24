//FormAI DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
// It was a gloomy day in London, the year 1895. As Sherlock Holmes sat in his study, he was suddenly interrupted by Dr. Watson.

#include <stdio.h>
#include <math.h>

int main() {
    float mass1, mass2, distance, force, acceleration;

    printf("Hello Holmes, I bring a case to solve. We have two objects, each with a mass and a distance between them. We need to calculate the gravitational force between them.\n");
    printf("What is the mass of the first object in kg?\n");
    scanf("%f", &mass1);

    printf("What is the mass of the second object in kg?\n");
    scanf("%f", &mass2);

    printf("What is the distance between the objects in meters?\n");
    scanf("%f", &distance);

    force = (6.67 * pow(10, -11) * mass1 * mass2) / pow(distance, 2);
    acceleration = force / mass2;

    printf("According to the laws of physics, the gravitational force between the objects is %.2f N.\n", force);
    printf("The acceleration of the second object due to the gravitational force is %.2f m/s^2.\n", acceleration);
    printf("Our case is solved, Dr. Watson.\n");

    return 0;
}