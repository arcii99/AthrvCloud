//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *shape = "circle";
    char *color = "red";
    int radius = 10;
    int sides = 0;

    printf("Please enter a shape (circle, square, triangle): ");
    scanf("%s", shape);

    if (strcmp(shape, "circle") == 0) {
        printf("Please enter a color (red, green, blue): ");
        scanf("%s", color);

        printf("Please enter a radius: ");
        scanf("%d", &radius);

        printf("Creating %s %s with radius %d...\n", color, shape, radius);
    } else if (strcmp(shape, "square") == 0) {
        printf("Please enter a color (red, green, blue): ");
        scanf("%s", color);

        printf("Please enter the length of a side: ");
        scanf("%d", &sides);

        printf("Creating %s %s with sides of length %d...\n", color, shape, sides);
    } else if (strcmp(shape, "triangle") == 0) {
        printf("Please enter a color (red, green, blue): ");
        scanf("%s", color);

        printf("Please enter the length of one side: ");
        scanf("%d", &sides);

        printf("Creating %s %s with one side of length %d...\n", color, shape, sides);
    } else {
        printf("Invalid shape entered.\n");
        exit(0);
    }

    return 0;
}