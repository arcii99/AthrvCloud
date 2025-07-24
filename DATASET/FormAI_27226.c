//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {
    int x1, x2, y1, y2, distance;
    printf("Enter the coordinates of point 1 (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the coordinates of point 2 (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    distance = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));

    printf("\nThe distance between the two points is %d\n", distance);

    int perimeter, area, s1, s2, s3;
    printf("\nEnter the sides of the triangle (s1, s2, s3): ");
    scanf("%d%d%d", &s1, &s2, &s3);

    perimeter = s1 + s2 + s3;
    float s = (float)perimeter/2;
    area = sqrt(s * (s - s1) * (s - s2) * (s - s3));

    printf("\nThe perimeter of the triangle is %d", perimeter);
    printf("\nThe area of the triangle is %d", area);

    return 0;
}