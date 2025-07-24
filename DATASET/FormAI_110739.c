//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

// function to check if the point lies in the fractal or not
int check_belongs(double complex c) {
    double complex z = 0;
    for (int i = 0; i < 100; i++) {
        z = z*z + c;
        if (cabs(z) > 2) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 800;
    int m = 800;
    double xmin = -2;
    double xmax = 2;
    double ymin = -2;
    double ymax = 2;
    double complex c;
    int belongs;

    // generate fractal image using escape time algorithm and output to file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d 255\n", n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double x = xmin + i*(xmax-xmin)/(double)n;
            double y = ymax - j*(ymax-ymin)/(double)m;
            c = x + y*I;
            belongs = check_belongs(c);
            if (belongs == 1) {
                fputc(255, fp);
                fputc(255, fp);
                fputc(255, fp);
            } else {
                fputc(0, fp);
                fputc(0, fp);
                fputc(0, fp);
            }
        }
    }

    fclose(fp);

    printf("Fractal generation successful! Please check the file 'fractal.ppm'\n");

    return 0;
}