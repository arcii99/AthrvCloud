//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_IMAGE_WIDTH 128
#define MAX_IMAGE_HEIGHT 128

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_WIDTH][MAX_IMAGE_HEIGHT];
} Image;

void printImage(Image* image) {
    printf("+");
    for (int i = 0; i < image->width; i++) {
        printf("-");
    }
    printf("+\n");
    for (int i = 0; i < image->height; i++) {
        printf("|");
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->pixels[j][i]);
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < image->width; i++) {
        printf("-");
    }
    printf("+\n");
}

char toggleCase(char c) {
    if (isupper(c)) {
        return tolower(c);
    } else if (islower(c)) {
        return toupper(c);
    } else {
        return c;
    }
}

void flipHorizontally(Image* image) {
    for (int i = 0; i < image->width / 2; i++) {
        for (int j = 0; j < image->height; j++) {
            char temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[image->width - i - 1][j];
            image->pixels[image->width - i - 1][j] = temp;
        }
    }
}

void flipVertically(Image* image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height / 2; j++) {
            char temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->height - j - 1];
            image->pixels[i][image->height - j - 1] = temp;
        }
    }
}

void invert(Image* image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            image->pixels[i][j] = toggleCase(image->pixels[i][j]);
        }
    }
}

int main() {
    Image testImage = {
        .width = 8,
        .height = 6,
        .pixels = {
            {'#', '.', '.', '.', '.', '.', '#', '#'},
            {'#', '.', '.', '.', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '#', '.', '.', '#'},
            {'#', '.', '.', '.', '#', '.', '.', '#'},
            {'#', '.', '.', '.', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '.', '#', '#'}
        }
    };
    printf("Original image:\n");
    printImage(&testImage);
    printf("\nFlipped horizontally:\n");
    flipHorizontally(&testImage);
    printImage(&testImage);
    printf("\nFlipped vertically:\n");
    flipVertically(&testImage);
    printImage(&testImage);
    printf("\nInverted:\n");
    invert(&testImage);
    printImage(&testImage);
    return 0;
}