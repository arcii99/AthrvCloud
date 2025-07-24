//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int numPoints;

    printf("Hey there! How many points would you like to enter?: ");
    scanf("%d", &numPoints);

    if (numPoints < 3) {
        printf("\nHmm, you need to enter at least three points. Try again.\n");
        exit(0);
    }

    // allocate dynamic memory for x and y coordinates of points
    int *x = malloc(numPoints * sizeof(int));
    int *y = malloc(numPoints * sizeof(int));

    printf("\nGreat! Now enter x and y (space-separated) coordinates for each point:\n");

    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: ", i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // calculate centroid of polygon
    double cx = 0, cy = 0;

    for (int i = 0; i < numPoints; i++) {
        cx += x[i];
        cy += y[i];
    }

    cx /= numPoints;
    cy /= numPoints;

    printf("\nWow! The centroid of your polygon is (%lf, %lf)\n\n", cx, cy);

    // calculate distance between each point and centroid
    double *distances = malloc(numPoints * sizeof(double));
    double totalDist = 0;

    for (int i = 0; i < numPoints; i++) {
        double dx = cx - x[i];
        double dy = cy - y[i];
        distances[i] = sqrt(pow(dx, 2) + pow(dy, 2));
        totalDist += distances[i];
    }

    printf("That's not all! The total distance between each point and centroid is %lf\n\n", totalDist);

    // free memory
    free(x);
    free(y);
    free(distances);

    return 0;
}