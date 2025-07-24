//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 60

void convertToASCII(unsigned char img[][WIDTH], char ascii[][WIDTH]);
void printASCII(char ascii[][WIDTH]);

int main() {
    unsigned char img[HEIGHT][WIDTH];
    char ascii[HEIGHT][WIDTH];

    // Load image data
    FILE *fp = fopen("image.dat", "rb");
    fread(img, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Convert to ASCII
    convertToASCII(img, ascii);

    // Print ASCII art
    printASCII(ascii);

    return 0;
}

void convertToASCII(unsigned char img[][WIDTH], char ascii[][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            ascii[y][x] = img[y][x] > 128 ? '.' : '#';
        }
    }
}

void printASCII(char ascii[][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(ascii[y][x]);
        }
        putchar('\n');
    }
}