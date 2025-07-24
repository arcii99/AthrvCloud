//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>

double calculateDistance(double x1, double y1, double x2, double y2) {
    /* This function returns the distance between two points in a 2D plane */
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point (x1, y1):\n");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2):\n");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of the third point (x3, y3):\n");
    scanf("%lf %lf", &x3, &y3);
    double distance1 = calculateDistance(x1, y1, x2, y2);
    double distance2 = calculateDistance(x1, y1, x3, y3);
    double distance3 = calculateDistance(x2, y2, x3, y3);
    double perimeter = distance1 + distance2 + distance3;
    double s = perimeter / 2;
    double area = sqrt(s * (s - distance1) * (s - distance2) * (s - distance3));
    printf("The perimeter of the triangle is: %lf\n", perimeter);
    printf("The area of the triangle is: %lf\n", area);
    return 0;
}