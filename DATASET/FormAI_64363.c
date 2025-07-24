//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>

/* This program generates a fractal pattern known as the Sierpinski Triangle.
   It is created by repeatedly subdividing equilateral triangles and removing their
   centers. */
   
/* Define the data structures for points and triangles */
typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point vertices[3];
} Triangle;

/* Get the midpoint between two points */
Point getMidpoint(Point p1, Point p2) {
    Point midpoint;
    midpoint.x = (p1.x + p2.x) / 2;
    midpoint.y = (p1.y + p2.y) / 2;
    return midpoint;
}

/* Draw a triangle on the screen */
void drawTriangle(Triangle t) {
    // Code to draw the triangle
}

/* Remove the center of a triangle and create three new triangles */
void subdivideTriangle(Triangle t) {
    Point midpoints[3];
    // Get midpoints of each edge
    midpoints[0] = getMidpoint(t.vertices[0], t.vertices[1]);
    midpoints[1] = getMidpoint(t.vertices[1], t.vertices[2]);
    midpoints[2] = getMidpoint(t.vertices[2], t.vertices[0]);
    // Create three new triangles
    Triangle triangles[3];
    triangles[0].vertices[0] = t.vertices[0];
    triangles[0].vertices[1] = midpoints[0];
    triangles[0].vertices[2] = midpoints[2];
    triangles[1].vertices[0] = midpoints[0];
    triangles[1].vertices[1] = t.vertices[1];
    triangles[1].vertices[2] = midpoints[1];
    triangles[2].vertices[0] = midpoints[2];
    triangles[2].vertices[1] = midpoints[1];
    triangles[2].vertices[2] = t.vertices[2];
    // Draw each new triangle
    for (int i = 0; i < 3; i++) {
        drawTriangle(triangles[i]);
    }
}

int main() {
    // Create initial triangle
    Triangle t;
    t.vertices[0].x = 0;
    t.vertices[0].y = 0;
    t.vertices[1].x = 1;
    t.vertices[1].y = 0;
    t.vertices[2].x = 0.5;
    t.vertices[2].y = 0.866;
    // Draw initial triangle
    drawTriangle(t);
    // Subdivide triangle recursively
    for (int i = 0; i < 5; i++) {
        subdivideTriangle(t);
    }
    return 0;
}