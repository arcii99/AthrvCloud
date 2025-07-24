//FormAI DATASET v1.0 Category: Fractal Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 1024 // The height of the image
#define WIDTH 1024 // The width of the image
#define FRACTAL_DEPTH 1024 // The depth of recursion for the fractal

typedef struct{
    double x,y;
} complex;

// This function calculates the square of a complex number
complex square (complex c){
    complex result;
    result.x = c.x*c.x - c.y*c.y;
    result.y = 2*c.x*c.y;
    return result;
}

// This function calculates the Mandelbrot set value for the given complex number c
int mandelbrot (complex c, int depth){
    complex z;
    z.x = 0;
    z.y = 0;
    int i;
    for(i=0;i<depth;i++){
        z = square(z);
        z.x += c.x;
        z.y += c.y;
        if(z.x*z.x + z.y*z.y > 4) return i;
    }
    return depth;
}

// This function calculates the Julia set value for the given complex numbers c and k
int julia (complex k, complex c, int depth){
    complex z;
    z = c;
    int i;
    for(i=0;i<depth;i++){
        z = square(z);
        z.x += k.x;
        z.y += k.y;
        if(z.x*z.x + z.y*z.y > 4) return i;
    }
    return depth;
}

// This function converts a given value to a color in RGB format
void getColor (int value, int max_value, int* r, int* g, int* b){
    if(value == max_value) *r = *g = *b = 0;
    else{
        double t = (double)value/(double)max_value;
        *r = (int)(sin(2*M_PI*t)*255);
        *g = (int)(sin(2*M_PI*t + 2*M_PI/3)*255);
        *b = (int)(sin(2*M_PI*t + 4*M_PI/3)*255);
    }
}

int main(){

    unsigned char img[HEIGHT][WIDTH][3];
    int i,j,k;
    complex c,k_val;

    // Calculate the Mandelbrot set for the entire image
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            c.x = ((double)j-WIDTH/2.0)/((double)WIDTH/4.0);
            c.y = ((double)i-HEIGHT/2.0)/((double)HEIGHT/4.0);
            getColor(mandelbrot(c,FRACTAL_DEPTH),FRACTAL_DEPTH,
            &img[i][j][0],&img[i][j][1],&img[i][j][2]);
        }
    }

    // Calculate the Julia set for a few points
    for(i=0;i<HEIGHT;i+=HEIGHT/2){
        for(j=0;j<WIDTH;j+=WIDTH/2){
            k_val.x = ((double)j-WIDTH/2.0)/((double)WIDTH/4.0);
            k_val.y = ((double)i-HEIGHT/2.0)/((double)HEIGHT/4.0);
            for(k=0;k<HEIGHT/32;k++){
                c.x = (double)(rand()%WIDTH)/((double)WIDTH/4.0) - 1.0;
                c.y = (double)(rand()%HEIGHT)/((double)HEIGHT/4.0) - 1.0;
                getColor(julia(k_val,c,FRACTAL_DEPTH),FRACTAL_DEPTH,
                &img[(int)(c.y*(double)HEIGHT/2.0+HEIGHT/2.0)][(int)(c.x*(double)WIDTH/2.0+WIDTH/2.0)][0],
                &img[(int)(c.y*(double)HEIGHT/2.0+HEIGHT/2.0)][(int)(c.x*(double)WIDTH/2.0+WIDTH/2.0)][1],
                &img[(int)(c.y*(double)HEIGHT/2.0+HEIGHT/2.0)][(int)(c.x*(double)WIDTH/2.0+WIDTH/2.0)][2]);
            }
        }
    }

    // Write the image to a file
    FILE *f = fopen("fractal.ppm","wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(img, 1, 3*WIDTH*HEIGHT, f);
    fclose(f);

    return 0;
}