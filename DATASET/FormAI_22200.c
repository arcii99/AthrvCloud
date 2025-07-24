//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define IMG_WIDTH 100
#define IMG_HEIGHT 100
#define MAX_WATERMARK_LEN 50
#define MAX_DIGIT 10

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} pixel;

void generateWatermark(char* watermark){
    srand(time(0));
    int watermarkLen = (rand() % MAX_WATERMARK_LEN) + 1;
    for (int i=0; i<watermarkLen; i++){
        watermark[i] = 'A' + (rand() % 26);
    }
    watermark[watermarkLen] = '\0';
}

void printImage(pixel img[IMG_HEIGHT][IMG_WIDTH]){
    for (int i=0; i<IMG_HEIGHT; i++){
        for (int j=0; j<IMG_WIDTH; j++){
            printf("(%d,%d,%d,%d) ",img[i][j].red,img[i][j].green,img[i][j].blue,img[i][j].alpha);
        }
        printf("\n");
    }
}

int getPixelSum(pixel pix){
    return pix.red + pix.green + pix.blue;
}

void embedWatermark(pixel img[IMG_HEIGHT][IMG_WIDTH], char* watermark){
    int watermarkLen = strlen(watermark);
    if (watermarkLen > IMG_WIDTH){
        printf("Watermark length exceeds image width. Exiting...");
        exit(1);
    }
    pixel watermarkPixel = {255, 255, 255, 0};
    int posX = (IMG_WIDTH - watermarkLen) / 2;
    int posY = (IMG_HEIGHT - 1) / 2;
    for (int i=0; i<watermarkLen; i++){
        char currChar = watermark[i];
        int currDigit = (int)currChar;
        for (int j=0; j<MAX_DIGIT; j++){
            int currBit = (currDigit >> j) & 1;
            int col = posX + i + j;
            int currPixelSum = getPixelSum(img[posY][col]);
            if (currBit == 1 && currPixelSum % 2 == 0){
                img[posY][col].red += 1;
                img[posY][col].green += 1;
                img[posY][col].blue += 1;
                img[posY][col].alpha += 1;
            }
            else if (currBit == 0 && currPixelSum % 2 == 1){
                img[posY][col].red -= 1;
                img[posY][col].green -= 1;
                img[posY][col].blue -= 1;
                img[posY][col].alpha -= 1;
            }
        }
        img[posY][posX+i] = watermarkPixel;
    }
}

void extractWatermark(pixel img[IMG_HEIGHT][IMG_WIDTH], char* extractedWatermark){
    int watermarkLen = 0;
    char currChar = 0;
    for (int i=0; i<IMG_WIDTH; i+=MAX_DIGIT){
        currChar = 0;
        for (int j=0; j<MAX_DIGIT; j++){
            int currPixelSum = getPixelSum(img[(IMG_HEIGHT-1)/2][i+j]);
            if (currPixelSum % 2 == 1){
                currChar += (1 << j);
            }
        }
        if (currChar == 0){
            break;
        }
        extractedWatermark[watermarkLen++] = currChar;
    }
    extractedWatermark[watermarkLen] = '\0';
}

int main(){
    pixel img[IMG_HEIGHT][IMG_WIDTH];
    char watermark[MAX_WATERMARK_LEN+1];
    char extractedWatermark[MAX_WATERMARK_LEN+1];
    for (int i=0; i<IMG_HEIGHT; i++){
        for (int j=0; j<IMG_WIDTH; j++){
            img[i][j].red = 0;
            img[i][j].green = 0;
            img[i][j].blue = 0;
            img[i][j].alpha = 0;
        }
    }
    generateWatermark(watermark);
    printf("The watermark is: %s\n", watermark);
    embedWatermark(img, watermark);
    printImage(img);
    extractWatermark(img, extractedWatermark);
    printf("The extracted watermark is: %s\n", extractedWatermark);
    return 0;
}