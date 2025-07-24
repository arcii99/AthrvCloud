//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <math.h>

struct Point {
    int x, y;
};

float calcDistance(struct Point p1, struct Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int main() {
    struct Point p1, p2;
    float dist;

    printf("Enter the coordinates of point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter the coordinates of point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    dist = calcDistance(p1, p2);

    printf("The distance between point 1 and point 2 is: %.2f\n", dist);

    return 0;
}