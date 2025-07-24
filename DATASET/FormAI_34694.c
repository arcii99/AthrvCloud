//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a triangle given its three sides
float areaOfTriangle(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // Take input from the user
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the third point (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Calculate the distance between the three points
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    // Check if the points form a valid triangle
    if (a + b > c && b + c > a && c + a > b) {
        // Calculate the perimeter of the triangle
        float perimeter = a + b + c;

        // Calculate the area of the triangle
        float area = areaOfTriangle(a, b, c);

        // Print the results
        printf("Perimeter of the triangle = %.2f units\n", perimeter);
        printf("Area of the triangle = %.2f sq. units\n", area);
    } else {
        printf("Points (%d, %d), (%d, %d), and (%d, %d) do not form a triangle.\n", x1, y1, x2, y2, x3, y3);
    }

    return 0;
}