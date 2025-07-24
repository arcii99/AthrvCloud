//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>

// Function to calculate the gravitational force between two objects
float gravitationalForce(float mass1, float mass2, float distance) {
    const float G = 6.67430e-11; // Universal gravitational constant
    return (G * mass1 * mass2) / (distance * distance);
}

int main() {
    float object1_mass, object2_mass, object_distance;

    printf("Enter mass of object 1 (in kg): ");
    scanf("%f", &object1_mass);

    printf("Enter mass of object 2 (in kg): ");
    scanf("%f", &object2_mass);

    printf("Enter distance between object 1 and object 2 (in meters): ");
    scanf("%f", &object_distance);

    float force = gravitationalForce(object1_mass, object2_mass, object_distance);

    printf("Gravitational force between object 1 and object 2 is %f N\n", force);

    return 0;
}