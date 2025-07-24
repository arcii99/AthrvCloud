//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include<stdio.h>
#include<math.h>

// Function to calculate area of triangle using Heron's formula
float areaOfTriangle(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to calculate perimeter of triangle
float perimeterOfTriangle(float a, float b, float c) {
    return a + b + c;
}

int main() {
    float a, b, c;
    printf("Enter the length of three sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    // Check if the entered lengths form a triangle
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Entered lengths do not form a triangle!");
        return 0;
    }

    float area = areaOfTriangle(a, b, c);
    float perimeter = perimeterOfTriangle(a, b, c);

    printf("Area of the triangle is: %.2f square units\n", area);
    printf("Perimeter of the triangle is: %.2f units\n", perimeter);

    return 0;
}