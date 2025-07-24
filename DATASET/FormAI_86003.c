//FormAI DATASET v1.0 Category: Physics simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to the Shape-Shifting Physics Simulation Program!\n\n");
    
    int shape_choice;
    float length, width, height, radius, volume, surface_area;
    
    do {
        printf("Choose a shape to simulate:\n");
        printf("1. Cube\n");
        printf("2. Sphere\n");
        printf("3. Cylinder\n");
        printf("4. Quit program\n");
        scanf("%d", &shape_choice);
        
        switch(shape_choice) {
            case 1:
                printf("\nYou have chosen the cube.\n");
                printf("Enter the length of the cube: ");
                scanf("%f", &length);
                
                volume = length * length * length;
                surface_area = 6 * length * length;
                
                printf("\nThe volume of the cube is: %.2f\n", volume);
                printf("The surface area of the cube is: %.2f\n\n", surface_area);
                break;
                
            case 2:
                printf("\nYou have chosen the sphere.\n");
                printf("Enter the radius of the sphere: ");
                scanf("%f", &radius);
                
                volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
                surface_area = 4 * M_PI * pow(radius, 2);
                
                printf("\nThe volume of the sphere is: %.2f\n", volume);
                printf("The surface area of the sphere is: %.2f\n\n", surface_area);
                break;
                
            case 3:
                printf("\nYou have chosen the cylinder.\n");
                printf("Enter the radius of the base: ");
                scanf("%f", &radius);
                printf("Enter the height of the cylinder: ");
                scanf("%f", &height);
                
                volume = M_PI * pow(radius, 2) * height;
                surface_area = (2 * M_PI * radius * height) + (2 * M_PI * pow(radius, 2));
                
                printf("\nThe volume of the cylinder is: %.2f\n", volume);
                printf("The surface area of the cylinder is: %.2f\n\n", surface_area);
                break;
                
            case 4:
                printf("\nGoodbye!\n");
                break;
                
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
    } while(shape_choice != 4);
    
    return 0;
}