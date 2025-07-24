//FormAI DATASET v1.0 Category: Fractal Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isInside(int x, int y, int w, int h, double cx, double cy, double r) {
    double dist = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
    return dist < r && x >= 0 && y >= 0 && x < w && y < h;
}

void generateFractal(int w, int h, double cx, double cy, double r, char* filename) {
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n255\n", w, h);
    int maxIter = 200;
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            double zx = 3 * ((double)x / w) - 2;
            double zy = 2 * ((double)y / h) - 1;
            int iter = 0;
            while(iter < maxIter) {
                double x2 = zx * zx - zy * zy + cx;
                double y2 = 2 * zx * zy + cy;
                zx = x2;
                zy = y2;
                if(!isInside(x, y, w, h, zx, zy, r)) {
                    int red = (iter % 3) * 100;
                    int green = (iter % 5) * 50;
                    int blue = (iter % 7) * 35;
                    fprintf(fp, "%d %d %d ", red, green, blue);
                    break;
                }
                iter++;
            }
            if(iter == maxIter) {
                fprintf(fp, "0 0 0 ");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    int w = 800;
    int h = 600;
    double cx = -0.5;
    double cy = 0;
    double r = 2;
    generateFractal(w, h, cx, cy, r, "fractal.ppm");
    return 0;
}