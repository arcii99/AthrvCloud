//FormAI DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800 // Width of the image
#define HEIGHT 600 // Height of the image

typedef struct {
    double x;
    double y;
} Vector2;

Vector2 add(Vector2 a, Vector2 b) {
    Vector2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector2 sub(Vector2 a, Vector2 b) {
    Vector2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Vector2 mult(Vector2 a, double s) {
    Vector2 result;
    result.x = a.x * s;
    result.y = a.y * s;
    return result;
}

double length(Vector2 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double dot(Vector2 a, Vector2 b) {
    return a.x * b.x + a.y * b.y;
}

double clamp(double value, double min, double max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

Vector2 fractal(Vector2 p, double scale, int iterations) {
    int i;
    Vector2 result = {0, 0};
    Vector2 point = mult(p, scale);

    for (i = 0; i < iterations; i++) {
        double lengthSquared = length(point) * length(point);
        point.x = fabs(point.x);
        point.y = fabs(point.y);
        point = (Vector2){point.y, -point.x};
        point = mult(point, 2.0 / lengthSquared);
        result = add(result, point);
    }

    result = mult(result, 0.5);
    return result;
}

int main() {
    FILE *imageFile = fopen("fractal.ppm", "wb");
    fprintf(imageFile, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    double scale = 2.0 / fmax(WIDTH, HEIGHT);
    int iterations = 20;

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            Vector2 point = {x - WIDTH/2, y - HEIGHT/2};
            Vector2 result = fractal(point, scale, iterations);
            double r = clamp(result.x + 0.5, 0, 1) * 255;
            double g = clamp(result.y + 0.5, 0, 1) * 255;
            double b = (r + g) / 2;
            fputc((int)r, imageFile);
            fputc((int)g, imageFile);
            fputc((int)b, imageFile);
        }
    }

    fclose(imageFile);
    return 0;
}