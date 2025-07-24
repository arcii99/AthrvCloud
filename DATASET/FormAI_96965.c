//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    This program demonstrates a geometrical algorithm to find the intersection point 
    of two line segments in 2D space 
*/

typedef struct Vector {
    float x;    //x-component of the vector
    float y;    //y-component of the vector
} Vector;

typedef struct Point {
    float x;    //x-coordinate of the point
    float y;    //y-coordinate of the point
} Point;

/*
    This function computes the magnitude of the given vector
*/
float magnitude(Vector v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

/*
    This function computes the dot product of two given vectors
*/
float dotProduct(Vector v1, Vector v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

/*
    This function computes the direction of vector v1 relative to v2
    Positive value indicates counter-clockwise direction
    Negative value indicates clockwise direction
    Zero value indicates collinear
*/
float direction(Vector v1, Vector v2) {
    return (v1.x * v2.y) - (v2.x * v1.y);
}

/*
    This function computes the intersection point of two line segments
*/
Point getIntersection(Point a1, Point a2, Point b1, Point b2) {
    Vector a = {a2.x - a1.x, a2.y - a1.y};
    Vector b = {b2.x - b1.x, b2.y - b1.y};
    Vector c = {b1.x - a1.x, b1.y - a1.y};

    float alpha = direction(c, b) / direction(a, b);
    
    Point p = {a1.x + (alpha * a.x), a1.y + (alpha * a.y)};
    return p;
}

int main() {
    Point a1 = {1.0, 2.0};
    Point a2 = {6.0, 7.0};
    Point b1 = {3.0, 4.0};
    Point b2 = {8.0, 9.0};

    Point intersection = getIntersection(a1, a2, b1, b2);

    printf("Intersection point: (%f, %f)\n", intersection.x, intersection.y);

    return 0;
}