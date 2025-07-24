//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>

typedef struct {
    float x;
    float y;
} point;

float distance(point a, point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

int main() {
    point a, b, c;

    printf("Enter the x and y coordinates of point A:\n");
    scanf("%f %f", &a.x, &a.y);

    printf("Enter the x and y coordinates of point B:\n");
    scanf("%f %f", &b.x, &b.y);

    printf("Enter the x and y coordinates of point C:\n");
    scanf("%f %f", &c.x, &c.y);

    float ab = distance(a, b);
    float bc = distance(b, c);
    float ac = distance(a, c);

    if ((ab + ac) > bc && (ab + bc) > ac && (ac + bc) > ab) {
        printf("The points you entered form a valid triangle\n");

        float perimeter = ab + bc + ac;
        float s = perimeter / 2;
        float area = sqrt(s * (s - ab) * (s - ac) * (s - bc));

        printf("The perimeter of the triangle is %.2f\n", perimeter);
        printf("The area of the triangle is %.2f\n", area);
    } else {
        printf("The points you entered do not form a valid triangle\n");
    }

    return 0;
}