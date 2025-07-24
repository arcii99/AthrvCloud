//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

float getDistance(struct Point point1, struct Point point2) {
    float distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    return distance;
}

int main() {
    struct Point points[3];

    printf("Enter coordinates for point 1:\n");
    scanf("%d %d", &points[0].x, &points[0].y);

    printf("Enter coordinates for point 2:\n");
    scanf("%d %d", &points[1].x, &points[1].y);

    printf("Enter coordinates for point 3:\n");
    scanf("%d %d", &points[2].x, &points[2].y);

    float distance1 = getDistance(points[0], points[1]);
    float distance2 = getDistance(points[0], points[2]);
    float distance3 = getDistance(points[1], points[2]);

    if(distance1 + distance2 > distance3 && distance1 + distance3 > distance2 && distance2 + distance3 > distance1) {
        printf("The three points form a triangle.\n");

        float semiperimeter = (distance1 + distance2 + distance3) / 2;
        float area = sqrt(semiperimeter * (semiperimeter - distance1) * (semiperimeter - distance2) * (semiperimeter - distance3));
        printf("Area of the triangle: %.2f\n", area);

        if(distance1 == distance2 && distance1 == distance3) {
            printf("The triangle is equilateral.\n");
        } else if(distance1 == distance2 || distance1 == distance3 || distance2 == distance3) {
            printf("The triangle is isosceles.\n");
        } else {
            printf("The triangle is scalene.\n");
        }
    } else {
        printf("The three points do not form a triangle.\n");
    }

    return 0;
}