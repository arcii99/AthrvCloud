//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(){

    int size = 1024;
    double complex c, z, zn;
    int iterations = 256;
    double x, y;
    double delta = 4.0 / (double)size;
    int i,j,k;

    for(j=0; j<size; j++){
        for(i=0; i<size; i++){
            x = -2.0 + i * delta;
            y = -2.0 + j * delta;
            c = x + I*y;

            for(k=0; k<iterations; k++){
                zn = z*z + c;
                if(cabs(zn) > 2.0){
                    break;
                }
                z = zn;
            }

            if(k == iterations){
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