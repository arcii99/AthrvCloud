//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a polygon with n vertices
float polygonArea(int n, float* x, float* y) {
    float area = 0;
    int j, k;
    for (int i = 0; i < n; i++) {
        j = (i + 1) % n;
        k = (i + 2) % n;
        area += x[i] * y[j] + x[j] * y[k] + x[k] * y[i];
        area -= x[i] * y[k] + x[j] * y[i] + x[k] * y[j];
    }
    return fabs(area / 2);
}

int main() {
    // Example polygon with 4 vertices
    int n = 4;
    float x[] = {0, 1, 1, 0};
    float y[] = {0, 0, 1, 1};

    float area = polygonArea(n, x, y);
    printf("Area of polygon is %.2f\n", area);

    return 0;
}