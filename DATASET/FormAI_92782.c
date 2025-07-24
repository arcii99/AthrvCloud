//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Custom types */
typedef struct Point {
    double x, y;
} Point;

/* Function prototypes */
bool isCCW(Point A, Point B, Point C);
double crossProduct(Point A, Point B);
double squareDistance(Point A, Point B);
bool isInsideTriangle(Point A, Point B, Point C, Point P);

int main() {
    /* Sample inputs */
    Point A = {1,1};
    Point B = {4,1};
    Point C = {3,4};
    Point P = {2,2};

    /* Determine if point P is inside triangle ABC */
    if(isInsideTriangle(A, B, C, P)) {
        printf("Point P is inside triangle ABC\n");
    } else {
        printf("Point P is NOT inside triangle ABC\n");
    }

    return 0;
}

/**
 * Determines if three points are listed in counterclockwise order.
 * Returns true if they are, false otherwise.
 */
bool isCCW(Point A, Point B, Point C) {
    return crossProduct(
                (Point) {B.x - A.x, B.y - A.y},
                (Point) {C.x - A.x, C.y - A.y}
           ) > 0;
}

/**
 * Calculates the cross product of two points.
 */
double crossProduct(Point A, Point B) {
    return A.x * B.y - A.y * B.x;
}

/**
 * Calculates the square of the Euclidean distance between two points.
 */
double squareDistance(Point A, Point B) {
    return pow(A.x - B.x, 2) + pow(A.y - B.y, 2);
}

/**
 * Determines if a point is inside a triangle.
 * Takes four Point structs: A, B, C (defining the triangle) and P (defining the point to check).
 * Returns true if point P is inside triangle ABC, false otherwise.
 */
bool isInsideTriangle(Point A, Point B, Point C, Point P) {
    /* Determine which side of each triangle edge point P is on */
    bool sideAB = isCCW(A, B, P);
    bool sideBC = isCCW(B, C, P);
    bool sideCA = isCCW(C, A, P);

    /* Determine if point P is inside triangle ABC */
    if((sideAB == sideBC) && (sideBC == sideCA)) {
        return true;
    }

    /* Determine the closest point on the triangle to point P */
    double minSqDist = squareDistance(A, P);
    Point closest = A;

    double currSqDist = squareDistance(B, P);
    if(currSqDist < minSqDist) {
        minSqDist = currSqDist;
        closest = B;
    }

    currSqDist = squareDistance(C, P);
    if(currSqDist < minSqDist) {
        minSqDist = currSqDist;
        closest = C;
    }

    /* Determine if point P is inside triangle ABC based on closest point */
    if(isCCW(A, B, closest)) {
        return isCCW(B, C, P) && isCCW(C, A, P);
    } else {
        return isCCW(A, C, P) && isCCW(C, B, P);
    }
}