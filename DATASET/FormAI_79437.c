//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//This program will calculate the area of a circle
//and the circumference of a rectangle

int main(){

    int radius;
    float pi=3.14, area, circumference;

    printf("Enter the radius of the circle: ");
    scanf("%d",&radius);

    area = pi*pow(radius,2);
    circumference = 2*pi*radius;

    printf("\nThe area of the circle is: %.2f", area);
    printf("\nThe circumference of the circle is: %.2f", circumference);
    
    int length, breadth;
    float rectangle_circumference, rectangle_area;

    printf("\n\nEnter the length of the rectangle: ");
    scanf("%d",&length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%d",&breadth);

    rectangle_area = length * breadth;
    rectangle_circumference = 2*(length + breadth);

    printf("\nThe area of the rectangle is: %.2f", rectangle_area);
    printf("\nThe circumference of the rectangle is: %.2f", rectangle_circumference);

    return 0;

}