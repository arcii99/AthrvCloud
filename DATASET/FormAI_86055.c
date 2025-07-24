//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, distance;
    printf("Enter the first point (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the second point (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("The distance between the two points is: %f\n", distance);

    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    float area = radius * radius * M_PI;
    float circumference = 2 * radius * M_PI;
    printf("The area of the circle is: %f\n", area);
    printf("The circumference of the circle is: %f\n", circumference);
    
    return 0;
}