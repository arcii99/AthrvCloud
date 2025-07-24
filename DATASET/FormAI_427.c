//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include<stdio.h>
#include<math.h>

int main(){
    int choice;
    float radius, length, breadth, base, height, area, perimeter, circumference;

    printf("Enter the choice of geometric shape:\n");
    printf("1. Circle\n2. Rectangle\n3. Triangle\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);

            area = M_PI * pow(radius, 2);
            circumference = 2 * M_PI * radius;

            printf("Area of the circle: %.2f\n", area);
            printf("Circumference of the circle: %.2f\n", circumference);
            break;

        case 2:
            printf("Enter the length and breadth of the rectangle: ");
            scanf("%f%f", &length, &breadth);

            area = length * breadth;
            perimeter = 2 * (length + breadth);

            printf("Area of the rectangle: %.2f\n", area);
            printf("Perimeter of the rectangle: %.2f\n", perimeter);
            break;

        case 3:
            printf("Enter the base and height of the triangle: ");
            scanf("%f%f", &base, &height);

            area = 0.5 * base * height;

            printf("Area of the triangle: %.2f\n", area);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}