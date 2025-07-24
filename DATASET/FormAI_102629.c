//FormAI DATASET v1.0 Category: Fractal Generation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITER 1000
#define SCALE 0.05f

void fractal(double r, double i, char buffer[WIDTH][HEIGHT]) {
    double x, y, xn, yn, temp;
    int n, px, py;
    for (py = 0; py < HEIGHT; py++) {
        for (px = 0; px < WIDTH; px++) {
            x = ((double)px / WIDTH - 0.5) / SCALE * 2;
            y = ((double)py / HEIGHT - 0.5) / SCALE * 2;
            n = 0;
            while (n < MAX_ITER) {
                xn = x * x - y * y + r;
                yn = 2 * x * y + i;
                if (xn * xn + yn * yn > 4) {
                    buffer[px][py] = n % 10 + '0';
                    break;
                }
                x = xn;
                y = yn;
                n++;
            }
            if (n == MAX_ITER) {
                buffer[px][py] = ' ';
            }
        }
    }
}

int main() {
    char buffer[WIDTH][HEIGHT];
    double r = -0.7, i = 0.27015;
    fractal(r, i, buffer);
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(buffer[x][y]);
        }
        putchar('\n');
    }
    return 0;
}