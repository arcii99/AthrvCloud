//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct point {
    double x;
    double y;
} point;

point midpoint(point p1, point p2) {
    point mid;
    mid.x = (p1.x + p2.x)/2;
    mid.y = (p1.y + p2.y)/2;
    return mid;
}

void draw_point(int x, int y, int r, int g, int b, FILE *fp) {
    fprintf(fp, "point %d %d %d %d %d\n", x, y, r, g, b);
}

void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b, FILE *fp) {
    fprintf(fp, "line %d %d %d %d %d %d %d\n", x1, y1, x2, y2, r, g, b);
}

void draw_triangles(point p1, point p2, point p3, int r, int g, int b, FILE *fp) {
    if ((fabs(p1.x - p3.x) < 1. || fabs(p2.x - p3.x) < 1.)) {
        return;
    }
    point mid1 = midpoint(p1, p2);
    point mid2 = midpoint(p2, p3);
    point mid3 = midpoint(p3, p1);

    draw_line(p1.x, p1.y, p2.x, p2.y, r, g, b, fp);
    draw_line(p2.x, p2.y, p3.x, p3.y, r, g, b, fp);
    draw_line(p3.x, p3.y, p1.x, p1.y, r, g, b, fp);

    draw_triangles(p1, mid1, mid3, r, g, b, fp);
    draw_triangles(p2, mid2, mid1, r, g, b, fp);
    draw_triangles(p3, mid3, mid2, r, g, b, fp);
}

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    int r, g, b;
    r = rand()%256;
    g = rand()%256;
    b = rand()%256;

    FILE *fp = fopen("fractal.ppm", "w");

    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");

    point p1, p2, p3;
    p1.x = WIDTH/2;
    p1.y = 0;
    p2.x = 0;
    p2.y = HEIGHT;
    p3.x = WIDTH;
    p3.y = HEIGHT;

    draw_triangles(p1, p2, p3, r, g, b, fp);

    fclose(fp);

    return 0;
}