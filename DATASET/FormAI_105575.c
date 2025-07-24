//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area, perimeter;

    printf("Enter the coordinates of the first point (x1 y1):\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2):\n");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point (x3 y3):\n");
    scanf("%d %d", &x3, &y3);

    // Calculate the lengths of the sides
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate the semi-perimeter
    s = (a + b + c) / 2;

    // Calculate the area
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Calculate the perimeter
    perimeter = a + b + c;

    // Print the results
    printf("The lengths of the sides are: %.2f, %.2f, %.2f\n", a, b, c);
    printf("The area of the triangle is: %.2f\n", area);
    printf("The perimeter of the triangle is: %.2f\n", perimeter);

    return 0;
}