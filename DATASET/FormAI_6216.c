//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float radius, area, circumference;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // calculating the area of the circle
    area = M_PI * pow(radius, 2);
    printf("The area of the circle is %f\n", area);

    // calculating the circumference of the circle
    circumference = 2 * M_PI * radius;
    printf("The circumference of the circle is %f\n", circumference);

    // creating the axis
    for (int y = -10; y < 11; y++) {
        for (int x = -30; x < 31; x++) {
            // checking if the pixel is inside the circle
            float dist = sqrt(pow(x, 2) + pow(y, 2));
            if (dist <= radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}