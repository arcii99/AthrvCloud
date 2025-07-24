//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
    int max_iter = 1000;
    double zoom = 1.0;
    double move_x = -0.5;
    double move_y = 0.0;

    int i, j, iter;
    double x, y;
    double complex z, c;
    double xmin = -2.0;
    double xmax = 2.0;
    double ymin = -2.0;
    double ymax = 2.0;

    FILE *fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            x = xmin + ((double) i * (xmax - xmin)) / ((double) WIDTH - 1);
            y = ymin + ((double) j * (ymax - ymin)) / ((double) HEIGHT - 1);
            z = 0.0 + 0.0 * I;
            c = (x + move_x) + (y + move_y) * I;
            iter = 0;
            
            while (creal(z * conj(z)) < 4.0 && iter < max_iter) {
                z = z * z + c;
                iter++;
            }

            if (iter == max_iter) {
                fputc(0, fp);
                fputc(0, fp);
                fputc(0, fp);
            } else {
                fputc(iter * (256 / max_iter), fp);
                fputc(0, fp);
                fputc(iter * (256 / max_iter), fp);
            }
        }
    }

    fclose(fp);
    return 0;
}