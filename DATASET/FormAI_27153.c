//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: genious
#include <stdio.h>
#include <math.h>

float find_distance(float x1, float y1, float x2, float y2) {
    /* Function to find the distance between two points */
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

float find_area(float a, float b, float c) {
    /* Function to find the area of a triangle */
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    /* Sample program to find the intersection of two circles */
    float x1, y1, r1, x2, y2, r2;
    printf("Enter the center and radius of circle 1 (x y r): ");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Enter the center and radius of circle 2 (x y r): ");
    scanf("%f %f %f", &x2, &y2, &r2);

    float d = find_distance(x1, y1, x2, y2);
    if (d > r1 + r2) {
        printf("The circles do not intersect.\n");
        return 0;
    }

    if (d < fabs(r1 - r2)) {
        printf("One circle is contained within the other.\n");
        return 0;
    }

    float a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    float h = sqrt(r1 * r1 - a * a);
    float cx = x1 + a * (x2 - x1) / d;
    float cy = y1 + a * (y2 - y1) / d;

    float x3 = cx + h * (y2 - y1) / d;
    float y3 = cy - h * (x2 - x1) / d;
    float x4 = cx - h * (y2 - y1) / d;
    float y4 = cy + h * (x2 - x1) / d;

    float area = find_area(r1, r2, d);
    printf("The two circles intersect at two points:\n");
    printf("(%.2f, %.2f) and (%.2f, %.2f)\n", x3, y3, x4, y4);
    printf("The area of their intersection is: %.2f\n", area);

    return 0;
}