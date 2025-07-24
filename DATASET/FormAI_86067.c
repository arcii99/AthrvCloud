//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <math.h>

struct point {
    double x;
    double y;
    double z;
};

double distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double area_triangle(struct point a, struct point b, struct point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);
    double s = (ab + bc + ca) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

double volume_tetrahedron(struct point a, struct point b, struct point c, struct point d) {
    double abc = area_triangle(a, b, c);
    double abd = area_triangle(a, b, d);
    double acd = area_triangle(a, c, d);
    double bcd = area_triangle(b, c, d);
    return fabs((b.x-a.x)*(c.y-a.y)*(d.z-a.z) + (c.x-a.x)*(d.y-a.y)*(b.z-a.z) +
                (d.x-a.x)*(b.y-a.y)*(c.z-a.z) - (d.x-a.x)*(c.y-a.y)*(b.z-a.z) -
                (c.x-a.x)*(b.y-a.y)*(d.z-a.z) - (b.x-a.x)*(d.y-a.y)*(c.z-a.z))/6;
}

int main() {
    struct point a = {0,0,0};
    struct point b = {1,0,0};
    struct point c = {0,1,0};
    struct point d = {0,0,1};
    double abc_area = area_triangle(a, b, c);
    double abcd_vol = volume_tetrahedron(a, b, c, d);
    printf("The area of triangle ABC is: %f\n", abc_area);
    printf("The volume of tetrahedron ABCD is: %f\n", abcd_vol);
    return 0;
}