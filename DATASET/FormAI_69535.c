//FormAI DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    int height;
    int width;
    char data[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void createImage(Image *img, int h, int w) {
    img->height = h;
    img->width = w;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            img->data[i][j] = ' ';
        }
    }
}

void printImage(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            printf("%c ", img.data[i][j]);
        }
        printf("\n");
    }
}

void drawLine(Image *img, int row, int col, int len, char direction) {
    if(direction == 'h') {
        for(int i = col; i < col + len; i++) {
            img->data[row][i] = '-';
        }
    } else if(direction == 'v') {
        for(int i = row; i < row + len; i++) {
            img->data[i][col] = '|';
        }
    }
}

void floodFill(Image *img, int row, int col, char color) {
    if(row < 0 || row >= img->height || col < 0 || col >= img->width) {
        return;
    }
    if(img->data[row][col] != ' ') {
        return;
    }
    img->data[row][col] = color;
    floodFill(img, row+1, col, color);
    floodFill(img, row-1, col, color);
    floodFill(img, row, col+1, color);
    floodFill(img, row, col-1, color);
}

int main() {
    Image img;
    createImage(&img, 10, 10);
    drawLine(&img, 2, 2, 5, 'h');
    drawLine(&img, 4, 4, 3, 'v');
    printf("Original Image:\n");
    printImage(img);
    floodFill(&img, 7, 7, '*');
    printf("\nImage after Flood Fill:\n");
    printImage(img);
    return 0;
}