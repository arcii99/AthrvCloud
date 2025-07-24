//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define WIDTH  80
#define HEIGHT 40
#define SCALE  0.05

typedef struct {
    double x;
    double y;
} Complex;

int check(Complex c) {
    Complex z;
    int i;

    z.x = 0;
    z.y = 0;

    for (i = 1; i <= 100; i++) {
        Complex temp;

        temp.x = z.x * z.x - z.y * z.y + c.x;
        temp.y = 2 * z.x * z.y + c.y;

        if (sqrt(temp.x * temp.x + temp.y * temp.y) >= 2) {
            return 0;
        }

        z = temp;
    }
    return 1;
}

int main() {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            Complex c;

            c.x = (x - WIDTH / 2) * SCALE;
            c.y = (y - HEIGHT / 2) * SCALE;

            if (check(c)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}