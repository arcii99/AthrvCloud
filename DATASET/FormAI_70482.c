//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>

int main() {
    int r, x, y, num_points = 10;
    int points[num_points][2];
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    printf("Enter the coordinates of the center of the circle (x,y): ");
    scanf("%d %d", &x, &y);

    for(int i=0; i<num_points; i++) {
        float angle = (float)i * (2.0 * 3.14 / (float)num_points);
        points[i][0] = x + r * cos(angle);
        points[i][1] = y + r * sin(angle);
    }

    printf("The coordinates of the points on the circle (x,y):\n");
    for(int i=0; i<num_points; i++) {
        printf("(%d,%d)\n", points[i][0], points[i][1]);
    }

    int perimeter = 0;
    for(int i=0; i<num_points-1; i++) {
        perimeter += sqrt(pow(points[i+1][0] - points[i][0], 2) + pow(points[i+1][1] - points[i][1], 2));
    }
    perimeter += sqrt(pow(points[0][0] - points[num_points-1][0], 2) + pow(points[0][1] - points[num_points-1][1], 2));

    printf("The perimeter of the circle is: %d\n", perimeter);

    int area = 0;
    for(int i=0; i<num_points-1; i++) {
        area += points[i][0] * points[i+1][1] - points[i][1] * points[i+1][0];
    }
    area += points[num_points-1][0] * points[0][1] - points[num_points-1][1] * points[0][0];

    area /= 2;

    printf("The area of the circle is: %d\n", area);
    return 0;
}