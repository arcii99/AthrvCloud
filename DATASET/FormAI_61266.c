//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <math.h>

struct Point
{
    int x, y;
};
typedef struct Point Point;

// Function to calculate the Euclidean distance between two points
double euclideanDistance(Point A, Point B)
{
    double distance = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    return distance;
}

// Function to calculate the slope of a line between two points
double slope(Point A, Point B)
{
    double slope = (B.y - A.y) / (double)(B.x - A.x);
    return slope;
}

// Function to find the centroid of the triangle formed by three given points
Point centroid(Point A, Point B, Point C)
{
    Point centroid;
    centroid.x = (A.x + B.x + C.x) / 3;
    centroid.y = (A.y + B.y + C.y) / 3;
    return centroid;
}

// Function to find the area of the triangle formed by three given points
double triangleArea(Point A, Point B, Point C)
{
    double area = 0.5 * abs((A.x * (B.y - C.y)) + (B.x * (C.y - A.y)) + (C.x * (A.y - B.y)));
    return area;
}

int main()
{
    Point A = {0, 0};
    Point B = {3, 4};
    Point C = {6, 0};

    double AB = euclideanDistance(A, B);
    double BC = euclideanDistance(B, C);
    double AC = euclideanDistance(A, C);

    if (AB + BC > AC && BC + AC > AB && AC + AB > BC) // Checking for the validity of the triangle
    {
        double perimeter = AB + BC + AC;
        double s = perimeter / 2;
        double area = triangleArea(A, B, C);
        double height = (2 * area) / AC;

        Point centroidPoint = centroid(A, B, C);

        printf("Sides of the triangle: AB = %lf, BC = %lf, AC = %lf\n", AB, BC, AC);
        printf("Perimeter of the triangle: %lf\n", perimeter);
        printf("Area of the triangle: %lf\n", area);
        printf("Height of the triangle: %lf\n", height);
        printf("Centroid of the triangle: (%d, %d)\n", centroidPoint.x, centroidPoint.y);

        if (slope(A, B) == slope(B, C) || slope(B, C) == slope(A, C) || slope(A, B) == slope(A, C)) // Checking for isosceles triangle
        {
            printf("This is an isosceles triangle.\n");
        }
        else
        {
            printf("This is not an isosceles triangle.\n");
        }
    }
    else
    {
        printf("These points do not form a triangle.\n");
    }

    return 0;
}