//FormAI DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH  512
#define HEIGHT 512

unsigned char image[WIDTH][HEIGHT];
unsigned char buffer[WIDTH][HEIGHT];

void flipImage(unsigned char img[WIDTH][HEIGHT]){
    int i,j;

    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            buffer[i][j] = img[HEIGHT-i-1][j];
        }
    }

    memcpy(img, buffer, WIDTH*HEIGHT);
}

void sharpenImage(unsigned char img[WIDTH][HEIGHT]){
    int i,j;
    int sum;
    int filter[5][5] = {
                {-1,-1,-1,-1,-1},
                {-1,-1,-1,-1,-1},
                {-1,-1,24,-1,-1},
                {-1,-1,-1,-1,-1},
                {-1,-1,-1,-1,-1}};

    for(i=2;i<HEIGHT-2;i++){
        for(j=2;j<WIDTH-2;j++){
            sum = filter[0][0]*img[i-2][j-2] +
                          filter[0][1]*img[i-2][j-1] +
                          filter[0][2]*img[i-2][j] +
                          filter[0][3]*img[i-2][j+1] +
                          filter[0][4]*img[i-2][j+2] +
                          filter[1][0]*img[i-1][j-2] +
                          filter[1][1]*img[i-1][j-1] +
                          filter[1][2]*img[i-1][j] +
                          filter[1][3]*img[i-1][j+1] +
                          filter[1][4]*img[i-1][j+2] +
                          filter[2][0]*img[i][j-2] +
                          filter[2][1]*img[i][j-1] +
                          filter[2][2]*img[i][j] +
                          filter[2][3]*img[i][j+1] +
                          filter[2][4]*img[i][j+2] +
                          filter[3][0]*img[i+1][j-2] +
                          filter[3][1]*img[i+1][j-1] +
                          filter[3][2]*img[i+1][j] +
                          filter[3][3]*img[i+1][j+1] +
                          filter[3][4]*img[i+1][j+2] +
                          filter[4][0]*img[i+2][j-2] +
                          filter[4][1]*img[i+2][j-1] +
                          filter[4][2]*img[i+2][j] +
                          filter[4][3]*img[i+2][j+1] +
                          filter[4][4]*img[i+2][j+2];

            if(sum<0){
                sum = 0;
            }

            if(sum>255){
                sum = 255;
            }

            buffer[i][j] = sum;
        }
    }

    memcpy(img, buffer, WIDTH*HEIGHT);
}

int main(){
    FILE *inFile;
    FILE *outFile;

    inFile = fopen("input.bmp", "rb");
    outFile = fopen("output.bmp", "wb");

    int i,j;
    int bmpWidth, bmpHeight, bmpHeaderSize;
    unsigned char bmpHeader[54];

    memset(bmpHeader, 0, sizeof(bmpHeader));

    fread(bmpHeader, 54, 1, inFile);

    bmpWidth = *(int*)&bmpHeader[18];
    bmpHeight = *(int*)&bmpHeader[22];
    bmpHeaderSize = *(int*)&bmpHeader[10];

    fread(image, WIDTH*HEIGHT, 1, inFile);

    flipImage(image);
    sharpenImage(image);
    flipImage(image);

    fwrite(bmpHeader, 54, 1, outFile);
    fwrite(image, WIDTH*HEIGHT, 1, outFile);

    fclose(inFile);
    fclose(outFile);

    printf("Image processing complete!");

    return 0;
}