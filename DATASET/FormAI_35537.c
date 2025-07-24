//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multivariable
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define WIDTH 50
#define HEIGHT 25
#define Z_SQUARED_WITHIN_THRESHOLD 4.0

int main(){
    double r_start=-2, r_end=2, i_start=-1, i_end=1;
    double x_ratio=(r_end-r_start)/WIDTH, y_ratio=(i_end-i_start)/HEIGHT;
    double x=0, y=0, zx=0, zy=0, new_zx=0, new_zy=0;

    //calculate mandelbrot set
    int i,j,k;
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            zx=0, zy=0, x=0, y=0;
            for(k=0; k<100; k++){
                new_zx = zx*zx - zy*zy + x;
                new_zy = 2*zx*zy + y;
                if(new_zx*new_zx + new_zy*new_zy > Z_SQUARED_WITHIN_THRESHOLD){
                    break;
                }
                
                zx = new_zx;
                zy = new_zy;
            }

            if(k!=100){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}