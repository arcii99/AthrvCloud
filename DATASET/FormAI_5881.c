//FormAI DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

typedef struct{
    double x; 
    double y;
} Point;

int mandelbrotSet(Point p){
    int i=0;
    double real = 0.0, imag = 0.0;
    double zReal = 0.0, zImag = 0.0;
    while(i<=MAX_ITER && ((real*real)+(imag*imag))<=4.0){
        double temp = (real * real) - (imag * imag) + p.x;
        imag = (2 * real * imag) + p.y;
        real = temp;
        i++;
    }
    return i;
}

void generateFractal(bool color){
    double minReal=-2.5, maxReal=1.0;
    double minImag=-1.0, maxImag=1.0;
    double scaleReal = (maxReal-minReal)/WIDTH;
    double scaleImag = (maxImag-minImag)/HEIGHT;
    Point p;
    int i,j,k;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            p.x = minReal+(j*scaleReal);
            p.y = minImag+(i*scaleImag);
            k = mandelbrotSet(p);
            if(color){
                printf("\033[48;2;%d;%d;%dm ",(int)(k*log(k)),(int)(k*log(k)),(int)(k*log(k))); // colored output
            }else{
                if(k==MAX_ITER){ 
                    printf("*"); //black dot for converged points
                }else{
                    printf("."); //white dot for diverged points
                }
            }
        }
        printf("\n");
    }
}

int main(){
    clock_t t;
    t = clock();
    generateFractal(true); // true for color, false for black and white
    t = clock()-t;
    printf("\nTime taken: %f seconds",((double)t)/CLOCKS_PER_SEC);
    return 0;
}