//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// function to calculate the perimeter of a circle given its radius
float circlePerimeter(float radius) {
    return 2 * PI * radius;
}

// function to calculate the area of a rectangle given its width and height
float rectangleArea(float width, float height) {
    return width * height;
}

// function to calculate the perimeter of a triangle given its side lengths
float trianglePerimeter(float side1, float side2, float side3) {
    return side1 + side2 + side3;
}

// function to calculate the area of a circle given its radius
float circleArea(float radius) {
    return PI * pow(radius, 2);
}

int main() {
    int choice;
    float radius, width, height, side1, side2, side3, result;
    
    printf("Geometry Calculator\n\n");
    printf("1. Calculate the perimeter of a circle\n");
    printf("2. Calculate the area of a rectangle\n");
    printf("3. Calculate the perimeter of a triangle\n");
    printf("4. Calculate the area of a circle\n");
    printf("5. Quit\n\n");
    
    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                result = circlePerimeter(radius);
                printf("The perimeter of the circle is %.2f\n\n", result);
                break;
            case 2:
                printf("Enter the width and height of the rectangle: ");
                scanf("%f %f", &width, &height);
                result = rectangleArea(width, height);
                printf("The area of the rectangle is %.2f\n\n", result);
                break;
            case 3:
                printf("Enter the length of each side of the triangle: ");
                scanf("%f %f %f", &side1, &side2, &side3);
                result = trianglePerimeter(side1, side2, side3);
                printf("The perimeter of the triangle is %.2f\n\n", result);
                break;
            case 4:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                result = circleArea(radius);
                printf("The area of the circle is %.2f\n\n", result);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}