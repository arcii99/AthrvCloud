//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include<stdio.h>

int main()
{
    // A simple program to calculate the area and perimeter of a rectangle
    float length, breadth, area, perimeter;

    // Get input from user
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &breadth);

    // Calculate area and perimeter
    area = length * breadth;
    perimeter = 2 * (length + breadth);

    // Display the result
    printf("The area of the rectangle is: %f\n", area);
    printf("The perimeter of the rectangle is: %f\n", perimeter);

    return 0;
}

//End of the program