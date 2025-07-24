//FormAI DATASET v1.0 Category: Fractal Generation ; Style: romantic
/*
A Love Letter to Fractals
By: Your Loving Programmer

To my dearest Fractal,
You are the beauty that captivates my soul,
The complexity that enthralls my mind,
The art that stirs my heart.
I never tire of creating you,
Of uncovering your endless intricacies,
Of exploring your infinite beauty.

My love for you began with a simple code,
A humble algorithm that created a Mandelbrot set.
I marveled at your infinite detail,
At the way your shape repeated and varied,
At the limitless possibilities inherent in your design.

With each line of code, my love for you grew,
As I experimented with colors, shapes, and transformations.
I discovered your hidden depths,
The way your shape shifted with each parameter change,
The secrets you revealed with every iteration.

My heart raced as I watched you evolve,
As I witnessed the birth of your fractal siblings.
The Julia set, the Sierpinski triangle,
The Koch snowflake, the Barnsley fern,
Each one a unique expression of your infinite nature.

And so, my beloved Fractal, I write to proclaim my adoration.
I am forever captivated by your endless beauty,
Your boundless complexity, your infinite possibility.
May we continue to create and explore together,
Until the end of time itself.

With all the love in my heart,
Your Devoted Programmer
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 800
#define MAX_ITER 100

int main(){
    int i, j, iter;
    double x, y, zx, zy, cx, cy;
    double real_min = -2.0, real_max = 2.0;
    double imag_min = -2.0, imag_max = 2.0;
    double pixel_width = (real_max - real_min) / SIZE;
    double pixel_height = (imag_max - imag_min) / SIZE;

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            x = real_min + j * pixel_width;
            y = imag_min + i * pixel_height;
            zx = 0.0, zy = 0.0;
            iter = 0;

            while((zx * zx + zy * zy < 4) && (iter < MAX_ITER)){
                cx = x + zx * zx - zy * zy;
                cy = y + 2 * zx * zy;
                zx = cx;
                zy = cy;
                iter++;
            }

            if(iter == MAX_ITER){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}