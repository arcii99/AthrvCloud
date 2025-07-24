//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <math.h>

/* Function to determine if a given point (x,y) lies within the triangle formed by (x1,y1), (x2,y2), and (x3,y3) */
int pointInTriangle(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3) {
    /* Calculate the area of the triangle formed by the points */
    float A = (0.5)*(-y3*y2+x2*y3+x3*y1-y1*x3-x2*y1+x1*y2);
    /* Calculate the area of three triangles formed by the test point and each of the vertices of the triangle */
    float A1 = (0.5)*(-y2*x+x2*y+y1*x-x1*y-y1*x2+x*x2);
    float A2 = (0.5)*(-y3*x+x3*y+y2*x-x2*y-y2*x3+x*x3);
    float A3 = (0.5)*(-y3*x+x3*y+y1*x-x1*y-y1*x3+x*x3);
    /* If the sum of the areas of the three triangles formed by the test point and each vertex is equal to the area of the triangle, the point lies within the triangle */
    if ((int)(A*1000) == (int)((A1 + A2 + A3) * 1000)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    /* Define the triangle vertices */
    float x1 = 0, y1 = 0;
    float x2 = 4, y2 = 6;
    float x3 = 8, y3 = 1;
    /* Test points */
    float x = 3, y = 3;
    /* Determine if the test point lies within the triangle */
    int result = pointInTriangle(x, y, x1, y1, x2, y2, x3, y3);
    if (result) {
        printf("The point (%f,%f) lies within the triangle formed by (%f,%f), (%f,%f), and (%f,%f).\n", x, y, x1, y1, x2, y2, x3, y3);
    }
    else {
        printf("The point (%f,%f) does not lie within the triangle formed by (%f,%f), (%f,%f), and (%f,%f).\n", x, y, x1, y1, x2, y2, x3, y3);
    }
    return 0;
}