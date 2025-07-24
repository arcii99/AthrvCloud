//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>

/* This program calculates the area, perimeter, and diagonal of a rectangle */

int main() {
    float width, height, area, perimeter, diagonal;

    printf("Please enter the width of the rectangle: ");
    scanf("%f", &width);

    printf("Please enter the height of the rectangle: ");
    scanf("%f", &height);

    area = width * height;
    perimeter = 2 * (width + height);
    diagonal = sqrt((width * width) + (height * height));

    printf("The area of the rectangle is: %.2f\n", area);
    printf("The perimeter of the rectangle is: %.2f\n", perimeter);
    printf("The diagonal of the rectangle is: %.2f\n", diagonal);

    return 0;
}