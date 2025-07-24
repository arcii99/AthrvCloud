//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <math.h>
#define G 6.6743e-11 //constant of gravitation

int main()
{
    float mass1, mass2, distance, force;
    
    printf("Enter the mass of the first object: ");
    scanf("%f", &mass1);
    
    printf("Enter the mass of the second object: ");
    scanf("%f", &mass2);
    
    printf("Enter the distance between the two objects: ");
    scanf("%f", &distance);
    
    force = G * ((mass1 * mass2) / (pow(distance, 2))); //calculating force of attraction
    
    printf("The force of attraction between the two objects is: %.2f Newtons\n", force);
    
    return 0;
}