//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

int image[WIDTH][HEIGHT];

int main(){
    // initialize the image to all white
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            image[i][j] = 255;
        }
    }
    // draw a rectangle in the center of the image
    for(int i=WIDTH/4;i<WIDTH*3/4;i++){
        for(int j=HEIGHT/4;j<HEIGHT*3/4;j++){
            image[i][j] = 0;
        }
    }
    // save the image to a file
    FILE *fp = fopen("image.pgm", "wb");
    fprintf(fp, "P5 %d %d 255\n", WIDTH, HEIGHT);
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            fputc(image[i][j], fp);
        }
    }
    fclose(fp);
    return 0;
}