//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

int main(void) {
    // Initialize variables for the coordinates of the three points
    float x1, y1, x2, y2, x3, y3;
    
    // Get input from user for the coordinates of the three points
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point (x3, y3): ");
    scanf("%f %f", &x3, &y3);
    
    // Calculate the distances between each pair of points
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);
    
    // Calculate the semiperimeter of the triangle
    float s = (a + b + c) / 2;
    
    // Calculate the area of the triangle using Heron's formula
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    // Determine if the triangle is acute, obtuse, or right-angled
    if (a*a + b*b > c*c && b*b + c*c > a*a && c*c + a*a > b*b) {
        printf("The triangle is acute-angled.\n");
    } else if (a*a + b*b < c*c || b*b + c*c < a*a || c*c + a*a < b*b) {
        printf("The triangle is obtuse-angled.\n");
    } else {
        printf("The triangle is right-angled.\n");
    }
    
    // Print the area and perimeter of the triangle
    printf("Area of the triangle = %.2f\n", area);
    printf("Perimeter of the triangle = %.2f\n", a + b + c);
    
    return 0;
}