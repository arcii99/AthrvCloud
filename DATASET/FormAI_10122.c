//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int max_iterations = 1000000;
    double x, y, xtemp, ytemp, x_0, y_0;
    int i, j, n;

    printf("Enter the real and imaginary parts of the starting point: ");
    scanf("%lf %lf", &x_0, &y_0);

    for (j = 0; j < 80; j++) {
        for (i = 0; i < 80; i++) {
            x = (((double)i) - 40) / 20;
            y = (((double)j) - 40) / 20;
            n = 0;
            while ((x*x + y*y < 4) && (n < max_iterations)) {
                xtemp = x*x - y*y + x_0;
                ytemp = 2*x*y + y_0;
                x = xtemp;
                y = ytemp;
                n++;
            }
            if (n == max_iterations) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}