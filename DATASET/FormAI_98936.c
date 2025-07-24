//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>

/* This program calculates the volume of a cube and a sphere */

int main(void) {
    int cubeSide;
    float sphereRadius, cubeVolume, sphereVolume;
    
    printf("Enter the length of the side of the cube: ");
    scanf("%d", &cubeSide);
    
    printf("Enter the radius of the sphere: ");
    scanf("%f", &sphereRadius);
    
    // Calculate the volume of the cube
    cubeVolume = cubeSide * cubeSide * cubeSide;
    
    // Calculate the volume of the sphere
    sphereVolume = (4.0 / 3.0) * 3.141592 * sphereRadius * sphereRadius * sphereRadius;
    
    printf("\nVolume of cube: %.2f", cubeVolume);
    printf("\nVolume of sphere: %.2f", sphereVolume);
    
    if (cubeVolume < sphereVolume) {
        printf("\nThe sphere has a greater volume.");
    } else if (sphereVolume < cubeVolume) {
        printf("\nThe cube has a greater volume.");
    } else {
        printf("\nThe sphere and cube have the same volume.");
    }
    
    return 0;
}