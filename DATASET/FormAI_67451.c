//FormAI DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_ITERATIONS 2000
#define WIDTH 640
#define HEIGHT 480

int main() {

    int x, y, i, n;
    double a, b, ca, cb, za, zb, mag;
    char buffer[HEIGHT * (WIDTH + 1)];
    char *p = buffer;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            a = ((double) x - WIDTH / 2) * 4.0 / WIDTH;
            b = ((double) y - HEIGHT / 2) * 4.0 / WIDTH;
            ca = a;
            cb = b;
            n = 0;
            for (i = 0; i < NUM_ITERATIONS; i++) {
                za = a * a - b * b;
                zb = 2 * a * b;
                a = za + ca;
                b = zb + cb;
                mag = a * a + b * b;
                if (mag > 4) {
                    n = i;
                    break;
                }
            }
            *p++ = n > 4 ? ' ' : ".,-~:;=!*#$@"[n % 10];
        }
        *p++ = '\n';
    }

    *p = '\0';

    printf("%s", buffer);

    return 0;
}