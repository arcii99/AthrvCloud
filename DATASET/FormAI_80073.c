//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include<stdio.h>
#include<math.h>

// Function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2)
{
    float d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return d;
}

int main()
{
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of point A: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of point B: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of point C: ");
    scanf("%f %f", &x3, &y3);

    // Lengths of the three sides of the triangle
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    // Calculating s (half of the perimeter)
    float s = (a + b + c) / 2;

    // Calculating the area of the triangle using Heron's formula
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("The area of the triangle is %f", area);

    return 0;
}