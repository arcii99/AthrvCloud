//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Yippee, let's calculate the area of a circle!\n\n");

    float radius, area;
    printf("What is the radius of the circle? ");
    scanf("%f", &radius);

    area = M_PI * pow(radius, 2);
    printf("\nThe area of the circle is %.2f units.\n", area);

    printf("\nNow let's find the perimeter of this triangle! This is fun!\n\n");

    float side1, side2, side3, perimeter;
    printf("What is the first side of the triangle? ");
    scanf("%f", &side1);
    printf("What is the second side of the triangle? ");
    scanf("%f", &side2);
    printf("What is the third side of the triangle? ");
    scanf("%f", &side3);

    perimeter = side1 + side2 + side3;
    printf("\nThe perimeter of the triangle is %.2f units.\n", perimeter);

    printf("\nThank you for playing with me! Goodbye!\n");
    return 0;
}