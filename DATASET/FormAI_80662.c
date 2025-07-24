//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int sides;
    printf("Enter the number of sides of the shape: ");
    scanf("%d", &sides);

    double vertices[sides][2];
    int i;

    printf("\nEnter the vertices for the shape:\n");
    for (i = 0; i < sides; i++) {
        printf(" Vertex %d: ", i+1);
        scanf("%lf,%lf", &vertices[i][0], &vertices[i][1]);
    }

    double circumference = 0;
    double area = 0;

    // Calculate circumference and area
    for (i = 0; i < sides; i++) {
        double x1 = vertices[i][0];
        double y1 = vertices[i][1];
        double x2 = vertices[(i+1)%sides][0];
        double y2 = vertices[(i+1)%sides][1];

        double side = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
        circumference += side;
        area += x1*y2 - x2*y1;
    }

    area = fabs(area)/2;

    printf("\nCircumference: %lf", circumference);
    printf("\nArea: %lf", area);

    return 0;
}