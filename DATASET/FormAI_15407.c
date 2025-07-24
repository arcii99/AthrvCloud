//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

/* A function to calculate the distance between two points */
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/* A function to check if a point lies inside a circle */
int isInside(int xc, int yc, int r, int x, int y) {
    if (distance(xc, yc, x, y) <= r) {
        return 1;
    }
    return 0;
}

/* Main function */
int main() {
    int xc, yc, r, x, y;

    /* Get the input values */
    printf("Enter the x-coordinate of the center of the circle: ");
    scanf("%d", &xc);
    printf("Enter the y-coordinate of the center of the circle: ");
    scanf("%d", &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    printf("Enter the x-coordinate of the point: ");
    scanf("%d", &x);
    printf("Enter the y-coordinate of the point: ");
    scanf("%d", &y);

    /* Check if the point lies inside the circle */
    if (isInside(xc, yc, r, x, y)) {
        printf("The point (%d, %d) lies inside the circle.\n", x, y);
    } else {
        printf("The point (%d, %d) does not lie inside the circle.\n", x, y);
    }

    return 0;
}