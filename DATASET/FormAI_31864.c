//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef enum {FALSE, TRUE} bool;

// Function to calculate distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to check if three points are collinear
bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (((y3 - y2) * (x2 - x1)) == ((y2 - y1) * (x3 - x2)));
}

// Function to calculate angle between two line segments
double angle(int x1, int y1, int x2, int y2, int x3, int y3) {
    double d1 = distance(x1, y1, x2, y2);
    double d2 = distance(x2, y2, x3, y3);
    double dotProduct = ((x2 - x1) * (x3 - x2)) + ((y2 - y1) * (y3 - y2));
    return acos(dotProduct / (d1 * d2)) * (180.0 / PI);
}

int main() {
    int x1, y1, x2, y2, x3, y3;

    printf("Enter the coordinates of point 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of point 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of point 3 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    printf("\nDistance between points 1 and 2: %.2f\n", distance(x1, y1, x2, y2));
    printf("Distance between points 2 and 3: %.2f\n", distance(x2, y2, x3, y3));

    if(collinear(x1, y1, x2, y2, x3, y3)) {
        printf("Points are collinear.\n");
    } else {
        printf("Points are not collinear.\n");
    }

    printf("Angle between line segments 1 and 2: %.2f degrees\n", angle(x1, y1, x2, y2, x3, y3));

    return 0;
}