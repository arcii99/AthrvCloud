//FormAI DATASET v1.0 Category: Scientific ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main() {
    // program to calculate the area and perimeter of a shape
    
    int choice, length, breadth, radius;
    float area, perimeter;
    
    printf("Choose a shape:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the length and breadth of the rectangle:\n");
            scanf("%d %d", &length, &breadth);
            area = length * breadth;
            perimeter = 2 * (length + breadth);
            printf("Area of the rectangle = %f\n", area);
            printf("Perimeter of the rectangle = %f\n", perimeter);
            break;
        case 2:
            printf("Enter the radius of the circle:\n");
            scanf("%d", &radius);
            area = M_PI * radius * radius;
            perimeter = 2 * M_PI * radius;
            printf("Area of the circle = %f\n", area);
            printf("Perimeter of the circle = %f\n", perimeter);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}