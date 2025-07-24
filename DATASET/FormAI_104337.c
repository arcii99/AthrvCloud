//FormAI DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 100
#define IMAGE_HEIGHT 100

void blur_recursion(unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH], int row, int col, int radius, int depth) {
    if (depth > radius) return;
    int sum = 0, count = 0;
    for (int i = -depth; i <= depth; i++) {
        for (int j = -depth; j <= depth; j++) {
            int x = row + i;
            int y = col + j;
            if (x >= 0 && x < IMAGE_HEIGHT && y >= 0 && y < IMAGE_WIDTH) {
                sum += image[x][y];
                count++;
            }
        }
    }
    unsigned char avg = (unsigned char)(sum / count);
    image[row][col] = avg;
    blur_recursion(image, row, col-1, radius, depth+1);
    blur_recursion(image, row, col+1, radius, depth+1);
    blur_recursion(image, row-1, col, radius, depth+1);
    blur_recursion(image, row+1, col, radius, depth+1);
}

int main() {
    unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH];
    memset(image, 0, IMAGE_HEIGHT*IMAGE_WIDTH*sizeof(unsigned char));
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }
    blur_recursion(image, IMAGE_HEIGHT/2, IMAGE_WIDTH/2, 5, 0);
    printf("P5\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fwrite(image, sizeof(unsigned char), IMAGE_HEIGHT*IMAGE_WIDTH, stdout);
    return 0;
}