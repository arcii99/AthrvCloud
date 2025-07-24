//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3], y[3], i;
    float area;

    printf("Enter the coordinates of the three vertices of the triangle.\n");

    for (i = 0; i < 3; i++) {
        printf("Vertex %d (x, y): ", i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Calculate the area using the Shoelace Formula
    area = abs((x[0] * y[1] + x[1] * y[2] + x[2] * y[0]) - (y[0] * x[1] + y[1] * x[2] + y[2] * x[0])) / 2.0;

    printf("The area of the triangle is %.2f square units.\n", area);

    return 0;
}