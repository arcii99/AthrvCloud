//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double heron(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double ax, ay, bx, by, cx, cy;
    printf("Enter the coordinates of three points in the Cartesian plane:\n");
    printf("Ax: ");
    scanf("%lf", &ax);
    printf("Ay: ");
    scanf("%lf", &ay);
    printf("Bx: ");
    scanf("%lf", &bx);
    printf("By: ");
    scanf("%lf", &by);
    printf("Cx: ");
    scanf("%lf", &cx);
    printf("Cy: ");
    scanf("%lf", &cy);
    
    Point A = {ax, ay};
    Point B = {bx, by};
    Point C = {cx, cy};
    
    double a = distance(B, C);
    double b = distance(C, A);
    double c = distance(A, B);
    
    if (a + b <= c || b + c <= a || c + a <= b) {
        printf("Invalid triangle!\n");
        return 1;
    }
    
    double area = heron(a, b, c);
    printf("The area of the triangle ABC is: %.2f.\n", area);
    
    Point G = {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
    printf("The centroid of the triangle ABC is: (%.2f, %.2f).\n", G.x, G.y);
    
    Point M = {(A.x + B.x) / 2, (A.y + B.y) / 2};
    Point D = {2 * G.x - M.x, 2 * G.y - M.y};
    double h = distance(D, C);
    printf("The height of the triangle ABC from vertex C is: %.2f.\n", h);
    
    return 0;
}