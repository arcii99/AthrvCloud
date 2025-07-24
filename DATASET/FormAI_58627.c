//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    double x[100], y[100], z[100], area = 0;

    // Get number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Get input for coordinates
    printf("Enter coordinates (x, y, z) for %d vertices:\n", n);
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i+1);
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
    }

    // Calculate area of polygon using cross product
    for (i = 0; i < n-2; i++) {
        double a[3] = {x[i+1] - x[i], y[i+1] - y[i], z[i+1] - z[i]};
        double b[3] = {x[i+2] - x[i], y[i+2] - y[i], z[i+2] - z[i]};
        double c[3];
        c[0] = a[1]*b[2] - a[2]*b[1];
        c[1] = a[2]*b[0] - a[0]*b[2];
        c[2] = a[0]*b[1] - a[1]*b[0];
        double mag = sqrt(c[0]*c[0] + c[1]*c[1] + c[2]*c[2]);
        area += mag;
    }

    // Output calculated area
    printf("Area of polygon: %lf\n", area);

    return 0;
}