//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include<stdio.h>
#include<math.h>

float getDistance(float x1, float y1, float x2, float y2) {
    // calculate and return the distance between two points in 2D space
    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

int main() {
    printf("Welcome to the Geometric Algorithms program!\n");
    printf("This program will help you find the circumcenter of a triangle.\n");

    // ask the user for the coordinates of the triangle vertices
    float x1, y1, x2, y2, x3, y3;
    printf("Please enter the coordinates of the first vertex (x1,y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Please enter the coordinates of the second vertex (x2,y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Please enter the coordinates of the third vertex (x3,y3): ");
    scanf("%f %f", &x3, &y3);

    // calculate the lengths of the triangle sides
    float sideA = getDistance(x1, y1, x2, y2);
    float sideB = getDistance(x2, y2, x3, y3);
    float sideC = getDistance(x3, y3, x1, y1);

    // calculate the semiperimeter of the triangle
    float semiperimeter = (sideA + sideB + sideC) / 2;

    // calculate the radius of the circumcircle
    float radius = (sideA * sideB * sideC) / (4 * sqrt(semiperimeter * (semiperimeter - sideA) * (semiperimeter - sideB) * (semiperimeter - sideC)));

    // calculate the coordinates of the circumcenter
    float centerX = ((y1 - y3) * sideA * sideB + (y2 - y1) * sideC * sideB + (y3 - y2) * sideA * sideC) / (2 * (x1 - x3) * sideA * sideB + 2 * (x2 - x1) * sideC * sideB + 2 * (x3 - x2) * sideA * sideC);
    float centerY = ((x1 - x3) * sideA * sideB + (x2 - x1) * sideC * sideB + (x3 - x2) * sideA * sideC) / (2 * (y1 - y3) * sideA * sideB + 2 * (y2 - y1) * sideC * sideB + 2 * (y3 - y2) * sideA * sideC);

    // print the results
    printf("\nThe circumcenter of the triangle with vertices (%f,%f), (%f,%f), and (%f,%f) is (%f,%f).\n", x1, y1, x2, y2, x3, y3, centerX, centerY);
    printf("The radius of the corresponding circumcircle is %f.\n", radius);
    printf("Thank you for using the Geometric Algorithms program!\n");

    return 0;
}