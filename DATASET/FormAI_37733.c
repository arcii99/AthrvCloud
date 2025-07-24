//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a convex polygon
float convex_polygon_area(int n, float x[], float y[]) {
    float area = 0.0;
    int j = n-1;
    
    // Iterate over all vertices of the polygon
    for (int i = 0; i < n; i++) {
        area += (x[j]+x[i]) * (y[j]-y[i]);
        j = i;
    }
    
    return fabs(area/2.0);
}

// Function to check if a point is inside a convex polygon
int is_point_in_convex_polygon(int n, float x[], float y[], float px, float py) {
    int inside = 1;
    
    // Iterate over all vertices of the polygon
    for (int i = 0; i < n; i++) {
        int j = (i+1) % n;
        float vx = x[j] - x[i];
        float vy = y[j] - y[i];
        float wx = px - x[i];
        float wy = py - y[i];
        float cross = vx * wy - vy * wx;
        if (cross < 0) {
            inside = 0;
            break;
        }
    }
    
    return inside;
}

int main() {
    int n = 4;  // Number of vertices of the polygon
    float x[] = {0, 3, 3, 0};  // X-coordinates of the vertices
    float y[] = {0, 0, 3, 3};  // Y-coordinates of the vertices
    
    float area = convex_polygon_area(n, x, y);
    printf("Area of the polygon is %.2f.\n", area);
    
    float px = 1.5, py = 1.5;  // Sample point
    int inside = is_point_in_convex_polygon(n, x, y, px, py);
    if (inside) {
        printf("The point (%.2f, %.2f) is inside the polygon.\n", px, py);
    } else {
        printf("The point (%.2f, %.2f) is outside the polygon.\n", px, py);
    }
    
    return 0;
}