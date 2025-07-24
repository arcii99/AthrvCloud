//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>

// This program calculates the area of a triangle using the Shoelace Formula
// It's a geometric algorithm that is based on the coordinates of the vertices
// of the triangle
// The Shoelace Formula is also known as the Surveyor's Formula

int main()
{
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the vertices of the triangle:\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    // We need to calculate two different sums for the Shoelace Formula
    int sum1 = x1 * y2 + x2 * y3 + x3 * y1;
    int sum2 = y1 * x2 + y2 * x3 + y3 * x1;

    // Calculate the area of the triangle
    int area = abs(sum1 - sum2) / 2;

    printf("\nThe area of the triangle is %d\n", area);
    return 0;
}