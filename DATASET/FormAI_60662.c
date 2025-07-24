//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

// function to compute the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// function to determine if three points are collinear
int collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    double area = 0.5 * (((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)));
    if (area == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // sample points
    int x1 = 1, y1 = 1, x2 = 2, y2 = 2, x3 = 3, y3 = 3;
    printf("Point 1 coordinates: (%d, %d)\n", x1, y1);
    printf("Point 2 coordinates: (%d, %d)\n", x2, y2);
    printf("Point 3 coordinates: (%d, %d)\n", x3, y3);

    // calculate distance between two points
    double d = distance(x1, y1, x2, y2);
    printf("Distance between point 1 and 2: %.2f\n", d);

    // determine if three points are collinear
    int c = collinear(x1, y1, x2, y2, x3, y3);
    if (c == 1) {
        printf("Points are collinear!\n");
    } else {
        printf("Points are not collinear!\n");
    }
    return 0;
}