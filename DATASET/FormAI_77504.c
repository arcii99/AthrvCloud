//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>

// Define a struct for a point in 3D space
typedef struct {
    float x;
    float y;
    float z;
} Point3D;

// Define a struct for a rectangle in 3D space
typedef struct {
    Point3D bottomLeft;
    float width;
    float height;
} Rectangle3D;

// Define a function to print a Point3D
void printPoint3D(Point3D point) {
    printf("(%f, %f, %f)", point.x, point.y, point.z);
}

// Define a function to print a Rectangle3D
void printRectangle3D(Rectangle3D rectangle) {
    printf("Rectangle:\n");
    printf("  Bottom Left: ");
    printPoint3D(rectangle.bottomLeft);
    printf("\n");
    printf("  Width: %f\n", rectangle.width);
    printf("  Height: %f\n", rectangle.height);
}

int main() {
    // Create a Point3D and print it
    Point3D point1 = {1.0, 2.0, 3.0};
    printf("Point 1: ");
    printPoint3D(point1);
    printf("\n");

    // Create a Rectangle3D and print it
    Rectangle3D rectangle1 = {{0.0, 0.0, 0.0}, 4.0, 3.0};
    printf("\n");
    printRectangle3D(rectangle1);

    // Move the rectangle to a new position
    rectangle1.bottomLeft = point1;
    printf("\n");
    printRectangle3D(rectangle1);

    return 0;
}