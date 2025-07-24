//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <math.h>

/* Function to calculate the distance between two points */
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

/* Function to calculate the area of a triangle given its three sides */
float area(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
    /* User input of three points */
    float x1, y1, x2, y2, x3, y3;
    printf("Enter x and y coordinates of Point 1: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter x and y coordinates of Point 2: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter x and y coordinates of Point 3: ");
    scanf("%f %f", &x3, &y3);

    /* Calculating the distance and areas of the three sides */
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);
    float triangleArea = area(a,b,c);

    /* Calculating the incenter of the triangle */
    float incenterX = (a*x3 + b*x1 + c*x2) / (a+b+c);
    float incenterY = (a*y3 + b*y1 + c*y2) / (a+b+c);

    /* Printing the results */
    printf("\nThe three sides of the triangle are %.2f, %.2f, and %.2f\n", a, b, c);
    printf("The area of the triangle is: %.2f\n", triangleArea);
    printf("The incenter of the triangle is: (%.2f, %.2f)", incenterX, incenterY);

    return 0;
}