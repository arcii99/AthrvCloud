//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point in 2D space
struct point {
    int x, y;
};

// Utility function to find the distance between two points
float dist(struct point p1, struct point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Recursive function to find the perimeter of a convex hull
float calcPerimeter(struct point arr[], int n) {
    // Base case - if less than 3 points, can't construct a convex hull
    if (n < 3) {
        return 0;
    }
    
    // Find the leftmost and rightmost points
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].x < arr[l].x) {
            l = i;
        }
        if (arr[i].x > arr[r].x) {
            r = i;
        }
    }
    
    // Find the upper and lower tangent points
    int upper[n], lower[n];
    int u = 0, v = 0;
    upper[u++] = l;
    lower[v++] = l;
    
    int temp = l;
    while (temp != r) {
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i].y < arr[temp].y) {
                break;
            }
        }
        temp = i;
        upper[u++] = temp;
    }
    
    temp = l;
    while (temp != r) {
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i].y > arr[temp].y) {
                break;
            }
        }
        temp = i;
        lower[v++] = temp;
    }
    
    // Combine the two halves
    struct point hull[n];
    int hullSize = 0;
    for (int i = 0; i < u; i++) {
        hull[hullSize++] = arr[upper[i]];
    }
    for (int i = v - 2; i > 0; i--) {
        hull[hullSize++] = arr[lower[i]];
    }
    
    // Calculate the perimeter
    float perimeter = 0;
    for (int i = 0; i < hullSize - 1; i++) {
        perimeter += dist(hull[i], hull[i + 1]);
    }
    perimeter += dist(hull[hullSize - 1], hull[0]);
    
    // Call the function recursively for the two halves
    return perimeter + calcPerimeter(arr, l + 1) + calcPerimeter(arr + r, n - r + l);
}

int main() {
    // Sample input - an array of 10 points
    struct point arr[] = {{0, 0}, {0, 10}, {10, 10}, {10, 0}, {5, 5}, {3, 7}, {7, 3}, {3, 3}, {7, 7}, {5, 0}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Find and print the perimeter of the convex hull
    float perimeter = calcPerimeter(arr, n);
    printf("Perimeter of convex hull is %.2f", perimeter);
    
    return 0;
}