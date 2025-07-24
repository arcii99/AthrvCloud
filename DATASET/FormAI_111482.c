//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define ASCII_RANGE 95
#define PIXEL_SIZE 3

char ascii_table[ASCII_RANGE] = {' ', '.', ',', ':', ';', '!', '*', 'o', 'x', 's',
                                          '0', '8', '#', '@'};

void convertToASCII(char image[MAX_HEIGHT][MAX_WIDTH][PIXEL_SIZE], int height, int width) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int grayscale = (int) (0.2126*image[i][j][0] + 0.7152*image[i][j][1] + 0.0722*image[i][j][2]);
            int index = (int) (grayscale/(255/(ASCII_RANGE-1)));
            printf("%c", ascii_table[index]);
        }
        printf("\n");
    }
}

int main() {
    char image[MAX_HEIGHT][MAX_WIDTH][PIXEL_SIZE];
    int height, width;
    FILE *fp = fopen("input.ppm", "r");
    if(fp == NULL) {
        printf("Could not open file");
        return -1;
    }
    fscanf(fp, "P3\n%d %d\n255\n", &width, &height);
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            fscanf(fp, "%hhu %hhu %hhu", &image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }
    fclose(fp);
    convertToASCII(image, height, width);
    return 0;
}