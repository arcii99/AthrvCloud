//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main()
{
    int option;
    printf("Welcome to the futuristic Geometric Algorithms program!\n");
    printf("Please select an option:\n");
    printf("1. Calculate the distance between two points in 3D space.\n");
    printf("2. Calculate the surface area of a sphere.\n");
    printf("3. Calculate the perimeter of a triangle in 2D space.\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        {
            float x1, y1, z1, x2, y2, z2, distance;
            printf("\nEnter the coordinates of the first point(x, y, z):");
            scanf("%f %f %f", &x1, &y1, &z1);
            printf("Enter the coordinates of the second point(x, y, z):");
            scanf("%f %f %f", &x2, &y2, &z2);
            distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
            printf("The distance between the two points in 3D space is: %.2f\n",distance);
            break;
        }
        case 2:
        {
            float radius, surface_area;
            printf("\nEnter the radius of the sphere:");
            scanf("%f", &radius);
            surface_area = 4 * M_PI * pow(radius, 2);
            printf("The surface area of the sphere is: %.2f\n", surface_area);
            break;
        }
        case 3:
        {
            float x1, y1, x2, y2, x3, y3, perimeter;
            printf("\nEnter the coordinates of the first point(x, y):");
            scanf("%f %f", &x1, &y1);
            printf("Enter the coordinates of the second point(x, y):");
            scanf("%f %f", &x2, &y2);
            printf("Enter the coordinates of the third point(x, y):");
            scanf("%f %f", &x3, &y3);
            perimeter = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) + sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
            printf("The perimeter of the triangle is: %.2f\n", perimeter);
            break;
        }
        default:
        {
            printf("\nInvalid option!\n");
            break;
        }
    }
    return 0;
}