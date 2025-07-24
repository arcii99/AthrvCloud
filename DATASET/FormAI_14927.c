//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Geometric Calculator!\n");
    int choice;
    double radius, height, base, length, width, area, perimeter, volume;

    do {
        printf("\nSelect the shape you want to calculate (1-3):\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Cylinder\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Circle calculations
                printf("\nEnter the radius of the circle: ");
                scanf("%lf", &radius);
                area = M_PI * pow(radius, 2);
                perimeter = 2 * M_PI * radius;
                printf("The area of the circle is: %.2lf\n", area);
                printf("The perimeter of the circle is: %.2lf\n", perimeter);
                break;

            case 2:
                // Rectangle calculations
                printf("\nEnter the length of the rectangle: ");
                scanf("%lf", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%lf", &width);
                area = length * width;
                perimeter = 2 * (length + width);
                printf("The area of the rectangle is: %.2lf\n", area);
                printf("The perimeter of the rectangle is: %.2lf\n", perimeter);
                break;

            case 3:
                // Cylinder calculations
                printf("\nEnter the radius of the cylinder: ");
                scanf("%lf", &radius);
                printf("Enter the height of the cylinder: ");
                scanf("%lf", &height);
                base = M_PI * pow(radius, 2);
                area = (2 * base) + (2 * M_PI * radius * height);
                volume = base * height;
                printf("The surface area of the cylinder is: %.2lf\n", area);
                printf("The volume of the cylinder is: %.2lf\n", volume);
                break;

            case 4:
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}