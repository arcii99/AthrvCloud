//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include<stdio.h>

int main(){
    //Calculating the area of a rectangle
    float length, width;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);
    float area = length * width;
    printf("The area of the rectangle is: %.2f\n", area);

    //Calculating the perimeter of a triangle
    float side1, side2, side3;
    printf("Enter the length of side 1 of the triangle: ");
    scanf("%f", &side1);
    printf("Enter the length of side 2 of the triangle: ");
    scanf("%f", &side2);
    printf("Enter the length of side 3 of the triangle: ");
    scanf("%f", &side3);
    float perimeter = side1 + side2 + side3;
    printf("The perimeter of the triangle is: %.2f\n", perimeter);

    //Calculating the circumference of a circle
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    float circumference = 2 * 3.14159 * radius;
    printf("The circumference of the circle is: %.2f\n", circumference);

    //Calculating the area of a square
    float side;
    printf("Enter the length of the side of the square: ");
    scanf("%f", &side);
    float squareArea = side * side;
    printf("The area of the square is: %.2f\n", squareArea);

    return 0;
}