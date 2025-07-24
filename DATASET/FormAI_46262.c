//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>

/* Function to find the Euclidean distance between two points */
double distance(double x1, double y1, double x2, double y2) {
    double dist;
    dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return dist;
}

int main() {
    double x1, y1, x2, y2, dist;
    printf("Enter the coordinates of Point 1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of Point 2: ");
    scanf("%lf %lf", &x2, &y2);
    dist = distance(x1, y1, x2, y2);
    printf("The Euclidean distance between the two points is: %lf", dist);
    return 0;
}