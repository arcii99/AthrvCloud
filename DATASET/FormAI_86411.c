//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/*
 * This program takes in the coordinates of three points in the Cartesian plane
 * and determines if they form a right triangle.
 * It does this by using the Pythagorean theorem, which states that in a
 * right triangle, a^2 + b^2 = c^2 where a and b are the lengths of the two legs
 * and c is the length of the hypotenuse.
 * If the sum of the squares of the two shortest sides equals the square of the longest side,
 * then the three points form a right triangle.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // variables to hold the coordinates of the three points
    double x1, y1, x2, y2, x3, y3;

    // prompt user for input
    printf("Enter the coordinates of the first point (x, y): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x, y): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter the coordinates of the third point (x, y): ");
    scanf("%lf %lf", &x3, &y3);

    // calculate the distances between the points
    double dist1 = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
    double dist2 = sqrt(pow(x3 - x2, 2.0) + pow(y3 - y2, 2.0));
    double dist3 = sqrt(pow(x3 - x1, 2.0) + pow(y3 - y1, 2.0));

    // determine which side is the longest
    double longest = dist1;
    if (dist2 > longest) {
        longest = dist2;
    }
    if (dist3 > longest) {
        longest = dist3;
    }

    // calculate the sum of the squares of the two shortest sides
    double short1, short2;
    if (dist1 < dist2 && dist1 < dist3) {
        short1 = dist1;
        if (dist2 < dist3) {
            short2 = dist2;
        } else {
            short2 = dist3;
        }
    } else if (dist2 < dist1 && dist2 < dist3) {
        short1 = dist2;
        if (dist1 < dist3) {
            short2 = dist1;
        } else {
            short2 = dist3;
        }
    } else {
        short1 = dist3;
        if (dist1 < dist2) {
            short2 = dist1;
        } else {
            short2 = dist2;
        }
    }

    double sumSquares = pow(short1, 2.0) + pow(short2, 2.0);

    // determine if the three points form a right triangle
    if (pow(longest, 2.0) == sumSquares) {
        printf("The three points form a right triangle.\n");
    } else {
        printf("The three points do not form a right triangle.\n");
    }

    return 0;
}