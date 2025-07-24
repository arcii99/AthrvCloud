//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>
#include <math.h>

// Define a point struct
typedef struct {
    double x, y;
} Point;

// Define a geometric shape struct
typedef struct {
    int num_points;
    Point *points;
} Shape;

// Function to compute the perimeter of a shape
double get_perimeter(Shape shape) {
    double perimeter = 0.0;

    for (int i = 0; i < shape.num_points; i++) {
        Point p1 = shape.points[i];
        Point p2 = shape.points[(i + 1) % shape.num_points];

        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;

        perimeter += sqrt(dx * dx + dy * dy);
    }

    return perimeter;
}

int main() {
    // Create a square
    Point square_points[] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Shape square = {4, square_points};

    // Compute the perimeter of the square
    double square_perimeter = get_perimeter(square);

    // Print the perimeter of the square
    printf("The perimeter of the square is %f\n", square_perimeter);

    return 0;
}