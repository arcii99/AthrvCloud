//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct Point2D {
    double x, y;
} Point2D;

typedef struct lineSegment2D {
    Point2D startPoint, endPoint;
} lineSegment2D;

double getDistance(Point2D point1, Point2D point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

double getAngle(lineSegment2D lineSegment) {
    double deltaX = lineSegment.endPoint.x - lineSegment.startPoint.x;
    double deltaY = lineSegment.endPoint.y - lineSegment.startPoint.y;

    return atan2(deltaY, deltaX) * 180 / PI;
}

int findClosestPoint(Point2D* pointArray, int numOfPoints, Point2D currentPoint) {
    int closestIndex = 0;
    double closestDistance = getDistance(pointArray[0], currentPoint);

    for (int i = 1; i < numOfPoints; i++) {
        double distance = getDistance(pointArray[i], currentPoint);
        if (distance < closestDistance) {
            closestIndex = i;
            closestDistance = distance;
        }
    }

    return closestIndex;
}

int main() {
    Point2D pointArray[4] = {{3, 8}, {6, 6}, {2, 3}, {6, 1}};
    Point2D currentPoint = {0, 0};
    lineSegment2D lineSegmentArray[3] = {{{1, 1}, {2, 2}}, {{3, 3}, {4, 4}}, {{5, 5}, {6, 6}}};

    int closestIndex = findClosestPoint(pointArray, 4, currentPoint);
    printf("The closest point is (%f, %f)\n", pointArray[closestIndex].x, pointArray[closestIndex].y);

    for (int i = 0; i < 3; i++) {
        printf("Line segment %d has an angle of %f degrees\n", i + 1, getAngle(lineSegmentArray[i]));
    }

    return 0;
}