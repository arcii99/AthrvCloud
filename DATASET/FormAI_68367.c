//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

/* This program recursively calculates the Euclidean distance between two points in a plane using their x-y coordinates */

struct Point {
    float x, y;
};

typedef struct Point Point;

float distance(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

float calculate_distance(Point points[], int size) {
    if (size <= 1)
        return 0;
    else if (size == 2)
        return distance(points[0], points[1]);
    else {
        Point mid_point = points[size / 2 - 1];
        float distance_left = calculate_distance(points, size / 2);
        float distance_right = calculate_distance(points + size / 2, size - size / 2);
        float min_distance = (distance_left < distance_right) ? distance_left : distance_right;
        Point* strip = (Point*) malloc(size * sizeof(Point));
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (abs(points[i].x - mid_point.x) < min_distance) {
                strip[j] = points[i];
                j++;
            }
        }
        for (int i = 0; i < j; i++) {
            for (int k = i+1; k < j && (strip[k].y - strip[i].y) < min_distance; k++) {
                float d = distance(strip[k], strip[i]);
                if (d < min_distance) {
                    min_distance = d;
                }
            }
        }
        free(strip);
        return min_distance;
    }
}

int main() {
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int size = sizeof(points) / sizeof(points[0]);
    float result = calculate_distance(points, size);
    printf("The distance between the two closest points is %.2f", result);
    return 0;
}