//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
/*
* Sherlock Holmes and the Case of the Elusive Triangle
*/

#include <stdio.h>
#include <math.h>

int main() {
    // Initialize variables
    float x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area;

    // Get user input
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point (x3, y3): ");
    scanf("%f %f", &x3, &y3);

    // Calculate the sides of the triangle
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Check if the input forms a valid triangle
    if (a + b > c && b + c > a && c + a > b) {
        // Find the perimeter and semi-perimeter of the triangle
        float perimeter = a + b + c;
        s = perimeter / 2;

        // Find the area of the triangle
        area = sqrt(s * (s - a) * (s - b) * (s - c));

        // Output the results
        printf("The perimeter of the triangle is %.2f units\n", perimeter);
        printf("The area of the triangle is %.2f square units\n", area);
    } else {
        // Input does not form a valid triangle
        printf("Sorry, your input does not form a valid triangle.\n");
    }

    return 0;
}