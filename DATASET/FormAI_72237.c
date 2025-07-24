//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

int main() {
    printf("*********** WELCOME TO GEOMETRIC ALGORITHMS ***********\n");
    
    // Input
    printf("Enter the radius of the circle: ");
    double radius;
    scanf("%lf", &radius);

    // Area and perimeter of the circle
    double area = M_PI * radius * radius;
    double perimeter = 2 * M_PI * radius;
    printf("The area of the circle is %.2lf\n", area);
    printf("The perimeter of the circle is %.2lf\n", perimeter);
    
    // Input
    printf("\nEnter the length of the rectangle: ");
    double length;
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    double width;
    scanf("%lf", &width);

    // Area and perimeter of the rectangle
    double rect_area = length * width;
    double rect_perimeter = 2 * (length + width);
    printf("The area of the rectangle is %.2lf\n", rect_area);
    printf("The perimeter of the rectangle is %.2lf\n", rect_perimeter);

    // Input
    printf("\nEnter the side length of the equilateral triangle: ");
    double side;
    scanf("%lf", &side);

    // Area and perimeter of the equilateral triangle
    double tri_area = (sqrt(3) / 4) * side * side;
    double tri_perimeter = 3 * side;
    printf("The area of the equilateral triangle is %.2lf\n", tri_area);
    printf("The perimeter of the equilateral triangle is %.2lf\n", tri_perimeter);

    printf("\n*********** THANK YOU FOR USING GEOMETRIC ALGORITHMS ***********\n");

    return 0;
}