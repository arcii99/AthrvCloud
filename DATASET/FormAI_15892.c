//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main() {
    int width = 80, height = 40, maxIterations = 50;
    double realMin = -2.0, realMax = 2.0;
    double imagMin = -1.2, imagMax = 1.2;
    double dx = (realMax - realMin) / width;
    double dy = (imagMax - imagMin) / height;
    double complex c, z;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            c = realMin + x * dx + (imagMax - y * dy) * I;
            z = 0 + 0 * I;
            int i;
            for (i = 0; i < maxIterations; i++) {
                z = z * z + c;
                if (cabs(z) > 2) break;
            }
            if (i == maxIterations) {
                printf(" ");
            } else {
                int index = i % 8;
                char *colors = "01234567";
                printf("%c", colors[index]);
            }
        }
        printf("\n");
    }

    return 0;
}