//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include<stdio.h>
#include<math.h>

// function to calculate area of a polygon
float areaOfPolygon(float x[], float y[], int n) {
    float area = 0.0;

    // calculate area for the first n-1 vertices
    for (int i=0; i<n-1; i++) {
        area += (x[i] * y[i+1]) - (y[i] * x[i+1]);
    }

    // add area for the last vertex to the first vertex
    area += (x[n-1] * y[0]) - (y[n-1] * x[0]);

    // divide the final result by 2 to get the actual area
    area = area / 2.0;

    return fabs(area);
}

// main function
int main() {

    int n;

    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the x and y coordinates of the vertices:\n");

    for (int i=0; i<n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    float area = areaOfPolygon(x, y, n);

    printf("The area of the polygon with %d vertices is: %f\n", n, area);

    return 0;
}