//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    float area;

    printf("Enter the coordinates of Point A in the format x y: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of Point B in the format x y: ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of Point C in the format x y: ");
    scanf("%d %d", &x3, &y3);

    area = (0.5) * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (area < 0) area = -area;

    printf("\nArea of the triangle with vertices (%d,%d), (%d,%d), and (%d,%d) is %.2f square units.\n", x1, y1, x2, y2, x3, y3, area);

    return 0;
}