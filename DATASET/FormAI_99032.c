//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ITERATIONS 1000000

double rand_double(double min, double max) {
    return min + ((double) rand() / RAND_MAX) * (max - min);
}

typedef struct {
    double x;
    double y;
} Point;

Point midpoint(Point a, Point b) {
    Point mid = { (a.x + b.x) / 2.0, (a.y + b.y) / 2.0 };
    return mid;
}

void draw_fractal(Point a, Point b, int n) {
    if(n == 0) {
        printf("%.2f,%.2f ", a.x, a.y);
    } else {
        Point tmp[3];
        tmp[0] = a;
        tmp[1] = midpoint(a, b);
        tmp[2] = b;
        for(int i = 0; i < 3; i++) {
            draw_fractal(tmp[i], midpoint(tmp[i], tmp[(i + 1) % 3]), n - 1);
        }
    }
}

int main() {
    srand(time(NULL));

    Point a = { rand_double(0.0, 1.0), rand_double(0.0, 1.0) };
    Point b = { rand_double(0.0, 1.0), rand_double(0.0, 1.0) };
    Point c = { rand_double(0.0, 1.0), rand_double(0.0, 1.0) };

    for(int i = 0; i < ITERATIONS; i++) {
        int r = rand() % 3;
        switch(r) {
            case 0:
                a = midpoint(a, c);
                break;
            case 1:
                b = midpoint(b, c);
                break;
            case 2:
                c = midpoint(c, a);
                break;
        }
    }

    printf("set terminal png\n");
    printf("set output 'fractal.png'\n");
    printf("set xrange [0:1]\n");
    printf("set yrange [0:1]\n");
    printf("plot '-' w l title 'Fractal'\n");
    draw_fractal(a, b, 6);
    printf("e\n");

    return 0;
}