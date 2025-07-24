//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>

// Function to check if three given points are collinear
int Collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if ((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2))
        return 1;
    else
        return 0;
}

// Function to find the distance between two points
float Distance(int x1, int y1, int x2, int y2)
{
    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

// Function to find the area of a triangle given three vertices
float Area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float area = abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0);
    return area;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point: ");
    scanf("%d %d", &x3, &y3);

    // Check if the three points are collinear
    if (Collinear(x1, y1, x2, y2, x3, y3))
        printf("The three points are collinear.\n");
    else
        printf("The three points are not collinear.\n");

    // Calculate the distances between the points
    float distance1 = Distance(x1, y1, x2, y2);
    float distance2 = Distance(x2, y2, x3, y3);
    float distance3 = Distance(x3, y3, x1, y1);

    // Display the distances between the points
    printf("The distance between point 1 and point 2 is %.2f units.\n", distance1);
    printf("The distance between point 2 and point 3 is %.2f units.\n", distance2);
    printf("The distance between point 3 and point 1 is %.2f units.\n", distance3);

    // Calculate the area of the triangle
    float area = Area(x1, y1, x2, y2, x3, y3);

    // Display the area of the triangle
    printf("The area of the triangle formed by the three points is %.2f square units.", area);

    return 0;
}