//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 1920
#define HEIGHT 1080

// A surrealistic fractal generator
// inspired by Salvador Dali's Persistence of Memory

int main(){

    char screen[HEIGHT][WIDTH];

    double x, y, r, angle, cos_val, sin_val, real, imag, tempre, tempim, new_re, new_im;
    int i, j, iteration, max_iteration = 40, color;

    // initialize the screen
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            screen[i][j] = ' ';
        }
    }

    // generate the fractal
    for(y = -1.5; y <= 1.5; y += 0.05){
        for(x = -2; x <= 1; x += 0.025){

            r = sqrt(x*x+y*y);
            angle = atan2(y,x);

            // apply a transformation to the complex number
            cos_val = cos(angle*r);
            sin_val = sin(angle*r);
            real = x*cos_val - y*sin_val;
            imag = x*sin_val + y*cos_val;

            iteration = 0;
            tempre = real;
            tempim = imag;

            // iterate using the mandatory surreal number
            while(iteration < max_iteration){

                new_re = tempre*tempre + tempim*tempim - 0.7*tempre;
                new_im = 2*tempre*tempim - 0.4*tempim;

                tempre = new_re;
                tempim = new_im;

                iteration++;

                if(r > 1 && tempre > -0.3 && tempre < 1 && tempim < 0){
                    break;
                }
            }

            // assign colors to the character in the screen
            if(iteration == max_iteration){
                screen[(int)((1.5-y)/0.05)][(int)((x+2)/0.025)] = 'O';
            }
            else if(iteration > 0){
                color = (iteration%7)+30;
                screen[(int)((1.5-y)/0.05)][(int)((x+2)/0.025)] = color;
            }
        }
    }

    // print the screen to the console
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            if(screen[i][j] == 'O'){
                printf("\033[0m%c", '\xB0');
            }
            else if(screen[i][j] == ' '){
                printf(" ");
            }
            else{
                printf("\033[%dm%c", screen[i][j], '\xB0');
            }
        }
        printf("\n");
    }

    return 0;
}