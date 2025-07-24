//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: content
#include <stdio.h>

// Function to calculate the area of a triangle given its three sides
float areaOfTriangle(float a, float b, float c)
{
    // Calculating the semi-perimeter
    float s = (a + b + c) / 2;

    // Calculating the area
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

// Function to calculate the perimeter of a triangle given its three sides
float perimeterOfTriangle(float a, float b, float c)
{
    // Calculating the perimeter
    float perimeter = a + b + c;

    return perimeter;
}

int main()
{
    float a, b, c;
    printf("Enter the three sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    // Check if the given sides can form a triangle
    if (a + b > c && b + c > a && c + a > b)
    {
        // If the sides can form a triangle, calculate its area and perimeter
        float area = areaOfTriangle(a, b, c);
        float perimeter = perimeterOfTriangle(a, b, c);
        
        printf("The area of the triangle is: %f\n", area);
        printf("The perimeter of the triangle is: %f\n", perimeter);
    }
    else
    {
        // If the sides cannot form a triangle, print an error message
        printf("Invalid input. The given sides cannot form a triangle.\n");
    }

    return 0;
}