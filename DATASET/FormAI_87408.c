//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int radius;
    printf("Let's calculate the area and circumference of a circle!\n");
    printf("Enter the circle's radius: ");
    scanf("%d", &radius);
    printf("\n");

    double area = M_PI * pow(radius, 2);
    double circumference = 2 * M_PI * radius;

    printf("The circle's area is: %.2lf\n", area);
    printf("The circle's circumference is: %.2lf\n", circumference);

    printf("\nNow, let's draw the circle using ASCII art!\n");

    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            if (sqrt(pow(x, 2) + pow(y, 2)) <= radius)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("\nIsn't this awesome? Now you know how to calculate and draw a circle!\n");
    return 0;
}