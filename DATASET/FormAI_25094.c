//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// Struct to hold a point in a two-dimensional space
typedef struct {
    double x;
    double y;
} Point;

/*
 * This function calculates the area of a triangle given its vertices.
 * It uses the Shoelace formula which involves calculating the sum of the
 * areas of each trapezoid created by adjacent sides of the triangle.
 */
double calculateTriangleArea(Point A, Point B, Point C) {
    double area = ((A.x * B.y) + (B.x * C.y) + (C.x * A.y)) - ((B.x * A.y) + (C.x * B.y) + (A.x * C.y));
    area = fabs(area/2);
    return area;
}

/*
 * This function determines if a point is inside a given polygon.
 * It uses the winding number algorithm which counts the number of times
 * a line from the point to an outside point crosses any of the polygon's edges.
 * If the count is odd, the point is inside the polygon. 
 * If the count is even, the point is outside the polygon.
 */
int pointInsidePolygon(Point point, Point polygon[], int numVertices) {
    int windingNumber = 0;
    for(int i = 0; i < numVertices; i++) {
        Point vertex1 = polygon[i];
        Point vertex2 = polygon[(i+1)%numVertices];
        // Check if point is on the same horizontal level as the current edge
        if(vertex1.y <= point.y && vertex2.y > point.y || vertex2.y <= point.y && vertex1.y > point.y) {
            double edgeSlope = (vertex2.x - vertex1.x) / (vertex2.y - vertex1.y);
            double xIntersect = vertex1.x + ((point.y - vertex1.y) * edgeSlope);
            if(point.x < xIntersect) {
                windingNumber++;
            }
        }
    }
    return windingNumber % 2 == 1;
}

int main() {
    // Define a triangle and a point to check if it is inside the triangle
    Point A = {0, 0};
    Point B = {3, 0};
    Point C = {2, 2};
    Point point = {1, 1};
    double triangleArea = calculateTriangleArea(A, B, C);
    printf("Area of triangle ABC = %f \n", triangleArea);
    int insideTriangle = pointInsidePolygon(point, (Point[]){A, B, C}, 3);
    printf("Point (%f,%f) is %s triangle ABC.\n", point.x, point.y, insideTriangle ? "inside" : "outside");

    // Define another polygon and check if the point is inside it
    Point polygon[] = {{0,0}, {0,3}, {3,3}, {3,1}, {1,1}, {1,2}, {2,2}, {2,0}};
    int numVertices = 8;
    double polygonArea = 0;
    for(int i = 0; i < numVertices; i++) {
        Point vertex1 = polygon[i];
        Point vertex2 = polygon[(i+1)%numVertices];
        polygonArea += (vertex1.x * vertex2.y) - (vertex2.x * vertex1.y);
    }
    polygonArea = fabs(polygonArea/2);
    printf("Area of polygon = %f \n", polygonArea);
    int insidePolygon = pointInsidePolygon(point, polygon, numVertices);
    printf("Point (%f,%f) is %s the polygon.\n", point.x, point.y, insidePolygon ? "inside" : "outside");

    return 0;
}