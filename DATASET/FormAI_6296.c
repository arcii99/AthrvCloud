//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>

// A function to calculate the Euclidean distance between two points in 2D space
float euclidean_distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// A function to calculate the area of a rectangle given its width and height
float rectangle_area(float width, float height) {
    return width * height;
}

// A function to calculate the area of a triangle given its base and height
float triangle_area(float base, float height) {
    return 0.5 * base * height;
}

int main() {
    float x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x,y): ");
    scanf("%f%f", &x1, &y1);
    printf("Enter the coordinates of the second point (x,y): ");
    scanf("%f%f", &x2, &y2);
    float distance = euclidean_distance(x1, y1, x2, y2);
    printf("The Euclidean distance between the two points is %.2f\n", distance);

    float width, height;
    printf("Enter the width and height of the rectangle: ");
    scanf("%f%f", &width, &height);
    float area_rect = rectangle_area(width, height);
    printf("The area of the rectangle is %.2f\n", area_rect);

    float base, tri_height;
    printf("Enter the base and height of the triangle: ");
    scanf("%f%f", &base, &tri_height);
    float area_tri = triangle_area(base, tri_height);
    printf("The area of the triangle is %.2f\n", area_tri);

    return 0;
}