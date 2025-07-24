//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2) {
    float dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return dist;
}

int main() {
    // points of the triangle
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point(x1,y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point(x2,y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point(x3,y3): ");
    scanf("%f %f", &x3, &y3);

    // lengths of the triangle sides
    float a, b, c;
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);

    // semiperimeter of the triangle
    float s = (a + b + c) / 2;

    // area of the triangle using Heron's formula
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    // printing the results
    printf("Length of side 'a': %.2f units\n", a);
    printf("Length of side 'b': %.2f units\n", b);
    printf("Length of side 'c': %.2f units\n", c);
    printf("Semiperimeter of the triangle: %.2f units\n", s);
    printf("Area of the triangle: %.2f square units\n", area);

    return 0;
}