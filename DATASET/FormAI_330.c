//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: accurate
#include<stdio.h>
#include<math.h>

struct point {
    double x_coordinate, y_coordinate;
};

// Function to find Euclidean distance between two points
double distance(struct point p, struct point q) {
    double dx = p.x_coordinate - q.x_coordinate;
    double dy = p.y_coordinate - q.y_coordinate;
    return sqrt(dx*dx + dy*dy);
}

// Function to find the perimeter of a triangle
double triangle_perimeter(struct point p, struct point q, struct point r) {
    return distance(p, q) + distance(q, r) + distance(r, p);
}

// Function to find the area of a triangle using Heron's formula
double triangle_area(struct point p, struct point q, struct point r) {
    double a = distance(p, q);
    double b = distance(q, r);
    double c = distance(r, p);
    double s = (a + b + c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// Function to determine if 3 points form a clockwise or counterclockwise orientation
int orientation(struct point p, struct point q, struct point r) {
    double cross_product = (q.x_coordinate - p.x_coordinate) * (r.y_coordinate - q.y_coordinate) 
                        - (q.y_coordinate - p.y_coordinate) * (r.x_coordinate - q.x_coordinate);
    if(cross_product > 0)
        return 1; // counterclockwise orientation
    else if(cross_product < 0)
        return -1; // clockwise orientation
    else
        return 0; // collinear points
}

// Function to determine if a point lies inside a triangle or not
int point_in_triangle(struct point p, struct point q, struct point r, struct point s) {
    int o1 = orientation(p, q, s);
    int o2 = orientation(q, r, s);
    int o3 = orientation(r, p, s);
    if(o1 == o2 && o2 == o3)
        return 1; // point lies inside the triangle
    else
        return 0; // point doesn't lie inside the triangle
}

// Sample main function to test the above functions
int main() {
    struct point p1 = {0, 0};
    struct point p2 = {3, 0};
    struct point p3 = {0, 4};
    printf("Perimeter of the triangle formed by (%.1lf, %.1lf), (%.1lf, %.1lf), and (%.1lf, %.1lf) is %.2lf\n",
            p1.x_coordinate, p1.y_coordinate, p2.x_coordinate, p2.y_coordinate, p3.x_coordinate, p3.y_coordinate,
            triangle_perimeter(p1, p2, p3));
    printf("Area of the triangle formed by (%.1lf, %.1lf), (%.1lf, %.1lf), and (%.1lf, %.1lf) is %.2lf\n",
            p1.x_coordinate, p1.y_coordinate, p2.x_coordinate, p2.y_coordinate, p3.x_coordinate, p3.y_coordinate,
            triangle_area(p1, p2, p3));
    struct point p = {1, 1};
    if(point_in_triangle(p1, p2, p3, p))
        printf("Point (%.1lf, %.1lf) lies inside the triangle formed by (%.1lf, %.1lf), (%.1lf, %.1lf), and (%.1lf, %.1lf)\n",
                p.x_coordinate, p.y_coordinate, p1.x_coordinate, p1.y_coordinate, p2.x_coordinate, p2.y_coordinate, p3.x_coordinate, p3.y_coordinate);
    else
        printf("Point (%.1lf, %.1lf) doesn't lie inside the triangle formed by (%.1lf, %.1lf), (%.1lf, %.1lf), and (%.1lf, %.1lf)\n",
                p.x_coordinate, p.y_coordinate, p1.x_coordinate, p1.y_coordinate, p2.x_coordinate, p2.y_coordinate, p3.x_coordinate, p3.y_coordinate);
    struct point q = {2, 2};
    if(point_in_triangle(p1, p2, p3, q))
        printf("Point (%.1lf, %.1lf) lies inside the triangle formed by (%.1lf, %.1lf), (%.1lf, %.1lf), and (%.1lf, %.1lf)\n",
                q.x_coordinate, q.y_coordinate, p1.x_coordinate, p1.y_coordinate, p2.x_coordinate, p2.y_coordinate, p3.x_coordinate, p3.y_coordinate);
    else
        printf("Point (%.1lf, %.1lf) doesn't lie inside the triangle formed by (%.1lf, %.1lf), (%.1lf, %.1lf), and (%.1lf, %.1lf)\n",
                q.x_coordinate, q.y_coordinate, p1.x_coordinate, p1.y_coordinate, p2.x_coordinate, p2.y_coordinate, p3.x_coordinate, p3.y_coordinate);
    return 0;
}