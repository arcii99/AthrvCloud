//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>

// Function to check whether the given three points are collinear or not
int collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    // Compare slopes of lines joining the points (x1, y1) & (x2, y2) and (x2, y2) & (x3, y3)
    if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1))
        return 1;
    else
        return 0;
}

// Program to find whether a point lies inside a polygon or not
int isInside(int polygon[][2], int n, int x, int y)
{
    // If polygon has less than 3 points, cannot form a polygon
    if (n < 3) 
        return 0;

    // Check if the point lies on any of the polygon edges
    for (int i = 0; i < n; i++) 
    {
        if (collinear(polygon[i][0], polygon[i][1], polygon[(i + 1) % n][0], polygon[(i + 1) % n][1], x, y)) 
            return 1;
    }

    // If point lies outside the polygon, return false
    if (collinear(polygon[0][0], polygon[0][1], polygon[1][0], polygon[1][1], x, y)) 
        return 0;

    // Initialize count of intersections
    int count = 0;

    // Check if the point intersects with polygon edges
    for (int i = 0; i < n; i++)
    {
        int x1 = polygon[i][0], y1 = polygon[i][1];
        int x2 = polygon[(i + 1) % n][0], y2 = polygon[(i + 1) % n][1];

        if (y2 < y1 || (y1 == y2 && x2 < x1))
            x1 = x2, y1 = y2, x2 = polygon[i][0], y2 = polygon[i][1];

        // Check if the line from (x,y) to (INF,y) intersects with line (x1,y1) to (x2,y2)
        if (y1 < y && y2 >= y && (x1 + (y - y1) / (y2 - y1) * (x2 - x1)) > x)
            count++;
    }

    // If the number of intersections is odd, point lies inside the polygon
    return (count % 2 != 0);
}

// Driver program to test the above functions
int main()
{
    int polygon[][2] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon) / sizeof(polygon[0]);

    int x = 20, y = 20;
    if (isInside(polygon, n, x, y))
        printf("Point (%d, %d) lies inside the polygon\n", x, y);
    else
        printf("Point (%d, %d) lies outside the polygon\n", x, y);

    x = 5, y = 5;
    if (isInside(polygon, n, x, y))
        printf("Point (%d, %d) lies inside the polygon\n", x, y);
    else
        printf("Point (%d, %d) lies outside the polygon\n", x, y);

    return 0;
}