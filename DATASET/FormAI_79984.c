//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mandelbrot(int Xres, int Yres, double xMin, double xMax, double yMin, double yMax, int maxIters){
    double x, y, xOld, yOld, xNew, yNew, modulus;
    int i, j, k;
    for(i=0;i<Yres;++i){
        y = yMin + (yMax - yMin) * i / (Yres-1);
        for (j=0; j < Xres; ++j){
            x = xMin + (xMax - xMin) * j / (Xres-1);
            xOld = x;
            yOld = y;
            modulus = 0;
            for (k=0; k < maxIters; ++k){
                xNew = xOld * xOld - yOld * yOld + x;
                yNew = 2 * xOld * yOld + y;
                modulus = xNew * xNew + yNew * yNew;
                if (modulus > 4){
                    break;
                }
                xOld = xNew;
                yOld = yNew;
            }   
            printf("%d ", k);
        }
        printf("\n");
    }
}

int main(){
  mandelbrot(100, 25, -2.0, 0.5, -1.25, 1.25, 200);
  return 0;
}