//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    int shape;
    float area, perimeter;

    printf("Enter the number of sides of the shape: ");
    scanf("%d", &shape);

    switch(shape) {
        case 1:
            printf("A shape cannot have one side only!");
            break;
        case 2:
            printf("A shape cannot have only two sides!");
            break;
        case 3:
            // Calculate area and perimeter of a triangle
            float base, height, side1, side2, side3;

            printf("Enter the base of the triangle: ");
            scanf("%f", &base);
            printf("Enter the height of the triangle: ");
            scanf("%f", &height);
            printf("Enter the length of side 1: ");
            scanf("%f", &side1);
            printf("Enter the length of side 2: ");
            scanf("%f", &side2);
            printf("Enter the length of side 3: ");
            scanf("%f", &side3);

            area = 0.5 * base * height;
            perimeter = side1 + side2 + side3;
            break;
        case 4:
            // Calculate area and perimeter of a square
            float side;

            printf("Enter the length of a side of the square: ");
            scanf("%f", &side);

            area = side * side;
            perimeter = 4 * side;
            break;
        case 5:
            // Calculate area and perimeter of a pentagon
            float apothem, side_length;

            printf("Enter the length of a side of the pentagon: ");
            scanf("%f", &side_length);
            printf("Enter the length of the apothem of the pentagon: ");
            scanf("%f", &apothem);

            area = (5 * side_length * apothem) / 2;
            perimeter = 5 * side_length;
            break;
        default:
            printf("Invalid choice.");
            return 0;
    }

    // Round area and perimeter to 2 decimal places
    area = roundf(area * 100) / 100;
    perimeter = roundf(perimeter * 100) / 100;

    // Print results
    printf("The area of the shape is: %.2f\n", area);
    printf("The perimeter of the shape is: %.2f\n", perimeter);

    return 0;
}