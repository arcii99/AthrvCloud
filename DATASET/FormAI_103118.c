//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct point {
    double x;
    double y;
} Point;

double calculate_distance(Point p1, Point p2);
double calculate_angle(Point p1, Point p2, Point p3);
double calculate_triangle_area(Point p1, Point p2, Point p3);

int main()
{
    Point p1, p2, p3;
    double distance, angle, area;

    printf("Enter the coordinates of Point 1: ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Enter the coordinates of Point 2: ");
    scanf("%lf %lf", &p2.x, &p2.y);

    printf("Enter the coordinates of Point 3: ");
    scanf("%lf %lf", &p3.x, &p3.y);

    distance = calculate_distance(p1, p2);
    printf("\nDistance between Point 1 and Point 2: %.2lf\n", distance);

    angle = calculate_angle(p1, p2, p3);
    printf("Angle between Point 1, Point 2, and Point 3: %.2lf degrees\n", angle);

    area = calculate_triangle_area(p1, p2, p3);
    printf("Area of the triangle formed by Point 1, Point 2, and Point 3: %.2lf\n", area);

    return 0;
}

double calculate_distance(Point p1, Point p2)
{
    double x_diff, y_diff;
    x_diff = p2.x - p1.x;
    y_diff = p2.y - p1.y;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

double calculate_angle(Point p1, Point p2, Point p3)
{
    double a, b, c, cos_angle;
    a = calculate_distance(p2, p3);
    b = calculate_distance(p1, p3);
    c = calculate_distance(p1, p2);
    cos_angle = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
    return acos(cos_angle) * 180 / PI;
}

double calculate_triangle_area(Point p1, Point p2, Point p3)
{
    double a, b, c, s;
    a = calculate_distance(p2, p3);
    b = calculate_distance(p1, p3);
    c = calculate_distance(p1, p2);
    s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}