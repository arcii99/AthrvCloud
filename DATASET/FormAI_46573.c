//FormAI DATASET v1.0 Category: Physics simulation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main()
{
    int option;
    float radius, height, base, slantLength, length, breadth, side, edge, area, volume;
    float pi = 3.141592653589793238;

    printf("Welcome to the Shape Shifting Simulator!\n");
    printf("Choose an option to see the simulation:\n");
    printf("1. Sphere\n");
    printf("2. Cone\n");
    printf("3. Cylinder\n");
    printf("4. Cube\n");
    printf("5. Cuboid\n");
    printf("6. Tetrahedron\n");

    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter the radius of the sphere: ");
            scanf("%f", &radius);
            area = 4 * pi * pow(radius, 2);
            volume = (4/3) * pi * pow(radius, 3);
            printf("The area of the sphere is: %.2f square units\n", area);
            printf("The volume of the sphere is: %.2f cubic units\n", volume);
            break;

        case 2:
            printf("Enter the radius of the base of the cone: ");
            scanf("%f", &radius);
            printf("Enter the height of the cone: ");
            scanf("%f", &height);
            slantLength = sqrt(pow(radius, 2) + pow(height, 2));
            area = pi * radius * slantLength + pi * pow(radius, 2);
            volume = (1/3) * pi * pow(radius, 2) * height;
            printf("The area of the cone is: %.2f square units\n", area);
            printf("The volume of the cone is: %.2f cubic units\n", volume);
            break;

        case 3:
            printf("Enter the radius of the base of the cylinder: ");
            scanf("%f", &radius);
            printf("Enter the height of the cylinder: ");
            scanf("%f", &height);
            area = 2 * pi * radius * height + 2 * pi * pow(radius, 2);
            volume = pi * pow(radius, 2) * height;
            printf("The area of the cylinder is: %.2f square units\n", area);
            printf("The volume of the cylinder is: %.2f cubic units\n", volume);
            break;

        case 4:
            printf("Enter the length of one side of the cube: ");
            scanf("%f", &side);
            area = 6 * pow(side, 2);
            volume = pow(side, 3);
            printf("The area of the cube is: %.2f square units\n", area);
            printf("The volume of the cube is: %.2f cubic units\n", volume);
            break;

        case 5:
            printf("Enter the length of the cuboid: ");
            scanf("%f", &length);
            printf("Enter the breadth of the cuboid: ");
            scanf("%f", &breadth);
            printf("Enter the height of the cuboid: ");
            scanf("%f", &height);
            area = 2 * (length * breadth + breadth * height + height * length);
            volume = length * breadth * height;
            printf("The area of the cuboid is: %.2f square units\n", area);
            printf("The volume of the cuboid is: %.2f cubic units\n", volume);
            break;

        case 6:
            printf("Enter the edge length of the tetrahedron: ");
            scanf("%f", &edge);
            area = sqrt(3) * pow(edge, 2);
            volume = (1/3) * sqrt(2) * pow(edge, 3);
            printf("The area of the tetrahedron is: %.2f square units\n", area);
            printf("The volume of the tetrahedron is: %.2f cubic units\n", volume);
            break;

        default:
            printf("Invalid option. Please try again.\n");
    }
    return 0;
}