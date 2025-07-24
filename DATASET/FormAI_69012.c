//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>

/*
 * This program calculates the area of a triangle given three points.
 * It demonstrates the use of geometric algorithms in computer programming.
 * The program prompts the user to enter the coordinates of the three points,
 * and then calculates the area of the triangle using the Shoelace formula.
 * It then outputs the result to the user.
 */

int main() {
    float x1, y1, x2, y2, x3, y3, area;

    printf("Enter the coordinates of Point A (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the coordinates of Point B (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    printf("Enter the coordinates of Point C (x3 y3): ");
    scanf("%f %f", &x3, &y3);

    //calculate the area of the triangle using Shoelace formula
    area = 0.5 * ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1));

    printf("The area of the triangle is %f\n", area);

    return 0;
}