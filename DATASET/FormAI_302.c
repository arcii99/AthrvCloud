//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

// Helper function to calculate Euclidean distance between two points
float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Create an array of n points
    float points[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter the x,y coordinates of point %d: ", i+1);
        scanf("%f %f", &points[i][0], &points[i][1]);
    }

    // Find the point pair with the largest distance between them
    float max_distance = -1;
    int max_i, max_j;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            float d = dist(points[i][0], points[i][1], points[j][0], points[j][1]);
            if (d > max_distance) {
                max_distance = d;
                max_i = i;
                max_j = j;
            }
        }
    }

    // Print the largest distance and the point pair that achieves it
    printf("The largest distance between two points is %.2f\n", max_distance);
    printf("The points are (%.2f, %.2f) and (%.2f, %.2f)\n", 
           points[max_i][0], points[max_i][1], points[max_j][0], points[max_j][1]);

    return 0;
}