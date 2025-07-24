//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_INTENSITY 255

char ascii[MAX_HEIGHT][MAX_WIDTH];

void convertToAscii(int intensities[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int intensity = intensities[i][j];
            int ascii_index = (intensity * 70) / (MAX_INTENSITY + 1);
            if(ascii_index > 69) {
                ascii_index = 69;
            }
            ascii[i][j] = (char)ascii_index;
        }
    }
}

void printAscii(int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            putchar(ascii[i][j]);
        }
        putchar('\n');
    }
}

void clearAscii(int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            ascii[i][j] = ' ';
        }
    }
}

int main() {
    int intensities[MAX_HEIGHT][MAX_WIDTH];

    // Sample data for testing
    for(int i = 0; i < MAX_HEIGHT; i++) {
        for(int j = 0; j < MAX_WIDTH; j++) {
            intensities[i][j] = (i+j)%256;
        }
    }

    convertToAscii(intensities, MAX_HEIGHT, MAX_WIDTH);
    printAscii(MAX_HEIGHT, MAX_WIDTH);
    clearAscii(MAX_HEIGHT, MAX_WIDTH);

    return 0;
}