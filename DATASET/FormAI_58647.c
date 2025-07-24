//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float s, area;

    printf("Enter the lengths of the three sides of a triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Triangle does not exist.\n");
    }
    else {
        s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));

        printf("The area of the triangle is %f square units.\n", area);
    }

    return 0;
}