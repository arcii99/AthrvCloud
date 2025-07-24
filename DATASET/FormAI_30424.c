//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int n, i;
    float radius, theta, x, y, area;

    printf("Enter the number of sides in the polygon: ");
    scanf("%d", &n);

    printf("Enter the radius of the polygon: ");
    scanf("%f", &radius);

    theta = (360.0 / n) * PI / 180.0;

    x = radius;
    y = 0.0;
    area = 0.0;

    for (i = 0; i < n; i++) {
        area += (x * y) / 2.0;
        float new_x = x * cos(theta) - y * sin(theta);
        float new_y = x * sin(theta) + y * cos(theta);
        x = new_x;
        y = new_y;
    }

    printf("The area of the polygon with %d sides and radius %.2f is %.2f\n", n, radius, area);

    return 0;
}