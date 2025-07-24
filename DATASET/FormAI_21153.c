//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: paranoid
#include <stdio.h>

// Function to calculate the area of a circle
float areaOfCircle(float radius) {
    const float PI = 3.14159f;
    return PI * radius * radius;
}

// Function to check if 3 points lie on the same line
int areCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    if ((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2))
        return 1;
    else
        return 0;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of Point 1 (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of Point 2 (x y): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of Point 3 (x y): ");
    scanf("%d %d", &x3, &y3);

    // Check if the points are collinear
    if (areCollinear(x1, y1, x2, y2, x3, y3) == 1) {
        printf("The three points (%d, %d), (%d, %d), and (%d, %d) are collinear\n", x1, y1, x2, y2, x3, y3);
        return -1;
    }

    // Calculate the area of the triangle using Heron's formula
    float a = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    float b = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    float c = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s-a) * (s-b) * (s-c));
    printf("The area of the triangle with vertices (%d, %d), (%d, %d), and (%d, %d) is %f\n", x1, y1, x2, y2, x3, y3, area);

    // Calculate the area of the circle with the triangle's circumcircle as diamter
    float diameter = a * b * c * sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)) / (2 * pow(a*b+b*c+c*a, 2));
    float circum_radius = diameter / 2;
    printf("The circumference of the circumcircle with radius %f is %f\n", circum_radius, areaOfCircle(circum_radius));

    return 0;
}