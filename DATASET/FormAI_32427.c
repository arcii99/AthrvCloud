//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, x3, y3;
    float a, b, c;

    printf("Enter the co-ordinates of point A (x, y): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the co-ordinates of point B (x, y): ");
    scanf("%f %f", &x2, &y2);

    printf("Enter the co-ordinates of point C (x, y): ");
    scanf("%f %f", &x3, &y3);

    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("The triangle cannot be formed with the given co-ordinates.\n");
    } else {
        float s = (a + b + c) / 2;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("The area of the triangle is: %f\n", area);
    }

    return 0;
}