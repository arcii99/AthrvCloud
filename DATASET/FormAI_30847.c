//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 80
#define MAX_GRAYSCALE 255

char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int calculateAverageGrayScaleValue(unsigned char* pixel, int channels) {
    int sum = 0;
    for(int i=0; i<channels; i++) {
        sum += pixel[i];
    }
    return sum/channels;
}

int getAsciiCharIndex(int grayScaleValue) {
    int index = grayScaleValue/(MAX_GRAYSCALE/sizeof(asciiChars));
    return index < sizeof(asciiChars) ? index : sizeof(asciiChars) -1;
}

void printAsciiArt(unsigned char* imageData, int width, int height, int channels) {
    for(int y=0; y<height; y+=2) {
        for(int x=0; x<width*channels; x+=channels) {
            unsigned char* pixel1 = imageData + (y*width*channels) + x;
            unsigned char* pixel2 = imageData + ((y+1)*width*channels) + x;
            int grayScaleValue1 = calculateAverageGrayScaleValue(pixel1, channels);
            int grayScaleValue2 = calculateAverageGrayScaleValue(pixel2, channels);
            int asciiIndex1 = getAsciiCharIndex(grayScaleValue1);
            int asciiIndex2 = getAsciiCharIndex(grayScaleValue2);
            putchar(asciiChars[asciiIndex1]);
            putchar(asciiChars[asciiIndex2]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }
    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Unable to open the file: %s\n", filename);
        return 0;
    }
    unsigned char imageData[WIDTH*HEIGHT*4];
    unsigned char* imagePointer = imageData;
    fread(imageData, sizeof(unsigned char), WIDTH*HEIGHT*4, file);
    fclose(file);
    printAsciiArt(imageData, WIDTH, HEIGHT, 4);
    return 0;
}