//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n = 80;
    int iterations = 600;
    double zoom = 1.5;
    double xPos = -0.5;
    double yPos = 0;
    double xMin = -2.5/zoom + xPos;
    double xMax = 1.5/zoom + xPos;
    double yMin = -2/zoom + yPos;
    double yMax = 2/zoom + yPos;
    int i, j, iteration;
    double x, y, xNew, yNew, xOrigin, yOrigin;
    char ascii;
    double epsilon = 1e-10;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
      
            xOrigin = xPos + (double)j/n*(xMax-xMin);
            yOrigin = yPos + (double)i/n*(yMax-yMin);
          
            iteration = 0;
            x = xOrigin;
            y = yOrigin;
            while(sqrt(x*x+y*y) < 2 && iteration < iterations) {
                xNew = x*x-y*y+xOrigin;
                yNew = 2*x*y+yOrigin;
                x = xNew;
                y = yNew;
                iteration++;
            }

            if(iteration == iterations) {
                ascii = ' ';
            } else {
                if(iteration < 4) {
                    ascii = '.';
                } else if(iteration < 8) {
                    ascii = ':';
                } else if(iteration < 16) {
                    ascii = '*';
                } else if(iteration < 32) {
                    ascii = 'o';
                } else if(iteration < 64) {
                    ascii = '&';
                } else if(iteration < 128) {
                    ascii = '8';
                } else {
                    ascii = '@';
                }
            }
          
            printf("%c", ascii);
        }
        printf("\n");
    }

    return 0;
}