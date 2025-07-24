//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>

// Define the structure for a point in a 2D space
typedef struct
{
    float x;
    float y;
} Point;

// Define the structure for a triangle in a 2D space
typedef struct
{
    Point A;
    Point B;
    Point C;
} Triangle;


/* Calculate the area of a triangle using cross product */
float triangle_area(Triangle t)
{
    float ax = t.A.x, ay = t.A.y;
    float bx = t.B.x, by = t.B.y;
    float cx = t.C.x, cy = t.C.y;
    return 0.5f * ((bx - ax) * (cy - ay) - (cx - ax) * (by - ay));
}

/* Determine if a point is inside a triangle */
int is_inside_triangle(Triangle t, Point p)
{
    float abc = triangle_area(t);
    float pab = triangle_area((Triangle) { p, t.A, t.B });
    float pbc = triangle_area((Triangle) { p, t.B, t.C });
    float pca = triangle_area((Triangle) { p, t.C, t.A });

    return abc == pab + pbc + pca;
}

/* Test the is_inside_triangle function with some sample data */
int main()
{
    Triangle t = {
        .A = { 0.0f, 0.0f },
        .B = { 10.0f, 0.0f },
        .C = { 0.0f, 10.0f }
    };

    // Check some points for being inside/outside the triangle
    Point p1 = { 5.0f, 5.0f };
    if (is_inside_triangle(t, p1))
        printf("Point (%.1f, %.1f) is inside the triangle\n", p1.x, p1.y);
    else
        printf("Point (%.1f, %.1f) is outside the triangle\n", p1.x, p1.y);

    Point p2 = { 20.0f, 20.0f };
    if (is_inside_triangle(t, p2))
        printf("Point (%.1f, %.1f) is inside the triangle\n", p2.x, p2.y);
    else
        printf("Point (%.1f, %.1f) is outside the triangle\n", p2.x, p2.y);

    return 0;
}