//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>

// a struct to represent a point in 2D space
struct Point {
    float x;
    float y;
};

// a function to calculate the distance between two points
float distance(struct Point p1, struct Point p2) {
    float x_diff = p2.x - p1.x;
    float y_diff = p2.y - p1.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// a function to calculate the area of a triangle given its three vertices
float triangle_area(struct Point p1, struct Point p2, struct Point p3) {
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // create three points to represent a triangle
    struct Point p1 = {1.0, 1.0};
    struct Point p2 = {4.0, 1.0};
    struct Point p3 = {2.0, 4.0};

    // calculate the area of the triangle
    float area = triangle_area(p1, p2, p3);
    
    // print the area of the triangle
    printf("The area of the triangle with vertices (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f) is %.2f.\n",
           p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);

    return 0;
}