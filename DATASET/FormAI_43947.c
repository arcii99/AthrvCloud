//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include<stdio.h>
#include<math.h>

/* Function to calculate area of a triangle given its three sides using Heron's formula */
float heron_formula(float a, float b, float c) {
    float s = (a+b+c)/2.0;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

/* Function to calculate the circumcenter of a triangle given its three vertices */
void circumcenter(float x1, float y1, float x2, float y2, float x3, float y3, float* xc, float* yc) {
    float a, b, c, d, e, f, g, h, i;
    a = x1 - x3;
    b = y1 - y3;
    c = x2 - x3;
    d = y2 - y3;
    e = a*(x1 + x3) + b*(y1 + y3);
    f = c*(x2 + x3) + d*(y2 + y3);
    g = 2*(a*(y2 - y3) - b*(x2 - x3));
    h = 2*(c*(y1 - y3) - d*(x1 - x3));
    i = 1/(g*h - (b*c - a*d));
    *xc = (d*e - b*f)*i;
    *yc = (a*f - c*e)*i;
}

/* Main function */
int main() {
    // Taking input of triangle coordinates
    float x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of first vertex: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter coordinates of second vertex: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter coordinates of third vertex: ");
    scanf("%f %f", &x3, &y3);

    // Calculating area and circumcenter of given triangle
    float a, b, c, area, xc, yc;
    a = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    b = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    c = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));
    area = heron_formula(a, b, c);
    circumcenter(x1, y1, x2, y2, x3, y3, &xc, &yc);

    // Printing output
    printf("Area of the given triangle is %.2f\n", area);
    printf("Circumcenter of the given triangle is (%.2f, %.2f)", xc, yc);
    
    return 0;
}