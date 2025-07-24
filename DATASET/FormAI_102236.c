//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include <stdio.h>
#include <math.h>
#define GRAVITY 10

int main() {
    float x1, y1, m1, x2, y2, m2, distance, force, acceleration;
    printf("Enter the x,y coordinates and mass of object 1: ");
    scanf("%f %f %f", &x1, &y1, &m1);
    printf("Enter the x,y coordinates and mass of object 2: ");
    scanf("%f %f %f", &x2, &y2, &m2);
    distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    force = (GRAVITY * m1 * m2)/ pow(distance,2);
    acceleration = force / m1;
    printf("The gravitational force between the objects is: %f\n", force);
    printf("The acceleration of object 1 towards object 2 is: %f\n", acceleration);
    printf("Enter any character to simulate the gravity: ");
    getchar();
    //simulate the gravity
    for(int i=0; i<10; i++) {
        x1 += (0.5*acceleration*pow(i,2));
        y1 += (0.5*acceleration*pow(i,2));
        printf("Object 1 is moving towards object 2. New position: (%f, %f)\n", x1, y1);
        getchar();
    }
    printf("Object 1 has reached object 2. Love has triumphed in the gravitational field.\n");
    return 0;
}