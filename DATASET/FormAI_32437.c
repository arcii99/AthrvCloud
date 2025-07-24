//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define max_iterations 100

int main(){

    double im_start = -1.5;
    double im_end = 1.5;
    double re_start = -2;
    double re_end = 1;
    double complex c, z, z_new;

    double im_step = (im_end - im_start) / 100.0;
    double re_step = (re_end - re_start) / 200.0;

    for(double im = im_start; im < im_end; im += im_step){

        for(double re = re_start; re < re_end; re += re_step){

            c = re + im * I;
            z = 0;

            for(int i = 0; i < max_iterations; i++){

                z_new = z * z + c;

                if(cabs(z_new) > 2){
                    printf("*");
                    break;
                }

                z = z_new;

                if(i == max_iterations - 1){
                    printf(".");
                }

            }

        }

        printf("\n");

    }

    return 0;

}