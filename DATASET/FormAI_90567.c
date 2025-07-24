//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    printf("Select type of Geometric Algorithm:\n");
    printf("1. Area of Circle\n");
    printf("2. Volume of Sphere\n");
    printf("3. Area of Triangle\n");
    printf("4. Perimeter of Rectangle\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            float radius, area;
            printf("Enter the radius of the Circle: ");
            scanf("%f", &radius);
            area = M_PI * pow(radius, 2);
            printf("The area of the circle is: %.2f square units.\n", area);
            break;
        }
        case 2: {
            float radius, volume;
            printf("Enter the radius of the Sphere: ");
            scanf("%f", &radius);
            volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
            printf("The volume of the sphere is: %.2f cubic units.\n", volume);
            break;
        }
        case 3: {
            float base, height, area;
            printf("Enter the base and height of the Triangle: ");
            scanf("%f %f", &base, &height);
            area = 0.5 * base * height;
            printf("The area of the triangle is: %.2f square units.\n", area);
            break;
        }
        case 4: {
            float length, breadth, perimeter;
            printf("Enter the length and breadth of the Rectangle: ");
            scanf("%f %f", &length, &breadth);
            perimeter = 2 * (length + breadth);
            printf("The perimeter of the rectangle is: %.2f units.\n", perimeter);
            break;
        }
        default: {
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}