//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int n, i, j;
    float x[25], y[25], area = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input the co-ordinates of the points
    printf("Enter the co-ordinates of the points:\n");
    for (i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f%f", &x[i], &y[i]);
    }

    // Calculate the area of the irregular polygon
    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        area += x[i] * y[j] - y[i] * x[j];
    }
    area /= 2;

    printf("Area of the polygon is %.2f\n", fabs(area));

    // Calculate the perimeter of the irregular polygon
    float perimeter = 0;
    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        perimeter += distance(x[i], y[i], x[j], y[j]);
    }

    printf("Perimeter of the polygon is %.2f\n", perimeter);

    // Calculate the distance between two farthest points
    float max_distance = 0, current_distance;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            current_distance = distance(x[i], y[i], x[j], y[j]);
            if (current_distance > max_distance)
                max_distance = current_distance;
        }
    }

    printf("Distance between the farthest points is %.2f\n", max_distance);

    return 0;
}