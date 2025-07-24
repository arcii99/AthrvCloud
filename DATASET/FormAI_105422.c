//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("\nEnter the coordinates of the vertices:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i+1);
        scanf("%f %f", &x[i], &y[i]);
    }
    float max_area = 0;
    float Ax, Ay, Bx, By, Cx, Cy;
    for (int i = 0; i < n-2; i++) {
        float x1 = x[i], y1 = y[i];
        for (int j = i+1; j < n-1; j++) {
            float x2 = x[j], y2 = y[j];
            for (int k = j+1; k < n; k++) {
                float x3 = x[k], y3 = y[k];
                float area = fabs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
                if (area > max_area) {
                    max_area = area;
                    Ax = x1;
                    Ay = y1;
                    Bx = x2;
                    By = y2;
                    Cx = x3;
                    Cy = y3;
                }
            }
        }
    }
    printf("\nLargest triangle area: %f\n", max_area);
    printf("Coordinates of the vertices of the triangle:\n");
    printf("A(%f, %f)\n", Ax, Ay);
    printf("B(%f, %f)\n", Bx, By);
    printf("C(%f, %f)\n", Cx, Cy);
    return 0;
}