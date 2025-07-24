//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    int shape = rand() % 3; // Generates a random integer from 0 to 2 (inclusive)

    int radius, base, height;
    double area;

    switch (shape) {
        case 0: // Circle
            radius = rand() % 10 + 1; // Generates a random integer from 1 to 10 (inclusive)
            area = 3.14 * radius * radius;
            printf("The area of the circle with radius %d is %f\n", radius, area);
            break;
        case 1: // Triangle
            base = rand() % 10 + 1;
            height = rand() % 10 + 1;
            area = 0.5 * base * height;
            printf("The area of the triangle with base %d and height %d is %f\n", base, height, area);
            break;
        case 2: // Rectangle
            int length, width;
            length = rand() % 10 + 1;
            width = rand() % 10 + 1;
            area = length * width;
            printf("The area of the rectangle with length %d and width %d is %f\n", length, width, area);
            break;
    }

    return 0;
}