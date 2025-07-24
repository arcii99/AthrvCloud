//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int option = rand() % 3; // generates random number between 0 and 2
    
    switch(option) {
        case 0:
            shapeShiftRectangle();
            break;
        case 1:
            shapeShiftTriangle();
            break;
        case 2:
            shapeShiftCircle();
            break;
    }
    
    return 0;
}

void shapeShiftRectangle() {
    printf("Enter the length and width of the rectangle: ");
    int length = 0, width = 0;
    scanf("%d %d", &length, &width);
    
    int area = length * width;
    int perimeter = 2 * (length + width);
    
    printf("The area of the rectangle is %d and the perimeter is %d.\n", area, perimeter);
}

void shapeShiftTriangle() {
    printf("Enter the lengths of the three sides of the triangle: ");
    int side1 = 0, side2 = 0, side3 = 0;
    scanf("%d %d %d", &side1, &side2, &side3);
    
    int perimeter = side1 + side2 + side3;
    float s = (float)perimeter / 2;
    float area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    
    printf("The area of the triangle is %f and the perimeter is %d.\n", area, perimeter);
}

void shapeShiftCircle() {
    printf("Enter the radius of the circle: ");
    int radius = 0;
    scanf("%d", &radius);
    
    float area = 3.14159 * radius * radius;
    float circumference = 2 * 3.14159 * radius;
    
    printf("The area of the circle is %f and the circumference is %f.\n", area, circumference);
}