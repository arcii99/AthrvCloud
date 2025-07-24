//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

// function to calculate the area of a triangle using Heron's formula
double calcArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the three points of the triangle:\n");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double a, b, c;
    // calculate the lengths of the sides of the triangle using distance formula
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    printf("The length of side a is %lf.\n", a);
    printf("The length of side b is %lf.\n", b);
    printf("The length of side c is %lf.\n", c);

    // check if the three points form a triangle
    if (a + b > c && a + c > b && b + c > a) {
        printf("The three points form a triangle!\n");
        
        // calculate the perimeter of the triangle
        double perimeter = a + b + c;
        printf("The perimeter of the triangle is %lf.\n", perimeter);

        // calculate the area of the triangle using Heron's formula
        double area = calcArea(a, b, c);
        printf("The area of the triangle is %lf.\n", area);
    }
    else {
        printf("The three points do not form a triangle.\n");
    }
    
    return 0;
}