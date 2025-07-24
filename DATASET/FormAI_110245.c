//FormAI DATASET v1.0 Category: Fractal Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480
#define FILENAME "fractal.ppm"

typedef struct _complex{
    double real;
    double imag;
} complex;

static const complex z_constant = {0.6, 0.4};

// check if a point is in the extended Mandelbrot set
bool in_set(complex z){
    complex prev_z = z;
    complex new_z;
    for(int i = 0; i < 1000; i++){
        new_z.real = prev_z.real * prev_z.real - prev_z.imag * prev_z.imag + z.real;
        new_z.imag = 2 * prev_z.real * prev_z.imag + z.imag;
        if(new_z.real * new_z.real + new_z.imag * new_z.imag > 16){
            return false;
        }
        prev_z = new_z;
    }
    return true;
}

// create an image of the Mandelbrot set and its Julia sets
void create_image(){
    // open file for writing ppm format image
    FILE *image_file = fopen(FILENAME, "wb");
    fprintf(image_file, "P6 %d %d 255\n", WIDTH, HEIGHT);

    // set up the Julia set and its transformation constant
    complex z;
    double zoom = 2.0;
    complex z_trans = {0.4, 0.7};

    // iterate through each pixel and color it based on whether it is in the set
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            z.real = (x - WIDTH/2.0) / (double)(WIDTH/zoom);
            z.imag = (y - HEIGHT/2.0) / (double)(HEIGHT/zoom);
            if(in_set(z)){
                fputc(0, image_file);
                fputc(0, image_file);
                fputc(0, image_file);
            }
            else{
                int julia_iterations = 2000;
                complex c = z_constant;
                for(int i = 0; i < julia_iterations; i++){
                    z.real = z.real * z.real - z.imag * z.imag + c.real + z_trans.real;
                    z.imag = 2 * z.real * z.imag + c.imag + z_trans.imag;
                    if(z.real * z.real + z.imag * z.imag > 16){
                        double nsmooth = i + 1 - log(log(sqrt(z.real*z.real+z.imag*z.imag))) / log(2);
                        int red = (int)(127.0 + 127.0*cos(nsmooth*0.03));
                        int green = (int)(127.0 + 127.0*cos(nsmooth*0.06));
                        int blue = (int)(127.0 + 127.0*cos(nsmooth*0.01));
                        fputc(red, image_file);
                        fputc(green, image_file);
                        fputc(blue, image_file);
                        break;
                    }
                    if(i == julia_iterations - 1){
                        fputc(0, image_file);
                        fputc(0, image_file);
                        fputc(0, image_file);
                    }
                }
            }
        }
    }

    fclose(image_file);
}

int main(){
    create_image();
    return 0;
}